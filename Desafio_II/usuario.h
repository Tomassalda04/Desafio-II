#ifndef USUARIO_H
#define USUARIO_H
#include "funciones.h"

using namespace std;

class cancion;

class usuario {
private:
    string nickname;
    string ciudad;
    string pais;
    string fechaRegistro;
    bool premium;
    cancion* favoritos;
    int numFavoritos;
    usuario* siguiendo;

public:
    usuario();
    usuario(string nickname, string ciudad, string pais, string fechaRegistro, bool premium);
    ~usuario();

    // Getters
    string getNickname() const;
    string getCiudad() const;
    string getPais() const;
    string getFechaRegistro() const;
    bool getPremium() const;

    // Setters
    void setNickname(string nuevoName);
    void setCiudad(string nuevaCiudad);
    void setPais(string nuevoPais);
    void setFechaRegistro(string nuevaFecha);
    void setPremium(bool actPremium);

    // Operaciones
    void agregarFavorito(cancion* c);
    void eliminarFavorito(const string& idCancion);
    void mostrarFavoritos() const;
    void seguirUsuario(usuario* otro);
    void mostrarFavoritosSeguido() const;

    // === NUEVOS GETTERS PARA GUARDAR Y CARGAR ===
    int getNumFavoritos() const;
    cancion* getFavoritos() const;
    usuario* getSeguido() const;
};

#endif
