#include <stdio.h>
#include <stdlib.h>
int factorial(int);
int main(void){
	int fact, n;
	printf("Introdueix n\n");
	scanf("%d", &n);
	fact=factorial(n);
	printf("%d! = %d\n",n,fact);
	return 0;
}
int factorial(int n){
	int fact;
	if(n==0){
		fact=1;
		return fact;
	}else{
		fact=n*factorial(n-1);
		return fact;
	}
}
