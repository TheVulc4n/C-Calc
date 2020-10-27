#include <stdio.h>
/*
To compile and run:
open up mingw and get to current directory
then do gcc C-Calc.c
then open up command prompt and get to current directory
do .\a.exe
*/
int readnumber(){
	int neg = 0;
	int acc = 0;
	int c = getchar();
	if(c == '-'){
		neg = 1;
	}else if(c >= '0' && c <= '9'){
		acc = c - '0';
	}else{
		return 0;
	}
	while(1){
		c = getchar()-'0';
		if(c < 0 || c > 9){
			break;
		}
		acc *= 10;
		acc += c;	
	}
	if(neg){
		return -acc;
	}else{
		return acc;
	}
}

void main() {
	printf("My number is: %d\n", readnumber());
}