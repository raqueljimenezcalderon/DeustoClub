//
// Created by Pablo Gaviria Lengaran on 2019-04-06.
//
#include <stdio.h>
#include <stlib.h>
#include "Operaciones.h"
#include "Personas.h"
#include "Peliculas.h"


void inicioApp() {
    int respuesta1, respuesta2;

    printf("DEUSTOCLUB TU VIDEOCLUB FAVORITO\n");
    printf("|| Elige una opcion ||\n");
    printf("\t1. Iniciar Sesion\n");
    printf("\t2. Deseo Registrarme")
    printf("\t3. Contrasena Olvidada\n");
    printf("\t4. Informacion de DeustoClub\n");
    printf("\t5. Cerrar Aplicacion\n");

    fflush(stdout);	scanf("%i", &respuesta1);

    switch (respuesta1) {
        case 1:
            elegirTipoInicio();
            break;
        case 2:
            anyadirNuevoCliente();
            break;
        case 3:
            //Metodo Contrasenya Olvidada
            break;
        case 4:
            mostrarInformacionVideoClub();
            break;
        case 5:
            printf("¿Esta seguro de que desea salir?\n");
            printf("\t1. Si, si deseo salir\n");
            printf("\t2. No, no deseo salir\n")
            fflush(stdout);	scanf("%i", &respuesta2);
            switch (respuesta2){
                case 1:
                    exit(0);
                    break;
                case 2:
                    inicioApp();
                    break;
                default:
                    printf("**Opcion no valida**\n");
                    inicioApp();
                    break;
            }
            break;
        default:
            printf("**Opcion no valida**\n");
            inicioApp();
            break;
    }
}

void elegirTipoInicio() {
    int respuesta1, respuesta2;

    printf("-- ¿Que tipo de usuario es? --\n");
    printf("\t1. Cliente\n");
    printf("\t2. Admin\n");
    printf("\t3. Volver al Menu Principal\n");
    printf("\t4. Salir\n");

    fflush(stdout);	scanf("%i", &respuesta1);

    switch (opcion) {
        case 1:
            inicioSesionCliente();
            break;
        case 2:
            inicioSesionTrabajador();
            break;
        case 3:
            inicioApp();
            break;
        case 4:
            printf("¿Esta seguro de que desea salir?\n");
            printf("\t1. Si, si deseo salir\n");
            printf("\t2. No, no deseo salir\n")
            fflush(stdout);	scanf("%i", &respuesta2);
            switch (respuesta2){
                case 1:
                    exit(0);
                    break;
                case 2:
                    inicioApp();
                    break;
                default:
                    printf("**Opcion no valida**\n");
                    inicioApp();
                    break;
            }
            break;
        default:
            printf("**Opcion erronea**\n");
            iniciarSesion(); break;
    }
}


void mostrarInformacionVideoClub() {

    FILE *fichero = fopen("informacionDeustoClub.txt", "r");
    if (fichero == NULL) {
        printf("**El fichero esta mal**\n");
    }

    //Variables metodo leer informacionDeustoClub.txt
    char nomVideoClub[20], dir[40], horarioSemana[20], horarioFestivos[20];
    long telefono = 0;

    //Metodo leer informacionDeustoClub.txt (informacion del videoClub)
    while (fscanf(fichero, "%[^,],%[^,],%ld,%[^,],%[^,]", nomVideoClub, dir, &telefono, horarioSemana, horarioFestivos) != EOF) {
        printf("--Datos de tu VideoClub favorito--\n");
        printf("\n\t**%s**", nomVideoClub);
        printf("\n\tDir: %s", dir);
        printf("\n\tTFNO: %ld", telefono);
        printf("\n\tHorario Semana: %s", horarioSemana);
        printf("\n\tHorario Festivos: %s", horarioFestivos);
        printf("Volver al Menu Principal -> 0");
    }
    printf("\n");

    //Metodo volver menuPincipal:
    int respuesta;
    do {
        fflush(stdout); scanf("%i", &opcion);
        if (respuesta == 0) {
            inicioApp();
        } else {
            printf("--Caracter no valido--\n");
        }
    } while (respuesta != 0);
}




