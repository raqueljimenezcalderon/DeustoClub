/*
 * trabajador.h
 *
 *  Created on: 6 abr. 2019
 *      Author: Raquel
 */
#include "usuario.h"
#ifndef TRABAJADOR_H_
#define TRABAJADOR_H_

typedef struct {
	char * cargo;
	long salario; //los float suelen dar problemas, pero podemos ponerlo.
	char * numSeguridadSocial;
	char * numCuentaBancaria;
	Usuario * usuario;
} Trabajador;

#endif /* TRABAJADOR_H_ */
