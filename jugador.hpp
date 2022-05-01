#ifndef JUGADOR_HPP
#define JUGADOR_HPP

#include <string>
using namespace std;

class Jugador {
private:
    string nombre;
    size_t numeroPlayera;
    size_t goles;
public:
    Jugador() {}
    Jugador(const string& nombre, 
            size_t numeroPlayera, 
            size_t goles) {
                Jugador::nombre = nombre;
                Jugador::numeroPlayera = numeroPlayera;
                Jugador::goles = goles;
            }
    // Setter and Getter
    void setNombre(const string& value) { nombre = value; }
    string getNombre() const { return nombre; }

    void setNumeroPlayera(size_t value) { numeroPlayera = value; }
    size_t getNumeroPlayer() const { return numeroPlayera; }

    void setGoles(size_t value) { goles = value; }
    size_t getGoles() const { return goles; }

    friend ostream& operator<<(ostream& out, const Jugador& j) {
        out << j.nombre << ", " 
        << j.numeroPlayera << ", " 
        << j.goles << endl;

        return out;
    }

    friend bool operator==(const Jugador& j1, const Jugador& j2) {
        return j1.nombre == j2.nombre;
    }

    friend bool operator<(const Jugador& j1, const Jugador& j2) {
        return j1.nombre < j2.nombre;
    }

      friend bool operator>(const Jugador& j1, const Jugador& j2) {
        return j1.nombre > j2.nombre;
    }
};
#endif