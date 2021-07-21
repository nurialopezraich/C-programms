/*15: Es tracta de comprovar si una frase és un palı́ndrom. Suposem que la frase està en minúscules i sense accents.*/
#include <stdio.h>
#include <stdlib.h>

void invertir(char *);
int main(void){
	
	char *frase, invertit[100];
	int i, pal, compt;
	
	frase=(char*)malloc(sizeof(char));
	if(frase==NULL){
		exit(1);
	}
	printf("Introdueix una frase en minúscules i sense accents\n");
	scanf(" %[^\n]", frase);
	
	for(i=0; frase[i]!='\0'; i++){
		invertit[i]=frase[i];
	}

	invertir(frase);
	printf("%s",frase);
	
	for(i=0; frase[i]!='\0'; i++){
		if(frase[i]==invertit[i]){
			pal++;
		}
		compt++;
	}
	if(compt==pal){
		printf("\nÉs un palíndrom\n");
	}else{
		printf("\nNo és un palíndrom\n");
	}
	free(frase);
	return 0;
}

void invertir(char *cadena){
	int i, compt=0;
	char aux;
	for(i=0; cadena[i]!='\0'; i++){
		compt++;
	}
	for(i=0; i<compt/2; i++){
		aux=cadena[i];
		cadena[i]=cadena[compt-i-1];
		cadena[compt-i-1]=aux;
	}
	return ;
}
