#include <stdio.h>
#include "varios.h"

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

