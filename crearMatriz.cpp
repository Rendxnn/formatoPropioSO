#include <iostream>
#include <random>
#include <vector>

using namespace std;



vector<vector<int>> crear_matriz(int filas, int columnas) {
	vector<vector<int>> matriz(filas, vector<int>(columnas));
	int numero_aleatorio = 0;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distribucion(0, 99);

	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			numero_aleatorio = distribucion(gen);
			matriz[i][j] = numero_aleatorio;
		}
	}

	return matriz;
}