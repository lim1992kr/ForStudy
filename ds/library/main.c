#include <stdio.h>
#include <string.h>
#include "book.h"

int main(void)
{
	book bookList[10];
	int count = 0;
	
	
	FILE *fin;
	fin = fopen("bookList.dat","r");
	
	char *delimieter = "@\n";
	char buf[1024];
	while (fgets(buf, 1014, fin) != NULL){
		char *token = strtok(buf, delimieter);
		
		strcpy(bookList[count].title, token);
		
		token = strtok(NULL, delimieter);
		strcpy(bookList[count].author, token);
		
		token = strtok(NULL, delimieter);
		strcpy(bookList[count].publisher, token);
		
		token = strtok(NULL, delimieter);
		strcpy(bookList[count].date, token);

		token = strtok(NULL, delimieter);
		strcpy(bookList[count].isbn, token);
		
		++count;
		
	
	}
	
		for (int i =0; i < count; ++i)
		printf("%s %s %s %s %s\n", bookList[count].title,bookList[count].author,
			bookList[count].publisher,bookList[count].date,bookList[count].isbn);
		
			
	fclose(fin);
	return 0;
}
