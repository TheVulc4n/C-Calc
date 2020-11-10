#include <stdio.h>
#include <stdlib.h>
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
		if(c <= 0 || c > 9){
			break;
		}
		//acc *= 10;
		acc += c;	
	}
	if(neg){
		return -acc;
	}else{
		return acc;
	}
}

int maxp(int arr_size, int *arr){
	if(!arr || arr_size <= 0){
		return 0;
	}
	int biggest_number = arr[0];
	for(int i = 1; i < arr_size; i++){
		if(arr[i] > biggest_number){
			biggest_number = arr[i];
		}
	}
	return biggest_number;
}
/*
int copy_larger(int arr_size, int *arr1, int *arr2){
	int copiedArr[arr_size] = {}; 
	for(int i = 0; i < arr_size; i++){
		if(arr1[i] > arr2[i]){
			copiedArr[i] = arr1[i];
		}else{
			copiedArr[i] = arr2[i];
		}
	}
	return copiedArr;
}
*/

int* copy_larger(int arr_size, int *arr1, int *arr2){			
	int *arr_out = malloc(sizeof(int)*arr_size);		
	if(!arr_out){		
		return NULL;
	}
	for(int i = 0; i < arr_size; i++){
		if(arr1[i] > arr2[i]){	
			arr_out[i] = arr1[i];
		}else{	
			arr_out[i] = arr2[i];
		}	
	}		
	return arr_out;		
}

void main() {
	int arr1[5] = {1,2,3,4,5};
	int arr2[5] = {1,2,7,-7,5};
	int *result = copy_larger(5,arr1,arr2);
	for(int i = 0; i < 5; i++){
		printf("Number %d is: %d\n", i+1, result[i]);
	}
	free(result);
}