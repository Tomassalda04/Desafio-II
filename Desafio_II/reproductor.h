#ifndef REPRODUCTOR_H
#define REPRODUCTOR_H
#include "funciones.h"
#include "cancion.h"
#include "usuario.h"

class reproductor
{
private:
    cancion *actual;        // Puntero a la canción que se está reproduciendo actualmente
    usuario *usuario;       // Puntero al usuario que está usando el reproductor
    bool reproduciendo;     // true si hay una canción sonando
    bool pausado;           // true si la canción está en pausa
    bool aleatorio;         // true si está en modo aleatorio
    int volumen;            // Nivel de volumen (0 a 100)

public:
    reproductor();
};

#endif // REPRODUCTOR_H
