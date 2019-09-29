#include"header.h"

#if(abc==1)
int my_strcmp(char *a,char *b)				//string comapre func definition
{
	char i;
	for(i=0;a[i];i++)
	{	
		if(a[i]!=b[i])
			return 0;
	}
			return 1;
}
#endif

#if(abc==10)
void my_strcpy(char *a,char *b)				//string copy func definition
{
	U8 i;
	for(i=0;a[i];i++)
	{
		b[i] = a[i];
	}
	b[i]=0;
}
#endif
