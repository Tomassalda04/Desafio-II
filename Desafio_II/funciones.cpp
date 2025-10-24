#include "funciones.h"
#include "usuario.h"
#include "artista.h"
#include "publicidad.h"
#include "funcionesaux.h"
#include "colaborador.h"
#include "creditos.h"
using namespace std;

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
        for (int i = 0; i < numUsuarios; i++)
            temp[i] = usuarios[i];
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
    int premium = -1;

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
    premium = verificarPremium(prem);
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
    ofstream archivo("usuarios.txt");
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
    ifstream archivo("publicidad.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir publicidad.txt" << endl;
        return;
    }

    numMensajes = 0;
    mensajes = nullptr;

    string linea;
    bool primeraLinea = true;

    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        if (primeraLinea && linea.find("texto") != string::npos) {
            primeraLinea = false;
            continue;
        }

        stringstream ss(linea);
        string texto;
        char categoria;

        getline(ss, texto, ',');
        ss >> categoria;

        publicidad nuevo(texto, categoria);

        publicidad* temp = new publicidad[numMensajes + 1];
        for (int i = 0; i < numMensajes; i++)
            temp[i] = mensajes[i];
        temp[numMensajes] = nuevo;

        delete[] mensajes;
        mensajes = temp;
        numMensajes++;
    }

    archivo.close();
    cout << "Mensajes publicitarios cargados: " << numMensajes << endl;
}

void cargarColaboradores(colaborador*& lista, int& numColab) {
    ifstream archivo("colaboradores.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir colaboradores.txt" << endl;
        lista = nullptr;
        numColab = 0;
        return;
    }

    numColab = 0;
    lista = nullptr;

    string linea;
    bool primeraLinea = true;

    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        if (primeraLinea && linea.find("codigoAfiliacion") != string::npos) {
            primeraLinea = false;
            continue;
        }

        stringstream ss(linea);
        string codigo, nombre, apellido;
        getline(ss, codigo, ',');
        getline(ss, nombre, ',');
        getline(ss, apellido, ',');

        colaborador nuevo;
        nuevo.setCodigoAfiliacion(codigo);
        nuevo.setNombre(nombre);
        nuevo.setApellido(apellido);

        colaborador* temp = new colaborador[numColab + 1];
        for (int i = 0; i < numColab; ++i) temp[i] = lista[i];
        temp[numColab] = nuevo;

        delete[] lista;
        lista = temp;
        numColab++;
    }

    archivo.close();
    cout << "Colaboradores cargados: " << numColab << endl;
}

colaborador* buscarColaboradorPorCodigo(colaborador* lista, int numColab, const string& codigo) {
    if (!lista) return nullptr;
    for (int i = 0; i < numColab; ++i) {
        if (lista[i].getCodigoAfiliacion() == codigo) return &lista[i];
    }
    return nullptr;
}

string* splitTokens(const string& s, char sep, int& outCount) {
    outCount = 0;
    for (size_t i = 0; i < s.size(); ++i) if (s[i] == sep) outCount++;
    outCount = outCount + ((s.empty()) ? 0 : 1);

    if (outCount == 0) return nullptr;

    string* arr = new string[outCount];
    int idx = 0;
    size_t start = 0;
    for (size_t i = 0; i <= s.size(); ++i) {
        if (i == s.size() || s[i] == sep) {
            arr[idx++] = s.substr(start, i - start);
            start = i + 1;
        }
    }
    return arr;
}

void cargarCreditos(creditos*& listaCreditos, int& numCreditos, colaborador* colaboradores, int numColab) {
    ifstream archivo("creditos.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir creditos.txt" << endl;
        return;
    }

    numCreditos = 0;
    listaCreditos = nullptr;

    string linea;
    bool primeraLinea = true;

    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        if (primeraLinea && linea.find("id") != string::npos) {
            primeraLinea = false;
            continue;
        }

        stringstream ss(linea);
        string idCred, prods, mus, comps;

        getline(ss, idCred, ',');
        getline(ss, prods, ',');
        getline(ss, mus, ',');
        getline(ss, comps, ',');

        colaborador* productores = nullptr;
        int nProd = 0;
        stringstream sp(prods);
        string cod;
        while (getline(sp, cod, '|')) {
            for (int i = 0; i < numColab; i++) {
                if (colaboradores[i].getCodigoAfiliacion() == cod) {
                    colaborador* temp = new colaborador[nProd + 1];
                    for (int j = 0; j < nProd; j++)
                        temp[j] = productores[j];
                    temp[nProd] = colaboradores[i];
                    delete[] productores;
                    productores = temp;
                    nProd++;
                    break;
                }
            }
        }

        colaborador* musicos = nullptr;
        int nMus = 0;
        stringstream sm(mus);
        while (getline(sm, cod, '|')) {
            for (int i = 0; i < numColab; i++) {
                if (colaboradores[i].getCodigoAfiliacion() == cod) {
                    colaborador* temp = new colaborador[nMus + 1];
                    for (int j = 0; j < nMus; j++)
                        temp[j] = musicos[j];
                    temp[nMus] = colaboradores[i];
                    delete[] musicos;
                    musicos = temp;
                    nMus++;
                    break;
                }
            }
        }

        colaborador* compositores = nullptr;
        int nComp = 0;
        stringstream sc(comps);
        while (getline(sc, cod, '|')) {
            for (int i = 0; i < numColab; i++) {
                if (colaboradores[i].getCodigoAfiliacion() == cod) {
                    colaborador* temp = new colaborador[nComp + 1];
                    for (int j = 0; j < nComp; j++)
                        temp[j] = compositores[j];
                    temp[nComp] = colaboradores[i];
                    delete[] compositores;
                    compositores = temp;
                    nComp++;
                    break;
                }
            }
        }

        creditos nuevo(productores, nProd, musicos, nMus, compositores, nComp);
        creditos* temp = new creditos[numCreditos + 1];

        for (int i = 0; i < numCreditos; i++)
            temp[i] = listaCreditos[i];
        temp[numCreditos] = nuevo;

        delete[] listaCreditos;
        listaCreditos = temp;
        numCreditos++;

    }

    archivo.close();
    cout << "Créditos cargados: " << numCreditos << endl;
}

void menuUsuarioPremium(usuario* u) {
    int opcion;
    do {
        cout << "\n===== MENU USUARIO PREMIUM =====\n";
        cout << "1. Reproducir canción\n";
        cout << "2. Pausar cancion\n";
        cout << "3. Reanudar cancion\n";
        cout << "4. Detener cancion\n";
        cout << "5. Subir volumen\n";
        cout << "6. Bajar volumen\n";
        cout << "7. Activar/desactivar modo aleatorio\n";
        cout << "8. Ver estado del reproductor\n";
        cout << "9. Seguir a otro usuario Premium\n";
        cout << "10. Ver favoritos del usuario seguido\n";
        cout << "11. Cerrar sesion\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 9: cout << "[Función seguir usuario Premium aún no implementada]\n"; break;
        case 10: cout << "[Función ver favoritos del usuario seguido aún no implementada]\n"; break;
        case 11: cout << "Cerrando sesión...\n"; break;
        default: cout << "Opción inválida.\n";
        }
    } while (opcion != 11);
}

void menuUsuarioEstandar(usuario* u, publicidad* anuncios, int numAnuncios) {
    int opcion = 0;
    do {
        cout << "\n===== MENÚ USUARIO ESTÁNDAR =====\n";
        cout << "1. Reproducir canción\n";
        cout << "2. Pausar canción\n";
        cout << "3. Reanudar canción\n";
        cout << "4. Detener canción\n";
        cout << "5. Subir volumen\n";
        cout << "6. Bajar volumen\n";
        cout << "7. Activar/desactivar modo aleatorio\n";
        cout << "8. Ver estado del reproductor\n";
        cout << "9. Cerrar sesión\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 9:
            cout << "Cerrando sesión...\n";
            break;
        default:
            cout << "Opción inválida, intente de nuevo.\n";
        }
    } while (opcion != 9);
}

