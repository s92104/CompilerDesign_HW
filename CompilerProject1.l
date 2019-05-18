%{
	char content[256];
	void addContent()	{strcat(content,yytext);}
	int lineCount=0;
	char symbolTable[100][100];
	int symbolCount=0;
	void addSymbol()	{
							int same=0;
							for(int i=0;i<symbolCount;i++)
							{
								for(int j=0;j<yyleng;j++)
								{
									if(symbolTable[i][j]!=yytext[j])
										break;
									if(j==yyleng-1)
										same=1;
								}
							}
							if(same!=1)
							{
								symbolCount++;
								strcat(symbolTable[symbolCount-1],yytext);
							}
								
						}
	void dump()	{
					printf("Symbol Table:\n");
					for(int i=0;i<symbolCount;i++)
						printf("%s\n",symbolTable[i]);
				}
%}
letter	[A-Za-z]
digit	[0-9]
digits	{digit}+
%x COMMENT
%%
,|:|;|"("|")"|"["|"]"|"{"|"}"	{addContent();printf("<'%s'>\n",yytext);}

"+"|"-"|"*"|"/"|"%"|"<"|"<="|">="|">"|=|"<>"|&&|"||"|~|:=	{addContent();printf("<'%s'>\n",yytext);}

array|boolean|begin|break|char|case|const|continue|do|else|end|exit|for|fn|if|in|integer|loop|module|print|println|procedure|repeat|return|real|string|record|then|type|use|util|var|while	{addContent();printf("<%s>\n",yytext);}

{digits}	{addContent();printf("<integer:%s>\n",yytext);}
true|false	{addContent();printf("<boolean:%s>\n",yytext);}
{digits}"."{digits}([Ee][+-]?{digits})?	{addContent();printf("<real:%s>\n",yytext);}
\"[^\"]*\"	{
				char c=input();	
				if(c=='\"')
					yymore();	
				else
				{		
					addContent();
					for(int i=0;i<yyleng-1;i++)
						yytext[i]=yytext[i+1];
					yytext[yyleng-2]='\0';
					for(int i=0;i<yyleng-1;i++)
					{
						if(yytext[i]=='\"' && yytext[i+1]=='\"')
						{
							for(int j=i;j<yyleng-1;j++)
								yytext[j]=yytext[j+1];
						}
					}					
					printf("<string:%s>\n",yytext);
				}	
				unput(c);
			}

{letter}({letter}|{digit})*	{
								addSymbol();
								addContent();
								printf("<id: %s>\n",yytext);
							}

[ \t]	{addContent();}
"//".*	{addContent();}

"(*"	{addContent();BEGIN(COMMENT);}
<COMMENT>.	{addContent();}
<COMMENT>\n	{
				lineCount++;
				printf("%d: %s\n",lineCount,content);
				content[0]='\0';
			}
<COMMENT>"*)"	{addContent();BEGIN(INITIAL);}

\n	{
		lineCount++;
		printf("%d: %s\n",lineCount,content);
		content[0]='\0';
	}

"."\n	{
			addContent();
			printf("<'.'>\n");
			lineCount++;
			printf("%d: %s\n",lineCount,content);
			content[0]='\0';
			dump();
		}
%%
