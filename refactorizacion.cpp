#include <iostream>
#include <string>
#include <limits>

using namespace std;

void mostrarMenu();
int leerEntero (string mensaje, int min, int max);
float leerCalificacion (int numero);
float calcularPromedio (float suma, int n);
string obtenerEstado (float promedio);
void registrarEstudiante();

int main() {
    int opcion;

    do {
        mostrarMenu();
        opcion = leerEntero("Opcion: ", 1, 3);

        switch (opcion) {
            case 1:
                registrarEstudiante();
                break;
            
            case 2:
                cout << "Ver informacion del programa." << endl;
                break;

            case 3:
                cout << "Salir." << endl;
                break;
        }
    } while (opcion !=3);

    return 0;
}

void mostrarMenu() {
    cout << "==SISTEMA DE CALIFICACIONES==" << endl;
    cout << "1. Registrar estudiante." << endl;
    cout << "2. Ver informacion del programa." << endl;
    cout << "3. Salir." << endl;
}

int leerEntero (string nombre, int min, int max) {
    int valor;

    while(true) {
        cout << nombre;
        
        if (cin >> valor && valor >= min && valor <= max) {
            cin.ignore (numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
        cout << "Error: Ingresar un numero entre " << min << " y " << max << "." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

float leerCalificacion(int numero) {
    float calificacion;

    while (true) {
        cout << "Ingrese la calificacion " << numero << ": ";
        if (cin >> calificacion && calificacion >= 0 && calificacion <= 10) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return calificacion;
        }
        cout << "Error: Calificacion invalida, debe ser entre 0 y 10." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

float calcularPromedio(float suma, int n) {
    return suma / n;
}

string obtenerEstado(float promedio) {
    if (promedio >= 9.0) {
        return "EXCELENTE";
    } else if (promedio >= 7.0) {
        return "APROBADO";
    } else if (promedio >= 6.0) {
        return "REGULAR";
    }
    return "REPROBADO";
}

void registrarEstudiante() {
    string nombre;
    int edad, n;
    float calificacion, suma = 0, promedio;
    int aprobadas = 0, reprobadas = 0;
    float mayor = 0, menor = 10;

    cout << "Registro de estudiante" << endl;
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, nombre);

    edad = leerEntero("Ingrese la edad: ", 0, 120);
    n = leerEntero("Cuantas calificaciones desea registrar (1 - 3)? ", 1, 3);

    for(int i = 1; i <= n; i++) {
        calificacion = leerCalificacion(i);

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

    promedio = calcularPromedio(suma, n);

    cout << "RESUMEN DEL ESTUDIANTE" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Calificacion mas alta: " << mayor << endl;
    cout << "Calificacion mas baja: " << menor << endl;
    cout << "Calificaciones aprobatorias: " << aprobadas << endl;
    cout << "Calificaciones reprobatorias: " << reprobadas << endl;
    cout << "Estado: " << obtenerEstado(promedio) << endl;
}