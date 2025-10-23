#include "usuario.h"

usuario::usuario() {
    nickname = "";
    ciudad = "";
    pais = "";
    fechaRegistro = "";
    premium = false;
}

usuario::usuario(string nickname,string ciudad,string pais,string fechaRegistro,bool premium){
    this->nickname = nickname;
    this->ciudad = ciudad;
    this->pais = pais;
    this->fechaRegistro = fechaRegistro;
    this->premium = premium;
    this->favoritos = nullptr;
    this->numFavoritos = 0;
    this->siguiendo = nullptr;
}

string usuario::getNickname() const {
    return nickname;
}
string usuario::getCiudad() const {
    return ciudad;
}
string usuario::getPais() const {
    return pais;
}
string usuario::getFechaRegistro() const {
    return fechaRegistro;
}
bool usuario::getPremium() const {
    return premium;
}

void usuario::setNickname(string nuevoName){
    nickname=nuevoName;
}
void usuario::setCiudad(string nuevaCiudadad){
    ciudad=nuevaCiudadad;
}
void usuario::setPais(string nuevoPais){
    pais=nuevoPais;
}
void usuario::setFechaRegistro(string nuevaFecha){
    fechaRegistro=nuevaFecha;
}
void usuario::setPremium(bool actPremium){
    premium=actPremium;
}
