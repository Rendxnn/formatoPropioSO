#include "crearMatriz.cpp"
#include "escribirArchivos.cpp"
#include "leerArchivos.cpp"
using namespace std;


void imprimir_matriz(vector<vector<int>> matriz) {
	for (auto const& fila: matriz) {
		for (auto const& numero: fila) {
			cout << numero << " ";
		}
		cout << endl;
	}
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		cerr << "uso: " << argv[0] << "<filas> <columnas>";
		return 1;
	}

	vector<vector<int>> matriz = crear_matriz(stoi(argv[1]), stoi(argv[2]));

	cout << "MATRIZ CREADA" << endl;

	imprimir_matriz(matriz);

	escribir_archivo_plano(matriz);

	escribir_archivo_binario(matriz);




	cout << endl << "MATRIZ LEIDA TEXTO" << endl;

	vector<vector<int>> matriz_leida_texto = leer_archivo_texto("matriz.txt");

	imprimir_matriz(matriz_leida_texto);



	cout << endl << "MATRIZ LEIDA BINARIO" << endl;

	vector<vector<int>> matriz_leida_binario = leer_archivo_binario("matriz.bin");

	

	imprimir_matriz(matriz_leida_binario);



	
	return 0;
}



