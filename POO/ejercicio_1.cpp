#include <iostream>
using namespace std;

struct Estudiante 
{
    string nombre;
    float calificaciones[5];
};

void llenarEstudiante(Estudiante &est)
{
    cout<<"Ingresa el nombre del estudiante: ";
    getline(cin, est.nombre);
    
    cout<<"Ingresa las calificaciones del alumno "<<est.nombre<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<"Calificacion "<<i+1<<": ";
        cin>>est.calificaciones[i];
    }
    
    cin.ignore();
}

float calcularPromedio(Estudiante est)
{
    float suma = 0;
    for (int i = 0; i < 5; i++)
    {
        suma += est.calificaciones[i];
    }
    
    return suma / 5;
}

void mostrarInfoEstudiante(Estudiante est, float promedio)
{
    cout<<"El nombre del estudiante es: "<<est.nombre<<endl;
    cout<<"Las calificaciones del estudiantes fueron: "<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<"Calificacion "<<i + 1<<": "<<est.calificaciones[i]<<endl;
    }
    cout<<"El promedio fue de: "<<promedio<<endl;
}

int main() {

    Estudiante est;

    llenarEstudiante(est);

    float promedio = calcularPromedio(est);
        
    mostrarInfoEstudiante(est, promedio);

    return 0;
}