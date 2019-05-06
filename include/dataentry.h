#ifndef _DATAENTRY_H 
#define _DATAENTRY_H

uint8_t DetectRules(const uint8_t);

#define __assert(matrixid, option, message) 															\
while(1) 																								\
{																										\
	dataread("%d", &get##option(matrixid), #message); 													\
	assertc(get##option(matrixid) >= 1, "\nError: La dimension de la matriz debe ser mayor a 0\n")		\
	break;																								\
}

/* DataEntry (Ingreso de datos) */
uint8_t DataEntry(const uint8_t option)
{
	uint32_t
		i,
		j
	;
	/* Pedir las dimensiones de las matrices */
	if(option != MULTI)
	{
		do
		{
			__assert(MA, rows, Ingrese el numero de filas de la Matriz)
			__assert(MA, cols, Ingrese el numero de columnas de la Matriz)
			setrows(MB, getrows(MA));
			setcols(MB, getcols(MA));
			if(!DetectRules(option)) continue;
			break;
		}while(1);
	}
	else
	{
		do
		{
			__assert(MA, rows, Ingrese el numero de filas de la Matriz A)
			__assert(MA, cols, Ingrese el numero de columnas de la Matriz A)
			__assert(MB, rows, Ingrese el numero de filas de la Matriz B)
			__assert(MB, cols, Ingrese el numero de columnas de la Matriz B)
			if(!DetectRules(option)) continue;
			break;
		}while(1);
	}
	/* Reservar memoria dinámicamente para la matriz A y B */
	realloc_m(int, MA, ROWS_COLS);
	realloc_m(int, MB, ROWS_COLS);
	
	/* Rellenar de datos a la matriz A */
	printf("\n-> Ingreso de datos de la matriz A (%d x %d):\n\n", getrows(MA), getcols(MA));
	repeatr(MA)
	{
		repeatc(MA)
		{
			dataread("%d", &gd(int, MA, i, j), "Ingrese el indice en la fila: %d - columna: %d", i, j);
		}
	}
	
	/* Rellenar de datos a la matriz B */
	printf("\n-> Ingreso de datos de la matriz B (%d x %d):\n\n", getrows(MB), getcols(MB));
	repeatr(MB)
	{
		repeatc(MB)
		{
			dataread("%d", &gd(int, MB, i, j), "Ingrese el indice en la fila: %d - columna: %d", i, j);
		}
	}
	return EXIT_SUCCESS;
}

/* Para detectar si la regla se cumplió o no, eso depende que la operación aritmética entre matrices se pueda efectuar */
uint8_t DetectRules(const uint8_t option)
{
	if(option != MULTI)
	{
		assertr((getrows(MA) == getrows(MB)) && (getcols(MA) == getcols(MB)), "\nError: Las dimensiones de ambas matrices deben coincidir\n")
	}
	switch(option)
	{
		case MULTI:
			assertr(getcols(MA) == getrows(MB), "\nError: El numero de columnas de la matriz A debe ser igual al numero de filas de la matriz B\n")
			break;
			
		case MD:
			assertr(getrows(MA) == getcols(MA), "\nError: El numero de filas y columnas de la matriz deben ser iguales\n")
			assertr(getrows(MA) >= 2, "\nError: El numero de filas de la matriz debe ser mayor a 2\n")
			assertr(getcols(MA) >= 2, "\nError: El numero de columnas de la matriz debe ser mayor a 2\n")
			break;
			
		case RD:
			assertr(getrows(MA) == getcols(MA), "\nError: El numero de filas y columnas de la matriz deben ser iguales\n");
			assertr(getrows(MA) >= 2, "\nError: El numero de filas de la matriz debe ser mayor a 2\n")
			assertr(getcols(MA) >= 2, "\nError: El numero de columnas de la matriz debe ser mayor a 2\n")
			break;

		case EDGE:
			assertr(getrows(MA) >= 3, "\nError: El numero de filas de la matriz debe ser mayor a 2\n")
			assertr(getcols(MA) >= 3, "\nError: El numero de columnas de la matriz debe ser mayor a 2\n")
			break;
			
		case WAY_T:
			assertr(getcols(MA) % 2 == 1, "\nError: El numero de columnas debe ser impar\n")
			assertr(getrows(MA) >= 2, "\nError: El numero de filas la matriz debe ser mayor a 1\n")
			assertr(getcols(MA) >= 3, "\nError: El numero de columnas de la matriz debe ser mayor a 2\n")
			break;
	}
	return 1;
}

#endif /* _DATAENTRY_H */
