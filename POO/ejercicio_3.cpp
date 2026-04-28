#include <iostream>
using namespace std;

struct Producto
{
    string nombre;
    float precio;
    int stock;
};

void llenarProductos(Producto productos[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<"PRODUCTO "<<i+1<<endl;
        cout<<"Ingresa el nombre: ";
        getline(cin, productos[i].nombre);

        cout<<"Ingresa el precio: ";
        cin>>productos[i].precio;

        cout<<"Ingresa el stock: ";
        cin>>productos[i].stock;
        cin.ignore();
    }
}

float obtenerMasCaro(Producto productos[], int n)
{
    float supuesto = productos[0].precio;
    
    for (int i = 1; i < n; i++)
    {
        if (productos[i].precio > supuesto)
        {
            supuesto = productos[i].precio;
        }
    }
    
    return supuesto;
}

int obtenerMayorStock(Producto productos[], int n)
{
    int supuesto = productos[0].stock;
    
    for (int i = 0; i < n; i++)
    {
        if (productos[i].stock > supuesto)
        {
            supuesto = productos[i].stock;
        }
    }
    
    return supuesto;
}

void mostrarDetalleProductos(Producto productos[], int n, float masCaro, int mayorStock)
{
    for (int i = 0; i < n; i++)
    {
        cout<<"INFORMACION PRODUCTO "<<i+1<<endl;
        cout<<"Nombre: "<<productos[i].nombre<<endl;
        cout<<"Precio: "<<productos[i].precio<<endl;
        cout<<"Stock: "<<productos[i].stock<<endl;
    }

    cout<<"Precio del producto mas caro: "<<masCaro<<endl;
    cout<<"Mayor stock de producto: "<<mayorStock<<endl;
}

void mostrarProductos(Producto productos[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<"INFORMACION PRODUCTO "<<i+1<<endl;
        cout<<"Nombre: "<<productos[i].nombre<<endl;
        cout<<"Precio: "<<productos[i].precio<<endl;
        cout<<"Stock: "<<productos[i].stock<<endl;
    }
}


int main() {

    int n, productoMayorStock;
    float productoMasCaro;
    
    cout<<"Cantidad de productos a ingresar: ";
    cin>>n;
    cin.ignore();
    
    Producto productos[n];
    
    llenarProductos(productos, n);
    productoMasCaro = obtenerMasCaro(productos, n);
    productoMayorStock = obtenerMayorStock(productos, n);
    mostrarDetalleProductos(productos, n, productoMasCaro, productoMayorStock);

    return 0;
}