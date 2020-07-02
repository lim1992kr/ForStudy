#include<stdio.h>

int main (void) 
{
	int po[10][2] = {0};
	int str[10] = {0};
	int spa[10] = {0};
	int sum = 0;
	
	
	for(int i=1; i<10; ){
	
	printf("i-1 point : ");
	scanf("%d",po[i][1]);
		sum += po[i][1]      //i-1 sum
		
		while(1){
			if (po[i][1] >= 0 || po[i][1] < 9)	 { // i-1 !=stike
				printf("i-2 point : " );
				scanf("%d",po[i][2]);					//i-2 score
				 			 
					if(po[i][1]+po[i][2]<10){  					//i-2 != spare
						sum += po[i][2];						
						printf("i frame score = %d",sum);
						
					}
					
					else if(po[i][1]+po[i][2]==10)){ 				//i-2 ==spare
						sum += po[i][2];								
						if(po[i+1][1]==10){							//(i+1)-1 == strike
						
						}
						else if(po[i+1][1] >= 0 || po[i+1][1] < 9){			//(i+1)-1 != strike
							if (po[i+1][1]+po[i+1][2]<10){					//(i+1)-2 != spare
							
							}
							else if(?){				//(i+1)-2 != spare
							
							}
							
						}
					}
				
				 
			}
			else if (po[i][1] == 10){ // i-1 ==strike
				if (?)	{					//(i+1) ==st
					if (?){				//(i+2) ==st
					
					}
					else if(?){				//(i+2) !=st
				
					
					}
				}	
					
				else if (?){      			//(i+1) !=st
				
				}
				 
			}
		}	
	}
	return 0;	
}

