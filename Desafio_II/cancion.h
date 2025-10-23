#ifndef CANCION_H
#define CANCION_H
#include "funciones.h"
#include "creditos.h"
#include "album.h"

class cancion
{

private:
    string id, nombre, ruta128, ruta320;
    float duracion;
    int reproducciones;
    creditos *creditos;
    album *album;

public:
    cancion();
};

#endif // CANCION_H
