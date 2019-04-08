//
// Created by Pablo Gaviria Lengaran on 2019-04-06.
//

#include <stdio.h>
#include <stdlib.h>
#include "Peliculas.h"
#include "Operaciones.h"
#include "Personas.h"

void anyadirNuevaPelicula(){
    char codigoPelicula[5], tituloPelicula[40], productora[20], categoria[20], ubicacion[20];
    int anyo;

    fflush(stdin);
    printf("Introduce el codigo de la pelicula: ");
    fflush(stdout);
    gets(codigoPelicula);
    printf("Introduce el titulo de la pelicula: ");
    fflush(stdout);
    gets(tituloPelicula);
    printf("Introduce la productora: ");
    fflush(stdout);
    gets(productora);
    printf("Introduce la categoria de la pelicula: ");
    fflush(stdout);
    gets(categoria);
    printf("Introduce el anyo de la pelicula: ");
    fflush(stdout);
    scanf("%i", &anyo);
    fflush(stdin);
    printf("Introduce la ubicacion (Trastienda, Espositor 1...): ");
    fflush(stdout);
    gets(ubicacion);

    FILE *fichero = fopen("peliculasDeustoClub.txt", "a");
    if (fichero == NULL) {
        printf("--Error al intentar abrir el fichero--");
    }
    fprintf(fichero, "%s,%s,%s,%s,%i,%s\n", codigoPelicula, tituloPelicula, productora, categoria, anyo, ubicacion);
    fclose(fichero);

    printf("Pelicula registrada. Menu de inicio -> 0 \n");

    int respuesta;
    do {
        fflush(stdout); scanf("%i", &respuesta);
        if (respuesta == 0) {
            inicioApp();
        } else {
            printf("--Caracter no valido--*\n");
        }
    } while (respuesta != 0);
}

void eliminarPelicula(){
    char codPelicula[5], tituloPelicula[40], productora[20], categoria[20], ubicacion[20];
    int anyo;

    FILE *ficheroOrigen = fopen("peliculasDuestoClub.txt", "r");
    if (ficheroOrigen == NULL) {
        printf("--Error al intentar abrir el fichero--\n");
    }

    FILE *ficheroDestino = fopen("nuevaListaPeliculas.txt", "w");
    if (ficheroDestino == NULL) {
        printf("--Error al intentar abrir el fichero--\n");
    }

    char codPeliculaBorrar[5];
    printf("¿Cual es el codigo de la pelicula que desea borrar? ");
    fflush(stdout);	scanf("%s", codPeliculaBorrar);
    rewind(ficheroOrigen);
    int peliculaEliminada = 0;
    while (fscanf(ficheroOrigen, "%[^,],%[^,],%[^,],%[^,],%i,%[^\n]\n", codPelicula, tituloPelicula, productora, categoria, anyo, ubicacion) != EOF){
        if(strcmp(codPelicula, codPeliculaBorrar) != 0) {
            fprintf(ficheroDestino, "%s,%s,%s,%s,%i,%s\n", codPelicula, tituloPelicula, productora, categoria, anyo, ubicacion);
        } else {
            peliculaEliminada = 1;
        }
    }
    if(peliculaEliminada == 0) {
        printf("Pelicula no encontrada, el codigo no existe.\n");
        eliminarPelicula();
    }

    fclose(ficheroOrigen); fclose(ficheroDestino);
    remove("peliculasDeustoClub.txt");
    rename("nuevaListaPeliculas.txt","peliculasDeustoClub.txt");

    printf("--Pelicula eliminada--\n");
    menuTrabajador();
}

void alquilarPelicula(char codPeliculaAlquilar [5]){
    char codPelicula[5],  tituloPelicula[20], productora[20], categoria[20],ubicacion[20];
    int anyo;

    FILE *ficheroOrigen = fopen("peliculasDeustoClub.txt", "r");
    if (ficheroOrigen == NULL) {
        printf("--Error al intentar abrir el fichero--\n");
    }

    FILE *ficheroDestino = fopen("nuevaListaPeliculas.txt", "w");
    if (ficheroDestino == NULL) {
        printf("--Error al intentar abrir el fichero--\n");
    }

    FILE *ficheroAlquiladas = fopen("listaPeliculasAlquiladas.txt", "a");
    if (ficheroAlquiladas == NULL) {
        printf("--Error al intentar abrir el fichero--\n");
    }

    rewind(ficheroOrigen);

    while (fscanf(ficheroOrigen, "%[^,],%[^,],%[^,],%[^,],%i,%[^\n]\n", codigoPelicula, tituloPelicula, productora, categoria, anyo, ubicacion) != EOF){
        int cmp = strcmp(codPeliculaAlquilar, codPelicula);
        if (cmp != 0) {
            fprintf(ficheroDestino, "%s,%s,%s,%s,%i,%s\n", codigoPelicula, tituloPelicula, productora, categoria, anyo, ubicacion);
        } else {
            fprintf(ficheroAlquiladas, "%s,%s,%s,%s,%i,%s\n", codigoPelicula, tituloPelicula, productora, categoria, anyo, ubicacion);
            printf("--Pelicula alquilada correctamente--\n");
        }
    }

    fclose(ficheroOrigen); fclose(ficheroDestino); fclose(ficheroAlquiladas);
    remove("peliculasDeustoClub.txt");
    rename("nuevaListaPeliculas.txt","peliculasDeustoClub.txt");
    menuCliente();
}

void mostrarListaPeliculas(){
    char codPelicula[5],  tituloPelicula[20], productora[20], categoria[20],ubicacion[20];
    int anyo;

    FILE *ficheroOrigen = fopen("peliculasDeustoClub.txt", "r");
    if (ficheroOrigen == NULL) {
        printf("--Error al intentar abrir el fichero--\n");
    }
    while (fscanf(ficheroOrigen, "%[^,],%[^,],%[^,],%[^,],%i,%[^\n]\n", codPelicula, tituloPelicula, productora, categoria, anyo, ubicacion) != EOF){
        printf("Cod: %s; Titulo: %s; Productora: %s; Anyo: %i; Categoria: %s; Ubicacion: %s \n", codPelicula, tituloPelicula, productora, anyo, categoria, ubicacion);
    }
    elegirPelicula();
}

void elegirPelicula(){
    char codPelicula[5], tituloPelicula[40], productora[20], categoria[20], ubicacion[20];
    int anyo;

    FILE *ficheroOrigen = fopen("peliculasDuestoClub.txt", "r");
    if (ficheroOrigen == NULL) {
        printf("--Error al intentar abrir el fichero--\n");
    }

    char peliculaSeleccionada[5];
    printf("¿Cual es el codigo de la pelicula que desea alquilar? \n");
    fflush(stdout);
    scanf("%s", peliculaSeleccionada);

    rewind(ficheroOrigen);

    int codigoPelicula = 0;
    while (fscanf(ficheroOrigen, "%[^,],%[^,],%[^,],%[^,],%i,%[^\n]\n", codPelicula, tituloPelicula, productora, categoria, anyo, ubicacion) != EOF){
        if(strcmp(codPelicula, peliculaSeleccionada) != 0) {
            alquilarPelicula(codPelicula);
            codigoPelicula = 1;
        }
    }
    if(codigoPelicula == 0) {
        printf("Pelicula no encontrada, el codigo no existe.\n");
        elegirPelicula();
    }
}

void devolverPelicula(){
    char codPelicula[5],  tituloPelicula[20], productora[20], categoria[20],ubicacion[20], codPeliculaDevolver[5];
    int anyo;

    printf("¿Cual es el codigo de la pelicula que desea alquilar? ");
    fflush(stdout);
    scanf("%s", codPeliculaDevolver);

    FILE *ficheroOrigen = fopen("listaPeliculasAlquiladas.txt", "r");
    if (ficheroOrigen == NULL) {
        printf("--Error al intentar abrir el fichero--\n");
    }

    FILE *ficheroDestino = fopen("nuevaListaPeliculas.txt", "w");
    if (ficheroDestino == NULL) {
        printf("--Error al intentar abrir el fichero--\n");
    }

    FILE *ficheroPeliculas = fopen("peliculasDeustoClub.txt", "a");
    if (ficheroPeliculas == NULL) {
        printf("--Error al intentar abrir el fichero--\n");
    }

    rewind(ficheroOrigen);

    while (fscanf(ficheroOrigen, "%[^,],%[^,],%[^,],%[^,],%i,%[^\n]\n", codPelicula, tituloPelicula, productora, categoria, anyo, ubicacion) != EOF){
        if (strcmp(codPeliculaDevolver, codPelicula) != 0) {
            fprintf(ficheroDestino, "%s,%s,%s,%s,%i,%s\n", codigoPelicula, tituloPelicula, productora, categoria, anyo, ubicacion);
        } else {
            fprintf(ficheroPeliculas, "%s,%s,%s,%s,%i,%s\n", codigoPelicula, tituloPelicula, productora, categoria, anyo, ubicacion);
            printf("--Pelicula devuelta correctamente--\n");
        }
    }
    fclose(ficheroOrigen);
    fclose(ficheroDestino);
    fclose(ficheroAlquiladas);
    remove("listaPeliculasAlquiladas.txt");
    rename("nuevaListaPeliculas.txt","listaPeliculasAlquiladas.txt");
    menuCliente();

}