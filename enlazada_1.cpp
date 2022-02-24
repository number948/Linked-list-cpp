#include<iostream>

using namespace std;

struct nodo{
    int dato;
    nodo* siguiente;
    nodo* atras;
} *primero, *ultimo;

void insertarNodo();
void imprimir();
void printList();
void bubbleSort();


//creamos funciona para insertarle nodos a la lista
void insertarNodo(){
    nodo* nuevo = new nodo;

    cout<<"ingere el dato que contendra el nodo: "<<endl;
    cin>>nuevo->dato;

    if(primero == NULL){
        primero = nuevo;
        primero -> siguiente = NULL;
        primero -> atras = NULL;
        ultimo = primero;
    }
    else{
        //como primero ya no es nulo...
        ultimo -> siguiente = nuevo;
        nuevo -> siguiente = NULL;
        nuevo -> atras =ultimo;
        ultimo = nuevo; //el nuevo ultimo dato del arreglo es el nuevo ultimo
    }
    cout << "Nodo ingresado\n\n";

}

void imprimir(){
    nodo* actual = new nodo;

    actual = primero;

    if(primero != NULL){
        //esto quiere decir que hay nodos enla lista, ahora vamos a recorrerla
        while(actual != NULL){
            cout<<" "<<actual -> dato;
            actual = actual ->siguiente;
        }
    }else{
        cout<< "la lista se encuentra vacia";
    }
}

void printList(struct nodo *actual_2){
    struct nodo *temp = actual_2;


    while(temp !=NULL){
        cout<<" "<<temp -> dato;
        temp = temp -> siguiente;
    }
}

void bubbleSort( struct nodo *actual_2){
int swapped, i;

//aqui crea dis nuevos nodos
struct nodo *ptr1;
struct nodo *lptr = NULL;

//verificar si lista está vacía

if(actual_2 == NULL){
    return;
}


do
{
    swapped = 0; //contador de cambios de numeros que hace
    ptr1 = actual_2;

 while (ptr1 ->siguiente != lptr)
{
    if(ptr1-> dato > ptr1 -> siguiente -> dato){
        swap(ptr1 ->dato, ptr1 -> siguiente -> dato);
        swapped = 1;
    }
    ptr1 = ptr1 ->siguiente;
}
lptr = ptr1;
}
while(swapped);
}


int main(){

    struct nodo *actual_2;
    //esto se pone para llamar las veces iguales a la cantidad de datos que quieres ingresar a la funciona
    insertarNodo();
    insertarNodo();
    cout<<"\n lista:\n\n ";
    imprimir();

    
    
    bubbleSort(actual_2);

    cout<<"\n lista ordenada:\n\n ";
    printList(actual_2);
    

    return 0;
}
