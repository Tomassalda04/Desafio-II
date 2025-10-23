#include "funciones.h"
#include "usuario.h"
#include "artista.h"
#include "publicidad.h"
#include "funcionesaux.h"

void cargarUsuarios(usuario*& usuarios, int& numUsuarios) {
    ifstream archivo("usuarios.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir usuarios.txt" << endl;
        return;
    }

    numUsuarios = 0;
    usuarios = nullptr;

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nick, ciudad, pais, fecha;
        int premiumFlag;

        getline(ss, nick, ',');
        getline(ss, ciudad, ',');
        getline(ss, pais, ',');
        getline(ss, fecha, ',');
        ss >> premiumFlag;

        usuario nuevo(nick, ciudad, pais, fecha, premiumFlag == 1);

        usuario* temp = new usuario[numUsuarios + 1];
        for (int i = 0; i < numUsuarios; i++){
            temp[i] = usuarios[i];
        }
        temp[numUsuarios] = nuevo;

        delete[] usuarios;
        usuarios = temp;
        numUsuarios++;
    }

    archivo.close();
    cout << "Usuarios cargados: " << numUsuarios << endl;
}

void agregarUsuario(usuario*& usuarios, int& numUsuarios) {
    string nick, ciudad, pais, fecha;
    char prem;
    int premium=-1;

    cout << "\nIngrese nickname: ";
    cin >> nick;
    cout << "Ingrese ciudad: ";
    cin >> ciudad;
    cout << "Ingrese pais: ";
    cin >> pais;
    cout << "Ingrese fecha (AAAA-MM-DD): ";
    cin >> fecha;
    cout << "Es premium? (1=Si, 0=No): ";
    cin >> prem;
    premium=verificarPremium(prem);
    usuario nuevo(nick, ciudad, pais, fecha, premium == 1);

    usuario* temp = new usuario[numUsuarios + 1];
    for (int i = 0; i < numUsuarios; i++)
        temp[i] = usuarios[i];
    temp[numUsuarios] = nuevo;

    delete[] usuarios;
    usuarios = temp;
    numUsuarios++;

    cout << "Usuario agregado correctamente.\n";
}

void guardarUsuarios(usuario* usuarios, int numUsuarios) {
    ofstream archivo("datos/usuarios.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir usuarios.txt para escritura" << endl;
        return;
    }

    for (int i = 0; i < numUsuarios; i++) {
        archivo << usuarios[i].getNickname() << ","
                << usuarios[i].getCiudad() << ","
                << usuarios[i].getPais() << ","
                << usuarios[i].getFechaRegistro() << ","
                << usuarios[i].getPremium() << "\n";
    }

    archivo.close();
    cout << "Usuarios guardados correctamente." << endl;
}

void cargarArtistas(artista*& artistas, int& numArtistas) {
    ifstream archivo("artistas.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir artistas.txt" << endl;
        return;
    }

    numArtistas = 0;
    artistas = nullptr;

    string linea;
    bool primeraLinea = true;

    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        if (primeraLinea && linea.find("id") != string::npos) {
            primeraLinea = false;
            continue;
        }

        stringstream ss(linea);
        string id, nombre, pais;
        string edadStr, seguidoresStr, posicionStr, numAlbumsStr;

        getline(ss, id, ',');
        getline(ss, nombre, ',');
        getline(ss, pais, ',');
        getline(ss, edadStr, ',');
        getline(ss, seguidoresStr, ',');
        getline(ss, posicionStr, ',');
        getline(ss, numAlbumsStr, ',');

        unsigned int edad = stoi(edadStr);
        unsigned int seguidores = stoul(seguidoresStr);
        unsigned int posicion = stoi(posicionStr);
        unsigned int numAlbums = stoi(numAlbumsStr);

        artista nuevo(id, nombre, pais, edad, seguidores, posicion, numAlbums);

        artista* temp = new artista[numArtistas + 1];
        for (int i = 0; i < numArtistas; i++)
            temp[i] = artistas[i];
        temp[numArtistas] = nuevo;

        delete[] artistas;
        artistas = temp;
        numArtistas++;
    }

    archivo.close();
    cout << "Artistas cargados: " << numArtistas << endl;
}

void cargarPublicidad(publicidad*& mensajes, int& numMensajes) {
    ifstream archivo("datos/publicidad.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir publicidad.txt" << endl;
        return;
    }

    numMensajes = 0;
    mensajes = nullptr;

    string linea;
    while (getline(archivo, linea)) {
        string texto;
        char categoria;

        stringstream ss(linea);
        getline(ss, texto, ',');
        ss >> categoria;

        publicidad nuevo(texto, categoria);

        publicidad* temp = new publicidad[numMensajes + 1];
        for (int i = 0; i < numMensajes; i++) temp[i] = mensajes[i];
        temp[numMensajes] = nuevo;

        delete[] mensajes;
        mensajes = temp;
        numMensajes++;
    }

    archivo.close();
    cout << "Mensajes publicitarios cargados: " << numMensajes << endl;
}
/*
void guardarUsuarios(usuario* usuarios, int numUsuarios) {
    ofstream archivo("datos/usuarios.txt");
    if (!archivo.is_open()) {
        cout << "️No se pudo abrir usuarios.txt para escritura" << endl;
        return;
    }

    for (int i = 0; i < numUsuarios; i++) {
        archivo << usuarios[i].getNickname() << ","
                << usuarios[i].getCiudad() << ","
                << usuarios[i].getPais() << ","
                << usuarios[i].getFechaRegistro() << ","
                << usuarios[i].getPremium() << "\n";
    }

    archivo.close();
    cout << "Usuarios guardados correctamente." << endl;
}

*/
