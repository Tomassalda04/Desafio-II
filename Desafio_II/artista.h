#ifndef ARTISTA_H
#define ARTISTA_H
#include "funciones.h"
#include "album.h"

class artista
{

private:
    string id, nombre, pais;
    unsigned int edad, seguidores, posicion, numAlbums;
    album *albums;

public:
    artista();
};

#endif // ARTISTA_H
