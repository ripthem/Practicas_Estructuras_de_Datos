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
        int n;
        float calificacion;
        float suma = 0; 
        float promedio;
        int aprobadas = 0;
        int reprobadas = 0;
        float mayor, menor; 
        

        cout << "Registro de Estudiante" << endl;
        cout << "Ingrese el nombre del estudiante: ";
        getline(cin, nombre);

        cout << "Ingrese la edad: ";
        cin >> edad;

        if (edad < 0 || edad > 120) {
            cout << "Error: Edad invalida. " << endl;
            return 1;
        }

        cout << "Cuantas calificaciones desea registrar? ";
        cin >> n;

        for (int i = 1; i <= n; i++) {
        cout << "Ingrese la calificacion " << i << ": ";
            cin >> calificacion;

        if (calificacion < 0 || calificacion > 10) {
            cout << "Error: Calificaciones invalidas." << endl;
            return 1;
        }

        if (i == 1) {
            mayor = calificacion;
            menor = calificacion;
        } else {
            if (calificacion > mayor) mayor = calificacion;
            if (calificacion < menor) menor = calificacion;
        }

        if (calificacion >= 6) {
            aprobadas++;
        } else {
            reprobadas++; 
        }

        suma += calificacion; 

    }

        promedio = suma / n;

        cout << "RESUMEN DEL ESTUDIANTE" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "Calificacion mas alta: " << mayor << endl;
        cout << "Calificacion mas baja: " << menor << endl;
        cout << "Calificaciones aprobatorias: " << aprobadas << endl;
        cout << "Calificaciones reprobatorias: " << reprobadas << endl;


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