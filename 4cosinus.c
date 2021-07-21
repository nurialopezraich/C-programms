/*4cosinus: funció taylor que retorna el valor del polinomi de Taylor de grau 8 de la funció cos en un punt donat. Funció main calcula l’error comès en l’interval
[−1.5, 1.5], prenent els punts en una xarxa equiespaiada en l’interval, en precisió simple i doble. Feu una gràfica de l’error en funció del valor de x.*/

#include <stdio.h>
#include <math.h>

double taylor(double);
double factorial(int);
double pot(double, int);

int main(void) {
	double x, res;
	printf("Introdueix el punt a avaluar\n");
	scanf("%le", &x);

	res=taylor(x);
	printf("%le\n", res);

	return 0;
}

double taylor(double x){
	int k, s=1;
	double sum=1;
	for(k=1; k<5; k++){
        s=-s;
		sum+=s*(pot(x,2*k))/factorial(2*k);
	}
	return sum;
}

double factorial(int n){
	int i;
	double fact=n;
	for(i=n-1; i>0; i--){
		fact*=i;
	}
	return fact;
}

double pot(double x, int n){
    double pot=1;
    int i;
    for(i=0; i<n; i++){
        pot *=x;
    }
    return pot;
}
