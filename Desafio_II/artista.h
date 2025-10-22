#ifndef ARTISTA_H
#define ARTISTA_H
#include "funciones.h"
#include "album.h"

class artista
{

private:
    string id, nombre, pais;             // id: código alfanumérico del artista | nombre: nombre artístico | pais: país de origen
    unsigned int edad, seguidores, posicion, numAlbums;
    // edad: edad del artista | seguidores: cantidad de seguidores en la plataforma
    // posicion: ranking global o popularidad | numAlbums: cantidad de álbumes publicados
    album *albums;                       // Arreglo dinámico de álbumes pertenecientes al artista

public:
    artista();
};

#endif // ARTISTA_H
