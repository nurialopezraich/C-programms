/*7: Llegeix una dimensió n entre 2 i DIM (valor definit en una instrucció #define), una matriu quadrada A de dimensió n per files; i, usant les funcions anteriors, escrigui norma1 i una aproximació de α(A), calculant el maxim per a 10^6 vectors x diferent 0 de components aleatories.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define DIM 20
#define DIM2 100

double norma1(double[], int);
double norma1Mat(double[][DIM], int);
void prodMatVec(double[][DIM], double[], double[], int);

int main(void){
	int n, i, j, maxI;
	double a[DIM][DIM], normaA1, x[DIM2], w[DIM2], norma1x[DIM2], norma1w[DIM2], alfaA[DIM2], max;
    while(n<2 || n>DIM){
		printf("Introdueix la dimensio\n");
		scanf("%d", &n);
	}
	
	printf("Introdueix els coeficients de la matriu\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%le", &a[i][j]);
		}
	}
	
	normaA1=norma1Mat(a,n);
	
	srand((unsigned) time(NULL));
	max=0;
	for(i=0; i<10; i++){
		for(j=0; j<n; j++){
			x[j]=rand()%RAND_MAX+1;
		}
		norma1x[i]=norma1(x,n);
		prodMatVec(a,x,w,n);
		norma1w[i]=norma1(w,n);
		alfaA[i]=norma1w[i]/norma1x[i];
		if(alfaA[i]>max){
			max=alfaA[i];
			maxI=i;
		}
	}  
    printf("%+20.12le", normaA1);
    printf("%+20.12le", alfaA[maxI]);
    
    return 0;
}

double norma1(double v[], int n){
    int i;
    double norma=0;
    for(i=0; i<n; i++){
        norma+=fabs(v[i]);
    }
    return norma;
}

double norma1Mat(double A[][DIM], int n){
    double max=0, sum=0;
    int i,j;
    for(j=0; j<n; j++){
        for(i=0; i<n; i++){
            sum+=fabs(A[i][j]);
        }
        if(sum>max){
            max=sum;
        }
        sum=0;
    }
    return max;
}

void prodMatVec(double A[][DIM], double v[], double w[], int n){
    int i, j;
    for(i=0; i<n; i++){
        w[i]=0;
        for(j=0; j<n; j++){
            w[i]+=A[i][j]*v[j];
        }
    }    
    return ;
}
