#ifndef CANCION_H
#define CANCION_H
#include "funciones.h"
#include "creditos.h"
#include "album.h"

class cancion
{

private:
    string id;             // Identificador alfanumérico (ej. "AR001AL02C03")
    string nombre;         // Título de la canción
    float duracion;        // En minutos
    int reproducciones;
    string ruta128;        // Ruta del archivo a 128 kbps
    string ruta320;        // Ruta del archivo a 320 kbps
    creditos* creditos;    // Colaboradores de la canción
    album* album;          // Referencia al álbum al que pertenece

public:
    cancion();

};

#endif // CANCION_H
