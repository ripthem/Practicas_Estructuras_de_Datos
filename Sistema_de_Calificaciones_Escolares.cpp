#include <iostream>
#include <string>

using namespace std;

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

    cout << "Ingrese la primera calificacion: ";
    cin >> calificacion1;

    cout << "Ingrese la segunda calificacion: ";
    cin >> calificacion2;

    cout << "Ingrese la tercera calificacion: ";
    cin >> calificacion3;

    promedio= (calificacion1 + calificacion2 + calificacion3) / 3;

    cout << "RESUMEN DEL ESTUDIANTE" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Calificaciones: " << calificacion1 << ", " << calificacion2 << ", " << calificacion3 << endl;
    cout << "Promedio final: " << promedio << endl;

    return 0;
}