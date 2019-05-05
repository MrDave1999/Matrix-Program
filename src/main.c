#define MAX_MATRIX	(2)
#include <mDynamic.h>
#include <pscanf.h>
#include <random.h>
#include <assertx.h>
#include "include/op.h"
#include "include/dataentry.h"

int main(void) 
{
	char option;
	while(1)
	{
		puts("-> Operaciones entre matrices.");
		puts("-> Menu de Opciones:");
		puts("1. Sumar");
		puts("2. Restar");
		puts("3. Multiplicar");
		puts("4. Sumar diagonal principal");
		puts("5. Sumar diagonal inversa");
		puts("6. Sumar los bordes");
		puts("7. Sumar en forma de T");
		puts("8. Salir del programa");
		dataread("%c", &option, "Ingrese una opcion <1-8>");
		assertc(option >= '1' && option <= '8', "\nError: Ingrese una opcion valida.\n");
		switch(option)
		{
			case '1':
				error(DataEntry);
				as_Matrix(ADD);
				break;
			case '2':
				error(DataEntry);
				as_Matrix(SUBTRACT);
				break;
			case '3':
				error(DataEntry);
				multi_Matrix();
				break;
			case '4':
				error(DataEntry);
				Add_MD();
				break;
			case '5':
				error(DataEntry);
				Add_RD();
				break;
			case '6':
				error(DataEntry);
				Add_Edge();
				break;
			case '7':
				error(DataEntry);
				Add_WayT();
				break;
			case '8':
				return EXIT_SUCCESS;
		}
		pauseprogram();
	}
	return EXIT_SUCCESS;
}
