#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {

    queue<string> colaClientes;

    int opcion;
    string nombreCliente;
    int numeroBox;

    do {

        cout << "\n--- SISTEMA DE TURNOS STL ---\n";
        cout << "1. Agregar cliente\n";
        cout << "2. Mostrar proximo cliente\n";
        cout << "3. Atender cliente\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        cin.ignore();

        switch (opcion) {

        case 1:

            cout << "Nombre del cliente: ";
            getline(cin, nombreCliente);

            colaClientes.push(nombreCliente);

            cout << "Cliente agregado\n";
            break;

        case 2:

            if (colaClientes.empty()) {
                cout << "No hay clientes\n";
            }
            else {
                cout << "Proximo cliente: "
                     << colaClientes.front()
                     << endl;
            }

            break;

        case 3:

            if (colaClientes.empty()) {
                cout << "No hay clientes\n";
            }
            else {

                cout << "Numero de Box: ";
                cin >> numeroBox;

                cout << colaClientes.front()
                     << " dirigirse al Box "
                     << numeroBox
                     << endl;

                colaClientes.pop();
            }

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