#include <stdio.h>
#include <string.h>

void main(){

	char mensaje[1000];
	int llave;

	printf("\n\n***********************************************************************************************\n\n");
	printf("\tCifrado ciclico\n");
	printf("\tIngrese mensaje a cifrar     : ");
	scanf("%[^\n]",mensaje);
	printf("\tIngrese la llave numerica    : ");
	scanf("%i",&llave);
	minusculaMayuscula(mensaje,llave);
	printf("\tMensaje cifrado              : %s",mensaje);
	printf("\n\n***********************************************************************************************\n\n");


}


int nuevoValor( int min, int max, int pos, int desfase){
	int tmp;
	if(desfase>0){
        	if((pos+desfase)>max){
                	tmp=pos+desfase-max;
                        pos=(min-1)+tmp;
                }else{
                        pos=pos+desfase;
                }
         }else{
                if((pos+desfase)<min){
          	      	tmp=min-(pos+desfase);
                	pos=(max+1)-tmp;
                }else{
         		pos=pos+desfase;
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
















