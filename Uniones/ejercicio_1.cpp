#include <iostream>
using namespace std;

union Convertidor {
    int entero; // 4 bytes
    float flotante; // 4 bytes
};

int main() {

    Convertidor convertidor;
    
    convertidor.entero = 10;    
    cout<<"Entero: "<<convertidor.entero<<endl;
    cout<<"Flotante: "<<convertidor.flotante<<endl;

    convertidor.flotante = 15.5f;
    cout<<"Entero: "<<convertidor.entero<<endl;
    cout<<"Flotante: "<<convertidor.flotante<<endl;
    
    cout<<sizeof(Convertidor)<<endl;

    return 0;
}