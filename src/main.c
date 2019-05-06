#define MAX_MATRIX	(2)
#include <mDynamic.h>
#include <pscanf.h>
//#include <random.h>
#include <assertx.h>
#include "include/op.h"
#include "include/dataentry.h"

enum
{
	DISABLE,
	ENABLE
};

int main(void) 
{
	char option;
	uint8_t act = ENABLE;
	while(1)
	{
		puts("-> Operaciones entre matrices.");
		puts("-> Menu de Opciones:");
		printf("0. %s el ingreso de datos\n", (act == ENABLE) ? ("Desactivar") : ("Activar"));
		puts("1. Sumar");
		puts("2. Restar");
		puts("3. Multiplicar");
		puts("4. Sumar diagonal principal");
		puts("5. Sumar diagonal inversa");
		puts("6. Sumar los bordes");
		puts("7. Sumar en forma de T");
		puts("8. Salir del programa");
		dataread("%c", &option, "Ingrese una opcion <0-8>");
		assertc(option >= '0' && option <= '8', "\nError: Ingrese una opcion valida.\n")
		if((act == ENABLE) && (option >= '1' && option <= '7'))
		{ 
			error(DataEntry, option);
		}
		else if((option != '0' && option != '8') && (!DetectRules(option)))
		{
			pauseprogram();
			continue;
		}
		switch(option)
		{
			case '0':
				assertc(getrows(MA) != 0, "\nError: Usted no ha ingresado ningun dato a las matrices A y B.\n")
				act = !act;
				printf("\nInfo: Has %s el ingreso de datos de ambas matrices (A y B)\n", (act == DISABLE) ? ("Desactivado") : ("Activado"));
				break;
			case ADD:
				as_Matrix(ADD);
				break;
				
			case SUB:
				as_Matrix(SUB);
				break;
				
			case MULTI:
				multi_Matrix();
				break;
				
			case MD:
				Add_MD();
				break;
				
			case RD:
				Add_RD();
				break;
				
			case EDGE:
				Add_Edge();
				break;
				
			case WAY_T:
				Add_WayT();
				break;
				
			case EXIT_:
				return EXIT_SUCCESS;
		}
		pauseprogram();
	}
	return EXIT_SUCCESS;
}
