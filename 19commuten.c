/*19: Fem el productes de matrius axb amb la funcio prodmat i el main comprova si commuten o no*/
#include <stdio.h>
#include <stdlib.h>
double ** prod_mat (int,int, double **, int, double **);

int main(void){
	int nFilA, nColA, nFilB, nColB, i, j;
	double **a, **b, **ab, **ba;
	
	printf("Introdueix les dimensions de la matriu a\n");
	scanf("%d %d", &nFilA, &nColA);
	
	a=(double **)malloc(nFilA*sizeof(double *));
	if(a==NULL){
		exit(1);
	}
	for(i=0; i<nFilA; i++){
		a[i]=(double *)malloc(nColA*sizeof(double));
		if(a[i]==NULL){
			exit(2);
		}
	}
	
	printf("Introdueix els coeficients de la matriu a\n");	
	for(i=0; i<nFilA; i++){
		for(j=0; j<nColA; j++){
			scanf("%le", &a[i][j]);
		}
	}
	
	printf("Introdueix les dimensions de la matriu b\n");
	scanf("%d %d", &nFilB, &nColB);
	
	b=(double **)malloc(nFilB*sizeof(double *));
	if(b==NULL){
		exit(1);
	}
	for(i=0; i<nFilB; i++){
		b[i]=(double *)malloc(nColB*sizeof(double));
		if(b[i]==NULL){
			exit(2);
		}
	}
	
	printf("Introdueix els coeficients de la matriu a\n");
	for(i=0; i<nFilB; i++){
		for(j=0; j<nColB; j++){
			scanf("%le", &b[i][j]);
		}
	}
	
	printf("Producte ab:\n");
	ab=prod_mat(nFilA,nColA,a,nColB,b);
	for(i=0; i<nFilA; i++){
		for(j=0; j<nColB; j++){
			printf("%le  ", ab[i][j]);
		}
		printf("\n");
	}
	
	printf("Producte ba:\n");
	ba=prod_mat(nFilB,nColB,b,nColA,a);
	for(i=0; i<nFilB; i++){
		for(j=0; j<nColA; j++){
			printf("%le  ", ba[i][j]);
		}
		printf("\n");
	}
	
	for(i=0; i<nFilA; i++){
		for(j=0; j<nColB; j++){
			if(ab[i][j]!=ba[i][j]){
				printf("No commuten\n");
				exit(1);
			}
		}
	}
	
	printf("Commuten\n");
	
	for(i=0; i<nFilA; i++){
		free(a[i]);
		free(ab[i]);
	}
	free(a);
	free(ab);
	
	for(i=0; i<nFilB; i++){
		free(b[i]);
		free(ba[i]);
	}
	free(b);
	free(ba);
	
	return 0;
}

double ** prod_mat (int nFilA , int nColA , double **a , int nColB , double ** b){
	int i, j, k;
	double **prod;
	
	prod=(double **)malloc(nFilA*sizeof(double *));
	if(prod==NULL){
		exit(1);
	}
	for(i=0; i<nFilA; i++){
		prod[i]=(double *)malloc(nColB*sizeof(double));
		if(prod[i]==NULL){
			exit(2);
		}
	}
	
	for(i=0; i<nFilA; i++){
		for(j=0; j<nColB; j++){
			prod[i][j]=0;
			for(k=0; k<nColA; k++){
				prod[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	return prod;
}
