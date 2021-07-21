#include <stdio.h>
#include <stdlib.h>
/*31: Gestiona les butaques de la sala d’un cinema.*/
typedef struct{
	int files, columnes;
	int **ocupada;
}cinema;

void ocuparButaca(cinema);
void lliurarTotesButaques(cinema);
void escriureLliures(cinema);

int main(void){
	cinema cine;
	int i, opcio;
	
	printf("Introdueix quantes files i butaques per fila te el cinema:\n");
	scanf("%d %d", &cine.files, &cine.columnes);
	cine.ocupada=(int **)calloc(cine.files,sizeof(int *));
	if(cine.ocupada==NULL){
		printf("Error de memoria\n");
		exit(1);
	}
	for(i=0; i<cine.files; i++){
		cine.ocupada[i]=(int *)calloc(cine.columnes,sizeof(int));
		if(cine.ocupada[i]==NULL){
		printf("Error de memoria\n");
		exit(2);
		}
	}
	
	do{
		printf("Escull una opcio:\n");
		printf("1: Ocupar butaca\n2: Lliurar totes les butaques\n3: Escriure lliures\n4: Sortir\n");
		scanf("%d", &opcio);
		switch (opcio){
			case 1: 
			ocuparButaca(cine);
			break;
			case 2:
			lliurarTotesButaques(cine);
			break;
			case 3: 
			escriureLliures(cine);
			break;
			case 4:
			printf("Gràcies per utilitzar els nostres serveis, fins una altra!");
		}
	}while(opcio!=4);
	
	return 0;
}
/*Es demanarà fila i butaca i la posarà com a ocupada. Si ja estava ocupada, donarà el missatge a l’usuari.*/
void ocuparButaca(cinema cine){
	int fila,butaca;
	printf("Introdueix la fila i la butaca que vols ocupar\n");
	scanf("%d %d", &fila, &butaca);
	
	if(fila<0 || butaca <0 || fila>=cine.files || butaca>=cine.columnes){
		printf("Aquesta butaca no existeix\n");
		exit(1);
	}
	if(cine.ocupada[fila][butaca]==0){
		cine.ocupada[fila][butaca]=1;
		printf("Has ocupat la butaca: %d %d\n", fila, butaca);
	}else{
		printf("La butaca %d de la fila %d ja esta ocupada\n", fila,butaca);
	}
	return ;
}

/*es posaran totes les butaques com a lliures.*/
void lliurarTotesButaques(cinema cine){
	int i, j;
	for(i=0; i<cine.files; i++){
		for(j=0; j<cine.columnes; j++){
			cine.ocupada[i][j]=0;
		}
	}	
	return ;
}

/*escriurà quines butaques estan lliures.*/
void escriureLliures(cinema cine){
	int i, j;
	printf("Les següents butaques estan lliures:\n");
	for(i=0; i<cine.files; i++){
		for(j=0; j<cine.columnes; j++){
			if(cine.ocupada[i][j]==0){
				printf("Butaca: %d %d\n", i, j);
			}
		}
	}	
	return ;
}
