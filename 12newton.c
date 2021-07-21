/*12: calcular un zero d’una funció derivable usant el mètode de Newton*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int newton (double, double, int, double *);
double fun(double);
double dfun(double);

int main(void){
	double x0, tol, sol;
	int maxIter, valor;
	
	do{
        printf("Introdueix la tolerància\n");
        scanf("%le", &tol);
        
    }while(tol<0 || tol>1);
	printf("Introdueix el valor inicial:\n");
	scanf("%le", &x0);
	printf("Introdueix el nombre d'iteracions maximes:\n");
	scanf("%d", &maxIter);
	
	valor=newton(x0,tol,maxIter,&sol);
	switch(valor){
		case 0:
		printf("Hi ha hagut convergència. L'arrel és: %le\n", sol);
		break;
		case 1:
		printf("S'ha arribat al nombre màxim d’iteracions maxIter sense tenir convergència\n");
		break;
		case 2:
		printf("En algun moment del procés la derivada s’anul·la");
		break;
	}		
	return 0;
}

int newton (double x0 , double tol , int maxIter , double * sol ){
	double xn, dif;
	int n=0;
	
	do{
		xn=x0-(fun(x0)/dfun(x0));
		dif=fabs(xn-x0);
		x0=xn;
		n++;
	}while(n<=maxIter && (dif>tol && fabs(dfun(xn)>tol)));
	*sol=xn;
	if(n>maxIter){
		return 1;
	}else if(fabs(dfun(x0))<=tol){
			return 2;
		}
	return 0;
}

double fun(double x){
	double fun;
	fun=x-cos(x);
	return fun;
}

double dfun(double x){
	double dfun;
	dfun=1+sin(x);
	return dfun;
}
