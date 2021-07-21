/*14: Feu un programa que llegeixi un enter n pel teclat, i que escrigui els coeficients binomials entre grau 0 i n. 
Per fer-ho, aneu calculant les files del triangle de Pascal i escrivint-les.*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n, i, j, *v, fil=0, actual=0;
	printf("Introdeix un nombre enter\n");
	scanf("%d", &n);
	v=(int *)malloc((n+1)*(n+2)/2*sizeof(int));
	if(v==NULL){
		exit(1);
	}
	
	for(i=0; i<=n; i=j){           
		for(j=0; j<=i; j++){     
			if(j==0 || j==fil){
				v[actual]=1;
				printf("%d ", v[actual]);
				actual++;
			}else{
				v[actual]=v[actual-i]+v[actual-i-1];
				printf("%d ", v[actual]);
				actual++;
			}
		}
		printf("\n");
		fil=j;
	}
	free(v);
	return 0;
}
