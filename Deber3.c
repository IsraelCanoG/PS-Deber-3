#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "morse.h"
#include "cifrado.h"
#include "varios.h"

int main(int arg, char *argv[]){

	switch(arg){

		case 1:
			imprimirS();
			break;

		case 3:
			imprimirC(argv);
			break;

		default:
			printf("--");
	}

	return 0;

}


