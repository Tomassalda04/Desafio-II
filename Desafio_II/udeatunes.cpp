#include "udeaTunes.h"
#include <iostream>
#include <cstdlib>
#include "funciones.h"
using namespace std;

udeatunes::udeatunes() {
    usuarios = nullptr;
    artistas = nullptr;
    albums = nullptr;
    canciones = nullptr;
    mensajes = nullptr;
    colaboradores = nullptr;
    listaCreditos = nullptr;

    numUsuarios = 0;
    numArtistas = 0;
    numAlbums = 0;
    numCanciones = 0;
    numMensajes = 0;
    numColaboradores = 0;
    numCreditos = 0;

    cargarUsuarios(usuarios, numUsuarios);
    cargarArtistas(artistas, numArtistas);
    cargarAlbums(albums, numAlbums, artistas, numArtistas);
    cargarCanciones(canciones, numCanciones, albums, numAlbums);
    cargarPublicidad(mensajes, numMensajes);

    cargarFavoritos(usuarios, numUsuarios, canciones, numCanciones, "favoritos.txt");
    cargarSeguidos(usuarios, numUsuarios, "seguidos.txt");

}

udeatunes::~udeatunes() {

    delete[] usuarios;
    delete[] artistas;
    delete[] albums;
    delete[] canciones;
    delete[] mensajes;
    delete[] colaboradores;
    delete[] listaCreditos;
}

void udeatunes::iniciarSesion() {
    srand(static_cast<unsigned>(time(nullptr)));
    string nick;
    cout << "\nIngrese su nickname: ";
    cin >> nick;

    usuario* usr = nullptr;
    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i].getNickname() == nick) {
            usr = &usuarios[i];
            break;
        }
    }

    if (!usr) {
        cout << "Usuario no encontrado.\n";
        return;
    }

    cout << "Bienvenido, " << usr->getNickname() << "!\n";
    if (usr->getPremium()) {
        menuUsuarioPremium(usr, usuarios, numUsuarios, canciones, numCanciones,numArtistas, numAlbums, numMensajes);
    } else {
        menuUsuarioEstandar(usr, canciones, numCanciones, mensajes, numMensajes,numArtistas, numAlbums, numMensajes);
    }
}

void udeatunes::menuPrincipal() {
    char opcion = 0;
    do {
        cout << "\n===== UdeATunes =====\n";
        cout << "1. Iniciar sesion\n";
        cout << "2. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case '1':
            iniciarSesion();
            break;
        case '2':
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opción invalida.\n";
        }
    } while (opcion != 2);
}



