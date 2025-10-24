#include "reproductor.h"

reproductor::reproductor() {
    actual = nullptr;
    usr = nullptr;
    anuncios = nullptr;
    numAnuncios = 0;
    contadorReproducciones = 0;
    reproduciendo = false;
    pausado = false;
    aleatorio = false;
    volumen = 50;
}

void reproductor::setUsuario(usuario* u) {
    usr = u;
}

void reproductor::setPublicidad(publicidad* a, int n) {
    anuncios = a;
    numAnuncios = n;
}

void reproductor::reproducir(cancion* c) {
    if (!usr) {
        cout << "No hay usuario asignado al reproductor.\n";
        return;
    }

    if (c == nullptr) {
        cout << "No hay canción seleccionada.\n";
        return;
    }

    if (!usr->getPremium()) {
        contadorReproducciones++;
        if (contadorReproducciones % 2 == 0 && anuncios && numAnuncios > 0) {
            int idx = rand() % numAnuncios;
            cout << "\n--- ANUNCIO PUBLICITARIO ---\n";
            anuncios[idx].mostrar();
            cout << "----------------------------\n";
        }
    }

    actual = c;
    reproduciendo = true;
    pausado = false;

    cout << "Reproduciendo: [nombre de la canción]" << endl;
}

void reproductor::pausar() {
    if (!reproduciendo) {
        cout << "No hay ninguna canción en reproducción.\n";
        return;
    }
    pausado = true;
    cout << "Canción pausada.\n";
}

void reproductor::reanudar() {
    if (reproduciendo && pausado) {
        pausado = false;
        cout << "Reanudando canción...\n";
    } else {
        cout << "No hay canción pausada para reanudar.\n";
    }
}

void reproductor::detener() {
    if (!reproduciendo) {
        cout << "No hay ninguna canción en reproducción.\n";
        return;
    }
    reproduciendo = false;
    actual = nullptr;
    cout << "Reproducción detenida.\n";
}

void reproductor::subirVolumen() {
    if (volumen < 100) volumen += 10;
    if (volumen > 100) volumen = 100;
    cout << "Volumen: " << volumen << "%\n";
}

void reproductor::bajarVolumen() {
    if (volumen > 0) volumen -= 10;
    if (volumen < 0) volumen = 0;
    cout << "Volumen: " << volumen << "%\n";
}

void reproductor::alternarAleatorio() {
    aleatorio = !aleatorio;
    cout << "Modo aleatorio " << (aleatorio ? "activado" : "desactivado") << ".\n";
}

void reproductor::mostrarEstado() const {
    cout << "\n--- ESTADO DEL REPRODUCTOR ---\n";
    if (usr) cout << "Usuario: " << usr->getNickname() << " ("
             << (usr->getPremium() ? "Premium" : "Estándar") << ")\n";
    if (actual) cout << "Canción actual: [nombre de la canción]" << endl;
    cout << "Reproduciendo: " << (reproduciendo ? "Sí" : "No") << endl;
    cout << "Pausado: " << (pausado ? "Sí" : "No") << endl;
    cout << "Modo aleatorio: " << (aleatorio ? "Activado" : "Desactivado") << endl;
    cout << "Volumen: " << volumen << "%" << endl;
    cout << "-------------------------------\n";
}
