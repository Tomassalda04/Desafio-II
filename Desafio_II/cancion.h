#ifndef CANCION_H
#define CANCION_H
#include "funciones.h"
#include "creditos.h"
#include "album.h"

class cancion
{

private:
    string id, nombre, ruta128, ruta320; // id: código alfanumérico de la canción | nombre: título | ruta128/ruta320: ubicaciones de los archivos de audio
    float duracion;                      // Duración de la canción en minutos
    int reproducciones;                  // Contador de cuántas veces se ha reproducido
    creditos *creditos;                  // Puntero al objeto que almacena los créditos de la canción
    album *album;                        // Puntero al álbum al que pertenece la canción

public:
    cancion();
};

#endif // CANCION_H
