#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>

using namespace std; 


void escribir_archivo_plano(vector<vector<int>> matriz) {
	ofstream archivo("matriz.txt");

	if (archivo.is_open()) {
		archivo << matriz.size() << " " << matriz[0].size() << endl;
		for (auto const& fila: matriz) {
			for (auto const& numero: fila) {
				archivo << numero << " ";
			}
			archivo << endl;
		}
		archivo.close();
	}
	else {
		cout << "error al escribir el archivo plano";
	}
}


void escribir_archivo_binario(vector<vector<int>> matriz) {
    ofstream archivo("matriz.bin", ios::binary);
    int filas = matriz.size();
    int columnas = matriz[0].size();

    if (archivo.is_open()) {
        // Escribir dimensiones
        archivo.write(reinterpret_cast<const char*>(&filas), sizeof(filas));
        archivo.write(reinterpret_cast<const char*>(&columnas), sizeof(columnas));

        // Escribir datos de la matriz
        for (const auto& fila : matriz) {
            for (int numero : fila) {
                // Convertir el número a bits y escribirlos
                bitset<16> bits(numero);
                archivo.write(reinterpret_cast<const char*>(&bits), sizeof(bits));
            }
        }
        cout << "Archivo binario guardado correctamente." << endl;
        archivo.close();
    } else {
        cout << "Error al abrir el archivo binario." << endl;
    }
}
