#include <stdio.h>

void printStringArray1(char(*arr)[20], int size)
{
	for(int i=0; i<size ; i++)
		printf("%s\n", &arr[i][0]);			//arr[i]

}
void printStringArray2 (char **arr, int size)
{
	for(int i = 0 ; i < size;++i)
		printf("%s\n", arr[i]);			//&arr[i][0]
}	
int main(void)
{
	char cities1[][20] = {
		"Seoul", "Los Angeles", "Rio De janeiro", "Moscow", "paris"
	};
	char *cities2[20] = {
		"Seoul", "Los Angeles", "Rio De janeiro", "Moscow", "paris"
	};

}
