#include <stdio.h>
#include <stdlib.h>

void quicksort(double *,int,int);
void ordenar(double *,int);
int main(void){
	int n, i;
	double *v;
	char nom[30];
	FILE *ent, *sor;
	
	printf("Introdueix el fitxer d'entrada\n");
	scanf(" %s", nom);
	ent=fopen(nom,"r");
	if(ent==NULL){
		printf("Error de memoria\n");
		exit(1);
	}
	printf("Introdueix maxim elements a ordenar\n");
	scanf("%d", &n);
	v=(double *)malloc(n*sizeof(double));
	for(i=0; i<n; i++){
		fscanf(ent,"%le", &v[i]);
	}
	fclose(ent);
	printf("Introdueix el fitxer de sortida\n");
	scanf(" %s", nom);
	sor=fopen(nom,"w");
	if(sor==NULL){
		printf("Error de memoria\n");
		exit(1);
	}
		
	ordenar(v,n);
	for(i=0; i<n; i++){
		fprintf(sor,"%le\n", v[i]);
	}
	fclose(sor);
	free(v);
	
	return 0;
}

void quicksort(double *v,int esq,int dret){
	int i, canvi;
	double aux;
	if(esq<dret){
		i=(esq+dret)/2;
		aux=v[i];
		v[i]=v[esq];
		v[esq]=aux;
		canvi=esq;
		for(i=esq+1; i<=dret; i++){
			if(v[i]<v[esq]){
				canvi++;
				if(i!=canvi){
					aux=v[i];
					v[i]=v[esq];
					v[esq]=aux;
				}
			}
		}
		aux=v[esq];
		v[esq]=v[canvi];
		v[canvi]=aux;
		quicksort(v,esq,canvi-1);
		quicksort(v,canvi+1,dret);
	}
		return ;
}

void ordenar(double *v, int n){
	int i, ipos=0, ineg=0;
	double *pos, *neg;
	pos=(double *)malloc(n*sizeof(double));
	if(pos==NULL){
		exit(1);
	}
	neg=(double *)malloc(n*sizeof(double));
	if(neg==NULL){
		exit(1);
	}
	for(i=0; i<n; i++){
		if(v[i]<0){
		neg[ineg]=v[i];
		ineg++;
		}else if(v[i]>0){
			pos[ipos]=v[i];
			ipos++;
		}
	}
	quicksort(pos,0,ipos-1);
	quicksort(neg,0,ineg-1);
	ineg=0;
	ipos=0;
	for(i=0; i<n; i++){
		if(v[i]<0){
			v[i]=neg[ineg];
			ineg++;
		}
		if(v[i]<0){
			v[i]=pos[ipos];
			ipos++;
		}
	}	
	
	return ;
}
