#include <iostream>
#include <list>
#include "jugador.hpp"
using namespace std;

int leerEntero() {
    int entero;
    cout << "Escribe un entero: ";
    cin >> entero;

    return entero;
}

Jugador leerJugador() {
    Jugador j;
    string temp;

    cout << "Nombre: "; getline(cin, temp); j.setNombre(temp);
    cout << "Numero: "; getline(cin, temp); j.setNumeroPlayera(stoll(temp));
    cout << "Goles: "; getline(cin, temp); j.setGoles(stoll(temp));

    return j;
}

int main() {
    list<Jugador> jugadores;
    string op;

    while (true)
    {
        cout << "1) push_back" << endl;
        cout << "2) push_front" << endl;
        cout << "3) mostrar" << endl;
        cout << "4) eliminar" << endl;
        cout << "5) eliminar por valor" << endl;
        cout << "6) eliminar si" << endl;
        cout << "7) ordenar ASC" << endl;
        cout << "8) ordenar DESC" << endl;
        cout << "9) ordenar numero" << endl;
        cout << "10) ordenar goles" << endl;
        cout << "0) salir" << endl;
        cin >> op; cin.ignore();

        if (op == "1") {
            Jugador jugador = leerJugador();
            jugadores.push_back(jugador);
        }
        else if (op == "2") {
            Jugador jugador = leerJugador();
            jugadores.push_front(jugador);
        }
        else if (op == "3") {
            for (auto it = jugadores.begin(); 
            it != jugadores.end(); it++) {
                Jugador& jugador = *it;
                cout << jugador << endl;
            }
        }
        else if (op == "4") {
            int posicion = leerEntero();
            size_t cont = 0;
            auto it = jugadores.begin();

            while (cont < posicion)
            {
                it++;
                cont++;
            }
            jugadores.erase(it);
        }
        else if (op == "5") {
            Jugador jugador = leerJugador();
            jugadores.remove(jugador);
        }
        else if (op == "6") {
            int param = leerEntero();
            jugadores.remove_if([param](Jugador& x){return x.getGoles() < param;});
        }
        else if (op == "7") {
            jugadores.sort();
        }
        else if (op == "8") {
            jugadores.sort(greater<Jugador>());
        }
        else if (op == "9") {
            jugadores.sort([]
            (const Jugador& j1, const Jugador& j2){
                return j1.getNumeroPlayer() < j2.getNumeroPlayer();
            });
        }
        else if (op == "10") {
            jugadores.sort([]
            (const Jugador& j1, const Jugador& j2){
                return j1.getGoles() > j2.getGoles();
            });
        }
        else if (op == "0") {
            break;
        }
    }
    

    return 0;
}