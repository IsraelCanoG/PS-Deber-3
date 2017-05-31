#include <stdio.h>
#include <string.h>

char *claveMorse(char *mensaje){

	char *codigoMorse[]={" .-"," -..."," -.-."," -.."," ."," ..-."," --."," ...."," .."," .---"," -.-"," .-.."," --"," -."," ---"
                                ," .--."," --.-"," .-."," ..."," -"," ..-"," ...-"," .--"," -..-"," -.--"," --.."," -----"," .----"," ..---"
                                ," ...--"," ....-"," ....."," -...."," --..."," ---.."," ----."," /"};
	int i;

	for(i=0;*(mensaje+i)!='\0';i++){

	        if(*(mensaje+i)>=48 && *(mensaje+i)<=57){
			printf("%s",codigoMorse[0]);

		}else if(*(mensaje+i)==32){
			printf("%s",codigoMorse[36]);

		}else if(*(mensaje+i)>=65&&*(mensaje+i)<=90){
			printf("%s",codigoMorse[*(mensaje+i)-65]);
	
		}else if(*(mensaje+i)>=97&&*(mensaje+i)<=122){
			printf("%s",codigoMorse[*(mensaje+i)-97]);

		}else{
			printf("%c",*(mensaje+i));

		}
	}

	return mensaje;

}

/*	char *mensajeMorse[]=mensaje;

        int i,j;

        minusculaAMayuscula(*mensaje);

        for(i=0;mensajeMorse[i]!='\0';i++){
                j=mensajeMorse[i];
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

	return mensajeMorse;
*/


