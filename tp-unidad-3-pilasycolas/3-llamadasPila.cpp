#include <iostream>
#include <stack>

using namespace std;

int main() {

    stack<string> historialLlamadas;

    int opcion;
    string numeroTelefono;

    do {

        cout << "\n--- HISTORIAL DE LLAMADAS ---\n";
        cout << "1. Registrar llamada\n";
        cout << "2. Ver ultima llamada\n";
        cout << "3. Volver llamada anterior\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        cin.ignore();

        switch (opcion) {

        case 1:

            cout << "Numero telefonico: ";
            getline(cin, numeroTelefono);

            historialLlamadas.push(numeroTelefono);

            cout << "Llamada registrada\n";
            break;

        case 2:

            if (historialLlamadas.empty()) {
                cout << "No hay llamadas registradas\n";
            }
            else {
                cout << "Ultima llamada: "
                     << historialLlamadas.top()
                     << endl;
            }

            break;

        case 3:

            if (historialLlamadas.empty()) {
                cout << "No hay llamadas para retroceder\n";
            }
            else {

                cout << "Volviendo desde: "
                     << historialLlamadas.top()
                     << endl;

                historialLlamadas.pop();
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