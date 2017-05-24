#include <stdio.h>
#include "morse.h"
#include "varios.h"

void mensajeAMorse(char mensaje[], char *mensajeMorse[]){

	char *codigoMorse[]={" .-"," -..."," -.-."," -.."," ."," ..-."," --."," ...."," .."," .---"," -.-"," .-.."," --"," -."," ---"
                                ," .--."," --.-"," .-."," ..."," -"," ..-"," ...-"," .--"," -..-"," -.--"," --.."," -----"," .----"," ..---"
                                ," ...--"," ....-"," ....."," -...."," --..."," ---.."," ----."};

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

