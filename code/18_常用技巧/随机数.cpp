#include <time.h>

//int型:
srand(time(NULL));
printf("%d\n",rand());

//给定范围:
int t=100;
srand(time(NULL));
printf("%d\n",rand()%t);

//double型:
srand(time(NULL));
printf("%.6lf\n",rand()*1.0/100);

//字符串
int len=100;
srand(time(NULL));
while(len--)
{
    printf("%c\n",'A'+rand()%26);
}
