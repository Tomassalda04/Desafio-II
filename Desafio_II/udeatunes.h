#ifndef UDEATUNES_H
#define UDEATUNES_H
#include "funciones.h"
#include "usuario.h"
#include "artista.h"
#include "publicidad.h"

class udeaTunes
{

private:
    usuario *usuarios;
    int numUsuarios;
    int numArtistas;
    int numMensajes;
    artista *artistas;
    publicidad *mensajes;
    usuario *usuarioActual;

public:
    udeaTunes();
    ~udeaTunes();

    void menuPrincipal();
    void iniciarSesion();
    void menuUsuario(usuario* actual);
};

#endif // UDEATUNES_H
