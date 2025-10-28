#ifndef UDEATUNES_H
#define UDEATUNES_H

#include "funciones.h"
#include "usuario.h"
#include "artista.h"
#include "album.h"
#include "cancion.h"
#include "publicidad.h"
#include "colaborador.h"
#include "creditos.h"
using namespace std;

class udeatunes {
private:
    usuario* usuarios;
    int numUsuarios;
    artista* artistas;
    int numArtistas;
    album* albums;
    int numAlbums;
    cancion* canciones;
    int numCanciones;
    publicidad* mensajes;
    int numMensajes;
    colaborador* colaboradores;
    int numColaboradores;
    creditos* listaCreditos;
    int numCreditos;

public:
    udeatunes();
    ~udeatunes();

    void menuPrincipal();
    void iniciarSesion();
};

#endif
