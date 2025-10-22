#ifndef UDEATUNES_H
#define UDEATUNES_H
#include "funciones.h"
#include "usuario.h"
#include "artista.h"
#include "publicidad.h"

class udeaTunes
{

private:
    usuario *usuarios;         // Arreglo dinámico con todos los usuarios registrados
    int numUsuarios;           // Cantidad total de usuarios
    int numArtistas;           // Cantidad total de artistas
    int numMensajes;           // Cantidad total de anuncios publicitarios
    artista *artistas;         // Arreglo dinámico con los artistas disponibles
    publicidad *mensajes;      // Arreglo dinámico de mensajes publicitarios del sistema

public:
    udeaTunes();
};

#endif // UDEATUNES_H
