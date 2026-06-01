#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string empresas[5] = {
        "Samsung", "xiaomi", "Xvideos", "Claro", "you tube"
    };
    
    ifstream datos2023("input/ingresos-2023.csv");
    ifstream datos2024("input/ingresos-2024.csv");
    ifstream datos2025("input/ingresos-2025.csv");
    ofstream totales("output/totales.txt");

    if (datos2023.is_open() && datos2024.is_open() && datos2025.is_open()) {

    string linea, valorStr;


    for (int i = 0; i < 5; i++) {
        
        int suma2023 = 0, suma2024 = 0, suma2025 = 0;

        getline(datos2023, linea); 
        stringstream ss23(linea);  
        while(getline(ss23, valorStr, ',')) {
            suma2023 += stoi(valorStr); 
        }

        getline(datos2024, linea); 
        stringstream ss24(linea);  
        while(getline(ss24, valorStr, ',')) {
            suma2024 += stoi(valorStr); 
        }

        getline(datos2025, linea); 
        stringstream ss25(linea);  
        while(getline(ss25, valorStr, ',')) {
            suma2025 += stoi(valorStr); 
        }

        int GananciaTotal = suma2023 + suma2024 + suma2025;

        totales << "Empresa: " << empresas[i] << endl;
        totales << " Ganancias 2023: " << suma2023 << endl;
        totales << " Ganancias 2024: " << suma2024 << endl;
        totales << " Ganancias 2025: " << suma2025 << endl;
        totales << "  Ganancias Totales: " << GananciaTotal << endl;
    }

    datos2023.close();
    datos2024.close();
    datos2025.close();
    totales.close();

    cout << "Archivo creado correctamente" << endl;
}else{
	cout<<"No se abrieron los archivos correctamente"<<endl;
	
}

    return 0;
}
