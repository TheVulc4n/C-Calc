#include <stdio.h>
#include <stdlib.h>
/*
To compile and run:
open up mingw and get to current directory
then do gcc C-Calc.c
then open up command prompt and get to current directory
do .\a.exe
*/

typedef struct{
  char* str;
  int cap;
} str_t;

void print_str(str_t s){
	for(int i = 0; s.str[i] !='\0'; i++){
		printf("%c",s.str[i]);
	}
}

str_t new_str(int size){
  str_t s;
  if(size <= 0){
	  size = 1;
  }
  s.cap = size;
  s.str = malloc(sizeof(char) * size);
  s.str[0] = '\0';
  return s;
}

void add_char(str_t* s, char c){
	int i;
	for(i = 0; i < s->cap && s->str[i] != '\0'; i++);
	if(i >= s->cap){
		//this string is broken. No null character in end.
		fprintf(stderr, "string broken. Crashing to avoid any further problems.");
		exit(-1);
	}else if(i + 1 >= s->cap){
		//string needs to be expanded
		char* p = malloc(sizeof(char) * s->cap * 2);
		for(int j = 0; j < i; j++){
			p[j] = s->str[j];
		}
		free(s->str);
		s->str = p;
		
		s->cap *= 2;
	}
	s->str[i] = c;
	s->str[i+1] = '\0';
}

char remove_char(str_t* s){
	int i;
	for(i = 0; i < s->cap && s->str[i] != '\0'; i++);
	if(i >= s->cap){
		//this string is broken. No null character in end.
		fprintf(stderr, "string broken. Crashing to avoid any further problems.");
		exit(-1);
	}else if(i == 0){
		return '\0';
	}else if(i <= s->cap/3 && s->cap >= 8){
		//string needs to be shrunk to save memory
		char* p = malloc(sizeof(char) * s->cap / 2);
		for(int j = 0; j < i; j++){
			p[j] = s->str[j];
		}
		free(s->str);
		s->str = p;
		
		s->cap /= 2;
	}
	char c = s->str[i-1];
	s->str[i-1] = '\0';
	return c;
}

int remove_specific_char(str_t* s, char c, int startpos){
	/*
	1. Find first instance of char c
	
	2. replace char c with ''
	
	3. replace this spot with the next spot and so on
	
	4. if char c not in string, return string as it is
	
	5. if no null found, crash and return -1
	*/
	
	int i = startpos;
	
	while(i < s->cap && s->str[i] != c && s->str[i] != '\0'){
		i++;
	}
	if(i >= s->cap){
		exit(-1);
	}else if(s->str[i] == c){
		for(int j = i; (j+1) < s->cap && s->str[j] != '\0'; j++){
			s->str[j] = s->str[j+1];
		}
		return i;
	}else{
		return -1;
	}
}

int remove_all(str_t *s, char c){
	int total = -1;
	int pos = 0;
	while(pos >= 0){
		pos = remove_specific_char(s, c, pos);
		total++;
	}
	return total;
}

str_t concatinate_string(str_t lhs, str_t rhs){
	int i;
	for(i = 0; i < lhs.cap && lhs.str[i] != '\0'; i++);
	int new_cap = i;
	for(i = 0; i < rhs.cap && rhs.str[i] != '\0'; i++);
	new_cap += i+1;
	str_t string = new_str(new_cap);
	for(int i = 0; i < lhs.cap && lhs.str[i] != '\0'; i++){
		add_char(&string, lhs.str[i]);
	}for(int i = 0; i < rhs.cap && rhs.str[i] != '\0'; i++){
		add_char(&string, rhs.str[i]);
	}
	return string;
}
/*
15,10,6,3,1,0,0,1,3,6,10,15
a[0] = 0
a[n] = a[n-1] + n
*/
int pattern_solver_1(int n){
	if(n == 0){
		return 0;
	}else if(n < 0){
		return pattern_solver_1(~n);
	}else{
		return pattern_solver_1(n-1)+n;
	}
}


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
*/
void print_pair_wise(int arr_size, int *arr1, char *arr2, float *arr3){
	for(int i = 0; i < arr_size; i++){
		printf("%d, %c, %f, %f\n", arr1[i],arr2[i],arr3[i*2],arr3[i*2+1]);
	}
}

void main() {
	/*
	int arr1[5] = {1,2,3,4,5};
	int arr2[5] = {1,2,7,-7,5};
	int *result = copy_larger(5,arr1,arr2);
	for(int i = 0; i < 5; i++){
		printf("Number %d is: %d\n", i+1, result[i]);
	}
	free(result);
	int arr1[] = {1,2,3};
	char arr2[] = {'a','b','c'};
	float arr3[] = {1.2,2.3,3.4,4.5,5.6,6.7};
	print_pair_wise(3,arr1,arr2,arr3);
	*/
	str_t string = new_str(6);
	
	add_char(&string, 'a');
	add_char(&string, 'b');
	add_char(&string, 'c');
	add_char(&string, 'b');
	add_char(&string, 'e');
	add_char(&string, 'f');
	printf("I removed %d characters\n",remove_all(&string, 'q'));
	print_str(string);
}








