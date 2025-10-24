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
void usuario::agregarFavorito(cancion* c) {
    if (!c) {
        cout << "No se puede agregar una canción nula a favoritos.\n";
        return;
    }
    cancion* temp = new cancion[numFavoritos + 1];
    for (int i = 0; i < numFavoritos; i++)
        temp[i] = favoritos[i];
    temp[numFavoritos] = *c;
    delete[] favoritos;
    favoritos = temp;
    numFavoritos++;
    cout << "Canción agregada a favoritos correctamente.\n";
}

void usuario::mostrarFavoritos() const {
    if (numFavoritos == 0) {
        cout << "No tienes canciones en favoritos.\n";
        return;
    }
    cout << "\n=== FAVORITOS DE " << nickname << " ===\n";
    for (int i = 0; i < numFavoritos; i++) {
        cout << "- " << favoritos[i].getNombre() << endl;
    }
}

void usuario::seguirUsuario(usuario* otro) {
    if (!otro) {
        cout << "Usuario no válido.\n";
        return;
    }
    if (!otro->getPremium()) {
        cout << "Solo puedes seguir a usuarios Premium.\n";
        return;
    }
    siguiendo = otro;
    cout << "Ahora sigues a " << otro->getNickname() << ".\n";
}

void usuario::mostrarFavoritosSeguido() const {
    if (!siguiendo) {
        cout << "No estás siguiendo a ningún usuario.\n";
        return;
    }
    cout << "\nFavoritos del usuario seguido (" << siguiendo->getNickname() << "):\n";
    siguiendo->mostrarFavoritos();
}
