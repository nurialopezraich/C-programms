/*10: Llegeix tres nombres reals i els ordena de major a menor.*/

#include <stdio.h>
#include <stdlib.h>

void ordena3(double *, double *, double *);
void intercanvi(double *, double *);

int main(void){
    double *px, *py, *pz;
    double x, y, z;

    printf("Introdueix 3 nombres\n");
    scanf("%le %le %le", &x,&y,&z);
    px=&x;
    py=&y;
    pz=&z;
    ordena3(px,py,pz);
    printf("%le %le %le",*px,*py,*pz);
    return 0;
}

void ordena3(double *x, double *y, double *z){
    if(*x<*y){
        intercanvi(x,y);
    }
    if(*x<*z){
        intercanvi(x,z);
    }
    if(*y<*z){
        intercanvi(y,z);
    }
    return ;
}

void intercanvi(double *x, double *y){
    double aux;
    if(*x<*y){
        aux=*x;
        *x=*y;
        *y=aux;
    }
    return ;
}
