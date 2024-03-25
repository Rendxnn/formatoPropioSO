#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <bitset>

using namespace std;


vector<vector<int>> leer_archivo_texto(string nombre_archivo) {
	ifstream archivo(nombre_archivo);
	vector<int> dimensiones(2, 0);


	if (archivo.is_open()) {
		vector<int> fila;
		string numero;
		string linea;

		getline(archivo, linea);
		stringstream stream(linea);
		while (getline(stream, numero, ' ')) {
			dimensiones.push_back(stoi(numero));
		}

		int filas = dimensiones[0];
		int columnas = dimensiones[1];

		vector<vector<int>> matriz(filas, vector<int>(columnas));


		while (getline(archivo, linea)) {
			stringstream stream(linea);
			while (getline(stream, numero, ' ')) {
				fila.push_back(stoi(numero));
			}
		matriz.push_back(fila);
		fila = {};
		}
		return matriz;
	}
	else {
		cout << "hubo un problema leyendo el archivo";
		return {{}};
	}
}



vector<vector<int>> leer_archivo_binario(string nombre_archivo) {
    ifstream archivo(nombre_archivo, ios::binary);
    int filas;
    int columnas;
    int numero;

    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&filas), sizeof(filas));
        archivo.read(reinterpret_cast<char*>(&columnas), sizeof(columnas));

        vector<vector<int>> matriz(filas, vector<int>(columnas));

        bitset<8> bits;

        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                if (archivo.read(reinterpret_cast<char*>(&bits), sizeof(bits))) {
                    numero = static_cast<int>(bits.to_ulong());
                    matriz[i][j] = numero;
                } else {
                    cout << "Error al leer el archivo binario." << endl;
                    return {{}};
                }
            }
        }

        return matriz;
    } else {
        cout << "Hubo un error al abrir el archivo binario." << endl;
        return {{}};
    }
}
