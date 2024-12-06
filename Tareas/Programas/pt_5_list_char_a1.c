#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/*
   Print List
*/

static void print_list(const List *list) {
    ListNode *node;
    char *data;
    int i;

    fprintf(stdout, "The size of the list is %d\n", list_size(list));

    i = 0;
    node = list_head(list);

    while (1) {
        data = list_data(node);
        fprintf(stdout, "list.node[%03d]=%c, %p -> %p \n", i, *data, node, node->next);

        i++;

        if (list_is_tail(node))
            break;
        else
            node = list_next(node);
    }

    return;
}

/*
   Functions to insert characters
*/
void insert_head(List *list, char value) {
    char *data = malloc(sizeof(char));
    *data = value;
    list_ins_next(list, NULL, data);
}

void insert_at_position(List *list, int pos, char value) {
    ListNode *node = list_head(list);
    for (int i = 0; i < pos && node != NULL; i++) {
        node = list_next(node);
    }
    char *data = malloc(sizeof(char));
    *data = value;
    list_ins_next(list, node, data);
}

void insert_tail(List *list, char value) {
    char *data = malloc(sizeof(char));
    *data = value;
    list_ins_next(list, list_tail(list), data);
}

/*
   Functions to remove nodes
*/
void remove_head(List *list) {
    char *data;
    list_rem_next(list, NULL, (void**)&data);
    free(data);
}

void remove_at_position(List *list, int pos) {
    ListNode *node = list_head(list);
    for (int i = 0; i < pos - 1 && node != NULL; i++) {
        node = list_next(node);
    }
    char *data;
    list_rem_next(list, node, (void**)&data);
    free(data);
}

void remove_tail(List *list) {
    ListNode *prev = NULL, *node = list_head(list);
    while (list_next(node) != NULL) {
        prev = node;
        node = list_next(node);
    }
    char *data;
    list_rem_next(list, prev, (void**)&data);
    free(data);
}

int main(int argc, char **argv) {
    List list;

    // Initialize the linked list
    list_init(&list, free);

    // Fill the list with 10 characters
    char initial_values[] = {'H', 'E', 'L', 'L', 'O', 'W', 'O', 'R', 'L', 'D'};
    for (int i = 0; i < 10; i++) {
        insert_tail(&list, initial_values[i]);
    }

    print_list(&list);

    // Insert new values
    insert_head(&list, 'A');
    insert_at_position(&list, 5, 'W');
    insert_tail(&list, 'T');

    fprintf(stdout, "\nAfter inserting A, W, and T:\n");
    print_list(&list);

    // Remove nodes
    remove_head(&list);
    remove_at_position(&list, 5);
    remove_tail(&list);

    fprintf(stdout, "\nAfter removing head, node 5, and tail:\n");
    print_list(&list);

    // Destroy the list
    fprintf(stdout, "\nDestroying the list\n");
    list_destroy(&list);

    return 0;
}
