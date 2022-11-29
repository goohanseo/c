#include <stdio.h>

int main(){
    printf("0 &LAB	TEST	&ARG1	&ARG2	&ARG3");	
printf("1 #i    A	1	#I");	
printf("2 #i    A	2	#I);	
printf(3 #i    A	3	#I);	
printf(4 #i	MEND);	
printf(-------------------MACEO NAME TABLE-----------------------);	
printf(0	TEST	0);	
printf(-------------------Pass1 Argument List array--------------);	
printf(0	&LAB);	
printf(1	&ARG1);	
printf(2	&ARG2);	
printf(3	&ARG3);	
printf();	
printf(-------------------pass1 buffer---------------------------);	
printf(LOOP1	TEST	DATA1	DATA2	DATA3);	
printf(LOOP2	TEST	DATA3	DATA2	DATA1);	
printf(DATA1	DC	F'5');	
printf(DATA2	DC	F'10');	
printf(DATA3	DC	F'15');	
printf(	END);	
printf(-------------------Pass2 Argument List array--------------);	
printf(0	LOOP2);	
printf(1	DATA3);	
printf(2	DATA2);	
printf(3	DATA1);	
printf(-------------------pass2 buffer---------------------------);	
printf(LOOP1	A	1	DATA1);	
printf(	A	2	DATA2);	
printf(	A	3	DATA3);	
printf(LOOP2	A	1	DATA3);	
printf(	A	2	DATA2);	
printf(	A	3	DATA1);	
printf(DATA1	DC	F'5');	
printf(DATA2	DC	F'10');	
printf(DATA3	DC	F'15');	
printf("	END");
    return 0;
}