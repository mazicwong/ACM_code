#include<stdio.h>
#include<stdlib.h>
int N;
struct student {
	int number;
	char name[20];
	char sex[20];
	int age;
	struct student *next;
};
void input(struct student stu[]);
struct student *search(int num, struct student*list);
int main() {
	int num;
	scanf("%d", &N);
	struct student stu[5];
	struct student *p = stu;
	struct student *list = stu;
	input(p);
	scanf("%d", &num);
	while (num != 0) {
		list = search(num, list);
		scanf("%d", &num);
	}
	return 0;
}
void input(struct student stu[]) {
	int i;
	for (i = 0; i<N; i++) {
		scanf("%d", &stu[i].number);
		getchar();
		gets_s(stu[i].name);
		scanf("%s", stu[i].sex);
		scanf("%d", &stu[i].age);
		stu[i].next = (struct student*)malloc(sizeof(struct student));
		if (stu[i].next == NULL) {
			printf("error\n");
			exit(EXIT_FAILURE);
		}
		stu[i].next = &stu[i + 1];
	}
	stu[i - 1].next = NULL;
}
struct student* search(int num, struct student*list) {
	struct student*cur = list, *prev = NULL;
	for (; cur != NULL&&cur->age != num; prev = cur, cur = cur->next)
		;
	if (cur == NULL) {
		printf("Can't find!\n");
	}
	else {
		printf("Delete success!\n");
		if (prev == NULL) list = list->next;
		else prev->next = cur->next;
	}
	free(cur);
	return list;
}