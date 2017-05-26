#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "varios.h"
#include "cifrado.h"
#include "morse.h"

void imprimirS(){

        char *mensajeMorse[1000], mensajeCifrar[1000], llaveNumerica[1000];

        printf("\n\n***********************************************************************************************\n\n");
        printf("\tCifrado ciclico\n");
        printf("\tIngrese mensaje a cifrar     : ");
        scanf("%[^\n]",mensajeCifrar);
        printf("\tIngrese la llave numerica    : ");
        scanf("%s",llaveNumerica);

	if(esNumero(llaveNumerica)){
                cifradoCiclico(mensajeCifrar,atoi(llaveNumerica));
                printf("\tMensaje cifrado              : %s",mensajeCifrar);
                mensajeAMorse(mensajeCifrar,mensajeMorse);
                printf("\n\tMensaje cifrado en morse    : ");
                imprimirArreglo(mensajeMorse);
        }else{
                printf("\n\tERROR, INGRESE UNA LLAVE NUMERICA VÁLIDA");
        }

        printf("\n\n***********************************************************************************************\n\n");
}

void imprimirC(char *argumentos[]){

	char *mensajeMorse[1000];

	printf("\n\n***********************************************************************************************\n\n");
        printf("\tCifrado ciclico\n");
	printf("\tIngrese mensjae a cifrar     : %s\n",argumentos[2]);
        printf("\tIngrese la llave numerica    : %s\n",argumentos[1]);

        if(esNumero(argumentos[1])){
        	cifradoCiclico(argumentos[2],atoi(argumentos[1]));
                printf("\tMensaje cifrado              : %s",argumentos[2]);
                mensajeAMorse(argumentos[2],mensajeMorse);
                printf("\n\tMensaje cifrado en morse    : ");
                imprimirArreglo(mensajeMorse);
       	}else{
                printf("\n\tERROR, INGRESE UNA LLAME NUMERICA VÁLIDA");
        }
        printf("\n\n***********************************************************************************************\n\n");

}

void imprimirArreglo(char *mensaje[]){

        int i;

        for(i=0;mensaje[i]!=NULL;i++){
                printf("%s",mensaje[i]);
        }

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

void minusculaAMayuscula(char string[]){
        int i=0;
        int desp='a'-'A';
        for (i=0;string[i]!='\0';++i){
                if(string[i]>='a'&&string[i]<='z'){
                        string[i]=string[i]-desp;
                }
        }
}

