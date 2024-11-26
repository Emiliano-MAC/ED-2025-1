#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dlist.h"

// ===== Estructura de Arbol Binario =====
typedef struct arbolBinario {
    char dato;
    struct arbolBinario* izq;
    struct arbolBinario* der;
} ab;

// Funciones para Arbol
ab* crearNodoArbol(char dato) {
    ab* nuevoNodo = (ab*)malloc(sizeof(ab));
    nuevoNodo->dato = dato;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    return nuevoNodo;
}

ab* construirArbol() {
    char dato, tieneIzq, tieneDer;

    printf("Ingrese el dato para el nodo: ");
    scanf(" %c", &dato);
    ab* nodo = crearNodoArbol(dato);

    printf("¿El nodo %c tiene hijo izquierdo? (s/n): ", dato);
    scanf(" %c", &tieneIzq);
    if (tieneIzq == 's' || tieneIzq == 'S') {
        printf("Construyendo hijo izquierdo de %c...\n", dato);
        nodo->izq = construirArbol();
    }

    printf("¿El nodo %c tiene hijo derecho? (s/n): ", dato);
    scanf(" %c", &tieneDer);
    if (tieneDer == 's' || tieneDer == 'S') {
        printf("Construyendo hijo derecho de %c...\n", dato);
        nodo->der = construirArbol();
    }

    return nodo;
}

void imprimirArbol(ab* nodo, int nivel) {
    if (nodo == NULL) {
        return;
    }
    imprimirArbol(nodo->der, nivel + 1);
    int i;
    for (i = 0; i < nivel; i++) {
        printf("    ");
    }
    printf("%c\n", nodo->dato);
    imprimirArbol(nodo->izq, nivel + 1);
}

void liberarArbol(ab* nodo) {
    if (nodo == NULL) {
        return;
    }
    liberarArbol(nodo->izq);
    liberarArbol(nodo->der);
    free(nodo);
}

//Funciones para Lista Doblemente Ligada
void imprimirLista(DList* lista) {
    DListNode* actual = dlist_head(lista);
    printf("Lista: ");
    while (actual != NULL) {
        printf("%c -> ", *((char*)dlist_data(actual)));
        actual = dlist_next(actual);
    }
    printf("NULL\n");
}

void construirLista(DList* lista) {
    char dato, continuar;
    do {
        printf("Ingrese un dato para la lista: ");
        scanf(" %c", &dato);
        char* datoPtr = (char*)malloc(sizeof(char));
        *datoPtr = dato;

        if (dlist_ins_next(lista, dlist_tail(lista), datoPtr) != 0) {
            printf("Error al insertar nodo en la lista.\n");
        }

        printf("¿Desea agregar otro nodo a la lista? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');
}

void destruirLista(DList* lista) {
    void* dato;
    while (dlist_size(lista) > 0) {
        if (dlist_remove(lista, dlist_tail(lista), &dato) == 0) {
            free(dato);
        }
    }
}

int esPalindromo(DList* lista) {
    if (dlist_size(lista) <= 1) {
        return 1;
    }
    DListNode* inicio = dlist_head(lista);
    DListNode* fin = dlist_tail(lista);

    while (inicio != fin && dlist_next(inicio) != fin) {
        char datoInicio = *((char*)dlist_data(inicio));
        char datoFin = *((char*)dlist_data(fin));

        if (datoInicio != datoFin) {
            return 0;
        }
        inicio = dlist_next(inicio);
        fin = dlist_prev(fin);
    }
    return 1;
}

//Funcion para Verificar Palindromo de Frase
void verificarPalindromo() {
    char frase[100], fraseLimpia[100];
    int i, j = 0;

    printf("Ingrese una frase o palabra: ");
    getchar(); // Limpiar el buffer de entrada
    fgets(frase, 100, stdin);

    for (i = 0; frase[i] != '\0'; i++) {
        if (isalnum(frase[i])) {
            fraseLimpia[j++] = tolower(frase[i]);
        }
    }
    fraseLimpia[j] = '\0';

    int inicio = 0, fin = j - 1;
    int esPalindromo = 1;

    while (inicio < fin) {
        if (fraseLimpia[inicio] != fraseLimpia[fin]) {
            esPalindromo = 0;
            break;
        }
        inicio++;
        fin--;
    }

    if (esPalindromo) {
        printf("La frase o palabra es un palindromo.\n");
    } else {
        printf("La frase o palabra NO es un palindromo.\n");
    }
}

// ===== Menú Principal =====
int main() {
    ab* raiz = NULL;
    DList lista;

    dlist_init(&lista, free);

    int opcion;
    do {
        printf("\n--- Menu Principal ---\n");
        printf("1. Construir arbol\n");
        printf("2. Imprimir arbol Visualmente\n");
        printf("3. Construir lista doblemente ligada\n");
        printf("4. Imprimir lista doblemente ligada\n");
        printf("5. Verificar si la lista es un Palindromo\n");
        printf("6. Verificar si una frase o palabra es un Palindromo\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (raiz != NULL) {
                    printf("Ya existe un arbol. Libere la memoria antes de crear uno nuevo.\n");
                } else {
                    raiz = construirArbol();
                }
                break;

            case 2:
                if (raiz == NULL) {
                    printf("El arbol esta vacio. Construya uno primero.\n");
                } else {
                    imprimirArbol(raiz, 0);
                }
                break;

            case 3:
                construirLista(&lista);
                break;

            case 4:
                imprimirLista(&lista);
                break;

            case 5:
                if (dlist_size(&lista) == 0) {
                    printf("La lista esta vacia. Construya una primero.\n");
                } else if (esPalindromo(&lista)) {
                    printf("La lista es un Palindromo.\n");
                } else {
                    printf("La lista NO es un Palindromo.\n");
                }
                break;

            case 6:
                verificarPalindromo();
                break;

            case 7:
                printf("Saliendo del programa...\n");
                liberarArbol(raiz);
                destruirLista(&lista);
                break;

            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 7);

    return 0;
}

