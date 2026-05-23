#include <iostream>
#include <queue>
#include <string>

using namespace std;

// FUNCION RECURSIVA
void mostrarTiempoEsperaRecursivo(queue<string> colaClientes,
                                  queue<int> colaTiempoEspera) {

    // caso base
    if (colaClientes.empty()) {
        return;
    }

    // mostrar cliente actual
    cout << colaClientes.front()
         << " - Espera estimada: "
         << colaTiempoEspera.front()
         << " minutos\n";

    // avanzar en ambas colas
    colaClientes.pop();
    colaTiempoEspera.pop();

    // llamada recursiva
    mostrarTiempoEsperaRecursivo(colaClientes,
                                 colaTiempoEspera);
}

int main() {

    queue<string> colaClientes;
    queue<int> colaTiempoEspera;

    int opcion;
    string nombreCliente;
    int numeroBox;
    int minutosEspera;

    do {

        cout << "\n--- SISTEMA DE TURNOS STL ---\n";
        cout << "1. Agregar cliente\n";
        cout << "2. Mostrar proximo cliente\n";
        cout << "3. Atender cliente\n";
        cout << "4. Mostrar tiempos de espera (Recursivo)\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";

        cin >> opcion;

        cin.ignore();

        switch (opcion) {

        case 1:

            cout << "Nombre del cliente: ";
            getline(cin, nombreCliente);

            cout << "Tiempo estimado de espera: ";
            cin >> minutosEspera;

            colaClientes.push(nombreCliente);
            colaTiempoEspera.push(minutosEspera);

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
                colaTiempoEspera.pop();
            }

            break;

        case 4:

            if (colaClientes.empty()) {

                cout << "No hay clientes en espera\n";
            }
            else {

                cout << "\n--- TIEMPOS DE ESPERA ---\n";

                mostrarTiempoEsperaRecursivo(
                    colaClientes,
                    colaTiempoEspera
                );
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