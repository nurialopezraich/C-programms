/*2: Escriviu un programa en C que llegeixi n (amb 1 ≤ n ≤ 50), i escrigui els valors de x i , f 1 (x i ) i f 2 (x i ),
i = 0, . . . , n, en els n + 1 punts equiespaiats de l’interval [−π, π], en forma de taula, perfectament encolumnada,
amb format exponencial amb 12 dı́gits després del punt.*/

#include <stdio.h>
#include <math.h>
double f1(double);
double f2(double);
int main(void){
	int n, i;
	double pi, xi, h, res1, res2 ;
	
	do{
    printf("Introdueix el valor de n:\n");
    scanf("%d", &n);
    }while(n<0 || n>50);
    
	pi=4*atan(1.);
	h=(2*pi)/n;
	
	printf("taula.c\n");
    printf("n = %d\n", n);
    printf("\tx \t\t\tf1(x)\t \t\tf2(x)\t \n");
    
	for(i=0; i<=n; i++){
		xi=-1*pi+i*h;
		res1=f1(xi);
		res2=f2(xi);
		printf("%20.12le\t %20.12le\t %20.12le\t \n", xi, res1, res2); 
	}	
	return 0;
}

double f1(double x) {
    double resultat;
    resultat=sin(2*x)-2*sin(x);
    return resultat;
}

double f2(double x){
    double resultat;
    resultat=exp(2*cos(x));
    return resultat;
}
