#ifndef ALBUM_H
#define ALBUM_H
#include "funciones.h"
#include"cancion.h"
class artista;


class album
{

private:
    string id, nombre, sello, fecha; // id: código alfanumérico del álbum | nombre: título del álbum | sello: discográfica | fecha: lanzamiento
    string genero[4];                // Hasta 4 géneros musicales asociados al álbum
    int puntuacion, numCandeciones;  // puntuacion: calificación promedio (1-10) | numCanciones: cantidad de canciones
    cancion *canciones;              // Arreglo dinámico con todas las canciones del álbum
    artista *artistas;               // Puntero al artista o grupo que creó el álbum

public:
    album();
};

#endif // ALBUM_H
