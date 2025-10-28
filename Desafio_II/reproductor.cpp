#include "reproductor.h"
#include "album.h"
#include "artista.h"
#include "cancion.h"
#include <iostream>
#include <thread>
#include <chrono>
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
    if (!c) return;
    actual = c;
    reproduciendo = true;
    pausado = false;
    contadorReproducciones++;
    string rutaAudio = c->getRuta128();
    if (usr && usr->getPremium()) rutaAudio = c->getRuta320();
    album* alb = c->getAlbum();
    string rutaPortada = "";
    if (alb) {
        artista* art = alb->getAutor();
        if (art) rutaPortada = "/users/storage/" + art->getNombre() + "/image/" + alb->getNombre() + ".png";
    }
    cout << "Reproduciendo: " << c->getNombre() << " (" << c->getDuracion() << " min)" << endl;
    if (!rutaPortada.empty()) cout << "Ruta portada: " << rutaPortada << endl;
    cout << "Ruta audio: " << rutaAudio << endl;
}

void reproductor::pausar() {
    if (reproduciendo && !pausado) {
        pausado = true;
        cout << "Reproduccion pausada." << endl;
    } else {
        cout << "No hay reproduccion activa para pausar." << endl;
    }
}

void reproductor::reanudar() {
    if (pausado) {
        pausado = false;
        cout << "Reanudando reproduccion." << endl;
    } else {
        cout << "No hay reproduccion pausada." << endl;
    }
}

void reproductor::detener() {
    if (reproduciendo) {
        reproduciendo = false;
        pausado = false;
        actual = nullptr;
        cout << "Reproduccion detenida." << endl;
    } else {
        cout << "No hay reproduccion activa." << endl;
    }
}

void reproductor::subirVolumen() {
    if (volumen < 100) volumen += 10;
    if (volumen > 100) volumen = 100;
    cout << "Volumen: " << volumen << "%" << endl;
}

void reproductor::bajarVolumen() {
    if (volumen > 0) volumen -= 10;
    if (volumen < 0) volumen = 0;
    cout << "Volumen: " << volumen << "%" << endl;
}

void reproductor::alternarAleatorio() {
    aleatorio = !aleatorio;
    cout << "Modo aleatorio " << (aleatorio ? "activado" : "desactivado") << "." << endl;
}

void reproductor::mostrarEstado() const {
    cout << "=== Estado del Reproductor ===" << endl;
    if (actual)
        cout << "Cancion actual: " << actual->getNombre() << endl;
    else
        cout << "No hay cancion en reproduccion." << endl;
    cout << "Volumen: " << volumen << "%" << endl;
    cout << "Aleatorio: " << (aleatorio ? "Si" : "No") << endl;
    cout << "Reproducciones totales en sesion: " << contadorReproducciones << endl;
    cout << "Reproduciendo: " << (reproduciendo ? "Si" : "No") << endl;
    cout << "Pausado: " << (pausado ? "Si" : "No") << endl;
}

static int seleccionarPublicidad(publicidad* anuncios, int numAnuncios, int ultimo) {
    if (!anuncios || numAnuncios == 0) return -1;
    int totalPeso = 0;
    int pesos[100];
    for (int i = 0; i < numAnuncios; i++) {
        char c = anuncios[i].getCategoria();
        int peso = 1;
        if (c == 'A') peso = 3;
        else if (c == 'B') peso = 2;
        else peso = 1;
        pesos[i] = peso;
        totalPeso += peso;
    }
    if (totalPeso == 0) return -1;
    int intento = 0;
    while (intento < 10) {
        int r = rand() % totalPeso;
        int acum = 0;
        for (int i = 0; i < numAnuncios; i++) {
            acum += pesos[i];
            if (r < acum) {
                if (i != ultimo) return i;
                else break;
            }
        }
        intento++;
    }
    for (int i = 0; i < numAnuncios; i++) if (i != ultimo) return i;
    return 0;
}

void reproductor::reproducirAleatorio(cancion* lista, int total) {
    srand((unsigned)time(nullptr));
    if (!lista || total == 0) {
        cout << "No hay canciones disponibles en la lista global.\n";
        return;
    }
    cout << "\n=== Reproduccion aleatoria (5 canciones, 3 segundos c/u) ===\n" << endl;
    int ultimoAd = -1;
    for (int i = 0; i < 5; i++) {
        int index = rand() % total;
        cancion* seleccionada = &lista[index];
        reproducir(seleccionada);
        if (!usr || !usr->getPremium()) {
            if ((i + 1) % 2 == 0 && numAnuncios > 0) {
                int idxAd = seleccionarPublicidad(anuncios, numAnuncios, ultimoAd);
                if (idxAd >= 0) {
                    ultimoAd = idxAd;
                    cout << "----- PUBLICIDAD -----\n";
                    anuncios[idxAd].mostrar();
                    cout << "----------------------\n";
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    detener();
    cout << "\nReproduccion aleatoria finalizada.\n" << endl;
}
