#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define LINE 256
#define WORD 30

int getline_length(char s[])
{
    	int len = 0;
    	char c  = getchar();
    	while(c != '\n' && c != EOF && len < LINE -1)
    	{
        	s[len++] = c;
        	c=getchar();
    	}
    	s[len] = '\0';
    	if(c == EOF)
    		return EOF;
    	return len;
}

int getword_length(char w[])
{
    	int len = 0;
    	char c = getchar();
    	while(c != '\n' && c != '\t' && c !=' ' && c != EOF && len < WORD -1)
    	{
         	w[len++] = c;
         	c = getchar();
    	}
    	w[len] = '\0';
    	if(c == EOF)
    		return EOF;
    	return len;
}

int substring(char * str1, char * str2)
{
    	int str1_len, str2_len;
    	str1_len = strlen(str1);
    	str2_len = strlen(str2);
   
    	if(str1_len < str2_len)
        	return FALSE;
       
    	for(int i = 0; i < str1_len - str2_len + 1; i++)
    	{
        	if(str1[i] == str2[0])
        	{
            		int j = 1;
            		while(j < str2_len)
            		{	
                		if(str1[i+j] != str2[j])
                    			break;
                		j++;	
            		}
            		if(j == str2_len)
                		return TRUE;
        	}
    	}
    	return FALSE;
}


int similar(char *s, char *t, int n)
{
    	int s_len, t_len;
    	s_len = strlen(s);
    	t_len = strlen(t);

    	if(s_len - n != t_len)
        	return FALSE;
   
    	int count = 0;
    	int i = 0, j = 0;
    	while(i < s_len)
    	{
        	if(*(s+i) == *(t+j))
        	{
            		i++;
            		j++;
        	}
        	else
        	{
           		count++;
            		i++;
        	}
        	if(count > n)
            		return FALSE;
    	}
    	if(count == n)
        	return TRUE;
    	else
        	return FALSE;
}

void print_lines(char * str)
{
    	char s[LINE];
    	while(getline_length(s) != EOF)
    	{
        	if(substring(s,str) == 1)
            		printf("%s\n" , s);
    	}	
}

void print_similar_words(char * str)
{
    	char s[WORD];
    	while(getword_length(s) != EOF)
    	{
        	if(similar(s,str,1) == 1 || similar(s,str,0))
            		printf("%s\n" , s);
    	}
}


int main()
{
    	char word[WORD];
    	char  action;
    	getword_length(word);
    	scanf("%c", &action);
   	
   	getchar();
   	getchar();
   	
   	printf("\n");
    	if (action == 'a')
        	print_lines(word);
    	else if (action == 'b')
        	print_similar_words(word);
       else
       	printf("ivalid input\n");
       
       printf("\n");
   
    return 0;
}
