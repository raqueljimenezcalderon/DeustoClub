//
// Created by Pablo Gaviria Lengaran on 2019-04-06.
//

#include "Personas.h"
#include <stdio.h>
#include <stlib.h>

void menuCliente() {
    int respuesta1, respuesta2;

    printf("--¿Que desea realizar?--\n");
    printf("\t1. Mostrar Peliculas Disponibles\n");
    printf("\t2. Devolver una Pelicula\n");
    printf("\t3. Visualizar Perfil Personal\n");
    printf("\t4. Cerrar sesion\n");
    fflush(stdout); scanf("%i", &respuesta1);

    switch (respuesta1) {
        case 1:
            //Metodo Mostrar Peliculas Disponibles
            break;
        case 2:
            //Metodo Devolver Pelicula
            break;
        case 3:
            //Mostrar Perfil
            break;
        case 4:
            printf("¿Esta seguro de que desea cerrar sesion?\n");
            printf("\t1. Si, si deseo cerrar sesion\n");
            printf("\t2. No, no deseo cerrar sesion\n")
            fflush(stdout);	scanf("%i", &respuesta2);
            switch (respuesta2){
                case 1:
                    inicioApp();
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
            printf("**Opcion incorrecta**\n");
            inicioCorrectoUsuario(); break;
    }
}

void menuTrabajador() {
    int respuesta1, respuesta2;

    printf("--¿Que desea realizar?--\n");
    printf("\t1. Registrar Nueva Pelicula\n");
    printf("\t2. Eliminar Pelicula Obsoleta\n");
    printf("\t3. Eliminar Usuario\n");
    printf("\t4. Visualizar Perfil Personal\n");
    printf("\t5. Cerrar sesion\n");
    fflush(stdout);
    scanf("%i", &respuesta1);

    switch (respuesta1) {
        case 1:
            // Metodo Registrar Nueva Pelicula
            break;
        case 2:
            // Metodo Eliminar Pelicula Obsoleta
            break;
        case 3:
            // Metodo Eliminar Usuario
            break;
        case 4:
            // Metodo Visualizar Perfil Usuario
            break;
        case 5:
            printf("¿Esta seguro de que desea cerrar sesion?\n");
            printf("\t1. Si, si deseo cerrar sesion\n");
            printf("\t2. No, no deseo cerrar sesion\n")
            fflush(stdout);	scanf("%i", &respuesta2);
            switch (respuesta2){
                case 1:
                    inicioApp();
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
            inicioCorrectoTrabajador();	break;
    }
}



