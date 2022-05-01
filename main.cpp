#include <iostream>
#include <list>

using namespace std;

int leerEntero() {
    int entero;
    cout << "Escribe un entero: ";
    cin >> entero;

    return entero;
}

int main() {
    list<int> enteros;
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
        cout << "0) salir" << endl;
        cin >> op; cin.ignore();

        if (op == "1") {
            int entero = leerEntero();
            enteros.push_back(entero);
        }
        else if (op == "2") {
            int entero = leerEntero();
            enteros.push_front(entero);
        }
        else if (op == "3") {
            for (auto it = enteros.begin(); 
            it != enteros.end(); it++) {
                int& entero = *it;
                cout << entero << endl;
            }
        }
        else if (op == "4") {
            int posicion = leerEntero();
            size_t cont = 0;
            auto it = enteros.begin();

            while (cont < posicion)
            {
                it++;
                cont++;
            }
            enteros.erase(it);
        }
        else if (op == "5") {
            int entero = leerEntero();
            enteros.remove(entero);
        }
        else if (op == "6") {
            int param = leerEntero();
            enteros.remove_if([param](int x){return x < param;});
        }
        else if (op == "7") {
            enteros.sort();
        }
        else if (op == "8") {
            enteros.sort(greater<int>());
        }
        else if (op == "0") {
            break;
        }
    }
    

    return 0;
}