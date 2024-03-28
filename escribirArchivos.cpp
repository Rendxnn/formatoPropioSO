#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <opencv2/opencv.hpp>

using namespace std; 


void escribir_archivo_plano(vector<vector<vector<int>>> matriz) {
	ofstream archivo("plano.txt");

	if (archivo.is_open()) {
		archivo << matriz.size() << " " << matriz[0].size() << endl;
		for (vector<vector<int>> fila: matriz) {
			for (vector<int> pixel: fila) {
                for (int color: pixel) {
                    archivo << color << " ";
                }
			}
			archivo << endl;
		}
		archivo.close();
	}
	else {
		cout << "error al escribir el archivo plano";
	}
}


void escribir_archivo_binario(vector<vector<vector<int>>> matriz) {
    ofstream archivo("binario.medic", ios::binary);

    if (archivo.is_open()) {
        int filas = matriz.size();
        int columnas = matriz[0].size();

        unsigned short binario_filas = static_cast<unsigned short>(filas);
        unsigned short binario_columnas = static_cast<unsigned short>(columnas);

        archivo.write(reinterpret_cast<const char*>(&binario_filas), sizeof(binario_filas));
        archivo.write(reinterpret_cast<const char*>(&binario_columnas), sizeof(binario_columnas));

        for (vector<vector<int>> fila: matriz) {
            for (vector<int> pixel: fila) {
                for (int color: pixel) {
                    unsigned short binario = static_cast<unsigned short>(color);
                    archivo.write(reinterpret_cast<const char*>(&binario), sizeof(binario)); 
                }
            }
        }
    }
}


void generar_imagen(vector<vector<vector<int>>> matriz_imagen) {
    int filas = matriz_imagen.size();
    int columnas = matriz_imagen[0].size();


    cv::Mat imagen(filas, columnas, CV_8UC3);

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cv::Vec3b &pixel = imagen.at<cv::Vec3b>(i, j);

            pixel[0] = matriz_imagen[i][j][0];
            pixel[1] = matriz_imagen[i][j][1];
            pixel[2] = matriz_imagen[i][j][2];
        }
    }

    cv::imshow("imagen leida", imagen);
    cv::imwrite("imagen_salida.jpg", imagen);
    cv::waitKey(0);


}
