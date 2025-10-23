#include "udeaTunes.h"

udeaTunes::udeaTunes() {
    usuarios = nullptr;
    artistas = nullptr;
    mensajes = nullptr;
    usuarioActual = nullptr;
    numUsuarios = numArtistas = numMensajes = 0;

    cargarUsuarios(usuarios, numUsuarios);
    cargarArtistas(artistas, numArtistas);
    cargarPublicidad(mensajes, numMensajes);
}

udeaTunes::~udeaTunes() {
    guardarUsuarios(usuarios, numUsuarios);
    delete[] usuarios;
    delete[] artistas;
    delete[] mensajes;
}

void udeaTunes::menuPrincipal() {
    int opcion;
    do {
        cout << "\n===== UDEATUNES =====\n";
        cout << "1. Iniciar sesión\n";
        cout << "2. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            iniciarSesion();
            break;
        case 2:
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opción inválida.\n";
        }

    } while (opcion != 2);
}

void udeaTunes::iniciarSesion() {
    string nick;
    cout << "\nIngrese su nickname: ";
    cin >> nick;

    bool encontrado = false;
    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i].getNickname() == nick) {
            usuarioActual = &usuarios[i];
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << " Usuario no encontrado.\n";
        return;
    }

    cout << " Bienvenido, " << usuarioActual->getNickname() << " (" << (usuarioActual->getPremium() ? "Premium" : "Estándar") << ")\n";

    menuUsuario(usuarioActual);
}

// ========== MENÚ DE USUARIO ==========
void udeaTunes::menuUsuario(usuario* u) {
    int opcion;
    do {
        cout << "\n===== MENÚ DE USUARIO =====\n";
        cout << "1. Ver información personal\n";
        cout << "2. Cerrar sesión\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "\n--- Información de usuario ---\n";
            cout << "Nickname: " << u->getNickname() << endl;
            cout << "Ciudad: " << u->getCiudad() << endl;
            cout << "País: " << u->getPais() << endl;
            cout << "Fecha registro: " << u->getFechaRegistro() << endl;
            cout << "Tipo: " << (u->getPremium() ? "Premium" : "Estándar") << endl;
            break;

        case 2:
            cout << "Cerrando sesión...\n";
            usuarioActual = nullptr;
            break;

        default:
            cout << "Opción inválida.\n";
        }
    } while (opcion != 2);
}
