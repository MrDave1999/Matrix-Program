#ifndef _DATAENTRY_H 

/* DataEntry (Ingreso de datos) */
uint8_t DataEntry(void)
{
	uint32_t
		i,
		j
	;
	/* Pedir las dimensiones de las matrices */
	dataread("%d", &getrows(MA), "Ingrese el numero de filas de la Matriz A");
	dataread("%d", &getcols(MA), "Ingrese el numero de columnas de la Matriz A");
	
	dataread("%d", &getrows(MB), "Ingrese el numero de filas de la Matriz B");
	dataread("%d", &getcols(MB), "Ingrese el numero de columnas de la Matriz B");

	/* Reservar memoria dinámicamente para la matriz A y B */
	realloc_m(int, MA, ROWS_COLS);
	realloc_m(int, MB, ROWS_COLS);
	
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
	return EXIT_SUCCESS;
}

#endif
