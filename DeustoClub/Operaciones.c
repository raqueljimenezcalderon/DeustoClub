//
// Created by Pablo Gaviria Lengaran on 2019-04-06.
//
#include <stdio.h>
#include <stdlib.h>
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

    fflush(stdout);
    scanf("%i", &respuesta1);

    switch (respuesta1) {
        case 1:
            elegirTipoInicio();
            break;
        case 2:
            anyadirNuevoCliente();
            break;
        case 3:
            contraOlvidada();
            break;
        case 4:
            mostrarInformacionVideoClub();
            break;
        case 5:
            printf("¿Esta seguro de que desea salir?\n");
            printf("\t1. Si, si deseo salir\n");
            printf("\t2. No, no deseo salir\n");
            fflush(stdout);	scanf("%i", &respuesta2);
            switch (respuesta2){
                case 1:
                    exit(0);
                    break;
                case 2:
                    inicioApp();
                    break;
                default:
                    printf("--Caracter no valido--\n");
                    inicioApp();
                    break;
            }
            break;
        default:
            printf("--Caracter no valido--\n");
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

    fflush(stdout);
    scanf("%i", &respuesta1);

    switch (respuesta1) {
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
            printf("\t2. No, no deseo salir\n");
            fflush(stdout);	scanf("%i", &respuesta2);
            switch (respuesta2){
                case 1:
                    exit(0);
                    break;
                case 2:
                    inicioApp();
                    break;
                default:
                    printf("--Opcion no valida--\n");
                    inicioApp();
                    break;
            }
            break;
        default:
            printf("--Opcion no valida--\n");
            iniciarSesion(); break;
    }
}


void mostrarInformacionVideoClub() {

    FILE *fichero = fopen("informacionDeustoClub.txt", "r");
    if (fichero == NULL) {
        printf("--Error al intentar abrir el fichero--\n");
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
        fflush(stdout); scanf("%i", &respuesta);
        if (respuesta == 0) {
            inicioApp();
        } else {
            printf("--Caracter no valido--\n");
        }
    } while (respuesta != 0);
}

void contraOlvidada() {

    Usuario usuario;
    Trabajador trabajador;
    FILE *fichero;
    char respuesta;
    printf("Indica si eres usuario ->(U) o un trabajador ->(T) ");
    fflush(stdout);
    scanf(" %c", &respuesta);
    fflush(stdout);

    if ((respuesta == 'u') || (respuesta == 'U')) {
        fichero = fopen("clientesDeustoClub.txt", "r");
        if (fichero == NULL ) {
            printf("--Error al intentar abrir el fichero--\n");
        }

        printf("Por favor, indicanos tu DNI: ");
        char dni[10], email[40];
        fflush(stdout);
        scanf("%s", dni);
        printf("Por favor, indicanos tu email: ");
        fflush(stdout);
        scanf("%s", email);

        int escorrecto = 0;
        while (!feof(fichero)) {
            fscanf(fichero,
                   "%[^,],%[^,],%[^,],%[^,],%[^,],%ld,%c,%[^,],%[^\n]\n",
                   usuario.DNI, usuario.nombre, usuario.apellido,
                   usuario.email, usuario.direccion, &usuario.telefono,
                   &usuario.sexo, usuario.contrasena,
                   usuario.numTarjetaCredito);
            if ((strcmp(dni, usuario.DNI) == 0)
                && (strcmp(email, usuario.email) == 0)) {
                printf("Esta es tu contrasenya: %s\n", usuario.contrasena);
                escorrecto = 1;
                printf("Salir ->0\n");
                int respuesta2;
                do {
                    fflush(stdout); scanf("%i", &respuesta2);
                    if (respuesta2 == 0) {inicioApp()();
                    } else {printf("--Caracter no valido--\n");}
                } while (respuesta2 != 0);
            }
        }
        if (escorrecto == 0) {
            printf("--El DNI y contrasena no existen--\n");
            contraOlvidada();
        }
    } else if ((respuesta == 't') || (respuesta == 'T')) {
        fichero = fopen("trabajadoresDesutoClub.txt", "r");
        if (fichero == NULL ) {
            printf("--Error al intentar abrir el fichero--\n");
        }

        printf("Por favor, indicanos tu DNI: ");
        char dni[10], email[40];
        fflush(stdout);
        scanf("%s", dni);
        printf("Por favor, indicanos tu email: ");
        fflush(stdout);
        scanf("%s", email);

        int escorrecto = 0;
        while (!feof(fichero)) {
            fscanf(fichero,
                   "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%ld,%c,%[^,],%f,%[^\n]\n",
                   trabajador.usuario.DNI, trabajador.usuario.nombre,
                   trabajador.usuario.apellido, trabajador.usuario.email,
                   trabajador.usuario.direccion, trabajador.usuario.telefono,
                   &trabajador.usuario.sexo, trabajador.cargo,
                   &trabajador.salario, trabajador.numCuentaBancaria,
                   trabajador.numSeguridadSocial,
                   trabajador.usuario.contrasena,
                   trabajador.usuario.numTarjetaCredito);
            if ((strcmp(dni, trabajador.usuario.DNI) == 0)
                && (strcmp(email, trabajador.usuario.email) == 0)) {
                printf("Esta es tu contrasenya: %s\n",
                       trabajador.usuario.contrasena);
                escorrecto = 1;
                printf("Salir ->0\n");
                int respuesta;
                do {
                    fflush(stdout); scanf("%i", &respuesta);
                    if (respuesta == 0) {inicioApp();
                    } else {printf("--Caracter no valido--\n");}
                } while (respuesta != 0);
            }
        }
        if (escorrecto == 0) {
            printf("--El DNI y contrasena no existen--\n");
            contraOlvidada();
        }
    } else {
        printf("--Error al intentar abrir el fichero--\n");
        contraOlvidada();
    }
}





