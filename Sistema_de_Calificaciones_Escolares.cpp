#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    int opcion;

    cout << "=== SISTEMA DE CALIFICACIONES ==="<< endl;
    cout << "1. Registrar estudiante." << endl;
    cout << "2. Ver informacion del programa." << endl;
    cout << "3. Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    switch (opcion) {
        case 1: {
        string nombre;
        int edad;
        float calificacion1, calificacion2, calificacion3;
        float promedio;

        cout << "Registro de Estudiante" << endl;
        cout << "Ingrese el nombre del estudiante: ";
        getline(cin, nombre);

        cout << "Ingrese la edad: ";
        cin >> edad;

        if (edad < 0 || edad > 120) {
            cout << "Error: Edad invalida. " << endl;
            return 1;
        }

        cout << "Ingrese la primera calificacion: ";
        cin >> calificacion1;

        cout << "Ingrese la segunda calificacion: ";
        cin >> calificacion2;

        cout << "Ingrese la tercera calificacion: ";
        cin >> calificacion3;


        if (calificacion1 < 0 || calificacion1 > 10 ||
            calificacion2 < 0 || calificacion2 > 10 ||
            calificacion3 < 0 || calificacion3 > 10) {
            cout << "Error: Calificaciones invalidas." << endl;
            return 1;
        }

        promedio = (calificacion1 + calificacion2 + calificacion3) / 3.0;

        cout << "RESUMEN DEL ESTUDIANTE" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Calificaciones: " << calificacion1 << ", " << calificacion2 << ", " << calificacion3 << endl;
        cout << "Promedio: " << promedio << endl;

        cout << "Estado: ";
        if (promedio >= 9.0) {
            cout << "EXCELENTE" << endl;
        } 
        else if (promedio >= 7.0) {
            cout << "APROBADO" << endl;
        } 
        else if (promedio >= 6.0) {
            cout << "REGULAR" << endl;
        } 
        else {
            cout << "REPROBADO" << endl;
        }
        break;
    }

    case 2:
        cout << "Ver informacion del programa." << endl;
        break;

    case 3: 
        cout << "Salir." << endl;
        return 0;
    } 

    return 0;
} 