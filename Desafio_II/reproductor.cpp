#include "reproductor.h"
#include "usuario.h"
#include "cancion.h"
#include "album.h"
#include "publicidad.h"
#include "artista.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


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
    if (!c) {
        cout << "No hay cancion seleccionada.\n";
        return;
    }

    actual = c;
    reproduciendo = true;
    pausado = false;
    contadorReproducciones++;

    cout << "\n===== REPRODUCIENDO =====\n";
    cout << "Cantante: ";
    if (c->getAlbum() && c->getAlbum()->getAutor())
        cout << c->getAlbum()->getAutor()->getNombre() << endl;
    else
        cout << "Desconocido\n";

    cout << "Album: ";
    if (c->getAlbum())
        cout << c->getAlbum()->getNombre() << endl;
    else
        cout << "Desconocido\n";

    cout << "Ruta del archivo: " << c->getRuta128() << endl;
    cout << "Duracion: " << c->getDuracion() << " segundos\n";
    cout << "==========================\n";
}

void reproductor::reproducirAleatorio(cancion* lista, int total) {
    if (!lista || total == 0) {
        cout << "No hay canciones disponibles.\n";
        return;
    }

    srand((unsigned)time(nullptr));
    int index = rand() % total;
    reproducir(&lista[index]);
}

void reproductor::pausar() {
    if (!reproduciendo) {
        cout << "No hay ninguna cancion reproduciendose.\n";
        return;
    }
    pausado = true;
    cout << "Cancion en pausa.\n";
}

void reproductor::reanudar() {
    if (!reproduciendo) {
        cout << "No hay ninguna cancion en reproduccion.\n";
        return;
    }
    if (!pausado) {
        cout << "La cancion ya esta en reproduccion.\n";
        return;
    }
    pausado = false;
    cout << "Reanudando cancion...\n";
}

void reproductor::detener() {
    if (!reproduciendo) {
        cout << "No hay ninguna cancion en reproduccion.\n";
        return;
    }
    reproduciendo = false;
    pausado = false;
    actual = nullptr;
    cout << "Reproductor detenido.\n";
}

void reproductor::subirVolumen() {
    if (volumen < 100) {
        volumen += 10;
        cout << "Volumen: " << volumen << "%\n";
    } else {
        cout << "Volumen al maximo.\n";
    }
}

void reproductor::bajarVolumen() {
    if (volumen > 0) {
        volumen -= 10;
        cout << "Volumen: " << volumen << "%\n";
    } else {
        cout << "Volumen al minimo.\n";
    }
}

void reproductor::alternarAleatorio() {
    aleatorio = !aleatorio;
    cout << (aleatorio ? "Modo aleatorio activado.\n" : "Modo aleatorio desactivado.\n");
}


void reproductor::mostrarEstado() const {
    cout << "\n=== ESTADO DEL REPRODUCTOR ===\n";
    if (actual)
        cout << "Reproduciendo: " << actual->getNombre() << endl;
    else
        cout << "Sin cancion actual.\n";

    cout << "Volumen: " << volumen << "%\n";
    cout << "Estado: ";
    if (reproduciendo)
        cout << (pausado ? "Pausado" : "Reproduciendo") << endl;
    else
        cout << "Detenido\n";
    cout << "==============================\n";
}

void reproductor::mostrarEstado(bool detalle) const {
    cout << "\n=== ESTADO DEL REPRODUCTOR ===\n";

    if (actual)
        cout << "Cancion: " << actual->getNombre() << endl;
    else
        cout << "Sin cancion actual.\n";

    cout << "Volumen: " << volumen << "%\n";

    if (detalle) {
        cout << "Estado: ";
        if (reproduciendo)
            cout << (pausado ? "Pausado" : "Reproduciendo") << endl;
        else
            cout << "Detenido\n";

        cout << "Modo aleatorio: " << (aleatorio ? "Activo" : "Inactivo") << endl;
        cout << "Reproducciones totales: " << contadorReproducciones << endl;
        if (usr)
            cout << "Usuario actual: " << usr->getNickname() << endl;
    }

    cout << "==============================\n";
}
