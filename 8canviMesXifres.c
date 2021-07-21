/*8: Anem llegint nombres enters xifres i els escriu canviant les xifres d’ordre. */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void canviXifres(int *);

int main(void){
	int *pn;
	int n;
	printf("Introdueix un nombre enter\n");
	scanf("%d", &n);
	pn=&n;
	canviXifres(pn);
	
	return 0;
}

void canviXifres(int *a){
	while(*a>=10){
		printf("%d", *a%10);
		*a=*a/10;
	}
	printf("%d", *a);
	return ;
}
