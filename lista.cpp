#include<iostream>

using namespace std;

class Nodo{
	public:
		int valor;
		Nodo * siguiente;
		Nodo(int v=0){valor=v; siguiente=NULL;}
};

class Lista{
	public:
		Nodo * inicio;
		Lista(){inicio=NULL;}
		void insertar(int valor);
		void mostrar();
		void eliminar_nodo(int n);
		void buscar(int e);
};

void Lista::insertar(int valor){
	Nodo * nuevo = new Nodo(valor); //creamo el nuevo nodo
	if(inicio == NULL){ // si esta vacia la lista
		inicio = nuevo;
	}
	else{
		Nodo * aux = inicio; //creamos copia de inicio
		while(aux->siguiente != NULL){
			aux=aux->siguiente;// movemos el puntero al siguiente nodo
		}
		nuevo->siguiente=aux->siguiente; //nuevo apunta al siguiente de aux
		aux->siguiente=nuevo;  // aux apunta al nuevo elemento
	}
}

void Lista::mostrar(){
    Nodo *aux=inicio;
    while(aux!=NULL){
        cout<<aux->valor<<" ";
        aux=aux->siguiente; // movemos el puntero al siguiente nodo
    }
}

void Lista::eliminar_nodo(int n){
    if(inicio!=NULL){ //verifica que la lista no este vacia
        Nodo *aux_borrar;
        Nodo *anterior=NULL;

        aux_borrar=inicio;
        while((aux_borrar!=NULL)&&(aux_borrar->valor!=n)){ //recorre la lista
            anterior=aux_borrar;
            aux_borrar=aux_borrar->siguiente; // movemos el puntero al siguiente nodo
        }
        if(aux_borrar==NULL){
            cout<<"El elemento no existe";
        }
        else if(anterior==NULL){
            inicio=inicio->siguiente; // movemos el puntero al siguiente nodo
            delete aux_borrar;
        }
        else{
            anterior->siguiente=aux_borrar->siguiente; //anterior apunta al siguiente de aux_borrar
            delete aux_borrar;
        }
    }
}

void Lista::buscar(int e){
    bool band=false;

    Nodo *actual=new Nodo();
    actual=inicio;

    while((actual!=NULL)&&(actual->valor<=e)){
        if(actual->valor==e){
            band=true;
        }
        actual=actual->siguiente; // movemos el puntero al siguiente nodo
    }
    if(band==true){
        cout<<"Elemento "<<e<<" SI a sido encontrado en la lista\n";
    }
    else{
        cout<<"Elemento "<<e<<" NO a sido encontrado en la lista\n";
    }
}

int main(){

	Lista * lista1=new Lista(); //creamos una lista y llamamos a su constructor

	//insertamos valores a la lista1
	lista1->insertar(3);
	lista1->insertar(5);
	lista1->insertar(10);
	cout<<"La lista es: "<<endl;
	lista1->mostrar();
	cout<<"\nEliminando un nodo..."<<endl;
	lista1->eliminar_nodo(5);
	cout<<"\nLa nueva lista es: "<<endl;
	lista1->mostrar();
	cout<<"\nBuscando un elemento..."<<endl;
	lista1->buscar(2);
	cout<<"\nBuscando un elemento..."<<endl;
	lista1->buscar(3);
	return 0;
}
