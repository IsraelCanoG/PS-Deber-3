#include "cifrado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// incio cifrado ciclico
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

// fin cifrado ciclico

// inicio cifrado autollave
/*
// @return el mensaje unido sin espacios
*/
char* mensajeSinEspacios(char* mensaje) {
    int cont = 0;
    int desface = 0;
    char *mensaje_temp = (char *)malloc(sizeof (char) * 50);

    while (mensaje[cont] != '\0') {
        if (mensaje[cont] == ' ') {
            desface++;
        } else {
            mensaje_temp[cont - desface] = mensaje[cont];
        }
        cont++;
    }
    mensaje_temp[cont - desface + 1] = '\0';
    return mensaje_temp;
}

<<<<<<< Updated upstream
/*
//  @return array de espacios en blanco de mensajes y el resto de ceros
*/
int * posicionesEspacios(char * mensaje) {
    int cont = 0;
    int *espacios = (int *)malloc(sizeof (int) *50);
    int espacios_index = 0;
    while(mensaje[cont] != '\0') {
        if(mensaje[cont] == ' ') {
            espacios[espacios_index] = cont;
            espacios_index++;
        }
        cont++;
    }
    return espacios;
}
=======
>>>>>>> Stashed changes

char * llaveEspaciada(char * llave, int * posiciones_espacios) {
    char *llaveEspaciada = (char *)malloc(sizeof(char) *50);
    int cont = 0;
    int inicial_espacio = posiciones_espacios[0];
    int cont_espacios = 0;
    while (llave[cont] != '\0') {
        if (cont == inicial_espacio) {
            llaveEspaciada[cont] = ' ';
            cont_espacios++;
            inicial_espacio = posiciones_espacios[cont_espacios];
        } else {
            llaveEspaciada[cont+cont_espacios] = llave[cont];
            cont++;
        }
    }
    return llaveEspaciada;
}

char* mensajeContrasena(char *llave_espaciada, char *mensaje, char *mensaje_no_espacios) {
    char *mensaje_contrasena = (char *)malloc(sizeof(char)*50);
    size_t tamano_mensaje = strlen(mensaje);
    size_t tamano_llave_espaciada = strlen(llave_espaciada);
    int tamano_restante = 0;
    if (tamano_mensaje > tamano_llave_espaciada) {
        tamano_restante = tamano_mensaje - tamano_llave_espaciada;
        strncpy(mensaje_contrasena, mensaje_no_espacios, tamano_restante);
        return strcat(llave_espaciada, mensaje_contrasena);
    } else if (tamano_mensaje < tamano_llave_espaciada) {
        strncpy(mensaje_contrasena, llave_espaciada, tamano_mensaje);
        return mensaje_contrasena;
    } else {
        return llave_espaciada;
    }
}

char* extraerString(char* palabra, int inicio, int fin) {
    char *st = (char *)malloc(sizeof(char)*50);
    int cont = 0;
    int cont_st = 0;
    while(palabra != '\0') {
        if (cont >= inicio && cont <= fin) {
            st[cont_st] = palabra[cont];
            cont_st++;
        }
        cont++;
    }
    st[cont_st] = '\0';
    return st;
}

int ciclico (int numero, int salto) {
    int limite_sup = 90;
    int limite_inf = 65;
    int num_salto = numero + salto;
    if (numero == 32) {
        return -1;
    }
    if (num_salto > 90) {
        return num_salto - limite_sup + limite_inf - 1;
    } else {
        return num_salto;
    }
}

char* generarClave(char* mensaje, char* mensaje_contrasena) {
    char* salida = (char *)malloc(sizeof(char) * 50);
    int c_actual_contrasena = 0;
    int c_actual_mensaje = 0;
    int limite_inf = 65;
    int tmp = 0;
    char letra_cifrado = '0';
    size_t cont = 0;
    int tmp_num = 0;
    while (mensaje[cont] != '\0' && mensaje_contrasena != '\0') {
        c_actual_contrasena = (int)mensaje_contrasena[cont];
        c_actual_mensaje = (int)mensaje[cont];
        tmp = c_actual_contrasena - limite_inf;
        tmp_num = ciclico(c_actual_mensaje, tmp);
        if (tmp == -1) {
            salida[cont] = ' ';
            cont++;
            continue;
        }
        letra_cifrado = (char)tmp_num;
        salida[cont] = letra_cifrado;
        cont++;
    }
    salida[cont] = '\0';
    return salida;
}

char* cifradoContrasena(char* mensaje, char* llave){
    char* mensaje_no_espacios = mensajeSinEspacios(mensaje);
    int *posiciones_espacios = posicionesEspacios(mensaje);
    char *llave_espaciada = llaveEspaciada(llave, posiciones_espacios);
    char *mensaje_contrasena = mensajeContrasena(llave_espaciada, mensaje, mensaje_no_espacios);
		char *contrasena = generarClave(mensaje, mensaje_contrasena);
    return contrasena;
}
// fin cifrado contrasena

<<<<<<< Updated upstream
=======
>>>>>>> Stashed changes

char *cifrarAutoLlave2(char *mensaje,char *llave){ 
	int k = 0;
	const char *str1 = llave;
	const char *str2 = mensaje;	
	char *pass = malloc(strlen(str1) + strlen(str2) + 1);
	while(*str1){
		pass[k++]=*str1++;
	}
  	while(*str2){
      		pass[k++]=*str2++;
  	}
  	pass[k]='\0';
	
	char *tmp;
  	while((tmp=strchr(pass,' '))!=NULL){
		strcpy(tmp,tmp+1);
  	}

	int i,j=0;
    	for(i=0;i<strlen(mensaje);i++){		
		if (mensaje[i]!=32){
			if ((mensaje[i]>=65&&mensaje[i]<=90) && (pass[j]>=65&&pass[j]<=90)){
				mensaje[i]=((mensaje[i]+pass[j])%26)+65;
			}else if ((mensaje[i]>=97&&mensaje[i]<=122) && (pass[j]>=97&&pass[j]<=122)){			
				mensaje[i]=(((mensaje[i]+pass[j])-64)%26)+97;
			}else if ((mensaje[i]>=97&&mensaje[i]<=122) && (pass[j]>=65&&pass[j]<=90)){
				mensaje[i]=(((mensaje[i]-32)+pass[j])%26)+97;
			}else if ((mensaje[i]>=65&&mensaje[i]<=90) && (pass[j]>=97&&pass[j]<=122)){
				mensaje[i]=((mensaje[i]+(pass[j]-32))%26)+65;
			}
			j=j+1;
		}
    	}
    	return mensaje;
}

char *cifrarContrasena2(char *mensaje, char *llave){
	int k = 0;
	const char *str1 = llave;
	const char *str2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	printf("\n\tAlfabeto: %s\n", str2);
	char *tmp;
  	while((tmp=strchr(llave,' '))!=NULL){
		strcpy(tmp,tmp+1);
  	}
	
	char *pass = malloc(strlen(str1) + strlen(str2) + 1);
	while(*str1){
		pass[k++]=*str1++;
	}
  	while(*str2){
      		pass[k++]=*str2++;
  	}
  	pass[k]='\0';
	printf("\tNuevo Alfabeto: %s\n\n", pass);
	int i;	
	for(i=0;i<strlen(mensaje);i++){		
		if (mensaje[i]!=32){
			if ((mensaje[i]>=65&&mensaje[i]<=90)){
				mensaje[i]=pass[mensaje[i]-65];
			}else if (mensaje[i]>=97&&mensaje[i]<=122){
				mensaje[i]=pass[mensaje[i]-97];
			}
		}
    	}
    	return mensaje;
}
