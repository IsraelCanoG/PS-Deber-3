#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void main(int arg, char *argv[]){

	char mensaje[1000], llave[1000];


	if(arg==3){

		strcpy(mensaje,argv[2]);
		minusculaMayuscula(mensaje,llave);
		printf("\n\n***********************************************************************************************\n\n");
	        printf("\tCifrado ciclico\n");
        	printf("\tIngrese mensaje a cifrar     : %s\n",argv[2]);
	        printf("\tIngrese la llave numerica    : %i\n",*argv[1]);
	        printf("\tMensaje cifrado              : %s\n",mensaje);
		printf("\n\n***********************************************************************************************\n\n");

	}

	if(arg==1){

		printf("\n\n***********************************************************************************************\n\n");
		printf("\tCifrado ciclico\n");
		printf("\tIngrese mensaje a cifrar     : ");
		scanf("%[^\n]",mensaje);
		printf("\tIngrese la llave numerica    : ");
		scanf("%s",llave);
		if(esNumero(llave)){
			minusculaMayuscula(mensaje,atoi(llave));
			printf("\tMensaje cifrado              : %s",mensaje);
		}else{
			printf("\n\tERROR, INGRESE UNA LLAME NUMERICA VALIDA");
		}
		printf("\n\n***********************************************************************************************\n\n");

	}


}

int esNumero(char num[]){
	int i;
	for(i=0;num[i]!='\0';i++){
		if(!(num[i]>=48 && num[i]<=57 || num[i]==45 || num[i]==43)){
			return 0;
		}
	}
	return 1;
}

int nuevoValor( int min, int max, int pos, int desfase){
	int tmp,i;
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

void minusculaMayuscula(char mensaje[], int desfase){

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
















