#include<iostream>

using namespace std;

struct nodo{
    int dato;
    nodo* siguiente;
    nodo* atras;
} *primero, *ultimo;



void insertarNodo();
void imprimir();
void sorting();



/* void insertarNodo(){
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
*/
void insertar(struct nodo **start_referencia, int dato){
struct nodo *ptr1 = new nodo;
    ptr1->dato = dato;
    ptr1->siguiente = *start_referencia;
    if (*start_referencia != NULL)
       (*start_referencia)->atras = ptr1;
    *start_referencia = ptr1;
}
void imprimir(struct nodo *start){
     struct nodo* actual = start;

   
        //esto quiere decir que hay nodos enla lista, ahora vamos a recorrerla
        while(actual != NULL){
            cout<<" "<<actual -> dato;
            actual = actual ->siguiente;
        }
   
}

void sorting(struct nodo *start){
    int swapped, i;
    struct nodo *ptr1;
    struct nodo *lptr = NULL;
  
    /* Checking for empty list */
    if (start == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = start;
  
        while (ptr1-> siguiente != lptr)
        {
            if (ptr1->dato > ptr1-> siguiente->dato)
            {
                swap(ptr1->dato, ptr1->siguiente->dato);
                swapped = 1;
            }
            ptr1 = ptr1->siguiente;
        }
        lptr = ptr1;
    }
    while (swapped);
}

int main(){

    int largo, i;
    int lista[] = { 90, 8, 4};

    
    

    struct nodo *start = NULL; 

    
    for (i = 0; i< 3; i++)
        insertar(&start, lista[i]);
    

    cout<<"\n lista:\n ";
    imprimir(start);

    sorting(start);

    cout<<"\n lista ordenada:\n";
    imprimir(start);
    return 0; 
}
