#include "./utilidades/utilidades.h"
#include "./utilidades/utilidades.c"

int main (void)
{
	int valorSO = 0;
	
	// int edadaux;    // Variable provisional para pedir las edades.
	int npersonas;  // Total de personas registradas.
	
	int suma = 0;       // Suma de las edades antes de hacer la media.
	float media = 0;   // Media de la suma de las edades.
	
	// float media;    // Resultado con la media calculada.
	
	npersonas = pedirEnteroPositivo("¿Cuántas personas contabilizar?", 5, TRUE);
	
	if (npersonas == 0)
	{
		mostrar("No puedo calcular medias si no existen datos.");
	}
	else
	{
		int edad[npersonas];
		
		for(int i=0 ; i<npersonas ; i++)
		{
			// Pedir una edad.
			mostrar_x_y("PERSONA ", 0, 2);
			printf("%d", i+1);
			mostrar("ª");
			LINEAENBLANCO;
			
			edad[i] = pedirEnteroIntervalo("Dame la edad", 5, FALSE, 0, 120);
			
			// Acumular edades sumándolas.
			suma = suma + edad[i];
			
			// pedirConfirmacion("¿Está de acuerdo con los datos?", 7, TRUE);
			pedirLetraSeleccion("Se formateará tu disco duro", 7, TRUE, "aico", FALSE);
		}
		
		LINEAENBLANCO;
		
		mostrar("Las edades dadas son:");
		
		LINEAENBLANCO;
		LINEAENBLANCO;
		
		for(int i=0; i<npersonas; i++)
		{
			printf("%d, ", edad[i]); 
		}
		
		NUEVALINEA;
		
		media = ((float) suma)  / npersonas;
		
		mostrar("La media de edades es ");
		printf("%5.2f", media);
		
		NUEVALINEA;
	}
	
	return valorSO;
}

