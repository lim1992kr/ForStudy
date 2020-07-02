#include<stdio.h>

typedef struct {
	char name[20];
	int kor;
	int eng;
	int mat;
	int sum;
	double average;
	int rank;
	
} Student;

int main (void)
{
	FILE *fin, *fout;
	fin = fopen("score.dat", "r");
	fout = fopen("score.dat", "w");
	
	Student students[10];
	for (int i =0; i <10; ++i){			// man 3 fscanf
										 // scanf( 를 fscanf(fin,빈칸 으로 바꾸고											
	fscanf(fin, "%s %d %d %d",    //printf( 를 fprintf(fout,빈칸  으로 바꿈 
		students[i].name, &students[i].kor, &students[i].eng, &students[i].mat);
		students[i].sum = students[i].kor + students[i].eng + students[i].mat;
		students[i].average = (double)students[i].sum/3;
		students[i].rank = 1 ;
	} 
	
		for(int k = 0 ; k < 10 ; ++k){
			for(int i = 0 ; i < 10 ; ++i){
				if(students[i].sum < students[k].sum){
					students[i].rank += 1;	
				}
			}	
		}	
		//sorting 
	Student *table[10];
	for (int i = 0 ; i < 10 ; ++ i)
		table[i] = &students[i];
	
	 for (int i = 0 ; i < 9 ; ++i){
		 	for(int j = i+1 ; j < 10 ;++j){
				if(table[i]->sum < table[j]->sum){
					Student *tem = table[i];
					table[i] = table[j];
					table[j] = tem;
				}
			}
	}

	/* for (int i = 0 ; i < 9 ; ++i){
		 	for(int j = i+1 ; j < 10 ;++j){
				if(students[i].sum < students[j].sum){
					Student tem = students[i];
					students[i] = students[j];
					students[j] = tem;
				}
			}
} */		


	for (int i = 0 ; i < 10; ++i){
		fprintf(fout, "%15s %3d %3d %3d %3d %6.2f %2d\n",
			students[i].name, students[i].kor, students[i].eng,
			students[i].mat,students[i].sum, students[i].average, students[i].rank);
	}
	
	for (int i = 0 ; i < 10; ++i){
		fprintf(fout, "\n\n%15s %3d %3d %3d %3d %6.2f %2d\n",
			table[i]->name, table[i]->kor, table[i]->eng,
			table[i]->mat, table[i]->sum, table[i]->average, table[i]->rank);
	}
	
	fclose(fin);
	fclose(fout);
	
	return 0;
}
