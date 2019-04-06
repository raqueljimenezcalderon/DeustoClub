//
// Created by Pablo Gaviria Lengaran on 2019-04-06.
//

#ifndef DEUSTOCLUB_PERSONAS_H
#define DEUSTOCLUB_PERSONAS_H

typedef struct {
    char DNI[10];
    char email [40];
    char contrasena [25];
    char nombre [20];
    char apellido [20];
    char direccion [40];
    long telefono;
    char sexo;
    char numTarjetaCredito[16];
} Usuarios;

typedef struct {
    char cargo [20];
    long salario;
    char numSeguridadSocial [11];
    char numCuentaBancaria [20];
    Usuario usuario;
} Trabajadores;

#endif //DEUSTOCLUB_PERSONAS_H
