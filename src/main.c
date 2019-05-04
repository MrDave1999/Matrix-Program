#define MAX_MATRIX	(2)
#include <mDynamic.h>
#include <pscanf.h>
#include <random.h>
#include "op.h"

int main(void) 
{
	int i, j;
	/* Pedir las dimensiones de las matrices */
	dataread("%d", &getrows(MA), "Ingrese el numero de filas de la MA");
	dataread("%d", &getcols(MA), "Ingrese el numero de columnas de la MA");
	
	dataread("%d", &getrows(MB), "Ingrese el numero de filas de la MB");
	dataread("%d", &getcols(MB), "Ingrese el numero de columnas de la MB");

	/* Reservar memoria dinámicamente para la matriz A y B */
	alloc_m(int, MA);
	alloc_m(int, MB);
	
	/* Rellenar de datos a la matriz A */
	repeatr(MA)
	{
		repeatc(MA)
			sd(int, MA, i, j, randomEx(-10, 5));
	}
	
	/* Rellenar de datos a la matriz B */
	repeatr(MB)
	{
		repeatc(MB)
			sd(int, MB, i, j, randomEx(-10, 5));
	}
	puts("\n\n");
	puts("Datos matriz A:\n");
	/* Imprimir los datos de la matriz A */
	repeatr(MA)
	{
		repeatc(MA)
			printf("%d\t", gd(int, MA, i, j));
		puts("");
	}
	puts("\n\n");
	puts("Datos matriz B:\n");
	/* Imprimir los datos de la matriz B */
	repeatr(MB)
	{
		repeatc(MB)
			printf("%d\t", gd(int, MB, i, j));
		puts("");
	}
	puts("\n");
	as_Matrix(ADD);
	as_Matrix(SUBTRACT);
	multi_Matrix();
	Add_MD();
	Add_RD();
	Add_Edge();
	Add_WayT();
	pauseprogram();
	return EXIT_SUCCESS;
}
