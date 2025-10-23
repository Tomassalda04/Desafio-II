#ifndef REPRODUCTOR_H
#define REPRODUCTOR_H
#include "funciones.h"
#include "cancion.h"
#include "usuario.h"
#include "publicidad.h"

class reproductor
{
private:
    cancion *actual;
    usuario *usr;
    publicidad *anuncios;
    int numAnuncios;
    int contadorReproducciones;
    bool reproduciendo;
    bool pausado;
    bool aleatorio;
    int volumen;

public:
    reproductor();
    void setUsuario(usuario* u);
    void setPublicidad(publicidad* a, int n);

    void reproducir(cancion* c);
    void pausar();
    void reanudar();
    void detener();

    void subirVolumen();
    void bajarVolumen();
    void alternarAleatorio();
    void mostrarEstado() const;
};

#endif // REPRODUCTOR_H
