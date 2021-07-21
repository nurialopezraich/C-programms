/*1: Feu un programa que llegeixi un natural n > 1 i calculi i escrigui ordenadament totes les fraccions p/q tals
que 2 ≤ q ≤ n, 1 ≤ p < q, mcd(p, q) = 1. També ha de dir quantes n’hi ha.*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 100
int mcd(int, int);
void escriure(int, int [][2]);
void inserir(int *, int, int, int [][2]);

int main(void){
	int q, p, n, mat[DIM][2]; 
	printf("Introdueix n\n");
	scanf("%d", &n);
	int *compt=malloc(sizeof*compt);
	*compt=1;
	mat[0][0]=1;
	mat[0][1]=2;
	
	for(q=3; q<=n; q++){
		for(p=1; p<q; p++){
			if(mcd(p,q)==1){
				inserir(compt,p,q,mat);
			}
		}
		printf("q = %d ",q);
		printf("quantitat = %d\n",*compt);
		escriure(*compt,mat);
    }
	return 0;
}

int mcd(int a, int b){
	int res;
	res=a%b;
	while(res>0){
		a=b;
		b=res;
		res=a%b;
	}
	return b;
}

void escriure(int fil, int mat[][2]){
	int i;
	for(i=0; i<fil; i++){
		printf("%d/%d", mat[i][0], mat[i][1]);
		if(i<fil-1){
			printf(" < ");
		}
	}
	printf("\n");
	return ;
}

void inserir(int *fil, int p, int q, int mat[][2]){
	int i, j;
	i=0;
	while(((double) p/q)>(double)mat[i][0]/mat[i][1]){
		i++;
	}
	for(j=(*fil); j>i; j--){
		mat[j][0]=mat[j-1][0];
        mat[j][1]=mat[j-1][1];
    }
    mat[j][0]=p;
    mat[j][1]=q;
      
    *fil=*fil+1;         
	return ;
}
	
	
