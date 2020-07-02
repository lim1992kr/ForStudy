#include<stdio.h>

int main (void)
{
	printf("%d %d %d\n", 100,0114,0x64); 				//decimal
	printf("%d 0%o 0x%x\n", 100,100,100); 			//octial(8), hexa-decimal(16)
	
	printf("%d %d %d\n", 'A', 'a','0');
	printf("%d %d %d\n", 65,97,48);					
	
	printf("%c %c %c\n", 65, 97, 48);					//character
	printf("%c %c %c\n", 'A','a','0');
	
	printf("%c %c %c\n", 'a','A'+1,'A'+2);
	
	printf("%f %f\n", 3.1415, 2.718F);
	
	printf("%s\n", "ABCD");								//string
	0000
	printf("%lldLL\n", 10000000000LL);
	return 0;
}
