#ifndef USUARIO_H
#define USUARIO_H
#include "funciones.h"
#include "cancion.h"

class usuario
{

private:
    string nickname;
    string ciudad;
    string pais;
    string fechaRegistro;
    bool premium;
    cancion *favoritos;
    int numFavoritos;
    usuario *siguiendo;

public:
    usuario();
    usuario(string nickname,string ciudad,string pais,string fechaRegistro,bool premium);

    string getNickname() const;
    string getCiudad() const;
    string getPais() const;
    string getFechaRegistro() const;
    bool getPremium() const;

    void setNickname(string nuevoName);
    void setCiudad(string nuevaCiudad);
    void setPais(string nuevoPais);
    void setFechaRegistro(string nuevaFecha);
    void setPremium(bool actPremium);

};

#endif // USUARIO_H
