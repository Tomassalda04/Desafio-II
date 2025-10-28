#ifndef ARTISTA_H
#define ARTISTA_H

#include "funciones.h"
#include "album.h"
using namespace std;

class artista {
private:
    string id;
    string nombre;
    string pais;
    unsigned int edad;
    unsigned int seguidores;
    unsigned int posicion;
    unsigned int numAlbums;
    album* albums;

public:
    artista();
    artista(string id, string nombre, string pais, unsigned int edad, unsigned int seguidores, unsigned int posicion, unsigned int numAlbums = 0);
    artista(const artista& other);
    ~artista();
    artista& operator=(const artista& other);

    // Getters
    string getId() const;
    string getNombre() const;
    string getPais() const;
    unsigned int getEdad() const;
    unsigned int getSeguidores() const;
    unsigned int getPosicion() const;
    unsigned int getNumAlbums() const;
    album* getAlbums() const;

    // Setters
    void setId(const string& id);
    void setNombre(const string& nombre);
    void setPais(const string& pais);
    void setEdad(unsigned int edad);
    void setSeguidores(unsigned int seguidores);
    void setPosicion(unsigned int posicion);
    void setNumAlbums(unsigned int n);

    // Otros
    void agregarAlbum(const album& nuevo);
    void mostrarInfo() const;
};

#endif
