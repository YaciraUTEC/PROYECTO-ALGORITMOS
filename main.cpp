#include <iostream>
#include "reader.h"

int main() {
    int reg = 0;
    cout << "Cuantos registros por bloque quiere:" << endl;
    cin >> reg;

    Master MasterBlockchain(reg);
    MasterBlockchain.addCsvData("data100.csv");

    MasterBlockchain.printBlockchain();

    cout<<"Busqueda por rango"<<endl;
    double lower = 500;
    double upper = 700;

    vector<record> result = MasterBlockchain.range_search(lower, upper);

    for (const auto& registro : result) {
        cout << registro << endl;
    }

    cout<< "Busqueda por cliente" << endl;
    vector<record> registros = MasterBlockchain.searchByClient("Herrod Meyers");
    double suma = 0.0;
    for (const auto& registro : registros) {
        cout << "Cliente: " << registro.cliente << endl;
        cout << "Lugar: " << registro.lugar << endl;
        cout << "Monto: " << registro.monto << endl;
        cout << "Fecha: " << registro.fecha << endl;
        suma += registro.monto;
    }

    cout<<"Calculo del monto total del cliente "<<"Herrod Meyers"<<": "<< suma <<endl;

    return 0;
}
