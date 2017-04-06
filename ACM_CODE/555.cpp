#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE*fp;
	char ch;
	fp = fopen("test", "w");
	ch = getchar();
	while (ch != '!')
	{
		if (ch >= 'a'&&ch <= 'z')
		{
			fputc(ch - 32, fp);
		}
		else
		{
			fputc(ch, fp);
		}
		ch = getchar();
	}
	fclose(fp);
	fp = fopen("test", "r");
	ch = fgetc(fp);
	while (ch != EOF)
	{
		putchar(ch);
		ch = fgetc(fp);
	}
	fclose(fp);
	return 0;
}

/*
#include <stdio.h>
int main()
{
	FILE *fp = fopen("test.txt", "w");
	char str[200];
	gets_s(str);
	int i = 0;
	while (str[i] != '!')
	{
		if (str[i] >= 'a'&&str[i] <= 'z') str[i] -= 32;
		putchar(str[i]);
		fputc(str[i], fp);
		i++;
	}
	fclose(fp);
	return 0;
}*/