//
// Created by Pablo Gaviria Lengaran on 2019-04-06.
//
#include <stdio.h>
#include <stlib.h>
#include "Operaciones.h"

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
            iniciarSesion();
            break;
        case 2:
            infoBiblio();
            break;
        case 3:
            olvidarContra();
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
            soyUsuario();
            break;
        case 2:
            soyTrabajador();
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
