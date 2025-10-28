#include "funciones.h"
#include "usuario.h"
#include "artista.h"
#include "album.h"
#include "cancion.h"
#include "publicidad.h"
#include "reproductor.h"
#include "funcionesaux.h"
#include "colaborador.h"
#include "creditos.h"
#include <cstdlib>
#include <ctime>

using namespace std;

void cargarUsuarios(usuario*& usuarios, int& numUsuarios) {
    ifstream archivo("usuarios.txt");
    if (!archivo.is_open()) {
        usuarios = nullptr;
        numUsuarios = 0;
        return;
    }
    numUsuarios = 0;
    usuarios = nullptr;
    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
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
        for (int i = 0; i < numUsuarios; i++) temp[i] = usuarios[i];
        temp[numUsuarios] = nuevo;
        delete[] usuarios;
        usuarios = temp;
        numUsuarios++;
    }
    archivo.close();
}

void agregarUsuario(usuario*& usuarios, int& numUsuarios) {
    string nick, ciudad, pais, fecha;
    char prem;
    int premium = -1;
    cout << "Ingrese nickname: ";
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
    for (int i = 0; i < numUsuarios; i++) temp[i] = usuarios[i];
    temp[numUsuarios] = nuevo;
    delete[] usuarios;
    usuarios = temp;
    numUsuarios++;
}

void guardarUsuarios(usuario* usuarios, int numUsuarios) {
    ofstream archivo("usuarios.txt");
    if (!archivo.is_open()) return;
    for (int i = 0; i < numUsuarios; i++) {
        archivo << usuarios[i].getNickname() << ","
                << usuarios[i].getCiudad() << ","
                << usuarios[i].getPais() << ","
                << usuarios[i].getFechaRegistro() << ","
                << usuarios[i].getPremium() << "\n";
    }
    archivo.close();
}

void cargarArtistas(artista*& artistas, int& numArtistas) {
    ifstream archivo("artistas.txt");
    if (!archivo.is_open()) {
        artistas = nullptr;
        numArtistas = 0;
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
        string id, nombre, pais, edadStr, seguidoresStr, posicionStr, numAlbumsStr;
        getline(ss, id, ',');
        getline(ss, nombre, ',');
        getline(ss, pais, ',');
        getline(ss, edadStr, ',');
        getline(ss, seguidoresStr, ',');
        getline(ss, posicionStr, ',');
        getline(ss, numAlbumsStr, ',');
        unsigned int edad = 0; unsigned int seguidores = 0; unsigned int posicion = 0; unsigned int numAlbums = 0;
        if (!edadStr.empty()) edad = stoi(edadStr);
        if (!seguidoresStr.empty()) seguidores = stoul(seguidoresStr);
        if (!posicionStr.empty()) posicion = stoi(posicionStr);
        if (!numAlbumsStr.empty()) numAlbums = stoi(numAlbumsStr);
        artista nuevo(id, nombre, pais, edad, seguidores, posicion, numAlbums);
        artista* temp = new artista[numArtistas + 1];
        for (int i = 0; i < numArtistas; i++) temp[i] = artistas[i];
        temp[numArtistas] = nuevo;
        delete[] artistas;
        artistas = temp;
        numArtistas++;
    }
    archivo.close();
}

void cargarAlbums(album*& albums, int& numAlbums, artista* artistas, int numArtistas) {
    ifstream archivo("albums.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir albums.txt\n";
        albums = nullptr;
        numAlbums = 0;
        return;
    }

    numAlbums = 0;
    albums = nullptr;

    string linea;
    bool primeraLinea = true;

    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        if (primeraLinea && linea.find("ID") != string::npos) {
            primeraLinea = false;
            continue;
        }

        stringstream ss(linea);
        string id, nombre, generosStr, sello, fecha, puntuacionStr, numCancionesStr, idArtista;

        getline(ss, id, ',');
        getline(ss, nombre, ',');
        getline(ss, generosStr, ',');
        getline(ss, sello, ',');
        getline(ss, fecha, ',');
        getline(ss, puntuacionStr, ',');
        getline(ss, numCancionesStr, ',');
        getline(ss, idArtista, ',');

        int puntuacion = stoi(puntuacionStr);
        int numCanciones = stoi(numCancionesStr);

        artista* artPtr = nullptr;
        for (int i = 0; i < numArtistas; i++) {
            if (artistas[i].getId() == idArtista) {
                artPtr = &artistas[i];
                break;
            }
        }

        album nuevo(id, nombre, sello, fecha, puntuacion, numCanciones, artPtr);

        string generos[4];
        stringstream sgen(generosStr);
        string gen;
        int idx = 0;
        while (getline(sgen, gen, '|') && idx < 4) {
            generos[idx++] = gen;
        }
        nuevo.setGeneros(generos, idx);

        album* temp = new album[numAlbums + 1];
        for (int i = 0; i < numAlbums; i++) temp[i] = albums[i];
        temp[numAlbums] = nuevo;

        delete[] albums;
        albums = temp;
        numAlbums++;
    }

    archivo.close();
    cout << "Albums cargados: " << numAlbums << endl;
}


void cargarCanciones(cancion*& canciones, int& numCanciones, album* albums, int numAlbums) {
    ifstream archivo("canciones.txt");
    if (!archivo.is_open()) {
        canciones = nullptr;
        numCanciones = 0;
        return;
    }
    numCanciones = 0;
    canciones = nullptr;
    string linea;
    bool primeraLinea = true;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        if (primeraLinea && linea.find("ID") != string::npos) {
            primeraLinea = false;
            continue;
        }
        stringstream ss(linea);
        string id, nombre, ruta128, ruta320, duracionStr, reproduccionesStr, idAlbum;
        getline(ss, id, ',');
        getline(ss, nombre, ',');
        getline(ss, ruta128, ',');
        getline(ss, ruta320, ',');
        getline(ss, duracionStr, ',');
        getline(ss, reproduccionesStr, ',');
        getline(ss, idAlbum, ',');
        float duracion = 0.0;
        int reproducciones = 0;
        if (!duracionStr.empty()) duracion = stof(duracionStr);
        if (!reproduccionesStr.empty()) reproducciones = stoi(reproduccionesStr);
        album* albPtr = nullptr;
        for (int i = 0; i < numAlbums; i++) if (albums[i].getId() == idAlbum) { albPtr = &albums[i]; break; }
        cancion nueva(id, nombre, ruta128, ruta320, duracion, reproducciones, albPtr);
        cancion* temp = new cancion[numCanciones + 1];
        for (int i = 0; i < numCanciones; i++) temp[i] = canciones[i];
        temp[numCanciones] = nueva;
        delete[] canciones;
        canciones = temp;
        numCanciones++;
        if (albPtr) albPtr->agregarCancion(nueva);
    }
    archivo.close();
}

void cargarPublicidad(publicidad*& mensajes, int& numMensajes) {
    ifstream archivo("publicidad.txt");
    if (!archivo.is_open()) {
        mensajes = nullptr;
        numMensajes = 0;
        return;
    }
    numMensajes = 0;
    mensajes = nullptr;
    string linea;
    bool primeraLinea = true;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        if (primeraLinea && linea.find("texto") != string::npos) { primeraLinea = false; continue; }
        stringstream ss(linea);
        string texto; char categoria;
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
}

void cargarColaboradores(colaborador*& lista, int& numColab) {
    ifstream archivo("colaboradores.txt");
    if (!archivo.is_open()) {
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
        if (primeraLinea && linea.find("codigoAfiliacion") != string::npos) { primeraLinea = false; continue; }
        stringstream ss(linea);
        string codigo, nombre, apellido;
        getline(ss, codigo, ',');
        getline(ss, nombre, ',');
        getline(ss, apellido, ',');
        colaborador nuevo(codigo, nombre, apellido);
        colaborador* temp = new colaborador[numColab + 1];
        for (int i = 0; i < numColab; ++i) temp[i] = lista[i];
        temp[numColab] = nuevo;
        delete[] lista;
        lista = temp;
        numColab++;
    }
    archivo.close();
}

colaborador* buscarColaboradorPorCodigo(colaborador* lista, int numColab, const string& codigo) {
    if (!lista) return nullptr;
    for (int i = 0; i < numColab; ++i) if (lista[i].getCodigoAfiliacion() == codigo) return &lista[i];
    return nullptr;
}

void cargarCreditos(creditos*& listaCreditos, int& numCreditos, colaborador* colaboradores, int numColab) {
    ifstream archivo("creditos.txt");
    if (!archivo.is_open()) {
        listaCreditos = nullptr;
        numCreditos = 0;
        return;
    }
    numCreditos = 0;
    listaCreditos = nullptr;
    string linea;
    bool primeraLinea = true;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        if (primeraLinea && linea.find("id") != string::npos) { primeraLinea = false; continue; }
        stringstream ss(linea);
        string idCred, prods, mus, comps;
        getline(ss, idCred, ',');
        getline(ss, prods, ',');
        getline(ss, mus, ',');
        getline(ss, comps, ',');
        auto parseColabs = [&](string str) {
            colaborador* arr = nullptr;
            int count = 0;
            stringstream s(str);
            string cod;
            while (getline(s, cod, '|')) {
                for (int i = 0; i < numColab; i++) {
                    if (colaboradores[i].getCodigoAfiliacion() == cod) {
                        colaborador* temp = new colaborador[count + 1];
                        for (int j = 0; j < count; j++) temp[j] = arr[j];
                        temp[count] = colaboradores[i];
                        delete[] arr;
                        arr = temp;
                        count++;
                        break;
                    }
                }
            }
            return pair<colaborador*, int>(arr, count);
        };
        auto prodPair = parseColabs(prods);
        auto musPair = parseColabs(mus);
        auto compPair = parseColabs(comps);
        creditos nuevo(prodPair.first, prodPair.second, musPair.first, musPair.second, compPair.first, compPair.second);
        creditos* temp = new creditos[numCreditos + 1];
        for (int i = 0; i < numCreditos; i++) temp[i] = listaCreditos[i];
        temp[numCreditos] = nuevo;
        delete[] listaCreditos;
        listaCreditos = temp;
        numCreditos++;
        delete[] prodPair.first;
        delete[] musPair.first;
        delete[] compPair.first;
    }
    archivo.close();
}

void menuUsuarioPremium(usuario* u, usuario* usuarios, int numUsuarios,cancion* canciones, int numCanciones,int numArtistas, int numAlbums, int numMensajes) {
    (void)numArtistas; // evita warning si no se usan luego
    (void)numAlbums;
    (void)numMensajes;

    reproductor player;
    player.setUsuario(u);
    char opcion;
    int iteraciones = 0; // declaramos iteraciones aqui

    do {
        cout << "\n===== MENU PREMIUM =====\n";
        cout << "1. Reproducir 5 canciones aleatorias\n";
        cout << "2. Pausar cancion\n";
        cout << "3. Reanudar cancion\n";
        cout << "4. Detener cancion\n";
        cout << "5. Subir volumen\n";
        cout << "6. Bajar volumen\n";
        cout << "7. Ver estado del reproductor\n";
        cout << "8. Agregar cancion a favoritos\n";
        cout << "9. Eliminar cancion de favoritos\n";
        cout << "A. Ver mis favoritos\n";
        cout << "B. Seguir usuario Premium\n";
        cout << "C. Ver favoritos del seguido\n";
        cout << "D. Cerrar sesion\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        opcion = toupper(opcion);

        switch (opcion) {
        case '1': {
            reproductor rep;
            rep.reproducirAleatorio(canciones, numCanciones);
            iteraciones++;
            medirConsumoRecursos("Reproducir aleatorio", iteraciones, numUsuarios, numArtistas, numAlbums, numCanciones, numMensajes);
            break;
        }

        case '2': player.pausar(); iteraciones++; break;
        case '3': player.reanudar(); iteraciones++; break;
        case '4': player.detener(); iteraciones++; break;
        case '5': player.subirVolumen(); iteraciones++; break;
        case '6': player.bajarVolumen(); iteraciones++; break;
        case '7': player.mostrarEstado(); iteraciones++; break;

        case '8': {
            string id;
            cout << "ID de la cancion a agregar: ";
            cin >> id;
            bool encontrada = false;
            for (int i = 0; i < numCanciones; i++) {
                if (canciones[i].getId() == id) {
                    u->agregarFavorito(&canciones[i]);
                    guardarFavoritos(usuarios, numUsuarios, "favoritos.txt");
                    encontrada = true;
                    break;
                }
            }
            if (!encontrada) cout << "Cancion no encontrada.\n";
            iteraciones++;
            medirConsumoRecursos("Agregar favorito", iteraciones, numUsuarios, numArtistas, numAlbums, numCanciones, numMensajes);
            break;
        }

        case '9': {
            string id;
            cout << "ID de la cancion a eliminar: ";
            cin >> id;
            u->eliminarFavorito(id);
            guardarFavoritos(usuarios, numUsuarios, "favoritos.txt");
            iteraciones++;
            medirConsumoRecursos("Eliminar favorito", iteraciones, numUsuarios, numArtistas, numAlbums, numCanciones, numMensajes);
            break;
        }

        case 'A': u->mostrarFavoritos(); iteraciones++; break;

        case 'B': {
            string nombreSeguir;
            cout << "Nickname del Premium a seguir: ";
            cin >> nombreSeguir;
            usuario* seguido = nullptr;
            for (int i = 0; i < numUsuarios; ++i) {
                if (usuarios[i].getNickname() == nombreSeguir && usuarios[i].getPremium()) {
                    seguido = &usuarios[i];
                    break;
                }
            }
            if (seguido) {
                u->seguirUsuario(seguido);
                guardarSeguidos(usuarios, numUsuarios, "seguidos.txt");
                cancion* favSeguido = seguido->getFavoritos();
                int numFavSeguido = seguido->getNumFavoritos();
                for (int i = 0; i < numFavSeguido; i++) {
                    bool yaExiste = false;
                    for (int j = 0; j < u->getNumFavoritos(); j++) {
                        if (u->getFavoritos()[j].getId() == favSeguido[i].getId()) {
                            yaExiste = true;
                            break;
                        }
                    }
                    if (!yaExiste) {
                        u->agregarFavorito(&favSeguido[i]);
                    }
                }
                guardarFavoritos(usuarios, numUsuarios, "favoritos.txt");
                cout << "Ahora sigues a " << nombreSeguir << " y se han agregado sus canciones favoritas a tus favoritos.\n";
            } else {
                cout << "Usuario no encontrado o no es premium.\n";
            }
            iteraciones++;
            medirConsumoRecursos("Seguir usuario y copiar favoritos", iteraciones, numUsuarios, numArtistas, numAlbums, numCanciones, numMensajes);
            break;
        }

        case 'C': u->mostrarFavoritosSeguido(); iteraciones++; break;
        case 'D': cout << "Sesion cerrada.\n"; iteraciones++; medirConsumoRecursos("Cerrar sesion", iteraciones, numUsuarios, numArtistas, numAlbums, numCanciones, numMensajes); break;
        default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 'D');
}


void menuUsuarioEstandar(usuario* u, cancion* canciones, int numCanciones,publicidad* anuncios, int numAnuncios,int numArtistas, int numAlbums, int numMensajes) {
    (void)numArtistas;
    (void)numAlbums;
    (void)numMensajes;

    reproductor player;
    player.setUsuario(u);
    player.setPublicidad(anuncios, numAnuncios);

    static int contadorCanciones = 0;
    int iteraciones = 0;
    char opcion;

    do {
        cout << "\n===== MENU USUARIO ESTANDAR =====\n";
        cout << "1. Reproducir cancion (con anuncios cada 2)\n";
        cout << "2. Pausar cancion\n";
        cout << "3. Reanudar cancion\n";
        cout << "4. Detener cancion\n";
        cout << "5. Subir volumen\n";
        cout << "6. Bajar volumen\n";
        cout << "7. Ver estado del reproductor\n";
        cout << "8. Cerrar sesion\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        opcion = toupper(opcion);

        switch (opcion) {
        case '1': {
            string id;
            cout << "Ingrese el ID de la cancion: ";
            cin >> id;

            bool encontrada = false;
            for (int i = 0; i < numCanciones; i++) {
                if (canciones[i].getId() == id) {
                    player.reproducir(&canciones[i]);
                    encontrada = true;
                    contadorCanciones++;
                    iteraciones++;

                    if (contadorCanciones % 2 == 0 && numAnuncios > 0) {
                        cout << "\n----- PUBLICIDAD -----\n";
                        int idx = rand() % numAnuncios;
                        anuncios[idx].mostrar();
                        cout << "----------------------\n";
                    }
                    break;
                }
            }

            if (!encontrada) cout << "Cancion no encontrada.\n";

            medirConsumoRecursos("Reproducir cancion (estandar)", iteraciones, /*numUsuarios*/ 0, numArtistas, numAlbums, numCanciones, numMensajes);
            break;
        }

        case '2': player.pausar(); iteraciones++; break;
        case '3': player.reanudar(); iteraciones++; break;
        case '4': player.detener(); iteraciones++; break;
        case '5': player.subirVolumen(); iteraciones++; break;
        case '6': player.bajarVolumen(); iteraciones++; break;
        case '7': player.mostrarEstado(); iteraciones++; break;
        case '8': cout << "Cerrando sesion...\n"; iteraciones++; medirConsumoRecursos("Cerrar sesion estandar", iteraciones, /*numUsuarios*/ 0, numArtistas, numAlbums, numCanciones, numMensajes); break;
        default: cout << "Opcion invalida.\n";
        }
    } while (opcion != '8');
}


void cargarFavoritos(usuario* usuarios, int numUsuarios, cancion* canciones, int numCanciones, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "No se pudo abrir " << filename << endl;
        return;
    }

    string linea;
    while (getline(file, linea)) {
        if (linea.empty()) continue;
        stringstream ss(linea);

        string nick;
        getline(ss, nick, ',');
        usuario* u = nullptr;

        // Buscar usuario premium correspondiente
        for (int i = 0; i < numUsuarios; i++) {
            if (usuarios[i].getNickname() == nick && usuarios[i].getPremium()) {
                u = &usuarios[i];
                break;
            }
        }
        if (!u) continue;

        // Leer los IDs de canciones y agregarlas
        string idCancion;
        while (getline(ss, idCancion, ',')) {
            for (int j = 0; j < numCanciones; j++) {
                if (canciones[j].getId() == idCancion) {
                    u->agregarFavorito(&canciones[j]);
                    break;
                }
            }
        }
    }

    file.close();
    cout << "Favoritos cargados desde " << filename << endl;
}

void guardarFavoritos(usuario* usuarios, int numUsuarios, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error al guardar en " << filename << endl;
        return;
    }

    for (int i = 0; i < numUsuarios; i++) {
        if (!usuarios[i].getPremium()) continue;

        file << usuarios[i].getNickname();

        int nFav = usuarios[i].getNumFavoritos();
        cancion* favs = usuarios[i].getFavoritos();

        for (int j = 0; j < nFav; j++) {
            file << "," << favs[j].getId();
        }
        file << "\n";
    }

    file.close();
    cout << "Favoritos actualizados en " << filename << endl;
}

void cargarSeguidos(usuario* usuarios, int numUsuarios, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "No se pudo abrir " << filename << endl;
        return;
    }

    string linea;
    while (getline(file, linea)) {
        if (linea.empty()) continue;
        stringstream ss(linea);
        string seguidor, seguido;
        getline(ss, seguidor, ',');
        getline(ss, seguido, ',');

        usuario* uSeguidor = nullptr;
        usuario* uSeguido = nullptr;

        for (int i = 0; i < numUsuarios; i++) {
            if (usuarios[i].getNickname() == seguidor) uSeguidor = &usuarios[i];
            if (usuarios[i].getNickname() == seguido) uSeguido = &usuarios[i];
        }

        if (uSeguidor && uSeguido && uSeguido->getPremium()) {
            uSeguidor->seguirUsuario(uSeguido);
        }
    }

    file.close();
    cout << "Seguidos cargados desde " << filename << endl;
}

void guardarSeguidos(usuario* usuarios, int numUsuarios, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error al guardar en " << filename << endl;
        return;
    }

    for (int i = 0; i < numUsuarios; i++) {
        usuario* seguido = usuarios[i].getSeguido();
        if (seguido != nullptr) {
            file << usuarios[i].getNickname() << "," << seguido->getNickname() << "\n";
        }
    }

    file.close();
    cout << "Seguidos actualizados en " << filename << endl;
}

void medirConsumoRecursos(const string& nombreFuncionalidad, int iteraciones,int numUsuarios, int numArtistas, int numAlbums, int numCanciones, int numMensajes) {
    size_t memoria = sizeof(usuario) * numUsuarios
                     + sizeof(artista) * numArtistas
                     + sizeof(album) * numAlbums
                     + sizeof(cancion) * numCanciones
                     + sizeof(publicidad) * numMensajes;

    cout << "\n===== MEDICION DE RECURSOS =====\n";
    cout << "Funcionalidad: " << nombreFuncionalidad << endl;
    cout << "Iteraciones realizadas: " << iteraciones << endl;
    cout << "Memoria total estimada: " << memoria << " bytes\n";
    cout << "================================\n";
}
