#include <stdio.h>
#include <stdlib.h>
typedef struct stu
{int num,age;char name[20],sex[20];struct stu *next;}Stu;
int main()
{Stu *head,*p1,*p2;
int n,age,i=0;
scanf("%d",&n);
p1 = p2 = (Stu *)malloc(sizeof(Stu));
do
{scanf("%d%*c", &p1->num);gets(p1->name);gets(p1->sex);
scanf("%d", &p1->age);
if (!i) head = p1;
else p2->next = p1;p2 = p1;p1 = (Stu *)malloc(sizeof(Stu));i++;}while(i<n);
p2->next = NULL;
while (~scanf("%d", &age), age)
{p1 = head;
while (p1->age != age&&p1->next != NULL){p2 = p1;p1 = p1->next;}
if (p1->age == age){if (p1 == head) head = p1->next;else p2->next = p1->next;free(p1);puts("Delete success!");}else puts("Can't find!");}
}