/*
 * library.h
 *
 *  Created on: 6 abr. 2022
 *      Author: Matias
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_

int menu();

int pedirKilometros(float *kilometros, int *pFlagKilometros);

int pedirPrecio(int *pFlagPrecio, float *aerolineas, float *latam);

int calcularCostosLatam(float kilometros, float aerolineas, float latam,
		float *tarjetaCredito, float *tarjetaDebito, float *bitcoin,
		float *precioUnitarioKm, float *diferenciaPrecio);
int calcularCostosAerolineas(float kilometros, float aerolineas,
		int *pFlagCostos, float *tarjetaCredito, float *tarjetaDebito,
		float *bitcoin, float *precioUnitarioKm);

void informarDatosLatam(float tarjetaCredito, float tarjetaDebito,
		float bitcoin, float precioUnitarioKm);

void informarDatosAerolineas(float tarjetaCredito, float tarjetaDebito,
		float bitcoin, float precioUnitarioKm, float diferenciaPrecio);

void pausarConsola();
#endif /* LIBRARY_H_ */
