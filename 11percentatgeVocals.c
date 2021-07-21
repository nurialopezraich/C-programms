/*11 Escriviu una funció main que llegeixi una frase d’un màxim de 100 caràcters i escrigui el percentatge de vocals que hi ha a la frase.*/

#include <stdio.h>
#include <stdlib.h>

int esVocal(char);
double percentatge(char *);

int main(void){
	char frase[100];
	double perc;
	char *cadena;
	
	printf("Introdueix una frase\n");
	scanf(" %[^\n]", frase);
	cadena=frase;
	
	perc=percentatge(cadena);
	printf("El percentatge de vocals que hi ha a la cadena és %lf%%", perc);
	return 0;
}

int esVocal(char a){
	int i;
	char vocal[10] = "aeiouAEIOU";
	for(i=0; i<10; i++){
		if(vocal[i]==a){
			return 1;
		}
	}
	return 0;
}

double percentatge(char *cadena){
	double perc=0;
	int compt=0, i;
	for(i=0; cadena[i]!='\0'; i++){
		if(esVocal(cadena[i])==1){
			perc++;
		}
		compt++;
	}	
	perc=(perc/compt)*100;
	return perc;
}	
