// Crea un programa que gestione productos. Algunos se venden por unidades y otros por peso

#include <iostream>
using namespace std;

struct Producto {
    int id; // 4 bytes
    char tipo; // 1 byte
    union {
        int cantidad; // 4 bytes
        float peso; // 4 bytes
    };
};

int main() {
    // laptop
    Producto producto1;
    producto1.id = 101;
    producto1.tipo = 'C';
    producto1.cantidad = 5;

    // manzana
    Producto producto2;
    producto2.id = 101;
    producto2.tipo = 'P';
    producto2.peso = 2.5f;

    cout<<"PRODUCTO 1"<<endl;
    cout<<"ID: "<<producto1.id<<endl;
    cout<<"TIPO: "<<producto1.tipo<<endl;
    cout<<"CANTIDAD: "<<producto1.cantidad<<endl;

    cout<<"PRODUCTO 2"<<endl;
    cout<<"ID: "<<producto2.id<<endl;
    cout<<"TIPO: "<<producto2.tipo<<endl;
    cout<<"CANTIDAD: "<<producto2.peso<<endl;
    
    cout<<"TAMANO PRODUCTO: "<<sizeof(Producto)<<endl;

    return 0;
}