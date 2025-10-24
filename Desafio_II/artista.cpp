#include "artista.h"

artista::artista() {
    id = "";
    nombre = "";
    pais = "";
    edad = seguidores = posicion = numAlbums = 0;
    albums = nullptr;
}

artista::artista(string id, string nombre, string pais,
                 unsigned int edad, unsigned int seguidores,
                 unsigned int posicion, unsigned int numAlbums) {
    this->id = id;
    this->nombre = nombre;
    this->pais = pais;
    this->edad = edad;
    this->seguidores = seguidores;
    this->posicion = posicion;
    this->numAlbums = numAlbums;
    albums = (numAlbums > 0) ? new album[numAlbums] : nullptr;
}

artista::artista(const artista& other) {
    id = other.id;
    nombre = other.nombre;
    pais = other.pais;
    edad = other.edad;
    seguidores = other.seguidores;
    posicion = other.posicion;
    numAlbums = other.numAlbums;
    if (numAlbums > 0) {
        albums = new album[numAlbums];
        for (unsigned int i = 0; i < numAlbums; i++)
            albums[i] = other.albums[i];
    } else {
        albums = nullptr;
    }
}

artista::~artista() {
    delete[] albums;
}

artista& artista::operator=(const artista& other) {
    if (this != &other) {
        delete[] albums;
        id = other.id;
        nombre = other.nombre;
        pais = other.pais;
        edad = other.edad;
        seguidores = other.seguidores;
        posicion = other.posicion;
        numAlbums = other.numAlbums;

        if (numAlbums > 0) {
            albums = new album[numAlbums];
            for (unsigned int i = 0; i < numAlbums; i++)
                albums[i] = other.albums[i];
        } else {
            albums = nullptr;
        }
    }
    return *this;
}

string artista::getId() const { return id; }
string artista::getNombre() const { return nombre; }
string artista::getPais() const { return pais; }
unsigned int artista::getEdad() const { return edad; }
unsigned int artista::getSeguidores() const { return seguidores; }
unsigned int artista::getPosicion() const { return posicion; }
unsigned int artista::getNumAlbums() const { return numAlbums; }
album* artista::getAlbums() const { return albums; }

void artista::setId(const string& i) { id = i; }
void artista::setNombre(const string& n) { nombre = n; }
void artista::setPais(const string& p) { pais = p; }
void artista::setEdad(unsigned int e) { edad = e; }
void artista::setSeguidores(unsigned int s) { seguidores = s; }
void artista::setPosicion(unsigned int pos) { posicion = pos; }
void artista::setNumAlbums(unsigned int n) { numAlbums = n; }

void artista::agregarAlbum(const album& nuevo) {
    album* temp = new album[numAlbums + 1];
    for (unsigned int i = 0; i < numAlbums; i++)
        temp[i] = albums[i];
    temp[numAlbums] = nuevo;
    delete[] albums;
    albums = temp;
    numAlbums++;
}

void artista::mostrarInfo() const {
    cout << "ID: " << id << "\n"
         << "Nombre: " << nombre << "\n"
         << "País: " << pais << "\n"
         << "Edad: " << edad << "\n"
         << "Seguidores: " << seguidores << "\n"
         << "Posición global: " << posicion << "\n"
         << "Álbumes: " << numAlbums << "\n";
}
