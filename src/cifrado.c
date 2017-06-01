#include "cifrado.h"
#include <stdio.h>

int nuevoValor(int min, int max, int pos, int desfase){
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

char *cifradoCiclico(char *mensaje, int llave){

        int i;

        for(i=0;*(mensaje+i)!='\0';i++){

                if(*(mensaje+i)>=65 && *(mensaje+i)<=90){
                        *(mensaje+i)=nuevoValor(65,90,*(mensaje+i),llave);
                }else{
                        if(*(mensaje+i)>=97 && *(mensaje+i)<=122)
                                *(mensaje+i)=nuevoValor(97,122,*(mensaje+i),llave);
                }
        }

	return mensaje;

}

char* cifradoAutollave(char* mensaje, char* llave){

	return mensaje;

}


char* cifradoContrasena(char* mensaje, char* llave){

	return mensaje;

}
