#include <stdio.h>

int absdif(int lhs, int rhs){
	if(lhs > rhs){
		return lhs-rhs;
	}else{
		return rhs-lhs;
	}
}

int max5(int arr[5]){
	int biggest_number = arr[0];
	for(int i = 1; i < 5; i++){
		if(arr[i] > biggest_number){
			biggest_number = arr[i];
		}
	}
	return biggest_number;
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
void main() {
	int arr[] = {};
	printf("My number is: %d\n", maxp(10, NULL));
}