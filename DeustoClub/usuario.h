/*
 * usuario.h
 *
 *  Created on: 6 abr. 2019
 *      Author: Raquel
 */

#ifndef USUARIO_H_
#define USUARIO_H_

typedef struct {
	char DNI[10];
	char * email;
	char * contrasena;
	char * nombre;
	char * apellido;
	char * direccion;
	long telefono;
	char sexo;
	char numTarjeta[9];
	//DNI trabajador no hace falta poner
} Usuario;

#endif /* USUARIO_H_ */
