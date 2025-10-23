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
    ofstream archivo("usuarios.txt");
    if (!archivo.is_open()) {
        cout << "⚠️ No se pudo abrir usuarios.txt para escritura" << endl;
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

void menuUsuarioPremium(usuario* u) {
    //reproductor player;
    //player.setUsuario(u); // Premium no recibe publicidad

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
        //case 1: player.reproducir(nullptr); break;
        //case 2: player.pausar(); break;
        //case 3: player.reanudar(); break;
        //case 4: player.detener(); break;
        //case 5: player.subirVolumen(); break;
        //case 6: player.bajarVolumen(); break;
        //case 7: player.alternarAleatorio(); break;
        //case 8: player.mostrarEstado(); break;
        case 9: cout << "[Función seguir usuario Premium aún no implementada]\n"; break;
        case 10: cout << "[Función ver favoritos del usuario seguido aún no implementada]\n"; break;
        case 11: cout << "Cerrando sesión...\n"; break;
        default: cout << "Opción inválida.\n";
        }
    } while (opcion != 11);
}

void menuUsuarioEstandar(usuario* u, publicidad* anuncios, int numAnuncios) {
    //reproductor player;
    //player.setUsuario(u);
    //player.setPublicidad(anuncios, numAnuncios);

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
        case 1:
            // Por ahora no hay canciones reales, así que simulamos
           // player.reproducir(nullptr);
            break;

        case 2:
            //player.pausar();
            break;

        case 3:
            //player.reanudar();
            break;

        case 4:
            //player.detener();
            break;

        case 5:
            //player.subirVolumen();
            break;

        case 6:
            //player.bajarVolumen();
            break;

        case 7:
            //player.alternarAleatorio();
            break;

        case 8:
           // player.mostrarEstado();
            break;

        case 9:
            cout << "Cerrando sesión...\n";
            break;

        default:
            cout << "Opción inválida, intente de nuevo.\n";
        }
    } while (opcion != 9);
}

