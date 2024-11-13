#include <stdio.h>
#include <stdlib.h>

// Definimos la estructura de un nodo para una lista doblemente ligada
struct Nodo {
    int dato;
    struct Nodo* next;
    struct Nodo* prev;
};

// Función para crear un nuevo nodo
struct Nodo* crearNodo(int dato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->next = NULL;
    nuevoNodo->prev = NULL;
    return nuevoNodo;
}

// Función para imprimir la lista
void imprimirLista(struct Nodo* head) {
    struct Nodo* actual = head;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->next;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Ingresa el n%dmero de elementos en la lista: ",163);
    scanf("%d", &n);

    struct Nodo* head = NULL;

    // Captura de datos de la lista
    for (int i = 0; i < n; ++i) {
        int dato;
        printf("Ingresa el elemento %d: ", i + 1);
        scanf("%d", &dato);
    }

    // Imprimimos la lista en sentido directo
    printf("Lista en sentido directo:\n");
    imprimirLista(head);



    // Liberamos la memoria al final
    while (head != NULL) {
        struct Nodo* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
