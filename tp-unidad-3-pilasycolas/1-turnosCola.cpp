#include <iostream>
#include <string>

using namespace std;

class ColaTurnos {
private:
    string clientes[100];
    int frente;
    int finalCola;

public:
    ColaTurnos() {
        frente = 0;
        finalCola = -1;
    }

    bool colaVacia() {
        return frente > finalCola;
    }

    void agregarCliente(string nombreCliente) {
        finalCola++;
        clientes[finalCola] = nombreCliente;

        cout << "Cliente agregado correctamente\n";
    }

    void mostrarClientes() {
        if (colaVacia()) {
            cout << "No hay clientes en espera\n";
            return;
        }

        cout << "\nClientes en espera:\n";

        for (int posicion = frente; posicion <= finalCola; posicion++) {
            cout << "- " << clientes[posicion] << endl;
        }
    }

    void llamarProximoCliente(int numeroBox) {
        if (colaVacia()) {
            cout << "No hay clientes para atender\n";
            return;
        }

        cout << "\nProximo cliente:\n";
        cout << clientes[frente]
             << " dirigirse al Box "
             << numeroBox << endl;

        frente++;
    }
};

int main() {

    ColaTurnos turnos;
    int opcion;
    string nombreCliente;
    int numeroBox;

    do {
        cout << "\n--- SISTEMA DE TURNOS ---\n";
        cout << "1. Agregar cliente\n";
        cout << "2. Mostrar clientes\n";
        cout << "3. Llamar proximo cliente\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        cin.ignore();

        switch (opcion) {

        case 1:
            cout << "Nombre del cliente: ";
            getline(cin, nombreCliente);

            turnos.agregarCliente(nombreCliente);
            break;

        case 2:
            turnos.mostrarClientes();
            break;

        case 3:
            cout << "Numero de Box: ";
            cin >> numeroBox;

            turnos.llamarProximoCliente(numeroBox);
            break;

        case 0:
            cout << "Programa finalizado\n";
            break;

        default:
            cout << "Opcion invalida\n";
        }

    } while (opcion != 0);

    return 0;
}