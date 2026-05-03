// Desarrollar un programa que determine si una matriz es simetrica o no. Una matriz es simetrica si es cuadrada y si es igual a su matriz transpuesta

#include <iostream>
using namespace std;

const int FILAS = 50;
const int COLUMNAS = 50;

void llenarMatriz(int matriz[FILAS][COLUMNAS], int filas, int columnas)
{
    cout<<"LLENANDO MATRIZ"<<endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout<<"Ingrese el valor para ["<<i<<"]"<<"["<<j<<"]"<<": ";
            cin>>matriz[i][j];
        }
    }
}

void mostrarMatriz(int matriz[FILAS][COLUMNAS], int filas, int columnas)
{
    cout<<"MOSTRANDO MATRIZ"<<endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
}

void transponerMatriz(int matriz[FILAS][COLUMNAS], int matrizTrans[FILAS][COLUMNAS], int filas, int columnas)
{
    cout<<"TRANSPONIENDO MATRIZ..."<<endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matrizTrans[j][i] = matriz[i][j];
        }
    }
}

int main() {

    int filas, columnas;
    
    cout<<"Ingrese el numero de filas: ";
    cin>>filas;

    cout<<"Ingrese el numero de columnas: ";
    cin>>columnas;

    // 1. Verificar si es una matriz cuadrada
    if (filas != columnas)
    {
        cout<<"No es una matriz cuadrada"<<endl;
        return 0;
    }
    
    int matrizOriginal[FILAS][COLUMNAS];

    // 2. Llenar nuestra matriz original
    llenarMatriz(matrizOriginal, filas, columnas);

    // 3. Mostrar mi matriz
    mostrarMatriz(matrizOriginal, filas, columnas);

    int matrizTranspuesta[FILAS][COLUMNAS];

    // 4. Transponer matriz original
    transponerMatriz(matrizOriginal, matrizTranspuesta, filas, columnas);

    // 5. Mostrar mi matriz transpuesta
    mostrarMatriz(matrizTranspuesta, filas, columnas);

    return 0;
}