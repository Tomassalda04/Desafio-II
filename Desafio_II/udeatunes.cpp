#include "udeaTunes.h"

udeaTunes::udeaTunes() {
    usuarios = nullptr;
    artistas = nullptr;
    mensajes = nullptr;
    colaboradores = nullptr;
    listaCreditos = nullptr;

    numUsuarios = numArtistas = numMensajes = 0;
    numColaboradores = numCreditos = 0;

    cargarUsuarios(usuarios, numUsuarios);
    cargarArtistas(artistas, numArtistas);
    cargarPublicidad(mensajes, numMensajes);

    cargarColaboradores(colaboradores, numColaboradores);
    cargarCreditos(listaCreditos, numCreditos, colaboradores, numColaboradores);
}


udeaTunes::~udeaTunes() {
    delete[] usuarios;
    delete[] artistas;
    delete[] mensajes;
    delete[] colaboradores;
    delete[] listaCreditos;
}

void udeaTunes::menuPrincipal() {
    char opcion;
    do {
        cout << "\n===== MENU PRINCIPAL - UdeATunes =====\n";
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
            cout << "Opcion invalida.\n";
        }
    } while (opcion != '2');
}

void udeaTunes::iniciarSesion() {
    string nombre;
    cout << "\nIngrese su nickname: ";
    cin >> nombre;

    usuario* usuarioActual = nullptr;
    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i].getNickname() == nombre) {
            usuarioActual = &usuarios[i];
            break;
        }
    }

    if (usuarioActual == nullptr) {
        cout << "Usuario no encontrado.\n";
        return;
    }

    cout << "Bienvenido, " << usuarioActual->getNickname() << "!\n";

    if (usuarioActual->getPremium()) {
        menuUsuarioPremium(usuarioActual);
    } else {
        menuUsuarioEstandar(usuarioActual, mensajes, numMensajes);
    }
}


