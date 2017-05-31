#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "codificacion.h"
#include "cifrado.h"

void imprimirS();
void imprimirC(char *argumentos[]);
void imprimirArreglo(char *mensaje[]);
int esNumero(char num[]);
void minusculaAMayuscula(char string[]);

int main(int arg, char *argv[]){


	switch(arg){

		case 1:
			imprimirS();
			break;

		case 3:
			imprimirC(argv);
			break;

		default:
			printf("--");
	}

	return 0;

}

void imprimirS(){

        char mensaje[1000], llaveNumerica[1000];

        printf("\n\n***********************************************************************************************\n\n");
        printf("\tCifrado ciclico\n");
        printf("\tIngrese mensaje a cifrar     : ");
        scanf("%[^\n]",mensaje);
        printf("\tIngrese la llave numerica    : ");
        scanf("%s",llaveNumerica);

	if(esNumero(llaveNumerica)){
                cifradoCiclico(mensaje,atoi(llaveNumerica));
                printf("\tMensaje cifrado              : %s",mensaje);
//		claveMorse(mensaje);
//                printf("\n\tMensaje cifrado en morse     : %s",mensaje);
	        printf("\n\tMensaje cifrado en morse     : ");
		claveMorse(mensaje);
        }else{
                printf("\n\tERROR, INGRESE UNA LLAVE NUMERICA VÁLIDA");
        }

        printf("\n\n***********************************************************************************************\n\n");
}

void imprimirC(char *argumentos[]){

	printf("\n\n***********************************************************************************************\n\n");
        printf("\tCifrado ciclico\n");
	printf("\tIngrese mensjae a cifrar     : %s\n",argumentos[2]);
        printf("\tIngrese la llave numerica    : %s\n",argumentos[1]);

        if(esNumero(argumentos[1])){
        	cifradoCiclico(argumentos[2],atoi(argumentos[1]));
                printf("\tMensaje cifrado              : %s",argumentos[2]);
                //claveMorse(argumentos[2]);
                //printf("\n\tMensaje cifrado en morse    : %s",argumentos[2]);
	        printf("\n\tMensaje cifrado en morse     : ");
		claveMorse(argumentos[2]);
       	}else{
                printf("\n\tERROR, INGRESE UNA LLAME NUMERICA VÁLIDA");
        }
        printf("\n\n***********************************************************************************************\n\n");

}

int esNumero(char num[]){

        int i;

        for(i=0;num[i]!='\0';i++){
                if(!((num[i]>=48 && num[i]<=57) || num[i]==45 || num[i]==43)){
                        return 0;
                }
        }
        return 1;
}


