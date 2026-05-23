#include <iostream>
#include <string>
using namespace std;


//  Nodo de la lista
struct Paciente {
    int    id;
    string nombre;
    string dni;
    string diagnostico;
    Paciente* next;

    Paciente(int i, string n, string d, string diag)
        : id(i), nombre(n), dni(d), diagnostico(diag), next(nullptr) {}
};


//  Lista enlazada simple de pacientes
class ListaPacientes {
private:
    Paciente* head;
    int       ultimoId;

public:
    ListaPacientes() : head(nullptr), ultimoId(0) {}

    ~ListaPacientes() {
        Paciente* tmp;      //tmp puntero auxiliar que se usa para recorrer la lista sin perder la referencia al head original
        while (head) { tmp = head; head = head->next; delete tmp; }
    }

    // Registrar 
    void registrar(string nombre, string dni, string diagnostico) {
        int nuevoId = ++ultimoId;
        Paciente* nuevo = new Paciente(nuevoId, nombre, dni, diagnostico);

        if (!head) {
            head = nuevo;
        } else {
            Paciente* tmp = head;       //tmp apunta al mismo nodo que head
            while (tmp->next) tmp = tmp->next;  //recorre sin mover head, avanza tmp al siguiente nodo
            tmp->next = nuevo;
        }
        cout << " Paciente registrado con ID: " << nuevoId << endl;
    }

    //  Modificar 
   void modificar(int id) {
        Paciente* tmp = head;
        while (tmp && tmp->id != id) tmp = tmp->next;

        if (!tmp) { cout << " Paciente no encontrado.\n"; return; }

        cout << "\nDatos actuales:  Nombre: " << tmp->nombre
            << " | DNI: " << tmp->dni
            << " | Diagnóstico: " << tmp->diagnostico << endl;

        string input;

        cout << "Nuevo nombre (Enter para mantener): ";
        cin.ignore(); getline(cin, input);
        if (!input.empty()) tmp->nombre = input;

        cout << "Nuevo DNI (Enter para mantener): ";
        getline(cin, input);
        if (!input.empty()) tmp->dni = input;

        cout << "Nuevo diagnóstico (Enter para mantener): ";
        getline(cin, input);
        if (!input.empty()) tmp->diagnostico = input;

        cout << " Paciente actualizado.\n";
}

    //  Eliminar
    void eliminar(int id) {
        if (!head) { cout << " Lista vacía.\n"; return; }

        if (head->id == id) {
            Paciente* tmp = head;
            head = head->next;
            delete tmp;
            cout << " Paciente eliminado.\n";
            return;
        }

        Paciente* prev = head;
        Paciente* curr = head->next;
        while (curr && curr->id != id) { prev = curr; curr = curr->next; }

        if (!curr) { cout << " Paciente no encontrado.\n"; return; }

        prev->next = curr->next;
        delete curr;
        cout << " Paciente eliminado.\n";
    }

    //  Listar 
    void listar() {
        if (!head) { cout << " No hay pacientes registrados.\n"; return; }

        cout << "\n+----+-------------------+-----------+----------------------+\n";
        cout <<   "| ID | Nombre            | DNI       | Diagnostico          |\n";
        cout <<   "+----+-------------------+-----------+----------------------+\n";

        Paciente* tmp = head;
        while (tmp) {
            printf("| %-2d | %-17s | %-9s | %-20s |\n",
                tmp->id,
                tmp->nombre.substr(0,17).c_str(),
                tmp->dni.substr(0,9).c_str(),
                tmp->diagnostico.substr(0,20).c_str());
            tmp = tmp->next;
        }
        cout << "+----+-------------------+-----------+----------------------+\n";
    }
};

// ─────────────────────────────────────────
//  Menu principal
// ─────────────────────────────────────────
int main() {
    ListaPacientes lista;
    int opcion;

    // Datos de prueba
    lista.registrar("Ana Garcia",    "30111222", "Hipertension");
    lista.registrar("Carlos Lopez",  "28333444", "Diabetes tipo 2");
    lista.registrar("Maria Perez",   "35555666", "Fractura muneca");

    do {
        cout << "\n+--------------------------------+\n";
        cout <<   "|   CLINICA LOCAL - PACIENTES    |\n";
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
            cout << "Nombre: ";      cin.ignore(); getline(cin, nombre);
            cout << "DNI: ";         getline(cin, dni);
            cout << "Diagnostico: "; getline(cin, diag);
            lista.registrar(nombre, dni, diag);

        } else if (opcion == 2) {
            int id;
            cout << "ID del paciente a modificar: "; cin >> id;
            lista.modificar(id);

        } else if (opcion == 3) {
            int id;
            cout << "ID del paciente a eliminar: "; cin >> id;
            lista.eliminar(id);

        } else if (opcion == 4) {
            lista.listar();
        }

    } while (opcion != 0);

    cout << "\nSistema cerrado. Hasta luego!\n";
    return 0;
}
