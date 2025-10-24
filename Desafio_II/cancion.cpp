#include "cancion.h"
#include "album.h"
#include <iostream>
using namespace std;

cancion::cancion() {
    id = "";
    nombre = "";
    ruta128 = "";
    ruta320 = "";
    duracion = 0.0;
    reproducciones = 0;
    infoCreditos = nullptr;
    alb = nullptr;
}

cancion::cancion(string id, string nombre, string ruta128, string ruta320,
                 float duracion, int reproducciones, album* alb) {
    this->id = id;
    this->nombre = nombre;
    this->ruta128 = ruta128;
    this->ruta320 = ruta320;
    this->duracion = duracion;
    this->reproducciones = reproducciones;
    this->alb = alb;
    this->infoCreditos = nullptr;
}

cancion::cancion(const cancion& other) {
    id = other.id;
    nombre = other.nombre;
    ruta128 = other.ruta128;
    ruta320 = other.ruta320;
    duracion = other.duracion;
    reproducciones = other.reproducciones;
    alb = other.alb;
    infoCreditos = other.infoCreditos;
}

cancion::~cancion() {
    // no se borra alb ni infoCreditos, solo se desconecta
    alb = nullptr;
    infoCreditos = nullptr;
}

cancion& cancion::operator=(const cancion& other) {
    if (this != &other) {
        id = other.id;
        nombre = other.nombre;
        ruta128 = other.ruta128;
        ruta320 = other.ruta320;
        duracion = other.duracion;
        reproducciones = other.reproducciones;
        alb = other.alb;
        infoCreditos = other.infoCreditos;
    }
    return *this;
}

string cancion::getId() const { return id; }
string cancion::getNombre() const { return nombre; }
string cancion::getRuta128() const { return ruta128; }
string cancion::getRuta320() const { return ruta320; }
float cancion::getDuracion() const { return duracion; }
int cancion::getReproducciones() const { return reproducciones; }
album* cancion::getAlbum() const { return alb; }

void cancion::setId(const string& i) { id = i; }
void cancion::setNombre(const string& n) { nombre = n; }
void cancion::setRuta128(const string& r) { ruta128 = r; }
void cancion::setRuta320(const string& r) { ruta320 = r; }
void cancion::setDuracion(float d) { duracion = d; }
void cancion::setReproducciones(int r) { reproducciones = r; }
void cancion::setAlbum(album* a) { alb = a; }

void cancion::mostrarInfo() const {
    cout << "\nCanción: " << nombre
         << "\nID: " << id
         << "\nDuración: " << duracion << " min"
         << "\nReproducciones: " << reproducciones
         << "\nRuta (128 kbps): " << ruta128
         << "\nRuta (320 kbps): " << ruta320
         << endl;
}
