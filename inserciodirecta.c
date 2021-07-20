#include <stdio.h>
#include <stdlib.h>

void insercio(int, double *);

int main(void){
	int n, i;
	double *v;
	
	printf("Introdueix la llargada del vector\n");
	scanf("%d", &n);
	
	v=(double *)malloc(n*sizeof(double));
	if(v==NULL){
		printf("Error de memoria\n");
		exit(1);
	}
	
	printf("Introdueix la llista de nombres\n");
	for(i=0; i<n; i++){
		scanf("%le", &v[i]);
	}
	
	insercio(n,v);
	
	for(i=0; i<n; i++){
		printf("%le ", v[i]);
	}
	
	return 0;
}

void insercio(int n, double *v){
	int j, k;
	double aux;
	
	for(j=1; j<n; j++){ 
		aux=v[j];
		k=j-1;
		while(k>=0 && aux<v[k]){
			v[k+1]=v[k];
			k--;
		}
		v[k+1]=aux;
	}
	return ;
}
