/*9: La funció main anirà llegint parelles de valors enters, i escriurà els valors llegits i els valors del quocient i
del residu. El programa s’acabarà quan es llegeixi com a divisor un 0*/
#include <stdio.h>
#include <stdlib.h>

void dividir(int *, int *);

int main(void){
	int *dividend, *divisor;
	int divi, dis;
	printf("Introdueix dividend i divisor\n");
	scanf("%d %d", &divi, &dis);
	while(dis!=0){
		dividend=&divi;
		divisor=&dis;
		dividir(dividend,divisor);
		printf("Introdueix dividend i divisor\n");
		scanf("%d %d", &divi, &dis);
	}
	return 0;
}

void dividir(int *dividend, int *divisor){
	int quocient, residu;
	quocient=*dividend/(*divisor);
	residu=*dividend%(*divisor);	
	printf("Dividend: %d\nDivisor: %2d\nQuocient: %d\nResidu: %3d\n\n", *dividend, *divisor, quocient, residu);
	return ;
}
