//
// Created by Pablo Gaviria Lengaran on 2019-04-06.
//


#include <stdio.h>
#include <stdlib.h>
#include "Personas.h"
#include "Peliculas.h"
#include "Operaciones.h"

void menuCliente() {
    int respuesta1, respuesta2;

    printf("--¿Que desea realizar?--\n");
    printf("\t1. Mostrar Peliculas Disponibles\n");
    printf("\t2. Devolver una Pelicula\n");
    printf("\t3. Visualizar Perfil Personal\n");
    printf("\t4. Cerrar sesion\n");
    fflush(stdout);
    scanf("%i", &respuesta1);

    switch (respuesta1) {
        case 1:
            mostrarListaPeliculas();
            break;
        case 2:
            devolverPelicula();
            break;
        case 3:
            mostrarPerfilCliente();
            break;
        case 4:
            printf("¿Esta seguro de que desea cerrar sesion?\n");
            printf("\t1. Si, si deseo cerrar sesion\n");
            printf("\t2. No, no deseo cerrar sesion\n");
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

            break;
        case 4:
            mostrarPerfilTrabajador();
            break;
        case 5:
            printf("¿Esta seguro de que desea cerrar sesion?\n");
            printf("\t1. Si, si deseo cerrar sesion\n");
            printf("\t2. No, no deseo cerrar sesion\n");
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
    fflush(stdout);
    scanf("%s", emailCliente);
    printf("\tContrasena: ");
    fflush(stdout);
    scanf("%s", contrasenya);

    FILE *fichero = fopen("clientesDeustoClub.txt", "r");
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

    FILE *fichero = fopen("trabajadoresDeustoClub.txt", "r");
    if (fichero == NULL) {
        printf("--Error al intentar abrir el fichero--\n");
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

    fprintf(fichero, "%s, %s, %s, %s, %s, %s, %ld, %c, %s, %s\n", DNICliente, nomCliente, apellCliente, email, dir, TFNO, sexo, numTarjetaCred, contrasenya);

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

void mostrarPerfilUsuario(char DNIMostrar){
    Usuario cliente;

    FILE *fichero = fopen("clientesDeustoClub.txt", "r");
    if (fichero == NULL) {
        printf("--Error al intentar abrir el fichero--\n");
    }

    int existe = 0;
    while (fscanf(fichero, "%[^,],%[^,],%[^,],%[^,],%[^,],%ld,%c,%[^,],%[^\n]\n", cliente.DNI, cliente.nombre, cliente.apellido, cliente.email, cliente.direccion, &cliente.telefono, &cliente.sexo, cliente.contrasena, cliente.numTarjetaCredito) != EOF) {
        if (strcmp(DNIMostrar, cliente.DNI) == 0) {
            printf("Perfil de %s %s\n", cliente.nombre, cliente.apellido);
            printf("\n\tDNI: %s", cliente.DNI);
            printf("\n\tNombre: %s", cliente.nombre);
            printf("\n\tApellido: %s", cliente.apellido);
            printf("\n\tEmail: %s", cliente.email);
            printf("\n\tDireccion: %s", cliente.direccion);
            printf("\n\tTelefono: %ld", cliente.telefono);
            printf("\n\tSexo: %c", cliente.sexo);
            printf("\n\tContrasena: %s", cliente.contrasena);
            printf("\n\tNumero de tarjeta de crédito: %s", cliente.numTarjetaCredito);
            printf("Menu Cliente -> 0\n");
            existe = 1;
        }
    }
    if(existe == 0) {
        printf("Este usuario no existe\n");
        perfilUsuario();
    }
    printf("\n");

    int respuesta;
    do {
        fflush(stdout); scanf("%i", &respuesta);
        if (respuesta == 0) { inicioCorrectoUsuario();
        } else {
            printf("--Caracter no valido--\n");
        }
    } while (respuesta != 0);
}

void mostrarPerfilTrabajador(DNIMostrar){
    Trabajadores trabajador;

    FILE *fichero = fopen("trabajadoresDeustoClub.txt", "r");
    if (fichero == NULL) {
        printf("--Error al intentar abrir el fichero--\n");
    }

    int existe = 0;
    while (fscanf(fichero, "%[^,],%[^,],%[^,],%[^,],%[^,],%ld,%c,%[^,],%ld,%[^,],%[^,],%[^,],%[^\n]\n", trabajador.usuario.DNI, trabajador.usuario.nombre, trabajador.usuario.apellido, trabajador.usuario.email, trabajador.usuario.direccion, &trabajador.usuario.telefono, &trabajador.usuario.sexo, trabajador.cargo, &trabajador.salario, trabajador.numCuentaBancaria, trabajador.numSeguridadSocial, trabajador.usuario.contrasena, trabajador.usuario.numTarjetaCredito)!= EOF) {
        if (strcmp(DNIMostrar, trabajador.usuario.DNI) == 0) {
            printf("Perfil de %s %s\n", trabajador.usuario.nombre, trabajador.usuario.apellido);
            printf("\n\tDNI: %s", trabajador.usuario.DNI);
            printf("\n\tNombre: %s", trabajador.usuario.nombre);
            printf("\n\tEmail: %s", trabajador.usuario.email);
            printf("\n\tDireccion: %s", trabajador.usuario.direccion);
            printf("\n\tTelefono: %ld", trabajador.usuario.telefono);
            printf("\n\tSexo: %c", trabajador.usuario.sexo);
            printf("\n\tCargo: %s", trabajador.cargo);
            printf("\n\tSalario: %ld", trabajador.salario);
            printf("\n\tNumero de cuenta Bancaria: %s", trabajador.numCuentaBancaria);
            printf("\n\tNSS: %s", trabajador.numSeguridadSocial);
            printf("\n\tContraseña: %s", trabajador.usuario.contrasena);
            printf("\n\tNumero de tarjeta de credito: %s,", trabajador.usuario.numTarjetaCredito);
            printf("Menu Trabajador -> 0 \n");
            existe = 1;
        }
    }
    if(existe == 0) {
        printf("Este usuario no existe\n");
        perfilUsuario();
    }
    printf("\n");

    int respuesta;
    do {
        fflush(stdout); scanf("%i", &respuesta);
        if (respuesta == 0) { inicioCorrectoUsuario();
        } else {
            printf("--Caracter no valido--\n");
        }
    } while (respuesta != 0);
}

void eliminarUsuario() {
    char DNI[10], email[40], contrasena[25], nombre[20], apellido[20],
            direccion[40], numTarjetaCredito[16];
    long telefono;
    char sexo;
    FILE *ficheroOrigen = fopen("clientesDeustoClub.txt", "r");
    if (ficheroOrigen == NULL ) {
        printf("--Error al intentar abrir el fichero--\n");
    }
    FILE *ficheroDestino = fopen("aux.txt", "w");
    if (ficheroDestino == NULL ) {
        printf("--Error al intentar abrir el fichero--\n");
    }

    char DNIBuscar[10];
    printf("Introduce el DNI del usuario que quieres eliminar: ");
    fflush(stdout);
    scanf("%s", DNIBuscar);
    rewind(ficheroOrigen);
    int eliminado = 0;
    while (fscanf(ficheroOrigen, "%[^,],%[^,],%[^,],%[^,],%[^,],%ld,%c,%[^,],%[^\n]\n", DNI, nombre, apellido, email, direccion, &telefono, &sexo, contrasena, numTarjetaCredito) != EOF) {
        if (strcmp(DNI, DNIBuscar) != 0) {
            fprintf(ficheroDestino, "%s,%s,%s,%s,%s,%ld,%c,%s\n", DNI, nombre, apellido, email, direccion, telefono, sexo, contrasena, numTarjetaCredito);
        } else {
            eliminado = 1;
        }
    }
    if (eliminado == 0) {
        printf("El usuario no existe\n");
        eliminarUsuario();
    }

    fclose(ficheroOrigen);
    fclose(ficheroDestino);
    remove("clientesDeustoClub.txt");
    rename("aux.txt", "clientesDeustoClub.txt");

    printf("Usuario eliminado.\n");
    menuTrabajador();
}