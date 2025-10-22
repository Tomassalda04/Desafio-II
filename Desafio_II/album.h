#ifndef ALBUM_H
#define ALBUM_H
#include "funciones.h"

class artista;
class cancion;

class album
{

private:
    string id,nombre,sello,fecha;
    string genero[4];
    int puntuacion,numCandeciones;
    cancion *canciones;
    artista *artistas;

public:
    album();

};

#endif // ALBUM_H
