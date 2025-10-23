#include "album.h"
#include "cancion.h"
#include "artista.h"

album::album() {
    id = "";
    nombre = "";
    sello = "";
    fecha = "";
    puntuacion = 0;
    numCanciones = 0;
    canciones = nullptr;
    autor = nullptr;
}

album::album(string id, string nombre, string sello, string fecha,
             int puntuacion, int numCanciones, artista* autor) {
    this->id = id;
    this->nombre = nombre;
    this->sello = sello;
    this->fecha = fecha;
    this->puntuacion = puntuacion;
    this->numCanciones = numCanciones;
    this->autor = autor;
    canciones = (numCanciones > 0) ? new cancion[numCanciones] : nullptr;
}

album::album(const album& other) {
    id = other.id;
    nombre = other.nombre;
    sello = other.sello;
    fecha = other.fecha;
    puntuacion = other.puntuacion;
    numCanciones = other.numCanciones;
    autor = other.autor;

    if (numCanciones > 0) {
        canciones = new cancion[numCanciones];
        for (int i = 0; i < numCanciones; i++)
            canciones[i] = other.canciones[i];
    } else {
        canciones = nullptr;
    }
}

album::~album() {
    delete[] canciones;
}

album& album::operator=(const album& other) {
    if (this != &other) {
        delete[] canciones;
        id = other.id;
        nombre = other.nombre;
        sello = other.sello;
        fecha = other.fecha;
        puntuacion = other.puntuacion;
        numCanciones = other.numCanciones;
        autor = other.autor;

        if (numCanciones > 0) {
            canciones = new cancion[numCanciones];
            for (int i = 0; i < numCanciones; i++)
                canciones[i] = other.canciones[i];
        } else {
            canciones = nullptr;
        }
    }
    return *this;
}

string album::getId() const { return id; }
string album::getNombre() const { return nombre; }
string album::getSello() const { return sello; }
string album::getFecha() const { return fecha; }
int album::getPuntuacion() const { return puntuacion; }
int album::getNumCanciones() const { return numCanciones; }
artista* album::getAutor() const { return autor; }
cancion* album::getCanciones() const { return canciones; }

void album::setId(const string& i) { id = i; }
void album::setNombre(const string& n) { nombre = n; }
void album::setSello(const string& s) { sello = s; }
void album::setFecha(const string& f) { fecha = f; }
void album::setPuntuacion(int p) { puntuacion = p; }
void album::setAutor(artista* a) { autor = a; }

void album::agregarCancion(const cancion& nueva) {
    cancion* temp = new cancion[numCanciones + 1];
    for (int i = 0; i < numCanciones; i++)
        temp[i] = canciones[i];
    temp[numCanciones] = nueva;
    delete[] canciones;
    canciones = temp;
    numCanciones++;
}

void album::mostrarInfo() const {
    cout << "\nÁlbum: " << nombre
         << "\nID: " << id
         << "\nSello: " << sello
         << "\nFecha: " << fecha
         << "\nPuntuación: " << puntuacion
         << "\nNúmero de canciones: " << numCanciones << endl;
}
