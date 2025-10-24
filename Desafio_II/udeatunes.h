#ifndef UDEATUNES_H
#define UDEATUNES_H
#include "funciones.h"
#include "usuario.h"
#include "artista.h"
#include "publicidad.h"

class udeaTunes {

private:
    usuario* usuarios;
    int numUsuarios;
    artista* artistas;
    int numArtistas;
    publicidad* mensajes;
    int numMensajes;
    colaborador* colaboradores;
    int numColaboradores;
    creditos* listaCreditos;
    int numCreditos;


public:
    udeaTunes();
    ~udeaTunes();

    void menuPrincipal();
    void iniciarSesion();
    void registrarUsuario();
};

#endif // UDEATUNES_H
