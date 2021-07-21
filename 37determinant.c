/*37: Determinant per regla de Laplace i per eliminacio gaussiana*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
double determinant(int, double **);
void determinant2(int, double **);

int main(void){
	double **a, det;
	int n, i, j;
	clock_t ti1, tf1, ti2, tf2;
	
	printf("Introdueix la dimensio del determinant\n");
	scanf("%d", &n);
	
	a=(double **)malloc(n*sizeof(double *));
	if(a==NULL){
		printf("Error de memoria\n");
		exit(1);
	}
	for(i=0; i<n; i++){
		a[i]=(double *)malloc(n*sizeof(double));
		if(a[i]==NULL){
			printf("Error de memoria\n");
			exit(2);
		}
	}
	
	printf("Introdueix els coeficients\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%le", &a[i][j]);
		}
	}
	
	ti1=clock();
	det=determinant(n,a);
	tf1=clock();
	printf("El determinant amb recursivitat es: %le\n", det);
	printf("Ha tardat %le segons\n", ((double)tf1-ti1)/CLOCKS_PER_SEC);
	
	det=1;
	ti2=clock();
	determinant2(n,a);
	for(i=0; i<n; i++){
		det*=a[i][i];
	}
	tf2=clock();
	printf("El determinant sense recursivitat es: %le\n", det);
	printf("Ha tardat %le segons\n", ((double)tf2-ti2)/CLOCKS_PER_SEC);
	return 0;
}

double determinant(int n, double **a){
	double det, **nova;
	int i, j, k, signe;
	
	if(n==2){
		return a[0][0]*a[1][1]-a[0][1]*a[1][0];
	}
	
	nova=(double **)calloc(n-1, sizeof(double *));
	if(nova==NULL){
		printf("Error de memoria\n");
		exit(1);
	}
	for(i=0; i<n-1; i++){
			nova[i]=(double*)calloc(n-1,sizeof(double));
			if(nova[i]==NULL){
				printf("Error de memòria\n");
				exit(2);
			}
	}
	
	det=0;
	signe=1;
	
	for(i=0; i<n; i++){
		for(k=1; k<n; k++){
			for(j=0; j<i; j++){
				nova[j][k-1]=a[j][k];
			}
			for(j=i+1; j<n; j++){
				nova[j-1][k-1]=a[j][k];
			}
		}
		
	det+=signe*a[i][0]*determinant(n-1, nova);
	signe=-signe;
	}
	for(i=0; i<n-1; i++){
		free(nova[i]);
	}
	free(nova);
	return det;		
}

void determinant2(int n, double **a){
	double m;
	int i, j, k;

	for(k=0; k<n-1; k++){
		for(i=k+1; i<n; i++){ 
			if(fabs(a[k][k])<10e-8){
				exit(1);
			}
			m=a[i][k]/a[k][k];
			for(j=0;j<n+1;j++){
				a[i][j]=a[i][j]-(m*a[k][j]);
			}
		 }
	 }
    return ;
}
