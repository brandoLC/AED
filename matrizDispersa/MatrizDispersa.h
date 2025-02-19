//
// Created by brano on 19/02/2025.
//

#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H

#include <iostream>
using namespace std;

// Nodo que representa un elemento no nulo en la matriz
struct NodoElemento {
    int fila, columna, valor;
    NodoElemento* siguiente; // Enlace al siguiente en la fila
    NodoElemento* abajo;     // Enlace al siguiente en la columna

    NodoElemento(int f, int c, int v) {
        fila = f;
        columna = c;
        valor = v;
        siguiente = abajo = nullptr;
    }
};

// Nodo cabecera que representa el inicio de una fila o columna
struct NodoCabecera {
    int indice; // Índice de la fila o columna
    NodoElemento* primerElemento; // Primer nodo en la fila o columna
    NodoCabecera* siguiente; // Siguiente cabecera (fila o columna)

    explicit NodoCabecera(int i) {
        indice = i;
        primerElemento = nullptr;
        siguiente = nullptr;
    }
};

// Nodo detalle que almacena información general de la matriz
struct NodoDetalle {
    int totalFilas, totalColumnas;
    NodoCabecera* filas;
    NodoCabecera* columnas;

    NodoDetalle(int filas, int columnas) {
        totalFilas = filas;
        totalColumnas = columnas;
        this->filas = nullptr;
        this->columnas = nullptr;
    }
};

// Clase que representa la matriz dispersa
class MatrizDispersa {
private:
    NodoDetalle* detalle;

public:
    MatrizDispersa(int filas, int columnas);
    void insertar(int fila, int columna, int valor);
    void imprimir();
    int buscar(int fila, int columna);
    void eliminar(int fila, int columna);
    MatrizDispersa sumar(const MatrizDispersa& otra);
    MatrizDispersa restar(const MatrizDispersa& otra);
    MatrizDispersa multiplicar(const MatrizDispersa& otra);
    MatrizDispersa multiplicarPorConstante(int constante);

private:
    NodoCabecera* obtenerCabecera(NodoCabecera* cabecera, int indice);
    void insertarCabecera(NodoCabecera** cabecera, NodoCabecera* nueva);
    void insertarEnLista(NodoElemento** lista, NodoElemento* nuevo, bool esFila);
    void actualizarValor(int fila, int columna, int valor);
};

// Implementación de los métodos de la clase MatrizDispersa
MatrizDispersa::MatrizDispersa(int filas, int columnas) {
    detalle = new NodoDetalle(filas, columnas);
}

void MatrizDispersa::insertar(int fila, int columna, int valor) {
    if (valor == 0) return; // No almacenamos valores nulos

    // Buscar o crear la cabecera de fila
    NodoCabecera* cabFila = obtenerCabecera(detalle->filas, fila);
    if (!cabFila) {
        cabFila = new NodoCabecera(fila);
        insertarCabecera(&(detalle->filas), cabFila);
    }

    // Buscar o crear la cabecera de columna
    NodoCabecera* cabColumna = obtenerCabecera(detalle->columnas, columna);
    if (!cabColumna) {
        cabColumna = new NodoCabecera(columna);
        insertarCabecera(&(detalle->columnas), cabColumna);
    }

    // Crear nuevo nodo de elemento
    NodoElemento* nuevo = new NodoElemento(fila, columna, valor);

    // Insertar en la fila
    insertarEnLista(&(cabFila->primerElemento), nuevo, true);

    // Insertar en la columna
    insertarEnLista(&(cabColumna->primerElemento), nuevo, false);
}

void MatrizDispersa::imprimir() {
    cout << "Elementos de la matriz dispersa:" << endl;
    NodoCabecera* f = detalle->filas;
    while (f) {
        NodoElemento* e = f->primerElemento;
        while (e) {
            cout << "Fila: " << e->fila << ", Columna: " << e->columna << ", Valor: " << e->valor << endl;
            e = e->siguiente;
        }
        f = f->siguiente;
    }
}

int MatrizDispersa::buscar(int fila, int columna) {
    NodoCabecera* cabFila = obtenerCabecera(detalle->filas, fila);
    if (!cabFila) return 0;

    NodoElemento* actual = cabFila->primerElemento;
    while (actual) {
        if (actual->columna == columna) return actual->valor;
        actual = actual->siguiente;
    }
    return 0;
}

void MatrizDispersa::eliminar(int fila, int columna) {
    NodoCabecera* cabFila = obtenerCabecera(detalle->filas, fila);
    if (!cabFila) return;

    NodoElemento* actual = cabFila->primerElemento;
    NodoElemento* anterior = nullptr;
    while (actual) {
        if (actual->columna == columna) {
            if (anterior) anterior->siguiente = actual->siguiente;
            else cabFila->primerElemento = actual->siguiente;
            break;
        }
        anterior = actual;
        actual = actual->siguiente;
    }

    NodoCabecera* cabColumna = obtenerCabecera(detalle->columnas, columna);
    if (!cabColumna) return;

    actual = cabColumna->primerElemento;
    anterior = nullptr;
    while (actual) {
        if (actual->fila == fila) {
            if (anterior) anterior->abajo = actual->abajo;
            else cabColumna->primerElemento = actual->abajo;
            delete actual;
            break;
        }
        anterior = actual;
        actual = actual->abajo;
    }
}

MatrizDispersa MatrizDispersa::sumar(const MatrizDispersa& otra) {
    MatrizDispersa resultado(detalle->totalFilas, detalle->totalColumnas);
    for (NodoCabecera* f = detalle->filas; f != nullptr; f = f->siguiente) {
        for (NodoElemento* e = f->primerElemento; e != nullptr; e = e->siguiente) {
            resultado.insertar(e->fila, e->columna, e->valor);
        }
    }
    for (NodoCabecera* f = otra.detalle->filas; f != nullptr; f = f->siguiente) {
        for (NodoElemento* e = f->primerElemento; e != nullptr; e = e->siguiente) {
            resultado.actualizarValor(e->fila, e->columna, resultado.buscar(e->fila, e->columna) + e->valor);
        }
    }
    return resultado;
}

MatrizDispersa MatrizDispersa::restar(const MatrizDispersa& otra) {
    MatrizDispersa resultado(detalle->totalFilas, detalle->totalColumnas);
    for (NodoCabecera* f = detalle->filas; f != nullptr; f = f->siguiente) {
        for (NodoElemento* e = f->primerElemento; e != nullptr; e = e->siguiente) {
            resultado.insertar(e->fila, e->columna, e->valor);
        }
    }
    for (NodoCabecera* f = otra.detalle->filas; f != nullptr; f = f->siguiente) {
        for (NodoElemento* e = f->primerElemento; e != nullptr; e = e->siguiente) {
            resultado.actualizarValor(e->fila, e->columna, resultado.buscar(e->fila, e->columna) - e->valor);
        }
    }
    return resultado;
}

MatrizDispersa MatrizDispersa::multiplicar(const MatrizDispersa& otra) {
    if (detalle->totalColumnas != otra.detalle->totalFilas) {
        throw invalid_argument("No se pueden multiplicar las matrices: dimensiones incompatibles.");
    }

    MatrizDispersa resultado(detalle->totalFilas, otra.detalle->totalColumnas);

    // Recorrer las filas de la primera matriz
    for (NodoCabecera* f = detalle->filas; f != nullptr; f = f->siguiente) {
        for (NodoElemento* e = f->primerElemento; e != nullptr; e = e->siguiente) {

            // Buscar la columna correspondiente en la segunda matriz
            NodoCabecera* cabColumna = obtenerCabecera(otra.detalle->filas, e->columna);
            if (!cabColumna) continue;  // No hay elementos en esta columna

            // Recorrer los elementos de esa columna en la segunda matriz
            for (NodoElemento* ec = cabColumna->primerElemento; ec != nullptr; ec = ec->siguiente) {
                // Multiplicar y acumular en la posición correspondiente
                int nuevoValor = resultado.buscar(e->fila, ec->columna) + e->valor * ec->valor;
                resultado.actualizarValor(e->fila, ec->columna, nuevoValor);
            }
        }
    }

    return resultado;
}

MatrizDispersa MatrizDispersa::multiplicarPorConstante(int constante) {
    MatrizDispersa resultado(detalle->totalFilas, detalle->totalColumnas);
    for (NodoCabecera* f = detalle->filas; f != nullptr; f = f->siguiente) {
        for (NodoElemento* e = f->primerElemento; e != nullptr; e = e->siguiente) {
            resultado.insertar(e->fila, e->columna, e->valor * constante);
        }
    }
    return resultado;
}

NodoCabecera* MatrizDispersa::obtenerCabecera(NodoCabecera* cabecera, int indice) {
    while (cabecera) {
        if (cabecera->indice == indice) return cabecera;
        cabecera = cabecera->siguiente;
    }
    return nullptr;
}

void MatrizDispersa::insertarCabecera(NodoCabecera** cabecera, NodoCabecera* nueva) {
    if (!*cabecera || (*cabecera)->indice > nueva->indice) {
        nueva->siguiente = *cabecera;
        *cabecera = nueva;
    } else {
        NodoCabecera* aux = *cabecera;
        while (aux->siguiente && aux->siguiente->indice < nueva->indice)
            aux = aux->siguiente;
        nueva->siguiente = aux->siguiente;
        aux->siguiente = nueva;
    }
}

void MatrizDispersa::insertarEnLista(NodoElemento** lista, NodoElemento* nuevo, bool esFila) {
    if (!*lista || (esFila ? (*lista)->columna : (*lista)->fila) > (esFila ? nuevo->columna : nuevo->fila)) {
        if (esFila) nuevo->siguiente = *lista;
        else nuevo->abajo = *lista;
        *lista = nuevo;
    } else {
        NodoElemento* aux = *lista;
        while ((esFila ? aux->siguiente : aux->abajo) &&
               (esFila ? aux->siguiente->columna : aux->abajo->fila) < (esFila ? nuevo->columna : nuevo->fila))
            aux = esFila ? aux->siguiente : aux->abajo;
        if (esFila) {
            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
        } else {
            nuevo->abajo = aux->abajo;
            aux->abajo = nuevo;
        }
    }
}

void MatrizDispersa::actualizarValor(int fila, int columna, int valor) {
    if (valor == 0) return; // Si el valor es 0, no almacenamos nada

    NodoCabecera* cabFila = obtenerCabecera(detalle->filas, fila);
    if (!cabFila) {
        cabFila = new NodoCabecera(fila);
        insertarCabecera(&(detalle->filas), cabFila);
    }

    NodoCabecera* cabColumna = obtenerCabecera(detalle->columnas, columna);
    if (!cabColumna) {
        cabColumna = new NodoCabecera(columna);
        insertarCabecera(&(detalle->columnas), cabColumna);
    }

    NodoElemento* actual = cabFila->primerElemento;
    while (actual) {
        if (actual->columna == columna) {
            actual->valor = valor;  // Si ya existe el nodo, actualizamos su valor
            return;
        }
        actual = actual->siguiente;
    }

    // Si no existe, lo insertamos
    insertar(fila, columna, valor);
}


#endif //MATRIZDISPERSA_H
