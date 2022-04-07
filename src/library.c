/*
 * library.c
 *
 *  Created on: 6 abr. 2022
 *      Author: Matias
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int menu() {
	int opcion;
	printf(" \n\n *** Menu de Opciones ***\n");
	printf(" 1) Ingresar la cantidad de kilometros \n");
	printf(" 2) Ingresar el precio de los vuelos \n");
	printf(" 3) Calcular todos los costos\n");
	printf(" 4) Informar resultados de los costos\n");
	printf(" 5) Carga forzada de datos\n");
	printf(" 6) Salir del menu\n ");
	scanf("%d", &opcion);

	return opcion;
}

int pedirKilometros(float *kilometros, int *pFlagKilometros) {
	int todoOk = 0;
	if (kilometros != NULL && pFlagKilometros != NULL) {
		printf("Ingrese la cantidad de kilometros a viajar: \n");
		scanf("%f", kilometros);
	}

	while (*kilometros <= 0) {

		printf(
				"\nError. Ingrese una cantidad valida de kilometros(mayor a cero): ");
		scanf("%f", kilometros);
	}
	*pFlagKilometros = 1;
	printf("-La cantidad de kilometros a viajar es: %.2f\n", *kilometros);
	todoOk = 1;
	return todoOk;
}

int pedirPrecio(int *pFlagPrecio, float *aerolineas, float *latam) {
	int todoOk = 0;

	if (pFlagPrecio != NULL && aerolineas != NULL && latam != NULL) {
		printf("Ingrese el precio del vuelo de Aerolineas: ");
		scanf("%f", aerolineas);
		printf("Ingrese el precio del vuelo de Latam: ");
		scanf("%f", latam);
	}

	while (*aerolineas <= 0 || *latam <= 0) {
		printf("Error. Ingrese un precio valido (mayor a cero)");
		printf("\nIngrese el precio del vuelo de Aerolineas: ");
		scanf("%f", aerolineas);
		printf("\nIngrese el precio del vuelo de Latam: ");
		scanf("%f", latam);
	}

	*pFlagPrecio = 1;
	todoOk = 1;
	printf("\n-El precio del vuelo de aerolineas es: %.2f", *aerolineas);
	printf("\n-El precio del vuelo de Latam es: %.2f", *latam);

	return todoOk;
}

int calcularCostosLatam(float kilometros, float aerolineas, float latam,
		float *pTarjetaCredito, float *pTarjetaDebito, float *pBitcoin,
		float *pPrecioUnitarioKm, float *pDiferenciaPrecio) {
	int todoOk = 0;

	if (pTarjetaCredito != NULL && pTarjetaDebito != NULL && pBitcoin != NULL
			&& pPrecioUnitarioKm != NULL && pDiferenciaPrecio != NULL) {
		todoOk = 1;
	}

	*pTarjetaCredito = ((float) kilometros * latam) * 1.25;
	*pTarjetaDebito = ((float) kilometros * latam) * 0.9;
	*pBitcoin = ((float) kilometros * latam) / 4606954.55;
	*pPrecioUnitarioKm = (float) latam / kilometros;
	*pDiferenciaPrecio = (float) latam - aerolineas;

	return todoOk;
}

int calcularCostosAerolineas(float kilometros, float aerolineas,
		int *pFlagCostos, float *pTarjetaCredito, float *pTarjetaDebito,
		float *pBitcoin, float *pPrecioUnitarioKm) {
	int todoOk;

	if (pTarjetaCredito != NULL && pTarjetaDebito != NULL && pBitcoin != NULL
			&& pPrecioUnitarioKm != NULL) {
		todoOk = 1;
	}

	*pFlagCostos = 1;
	*pTarjetaCredito = ((float) kilometros * aerolineas) * 1.25;
	*pTarjetaDebito = ((float) kilometros * aerolineas) * 0.9;
	*pBitcoin = ((float) kilometros * aerolineas) / 4606954.55;
	*pPrecioUnitarioKm = (float) aerolineas / kilometros;

	return todoOk;
}

void informarDatosLatam(float tarjetaCredito, float tarjetaDebito,
		float bitcoin, float precioUnitarioKm) {
	printf("\nAerolinea LATAM\n");
	printf("\na) Precio con tarjeta de débito: %.2f", tarjetaDebito);
	printf("\nb) Precio con tarjeta de crédito: %.2f", tarjetaCredito);
	printf("\nc) Precio pagando con bitcoin: %f", bitcoin);
	printf("\nd) Precio unitario: %.2f", precioUnitarioKm);

}
void informarDatosAerolineas(float tarjetaCredito, float tarjetaDebito,
		float bitcoin, float precioUnitarioKm, float diferenciaPrecio) {
	printf("\n\nAerolineas Argentinas\n");
	printf("\na) Precio con tarjeta de débito: %.2f", tarjetaDebito);
	printf("\nb) Precio con tarjeta de crédito: %.2f", tarjetaCredito);
	printf("\nc) Precio pagando con bitcoin: %f", bitcoin);
	printf("\nd) Precio unitario: %.2f", precioUnitarioKm);
	printf("\n\nLa diferencia de precio es: %.2f", diferenciaPrecio);

}

void pausarConsola(){
fflush(stdin);
getchar();
}

