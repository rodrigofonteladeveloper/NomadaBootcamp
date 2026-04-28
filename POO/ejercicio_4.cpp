/*
Escribe un programa que mediante un menú, gestione los datos de un conjunto de alumnos en
un curso determinado. Deberá tener las opciones de ingreso, consulta, modificación,
eliminación y listado

menu => do while + switch (variable opcion)
struct => agrupar datos del alumno (id, nombre, edad, curso)
ingreso (array alumnos, numero alumnos)
consulta(array alumnos, id alumno)
modificacion(array alumnos, id alumno)
eliminacion (array alumnos, id alumno)
listado(array alumnos) 
*/

#include <iostream>
using namespace std;

const int TAMANIO = 10;

struct Alumno {
    int id;
    string nombre;
    int edad;
    string curso;
};

int mostrarMenu() {
    int opcion;
    
    cout<<"==============================="<<endl;
    cout<<"MENU PRINCIPAL"<<endl;
    cout<<"1. Ingresar nuevo alumno"<<endl;
    cout<<"2. Consultar alumno"<<endl;
    cout<<"3. Modificar alumno"<<endl;
    cout<<"4. Eliminar alumno"<<endl;
    cout<<"5. Listar alumnos"<<endl;
    cout<<"6. Salir"<<endl;
    cout<<"Ingresa tu opcion: ";
    cin>>opcion;
    cout<<"==============================="<<endl;
    
    cin.ignore();
    
    return opcion;
}

void ingresarAlumno(Alumno alumnos[], int &contador, int &id) {
    for (int i = contador; i > 0; i--) {
        alumnos[i] = alumnos[i - 1];
    }
    
    cout<<"DATOS NUEVO ALUMNO"<<endl;
    alumnos[0].id = id;

    cout<<"Nombre alumno: ";
    getline(cin, alumnos[0].nombre);
    
    cout<<"Edad alumno: ";
    cin>>alumnos[0].edad;
    cin.ignore();

    cout<<"Curso: ";
    getline(cin, alumnos[0].curso);
    
    contador++;
    id++;
}

void consultaAlumno(Alumno alumnos[], int contador) {
    bool existeAlumno = false;

    if (contador == 0) {
        cout<<"No hay ninguno alumno registrado hasta el momento..."<<endl;
        return;
    }
    
    int alumnoId;
    cout<<"CONSULTA ALUMNO"<<endl;
    cout<<"Ingresa el ID del alumno: ";
    cin>>alumnoId;

    for (int i = 0; i < contador; i++) {
        if (alumnos[i].id == alumnoId) {
            cout<<"ALUMNO ENCONTRADO"<<endl;
            cout<<"Nombre alumno: "<<alumnos[i].nombre<<endl;
            cout<<"Edad alumno: "<<alumnos[i].edad<<endl;
            cout<<"Curso alumno: "<<alumnos[i].curso<<endl;
            existeAlumno = true;
        }
    }
    
    if (!existeAlumno) cout<<"ID invalido de Alumno..."<<endl;
}

void modificarAlumno(Alumno alumnos[], int contador) {
    bool existeAlumno = false;

    if (contador == 0) {
        cout<<"No hay ninguno alumno registrado hasta el momento..."<<endl;
        return;
    }
    
    int alumnoId;
    cout<<"MODIFICAR ALUMNO"<<endl;
    cout<<"Ingresa el ID del alumno: ";
    cin>>alumnoId;
    cin.ignore();

    for (int i = 0; i < contador; i++) {
        if (alumnos[i].id == alumnoId) {
            cout<<"ALUMNO ENCONTRADO"<<endl;
            cout<<"Nuevo nombre alumno: ";
            getline(cin, alumnos[i].nombre);

            cout<<"Nueva edad alumno: ";
            cin>>alumnos[i].edad;
            cin.ignore();

            cout<<"Nuevo curso alumno: ";
            getline(cin, alumnos[i].curso);

            existeAlumno = true;
        }
    }    

    if (existeAlumno) {
        cout<<"Alumno modificado con exito"<<endl;
    } else {
        cout<<"ID Alumno invalido..."<<endl;
    }
}

void eliminarAlumno(Alumno alumnos[], int &contador) {
    bool existeAlumno = false;

    if (contador == 0) {
        cout<<"No hay ninguno alumno registrado hasta el momento..."<<endl;
        return;
    }
    
    int alumnoId, position;
    cout<<"ELIMINAR ALUMNO"<<endl;
    cout<<"Ingresa el ID del alumno: ";
    cin>>alumnoId;
    cin.ignore();

    for (int i = 0; i < contador; i++) {
        if (alumnos[i].id == alumnoId) {
            existeAlumno = true;
            position = i;
            break;
        }
    }
    
    if (existeAlumno)  {
        for (int i = position; i < contador; i++) {
            alumnos[i] = alumnos[i + 1];
        }
        contador--;
        cout<<"Alumno eliminado con exito"<<endl;
    } else {
        cout<<"ID Alumno invalido..."<<endl;
    }
}

void listarAlumnos(Alumno alumnos[], int contador) {
    if (contador == 0) {
        cout<<"No hay ninguno alumno registrado hasta el momento..."<<endl;
        return;
    }

    int j = 1;
    cout<<"LISTA ALUMNOS"<<endl;
    for (int i = contador; i > 0; i--) {
        cout<<"==============================="<<endl;
        cout<<"ALUMNO "<<j<<endl;
        cout<<"ID alumno: "<<alumnos[i - 1].id<<endl;
        cout<<"Nombre alumno: "<<alumnos[i - 1].nombre<<endl;
        cout<<"Edad alumno: "<<alumnos[i - 1].edad<<endl;
        cout<<"Curso alumno: "<<alumnos[i - 1].curso<<endl;
        cout<<"==============================="<<endl;
        j++;
    }
}

int main() {

    int opcion, contador = 0, id = 1;
    Alumno alumnos[TAMANIO];
    
    do
    {
        opcion = mostrarMenu();

        switch (opcion) {
            case 1:
                ingresarAlumno(alumnos, contador, id);
                cout<<"Alumno registrado con exito"<<endl;
                break;
            case 2:
                consultaAlumno(alumnos, contador);
                break;
            case 3:
                modificarAlumno(alumnos, contador);
                break;
            case 4:
                eliminarAlumno(alumnos, contador);
                break;
            case 5:
                listarAlumnos(alumnos, contador);
                break;
            case 6:
                cout<<"Saliendo del sistema..."<<endl;
                break;
            default:
                cout<<"Opcion no valida..."<<endl;
        }

    } while (opcion != 6);

    return 0;
}