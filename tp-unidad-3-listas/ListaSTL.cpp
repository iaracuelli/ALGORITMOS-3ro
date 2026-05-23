#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;


//  Estructura Paciente
struct Paciente {
    int    id;
    string nombre;
    string dni;
    string diagnostico;
};


//  Sistema usando STL list
class ClinicaSTL {
private:
    list<Paciente> pacientes;
    int            ultimoId;

    // Busca un paciente por ID, devuelve iterador
    list<Paciente>::iterator buscar(int id) {
        return find_if(pacientes.begin(), pacientes.end(),
                       [id](const Paciente& p){ return p.id == id; });
    }

public:
    ClinicaSTL() : ultimoId(0) {}

    //  Registrar
    void registrar(string nombre, string dni, string diagnostico) {
        Paciente p = { ++ultimoId, nombre, dni, diagnostico };
        pacientes.push_back(p);
        cout << " Paciente registrado con ID: " << ultimoId << endl;
    }

    //  Modificar
    void modificar(int id) {
        auto it = buscar(id);
        if (it == pacientes.end()) { cout << " Paciente no encontrado.\n"; return; }

        cout << "\nDatos actuales:  Nombre: " << it->nombre
             << " | DNI: " << it->dni
             << " | Diagnostico: " << it->diagnostico << endl;

        string input;
        cout << "Nuevo nombre (Enter para mantener): ";
        cin.ignore(); getline(cin, input);
        if (!input.empty()) it->nombre = input;

        cout << "Nuevo DNI (Enter para mantener): ";
        getline(cin, input);
        if (!input.empty()) it->dni = input;

        cout << "Nuevo diagnostico (Enter para mantener): ";
        getline(cin, input);
        if (!input.empty()) it->diagnostico = input;

        cout << " Paciente actualizado.\n";
    }

    // ── Eliminar ───────────────────────────
    void eliminar(int id) {
        auto it = buscar(id);
        if (it == pacientes.end()) { cout << " Paciente no encontrado.\n"; return; }
        pacientes.erase(it);
        cout << " Paciente eliminado.\n";
    }

    // ── Listar ─────────────────────────────
    void listar() {
        if (pacientes.empty()) { cout << " No hay pacientes registrados.\n"; return; }

        cout << "\n+----+-------------------+-----------+----------------------+\n";
        cout <<   "| ID | Nombre            | DNI       | Diagnostico          |\n";
        cout <<   "+----+-------------------+-----------+----------------------+\n";

        for (const Paciente& p : pacientes) {
            printf("| %-2d | %-17s | %-9s | %-20s |\n",
                p.id,
                p.nombre.substr(0,17).c_str(),
                p.dni.substr(0,9).c_str(),
                p.diagnostico.substr(0,20).c_str());
        }
        cout << "+----+-------------------+-----------+----------------------+\n";
        cout << "Total de pacientes: " << pacientes.size() << "\n";
    }
};

// ─────────────────────────────────────────
//  Menu principal
// ─────────────────────────────────────────
int main() {
    ClinicaSTL clinica;
    int opcion;

    // Datos de prueba
    clinica.registrar("Ana Garcia",   "30111222", "Hipertension");
    clinica.registrar("Carlos Lopez", "28333444", "Diabetes tipo 2");
    clinica.registrar("Maria Perez",  "35555666", "Fractura muneca");

    do {
        cout << "\n+--------------------------------+\n";
        cout <<   "|  CLINICA LOCAL - STL list      |\n";
        cout <<   "+--------------------------------+\n";
        cout <<   "|  1. Registrar paciente         |\n";
        cout <<   "|  2. Modificar paciente         |\n";
        cout <<   "|  3. Eliminar paciente          |\n";
        cout <<   "|  4. Listar pacientes           |\n";
        cout <<   "|  0. Salir                      |\n";
        cout <<   "+--------------------------------+\n";
        cout << "Opcion: ";
        cin  >> opcion;

        if (opcion == 1) {
            string nombre, dni, diag;
            cout << "Nombre: ";       cin.ignore(); getline(cin, nombre);
            cout << "DNI: ";          getline(cin, dni);
            cout << "Diagnostico: ";  getline(cin, diag);
            clinica.registrar(nombre, dni, diag);

        } else if (opcion == 2) {
            int id;
            cout << "ID a modificar: "; cin >> id;
            clinica.modificar(id);

        } else if (opcion == 3) {
            int id;
            cout << "ID a eliminar: "; cin >> id;
            clinica.eliminar(id);

        } else if (opcion == 4) {
            clinica.listar();
        }

    } while (opcion != 0);

    cout << "\nSistema cerrado. Hasta luego!\n";
    return 0;
}
