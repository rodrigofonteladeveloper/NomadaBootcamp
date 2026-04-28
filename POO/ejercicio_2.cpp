#include <iostream>
using namespace std;

struct Libro
{
    string titulo;
    string autor;
    int anioPublicacion;
};

void llenarInfoLibro(Libro &libro)
{
    cout<<"Ingresa el titulo del libro: ";
    getline(cin, libro.titulo);

    cout<<"Ingresa el autor del libro: ";
    getline(cin, libro.autor);

    cout<<"Ingresa el anio de publicacion del libro: ";
    cin>>libro.anioPublicacion;
    
    cin.ignore();
}

void mostrarInfoLibro(Libro libro)
{
    cout<<"Informacion del libro"<<endl;
    cout<<"Titulo: "<<libro.titulo<<endl;
    cout<<"Autor: "<<libro.autor<<endl;
    cout<<"Anio Publicacion: "<<libro.anioPublicacion<<endl;
}

int main() {
    
    Libro libro1, libro2;

    llenarInfoLibro(libro1);
    mostrarInfoLibro(libro1);

    return 0;
}