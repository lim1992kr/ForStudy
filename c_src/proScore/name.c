#include<stdio.h>

int main (void)
{
	char name[20];
	scanf("%19s", name);				//scnaf("%s", &name[0]);  %19s 19개 까지 읽겠다.
	printf("%s\n", name);				//	printf("%s", &name[0]);

	printf("%s\n", "hello, world" +2);   // l부터 출력해라 %s 는 \0를 만날때까지 스캔 프린트해라
	return 0;
}
