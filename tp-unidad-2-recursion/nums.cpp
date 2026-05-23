#include <iostream>

using namespace std;

// Declaracion previa
bool impar(int numero);

// Funcion par
bool par(int numero) {

    // Caso base
    if (numero == 0) {
        return true;
    }

    return impar(numero - 1);
}

// Funcion impar
bool impar(int numero) {

    // Caso base
    if (numero == 0) {
        return false;
    }

    return par(numero - 1);
}

int main() {

    int numero;

    cout << "Ingrese un numero natural: ";
    cin >> numero;

    if (par(numero)) {

        cout << "El numero es PAR\n";
    }
    else {

        cout << "El numero es IMPAR\n";
    }

    return 0;
}