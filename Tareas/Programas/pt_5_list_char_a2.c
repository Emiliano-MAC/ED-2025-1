#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

/*
   Additional insertion functions
*/
void insert_d(List *list) {
    insert_head(list, 'D');
}

void insert_r(List *list) {
    insert_at_position(list, 2, 'R');
}

void insert_o(List *list) {
    insert_tail(list, 'o');
}

void insert_9(List *list) {
    insert_at_position(list, list_size(list) / 2, '9');
}

/*
   Additional removal functions
*/
void remove_at_start(List *list) {
    remove_head(list);
}

void remove_at_middle(List *list) {
    remove_at_position(list, list_size(list) / 2);
}

void remove_at_end(List *list) {
    remove_tail(list);
}

void remove_second_node(List *list) {
    remove_at_position(list, 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <characters>\n", argv[0]);
        return 1;
    }

    List list;

    // Initialize the linked list
    list_init(&list, free);

    // Fill the list with characters from command-line arguments
    for (int i = 1; i < argc; i++) {
        insert_tail(&list, argv[i][0]);
    }

    fprintf(stdout, "Initial list:\n");
    print_list(&list);

    // Perform additional insertions
    insert_d(&list);
    insert_r(&list);
    insert_o(&list);
    insert_9(&list);

    fprintf(stdout, "\nAfter additional insertions (D, R, o, 9):\n");
    print_list(&list);

    // Perform additional removals
    remove_at_start(&list);
    remove_at_middle(&list);
    remove_at_end(&list);
    remove_second_node(&list);

    fprintf(stdout, "\nAfter additional removals:\n");
    print_list(&list);

    // Destroy the list
    fprintf(stdout, "\nDestroying the list\n");
    list_destroy(&list);

    return 0;
}
