#include <iostream>

using namespace std;

struct nodo
{
    int dato;
    nodo *sig;
    nodo *prev;

} * fin;

class ListaEnlazada
{
private:
    nodo *inicio;

public:
    nodo *crearNodo(int valor)
    {
        nodo *n = new nodo;
        n->dato = valor;
        n->sig = nullptr;
        n->prev = nullptr;
        return n;
    }
    void mostrarListaAdelante()
    {
        nodo *temp = inicio;
        if (!inicio)
        {
            cout << "Lista vacia";
        }
        else
        {
            while (temp)
            {
                cout << temp->dato << ", ";
                temp = temp->sig;
            }
        }
    }

    void mostrarListaAtras()
    {
        nodo *temp = fin;
        if (!inicio)
        {
            cout << "Lista vacia";
        }
        else
        {
            while (temp)
            {
                cout << temp->dato << ", ";
                temp = temp->prev;
            }
        }
    }

    void agregarElemento(int valor)
    {
        nodo *n = crearNodo(valor);
        if (!inicio)
        {
            inicio = n;
            fin = n;
        }
        else
        {
            fin->sig = n;
            n->prev = fin;
            fin = n;
        }
    }

    void eliminar(int valor)
    {
        int flag = 0;
        nodo *actual = inicio;

        while (actual && flag == 0)
        {
            if (actual->sig->dato == valor)
            {

                actual->sig->prev = actual->prev;
                actual->prev->sig = actual->sig;

                free(actual);
                flag = 1;
            }
            else
            {
                actual = actual->sig;
            }
        }
    }

    ListaEnlazada()
    {
        this->inicio = nullptr;
    }
};

int main()
{
    ListaEnlazada lista;
    lista.agregarElemento(1);
    lista.agregarElemento(2);
    lista.agregarElemento(3);
    lista.mostrarListaAdelante();
    lista.eliminar(3);
    lista.mostrarListaAdelante();

    return 0;
}
