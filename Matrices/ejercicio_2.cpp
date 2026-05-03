// Desarrolla un programa que calcule el producto de dos matrices cuadradas

#include <iostream>
using namespace std;

const int FILAS = 50;
const int COLUMNAS = 50;

void llenarMatriz(int matriz[FILAS][COLUMNAS], char letra, int filas, int columnas)
{
    cout<<"LLENANDO MATRIZ "<<letra<<endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout<<"Ingrese el valor para ["<<i<<"]"<<"["<<j<<"]"<<": ";
            cin>>matriz[i][j];
        }
    }
}

void mostrarMatriz(int matriz[FILAS][COLUMNAS], char letra, int filas, int columnas)
{
    cout<<"MOSTRANDO MATRIZ "<<letra<<endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
}

void productoMatrices(int matrizP[FILAS][COLUMNAS], int matrizA[FILAS][COLUMNAS], int matrizB[FILAS][COLUMNAS], int filas, int columnas)
{
    cout<<"PRODUCTO DE MATRICES"<<endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matrizP[i][j] = 0;
        
            for (int k = 0; k < columnas; k++)
            {
                matrizP[i][j] += matrizA[i][k] * matrizB[k][j];
            }
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
    
    int matrizA[FILAS][COLUMNAS];
    int matrizB[FILAS][COLUMNAS];
    int matrizProducto[FILAS][COLUMNAS];

    // 2. Llenar nuestra matriz A
    llenarMatriz(matrizA, 'A', filas, columnas);
    // 3. Mostrar matriz A
    mostrarMatriz(matrizA, 'A', filas, columnas);

    // 4. Llenar nuestra matriz A
    llenarMatriz(matrizB, 'B', filas, columnas);
    // 5. Mostrar matriz A
    mostrarMatriz(matrizB, 'B', filas, columnas);
    
    // 6. Realizar producto de matriz A x matriz B
    productoMatrices(matrizProducto, matrizA, matrizB, filas, columnas);
    // 7. Mostrar matriz Productos
    mostrarMatriz(matrizProducto, 'P', filas, columnas);

    return 0;
}