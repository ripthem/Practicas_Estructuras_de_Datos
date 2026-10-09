#include <iostream>
using namespace std;

int main() {

    cout.setf(ios::fixed);
    cout.precision(2);

    double saldo = 5000;
    int pin_correcto = 1234;
    int max_intentos = 3;
    int pin_ingresado;
    int contador_intentos = 0;
    bool accesoCorrecto = false;
    int opcion;

    while (contador_intentos < max_intentos && !accesoCorrecto) {
        cout << "Ingrese el PIN: ";
        cin >> pin_ingresado;

        if (pin_ingresado == pin_correcto) {
            accesoCorrecto = true;
            cout << "PIN correcto, bienvenido." << endl;
        } else {
            contador_intentos++;
            cout << "PIN incorrecto. Intentos restantes: "
                 << (max_intentos - contador_intentos) << endl;
        }
    }

    if (!accesoCorrecto) {
        cout << "Tarjeta bloqueada, contacte a soporte." << endl;
        return 0;
    }

    do {
        cout << "\n========= CAJERO AUTOMATICO =========" << endl;
        cout << "1. Consultar saldo." << endl;
        cout << "2. Depositar." << endl;
        cout << "3. Retirar." << endl;
        cout << "4. Retiros rapidos." << endl;
        cout << "5. Salir." << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1: {
            cout << "Tu saldo actual es de: $" << saldo << endl;
            break;
        }

        case 2: {
            double cantidad;
            cout << "Ingrese la cantidad que desea depositar: $";
            cin >> cantidad;

            if (cantidad <= 0) {
                cout << "Error: La cantidad a depositar debe ser mayor a 0." << endl;
            } else if (cantidad > 10000) {
                cout << "Error: Se supera la cantidad maxima a depositar $10000.00." << endl;
            } else {
                saldo += cantidad;
                cout << "Deposito exitoso. Tu nuevo saldo es de: $" << saldo << endl;
            }
            break;
        }

        case 3: {
            int cantidad;
            double comision, total;
            cout << "Ingrese la cantidad a retirar: $";
            cin >> cantidad;

            if (cantidad <= 0) {
                cout << "Error: El retiro debe ser mayor a 0." << endl;
            } else if (cantidad % 100 != 0) {
                cout << "Error: La cantidad debe ser multiplo de 100." << endl;
            } else {
                comision = (cantidad < 1000) ? 15.00 : 0.00;
                total = cantidad + comision;

                if (cantidad > saldo) {
                    cout << "Error: Fondos insuficientes. Intenta retirar $"
                         << (double)cantidad << " y tu saldo es de $" << saldo << endl;
                } else if (total > saldo) {
                    cout << "Error: Fondos insuficientes para cubrir la comision de $"
                         << comision << ". Se requieren $" << total
                         << " y tu saldo es de $" << saldo << endl;
                } else {
                    saldo -= total;
                    cout << "Retiro exitoso de $" << (double)cantidad << endl;

                    if (comision > 0) {
                        cout << "Comision aplicada: $" << comision << endl;
                    }
                    cout << "Nuevo saldo: $" << saldo << endl;
                }
            }
            break;
        }

        case 4: {
            double comision, total;

            cout << "\n--- RETIROS RAPIDOS ---" << endl;
            cout << "Saldo actual: $" << saldo << endl;
            cout << "Monto\t\tComision\tTotal\t\tDisponible" << endl;

                        for (int monto = 500; monto <= 3000; monto += 500) {
                comision = (monto < 1000) ? 15.00 : 0.00;
                total = monto + comision;

                cout << "$" << (double)monto;
                if (monto < 1000) cout << " ";   // alinea montos de 3 digitos
                cout << "\t$" << comision << "\t\t$" << total;
                if (total < 1000) cout << " ";   // alinea totales de 3 digitos
                cout << "\t" << ((total <= saldo) ? "SI" : "NO") << endl;
            }
            break;
        }

        case 5: {
            cout << "Gracias por usar nuestro servicio." << endl;
            break;
        }

        default: {
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }
        }

    } while (opcion != 5);

    return 0;
}