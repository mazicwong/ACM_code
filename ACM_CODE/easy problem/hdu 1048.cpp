#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
	char str[200];
	int n;
	while (gets_s(str) != NULL && strcmp(str, "ENDOFINPUT"))
	{
		if (strcmp(str, "START") == 0 || strcmp(str, "END") == 0)
			continue;
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] >= 'A')
			{
				if (str[i] <= 'E')
				{
					str[i] = 'V' + str[i] - 'A';
					printf("%c", str[i]);
				}
				else
					printf("%c", str[i] - 5);
			}
			else
				printf("%c", str[i]);
		}
		puts("");
	}
	return 0;
}