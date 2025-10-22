#ifndef USUARIO_H
#define USUARIO_H
#include "funciones.h"
#include "cancion.h"

class usuario
{

private:
    string nickname;       // Nombre único del usuario en el sistema
    string ciudad;         // Ciudad de residencia
    string pais;           // País de origen
    string fechaRegistro;  // Fecha en la que se registró en el sistema
    bool premium;          // true = Premium (sin publicidad) | false = Estándar (con publicidad)
    cancion *favoritos;    // Arreglo dinámico de canciones favoritas del usuario
    int numFavoritos;      // Número de canciones favoritas
    usuario *siguiendo;    // Puntero al usuario Premium al que sigue (para ver sus favoritos)

public:
    usuario();
};

#endif // USUARIO_H
