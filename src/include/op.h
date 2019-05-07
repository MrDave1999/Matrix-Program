#ifndef _OP_H /* Operaciones aritméticas entre matrices */
#define _OP_H

/* repeat-rows -> recorrer cada fila de una matriz */
#define repeatr(matrixid) for(i = 0; i != getrows(matrixid); ++i)

/* repeat-cols -> recorrer cada columna de una matriz */
#define repeatc(matrixid) for(j = 0; j != getcols(matrixid); ++j)

enum __ID_MATRIX
{
	/* Las ID de las matrices comienzan desde 0 */
	MA, 		/* matriz A  - ID: 0 */
	MB, 		/* matriz B - ID: 1 */
};

enum __OPTIONS
{
	ADD = '1',  /* Opción sumar */
	SUB,		/* Opción restar (subtract) */
	MULTI,		/* Opción multiplicar */
	MD,			/* Opción sumar diagonal principal (Main Diagonal) */
	RD,			/* Opción sumar diagonal inversa (Reverse Diagonal) */
	EDGE,		/* Opción sumar bordes */
	WAY_T,		/* Opción sumar en forma de T */
	EXIT_		/* Opción salir del programa */
	
};

/* Add-Subtract matrix (suma y resta entre matrices) */
void as_Matrix(const uint8_t option)
{
	puts("\n\n");
	puts(option == ADD ? "Matriz A+B:\n" : "Matriz A-B:\n");
	uint32_t 
		i,
		j
	;
	repeatr(MA)
	{
		repeatc(MA)
		{
			(option == ADD) ? (printf("%d\t", gd(int, MA, i, j) + gd(int, MB, i, j))) : (printf("%d\t", gd(int, MA, i, j) - gd(int, MB, i, j)));
		}
		puts("");
	}
}

/* Multiply matrix (multiplicación entre matrices) */
void multi_Matrix(void)
{
	puts("\n\n");
	puts("Matriz AxB:\n");
	uint32_t 
		rows_ma, 
		cols_ma = -1,
		rows_mb, 
		cols_mb 
	;
	int32_t add = 0;
	/* Para recorrer los índices de cada fila de la matriz A */
	for(rows_ma = 0; rows_ma != getrows(MA); ++rows_ma)
	{
		/* Para recorrer los índices de cada columna de la matriz B */
		for(cols_mb = 0; cols_mb != getcols(MB); ++cols_mb)
		{
			/* Para recorrer los índices de cada fila de la matriz B */
			for(rows_mb = 0; rows_mb != getrows(MB); ++rows_mb)
			{
				++cols_ma; /* Para recorrer los índices de cada columna de la matriz A */
				add = add + (gd(int, MA, rows_ma, cols_ma) * gd(int, MB, rows_mb, cols_mb));
			}
			printf("%d\t", add);
			cols_ma = -1;
			add = 0;
		}
		puts("");
	}
}

/* Add Main Diagonal (sumar la diagonal principal entre matrices) */
void Add_MD(void)
{
	puts("\n\n");
	puts("Matriz A+B:\n");
	uint32_t 
		i,
		space
	;
	repeatr(MA)
	{
		for(space = i; space != 0; --space)
			printf("\t");
		printf("%d\n", gd(int, MA, i, i) + gd(int, MB, i, i));
	}
}

/* Add Reverse Diagonal (sumar la diagonal inversa entre matrices) */
void Add_RD(void)
{
	puts("\n\n");
	puts("Matriz A+B:\n");
	uint32_t 
		i,
		space
	;
	int32_t n = getrows(MA);
	for(i = 0; --n != -1; ++i)
	{
		for(space = n; space != 0; --space)
			printf("\t");
		printf("%d\n", gd(int, MA, i, n) + gd(int, MB, i, n));
	}
}

/* Add Edge (sumar los bordes entre matrices) */
void Add_Edge(void)
{
	puts("\n\n");
	puts("Matriz A+B:\n");
	uint32_t 
		i,
		j
	;  
	/* Para recorrer el primer borde (primera fila) */
	repeatc(MA)
		printf("%d\t", gd(int, MA, 0, j) + gd(int, MB, 0, j));
	puts("");
	/* Para recorrer el segundo y tercer borde (primera y última columna) */
	for(i = 1; i != getrows(MA)-1; ++i)
	{
		/* Para sumar los datos del segundo borde entre matrices */
		printf("%d", gd(int, MA, i, 0) + gd(int, MB, i, 0));
		/* Para que la última columna esté alineada con respecto al último elemento de la primera fila */
		for(j = 1; j != getcols(MA); ++j)
			printf("\t");
		/* Para sumar los datos del tercer borde entre matrices */
		printf("%d\n", gd(int, MA, i, getcols(MA)-1) + gd(int, MB, i, getcols(MB)-1));
	}
	/* Para recorrer el cuarto borde (última fila) */
	repeatc(MA)
		printf("%d\t", gd(int, MA, getrows(MA)-1, j) + gd(int, MB, getrows(MB)-1, j));
	puts("");
}

/* Add WayT (sumar en forma de T entre matrices */
void Add_WayT(void)
{
	puts("\n\n");
	puts("Matriz A+B:\n");
	uint32_t 
		i,
		j,
		media
	;
	/* Recorrer la primera fila y sumar entre matrices */
	repeatc(MA)
		printf("%d\t", gd(int, MA, 0, j) + gd(int, MB, 0, j));
	puts("");
	/* Calculamos la posición/índice del medio para saber cual es la columna que formará la T */
	media = (getcols(MA)-1) / 2;
	/* Recorremos cada fila con respecto a la columna del medio */
	for(i = 1; i != getrows(MA); ++i)
	{
		/* Tabulamos para formar la T */
		for(j = 0; j != media; ++j)
			printf("\t");
		/* Sumamos la columnas del medio entre las matrices */
		printf("%d\n", gd(int, MA, i, media) + gd(int, MB, i, media));
	}
}

#endif /* _OP_H */
