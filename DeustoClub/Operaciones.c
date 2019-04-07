//
// Created by Pablo Gaviria Lengaran on 2019-04-06.
//
#include <stdio.h>
#include <stlib.h>
#include "Operaciones.h"
#include "Personas.h"

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
            //Metodo Entrar Como Usuario
            break;
        case 2:
            //Metodo Entar Como Trabajador
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

void anyadirNuevoCliente() {

    char DNICliente[10], nomCliente[20], apellCliente[20], email[40], dir[40], contrasenya[10], numTarjetaCred[16];
    long TFNO;
    char sexo;

    fflush(stdin);
    printf("Introduce el DNI completo: ");
    fflush(stdout);
    gets(DNICliente);
    printf("Introduce el nombre de usuario: ");
    fflush(stdout);
    gets(nomCliente);
    printf("Introduce el apellido: ");
    fflush(stdout);
    gets(apellCliente);
    printf("Introduce el email: ");
    fflush(stdout);
    gets(email);
    printf("Introduce la direccion: ");
    fflush(stdout);
    gets(dir);
    printf("Introduce el telefono: ");
    fflush(stdout);
    scanf("%ld", &TFNO);
    printf("Introduce el sexo (H - hombre; M - Mujer; O - Otro): ");
    fflush(stdout);
    scanf(" %c", &sexo);
    fflush(stdin);
    printf("Introduce la contrasena: ");
    fflush(stdout);
    gets(contrasenya);
    printf("Introduce el numero de tarjeta de credito: ");
    fflush(stdout);
    gets(numTarjetaCred);
    printf("\n");

    FILE *fichero = fopen("clientesDeustoClub.txt", "a");
    if (fichero == NULL) {
        printf("--Error al intentar abrir el fichero--");
    }

    fprintf(fichero, "%s, %s, %s, %s, %s, %s, %ld, %c, %s, %s\n", DNI, nomCliente, apellCliente, email, dir, TFNO, sexo, numTarjetaCred, contrasena);

    fclose(fichero);

    printf("El cliente se ha registrado correctamente. Menu de inicio -> 0\n");
    int respuesta1;
    do {
        fflush(stdout); scanf("%i", &respuesta1);
        if (respuesta1 == 0) {
            inicioCorrectoTrabajador();
        } else {
            printf("--Caracter no valido--\n");
        }
    } while (respuesta1 != 0);
}


