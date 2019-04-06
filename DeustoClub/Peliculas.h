/*
 * pelicula.h
 *
 *  Created on: 6 abr. 2019
 *      Author: Raquel
 */

#ifndef PELICULA_H_
#define PELICULA_H_

typedef struct {
    char codigoPelicula [5];
    char titulo [40];
    char productora [20];
    int año;
    char categoria [20];
    char ubicacion [20];
} Peliculas;


#endif /* PELICULA_H_ */
