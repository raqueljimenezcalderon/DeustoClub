//
// Created by Pablo Gaviria Lengaran on 2019-04-06.
//


#include <stdio.h>
#include <stlib.h>
#include "Personas.h"
#include "Peliculas.h"

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
            mostrarPerfilCliente();
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
            anyadirNuevaPelicula();
            break;
        case 2:
            elimimarPelicula();
            break;
        case 3:
            // Metodo Eliminar Usuario
            break;
        case 4:
            mostrarPerfilTrabajador(); //Falta hacer
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

void inicioSesionCliente() {

    Usuario cliente;
    char emailCliente[40], contrasenya[25];

    printf("Iniciar Sesion Modo Cliente:\n");
    printf("\tEmail: ");
    fflush(stdout); scanf("%s", emailCliente);
    printf("\tContrasena: ");
    fflush(stdout);	scanf("%s", contrasenya);

    FILE *fichero = fopen("ClientesDeustoClub.txt", "r");
    if (fichero == NULL) {
        printf("--Error al intentar abrir el fichero--\n");
    }

    int existe = 0;
    while (!feof(fichero)) {
        fscanf(fichero, "%[^,],%[^,],%[^,],%[^,],%[^,],%ld,%c,%[^,],%[^\n]\n", cliente.DNI, cliente.nombre, cliente.apellido, cliente.email, cliente.direccion, &cliente.telefono, &cliente.sexo, cliente.contrasena, cliente.numTarjetaCredito);
        fflush(stdout);
        if ((strcmp(emailCliente, cliente.email) == 0) && (strcmp(contrasenya, cliente.contrasena) == 0)) {
            menuCliente();
            existe = 1;
        }
    }
    if (existe == 0) {
        printf("--Email o contraseña incorrectos, vuelva a intentarlo--\n");
        inicioSesionCliente();
    }
}

void inicioSesionTrabajador() {
    Trabajadores trabajador;
    char emailTrabajador[40], contrasenya[25];

    printf("Iniciar Sesion Modo Trabajador\n");
    printf("\tEmail: ");
    fflush(stdout);	scanf("%s", emailTrabajador);
    printf("\tContrasena: ");
    fflush(stdout);	scanf("%s", contrasenya);

    FILE *fichero = fopen("TrabajadoresDeustoClub.txt", "r");
    if (fichero == NULL) {
        printf("**Error en apertura de fichero**\n");
    }

    int existe = 0;
    while (!feof(fichero)) {
        fscanf(fichero, "%[^,],%[^,],%[^,],%[^,],%[^,],%ld,%c,%[^,],%ld,%[^,],%[^,],%[^,],%[^\n]\n", trabajador.usuario.DNI, trabajador.usuario.nombre, trabajador.usuario.apellido, trabajador.usuario.email, trabajador.usuario.direccion, &trabajador.usuario.telefono, &trabajador.usuario.sexo, trabajador.cargo, &trabajador.salario, trabajador.numCuentaBancaria, trabajador.numSeguridadSocial, trabajador.usuario.contrasena, trabajador.usuario.numTarjetaCredito);
        if ((strcmp(emailTrabajador, trabajador.usuario.email) == 0) && (strcmp(contrasenya, trabajador.usuario.contrasena) == 0)) {
            menuTrabajador();
            existe = 1;
        }
    }
    if (existe == 0) {
        printf("--Email o contraseña incorrectos, vuelva a intentarlo--\n");
        inicioSesionTrabajador();
    }
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
            inicioApp();
        } else {
            printf("--Caracter no valido--\n");
        }
    } while (respuesta1 != 0);
}




