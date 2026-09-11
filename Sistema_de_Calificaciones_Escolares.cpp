#include <iostream>
#include <string>

using namespace std;

// Nivel 1

int main() {
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

    // Nivel 2

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

    return 0;
}
