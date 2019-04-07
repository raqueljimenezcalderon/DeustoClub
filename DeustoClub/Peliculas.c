//
// Created by Pablo Gaviria Lengaran on 2019-04-06.
//

#include <stdio.h>
#include <stlib.h>
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

    FILE *fichero = fopen("PeliculasDeustoClub.txt", "a");
    if (fichero == NULL) {
        printf("**Error en apertura de fichero**");
    }
    fprintf(fichero, "%s,%s,%s,%s,%i,%s\n", codigoPelicula, tituloPelicula, productora, categoria, anyo, ubicacion);
    fclose(fichero);

    printf("Pelicula registrada. Menu de inicio -> 0 \n");

    int opcion;
    do {
        fflush(stdout); scanf("%i", &opcion);
        if (opcion == 0) {
            inicioApp();
        } else {
            printf("**Opcion incorrecta, intentelo de nuevo**\n");
        }
    } while (opcion != 0);
}

void eliminarPelicula(){
    char codPelicula[5], tituloPelicula[40], productora[20], categoria[20], ubicacion[20];
    int anyo;

    FILE *ficheroOrigen = fopen("PeliculasDuestoClub.txt", "r");
    if (ficheroOrigen == NULL) {
        printf("**Error en apertura de fichero**\n");
    }

    FILE *ficheroDestino = fopen("NuevaListaPeliculas1.txt", "w");
    if (ficheroDestino == NULL) {
        printf("**Error en apertura de fichero**\n");
    }

    char codPeliculaBorrar[5];
    printf("¿Cual es el codigo de la pelicula que desea borrar? ");
    fflush(stdout);	scanf("%s", codPeliculaBorrar);
    rewind(ficheroOrigen);
    int peliculaEliminada = 0;
    while (fscanf(ficheroOrigen, "%[^,],%[^,],%[^,],%[^,],%i,%[^\n]\n", codigoPelicula, tituloPelicula, productora, categoria, anyo, ubicacion) != EOF){
        if(strcmp(codPelicula, codPeliculaBorrar) != 0) {
            fprintf(ficheroDestino, "%s,%s,%s,%s,%i,%s\n", codigoPelicula, tituloPelicula, productora, categoria, anyo, ubicacion);
        } else {
            peliculaEliminada = 1;
        }
    }
    if(peliculaEliminada == 0) {
        printf("Pelicula no encontrada, el codigo no existe.\n");
        eliminarPelicula();
    }

    fclose(ficheroOrigen); fclose(ficheroDestino);
    remove("PeliculasDeustoClub.txt");
    rename("NuevaListaPeliculas1.txt","PeliculasDeustoClub.txt");

    printf("--Pelicula eliminada.--\n");
    menuTrabajador();
}

void alquilarPelicula(char codPeliculaAlquilar [5]){
    char codPelicula[5],  tituloPelicula[20], prductora[20], categoria[20],ubicacion[20];
    int anyo;

    FILE *ficheroOrigen = fopen("PeliculasDeustoClub.txt", "r");
    if (ficheroOrigen == NULL) {
        printf("**Error en apertura de fichero**\n");
    }

    FILE *ficheroDestino = fopen("NuevaListaPeliculas2.txt", "w");
    if (ficheroDestino == NULL) {
        printf("**Error en apertura de fichero**\n");
    }

    FILE *ficheroAlquiladas = fopen("ListaPeliculasAlquiladas.txt", "a");
    if (ficheroAlquiladas == NULL) {
        printf("**Error en apertura de fichero**\n");
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
    remove("PeliculasDeustoClub.txt");
    rename("NuevaListaPeliculas2.txt","PeliculasDeustoClub.txt");
    menuCliente();
}

void mostrarListaPeliculas(){
    char codPelicula[5],  tituloPelicula[20], prductora[20], categoria[20],ubicacion[20];
    int anyo, i;
    int contador = 0;


    FILE *ficheroOrigen = fopen("ListaPeliculas.txt", "r");
    if (ficheroOrigen == NULL) {
        printf("--Error al intentar abrir el fichero--\n");
    }
    while (fscanf(ficheroOrigen, "%[^,],%[^,],%[^,],%[^,],%i,%[^\n]\n", codigoPelicula, tituloPelicula, productora, categoria, anyo, ubicacion) != EOF){
        contador++;
        for (i = 0; i < contador; i++){

        }
    }




    }
