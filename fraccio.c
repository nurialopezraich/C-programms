#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char signe;
	int numer, denom;
}fraccio;

int mcd(int, int);
int mcm(int,int);
void reduir(fraccio *);
void sumar(fraccio, fraccio, fraccio *);
/*void restar(fraccio, fraccio, fraccio *);
fraccio multiplicar(fraccio,fraccio);
int dividir(fraccio, fraccio, fraccio *);*/

int main(void){
	fraccio a, b, *sum=NULL;
	
	printf("Introdueix dues fraccions i el seu signe\n");
	scanf("%c %d %d %c %d %d", &a.signe, &a.numer, &a.denom, &b.signe, &b.numer, &b.denom);
	
	reduir(&a);
	reduir(&b);
	printf("%d %d\n", a.numer, a.denom);
	printf("%d %d\n", b.numer, b.denom);
	
	sumar(a,b,sum);
	printf("%d %d\n", sum->numer, sum->denom);
	return 0;
}

int mcd (int a, int b){
	/*algoritme d'Euclides*/
	int  r;
	
	r=a%b;
	while(r!=0){
		a=b;
		b=r;
		r=a%b;
	}
	
	return b;		
}

int mcm(int a, int b){
	int m;
	if(a%b==0){
		m=a;
	}else if(b%a==0){
		m=b;
	}else{
		m=a*b;
	}		
	return m;
} 

void reduir(fraccio *a){
	int m;
	m=mcd(a->numer,a->denom);
	a->numer=a->numer/m;
	a->denom=a->denom/m;
}
	
void sumar(fraccio a, fraccio b, fraccio *sum){
	int m;
	if(a.denom==b.denom){
		sum->numer=a.numer+b.numer;
		sum->denom=a.denom;
	}else{
		m=mcm(a.denom, b.denom);
		sum->numer=a.numer*(m/a.denom)+b.numer*(m/b.denom);
		sum->denom=m;
	}	
	return ;
}
