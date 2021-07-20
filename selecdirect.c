#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int j, k, n, min;
	double *v, aux;
	
	printf("Introdueix quants elements vols ordenar:\n");
	scanf("%d", &n);
	v=(double *)malloc(n*sizeof(double));
    if(v==NULL){
      printf("Error de memoria\n");
      exit(1);
    }
	printf("Introdueix els elements a ordenar:\n");
	for(j=0; j<n; j++){
		scanf("%le", &v[j]);
	}
	
	
	for(j=0; j<n-1; j++){
		min=j;
		for(k=j+1; k<n; k++){
			if(v[min]>v[k]){
				min=k;
			}
		}
		aux=v[j];
		v[j]=v[min];
		v[min]=aux;
	}
	
	for(j=0; j<n; j++){
		printf("%le ", v[j]);
	}
	free(v);
	
	return 0;
}
