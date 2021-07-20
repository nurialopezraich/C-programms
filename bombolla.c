#include <stdio.h>
#include <stdlib.h>

void bombolla(int, double *);

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
	
	bombolla(n,v);
	
	for(i=0; i<n; i++){
		printf("%le ", v[i]);
	}
	
	free(v);
	return 0;
}

void bombolla(int n, double *v){
	int j, k;
	double aux;
	
	for(j=1; j<n; j++){ 
		for(k=0; k<n-1; k++){
			if(v[k+1]<v[k]){
				aux=v[k];
				v[k]=v[k+1];
				v[k+1]=aux;
			}
		}
	}
	return ;
}
