#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "morse.h"
#include "cifrado.h"
#include "varios.h"

int main(int arg, char *argv[]){

	char mensaje[1000], llave[1000], *mensajeMorse[1000];

	if(arg==3){
		if(!esNumero(argv[1])){
			printf("\n\n\tPARAMETROS ERRONEOS\n\n");
		}else{
			printf("\n\n***********************************************************************************************\n\n");
		        printf("\tCifrado ciclico\n");
        		printf("\tIngrese mensaje a cifrar     : %s\n",argv[2]);
		        printf("\tIngrese la llave numerica    : %s\n",argv[1]);
			cifradoCiclico(argv[2],atoi(argv[1]));
		        printf("\tMensaje cifrado              : %s",argv[2]);
			mensajeAMorse(argv[2],mensajeMorse);
			printf("\n\tMensaje cifrado en morse    : ");
			imprimirArreglo(mensajeMorse);
			printf("\n\n***********************************************************************************************\n\n");
		}
	}

	if(arg==1){

		printf("\n\n***********************************************************************************************\n\n");
		printf("\tCifrado ciclico\n");
		printf("\tIngrese mensaje a cifrar     : ");
		scanf("%[^\n]",mensaje);
		printf("\tIngrese la llave numerica    : ");
		scanf("%s",llave);
		if(esNumero(llave)){
			cifradoCiclico(mensaje,atoi(llave));
			printf("\tMensaje cifrado              : %s",mensaje);
			mensajeAMorse(mensaje,mensajeMorse);
			printf("\n\tMensaje cifrado en morse    : ");
			imprimirArreglo(mensajeMorse);
		}else{
			printf("\n\tERROR, INGRESE UNA LLAME NUMERICA VALIDA");
		}
		printf("\n\n***********************************************************************************************\n\n");

	}
	return 0;

}


/*
int esNumero(char num[]){
	int i;
	for(i=0;num[i]!='\0';i++){
		if(!((num[i]>=48 && num[i]<=57) || num[i]==45 || num[i]==43)){
			return 0;
		}
	}
	return 1;


int nuevoValor( int min, int max, int pos, int desfase){
	int i;
	if(desfase>0){

		for (i=1;i<=desfase;i++){
			if(pos<max){
				pos=pos+1;
			}else{
				pos=min;
			}
		}
         }else{
                for (i=1;i<=(desfase*-1);i++){
                        if(pos>min){
                                pos=pos-1;
                        }else{
                                pos=max;
                        }
                }

         }
	return pos;
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

void imprimirArrayString(char *mensajeMorse[]){


	for(i=0;mensajeMorse[i]!=NULL;i++){
		printf("%s",mensajeMorse[i]);
	}

}

void mensajeAMorse(char mensaje[], char *mensajeMorse[]){

	char *codigoMorse[]={" .-"," -..."," -.-."," -.."," ."," ..-."," --."," ...."," .."," .---"," -.-"," .-.."," --"," -."," ---"," .--."," --.-"," .-."," ..."," -"," ..-"," ...-"," .--"," -..-"," -.--"," --.."," -----"," .----"," ..---"," ...--"," ....-"," ....."," -...."," --..."," ---.."," ----."};
	int i,j;

	minusculaAMayuscula(mensaje);

	for(i=0;mensaje[i]!='\0';i++){
		j=mensaje[i];
		if(j>=48&&j<=57){
			mensajeMorse[i]=codigoMorse[j-22];
		}else{
			if(j==32){
				mensajeMorse[i]=" /";
			}else{
				if(j>=65&&j<=90){
					mensajeMorse[i]=codigoMorse[j-65];
				}else{
					mensajeMorse[i]=" |";
				}
			}
		}
	}
}

void cifradoCiclico(char mensaje[], int desfase){

	int i;

	for(i=0;mensaje[i]!='\0';i++){

		if(mensaje[i]>=65 && mensaje[i]<=90){
			mensaje[i]=nuevoValor(65,90,mensaje[i],desfase);
		}else{
			if(mensaje[i]>=97 && mensaje[i]<=122){
				mensaje[i]=nuevoValor(97,122,mensaje[i],desfase);
			}else{
				mensaje[i]=mensaje[i];
			}
		}
	}

	return;

}

*/
