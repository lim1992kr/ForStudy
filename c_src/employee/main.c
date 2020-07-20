#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int id;
	char name[20];
	//
} Employee;

typedef struct{
	int id;
	char *name;
}Employee2;

void assignEmployee(Employee2 *des, const Employee2 *src)
{
	des->id = src->id;
	free(des->name);
	des->name = (char *)malloc(sizeof(char) * 20); 	//strlen(src -> name) +1 
	strcpy(des->name, src->name);
}

int compareEmployee(const Employee2 *pe1, const Employee2 *pe2)
{
	return	!(pe1->id == pe2->id && strcmp(pe1->name, pe2->name) == 0);
}

int main(void)
{
	Employee e1;
	e1.id = 1;
	strcpy(e1.name, "lim chea beom");

	Employee e2,e3;
	e2.id = 2;
	e2.name = (char *)malloc(sizeof(char)*20);
	strcpy(e2.name, "lim yo han" );
	
	e3.id = 3;
	e3.name = (char *)malloc(sizeof(char)*20);
	strcpy(e3.name, "lim yo hadfag" );
	
	// e2 = e3;
	assignEmployee(&e2,&e3);
	
	// e2 == e3
	if (	compareEmployee(&e2,&e3)==0)
		printf("e2 and e3 are equal\n");
	else
		printf("e2 and e3 are not equal\n");

	free(e2.name);
	free(e3.name);	
	return 0;
}
/*
char buf[1024];
char *name = buf;
char *name = (char *)malloc(sizeof(char)* 100 );
strcpy(name, "lim chae beom");
...
free(name);
*/



