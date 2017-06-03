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

char* cifradoContrasena(char* mensaje, char* llave){
    printf("%s\n", mensaje);
    char* mensaje_no_espacios = mensajeSinEspacios(mensaje);
    printf("%s\n", mensaje_no_espacios);
    int *posiciones_espacios = posicionesEspacios(mensaje);
    printf("%d\n", posiciones_espacios[2]);
    char *llave_espaciada = llaveEspaciada(llave, posiciones_espacios);
    printf("%s\n", llave_espaciada);
    char *mensaje_contrasena = mensajeContrasena(llave_espaciada, mensaje, mensaje_no_espacios);
    printf("%s\n", mensaje_contrasena);
    char *tmp = "";
    return tmp;
}

// fin cifrado contrasena


char* cifradoAutollave(char* mensaje, char* llave){
  char *tmp = "";
  return tmp;
}
