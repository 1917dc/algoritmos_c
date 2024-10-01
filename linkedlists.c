#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node *next;
}; 
typedef struct node node_t;

void printlist(node_t *head){
    node_t *temp = head;

    while(temp != NULL){
        printf(" %i ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

node_t* new_node(int value){
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;

    return result;
}

node_t* insert_at_head(node_t **head, node_t* node_to_insert){
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

node_t* find_node(node_t* head, int value){
    node_t* tmp = head;
    while(tmp != NULL){
        if(tmp->value == value) return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void remove_first(node_t **head){
    if(*head == NULL){
        return;
    }
    *head = (*head)->next;
}

void remove_last(node_t **head){
    if(*head == NULL){
        return;
    }

    if((*head)->next == NULL){
        free(*head);
        *head == NULL;
        return;
    }

    node_t *tmp = *head;
    node_t *prev = NULL;

    while(tmp->next != NULL){
        prev = tmp;
        tmp = tmp->next;
    }

    free(tmp);
    prev->next = NULL;
    return;
}

void insert_after_node(node_t** node_to_insert_after, node_t* new_node){
    new_node->next = (*node_to_insert_after)->next;
    (*node_to_insert_after)->next = new_node;
    return;
}

int main(){
    // inicializando a linked list
    node_t *head = NULL;
    node_t *tmp;

    //atribuindo valores ás nodes
    printf("primeira lista \n");

    for(int i = 0; i < 10; i++){
        tmp = new_node(i);
        insert_at_head(&head, tmp);
    }

    printlist(head);


    //removendo primeiro elemento com método de remove
    printf("removendo primeiro elemento \n");
    remove_first(&head);
    printlist(head);

    printf("buscando valores dentro da lista: 8 \n");
    printf("%i \n", find_node(head, 8)->value);

    //removendo o último termo
    printf("removendo o último termo \n");
    remove_last(&head);
    printlist(head);

    printf("inserindo após a node 5 \n");
    node_t* node = find_node(head, 5);
    insert_after_node(&node, new_node(10));
    printlist(head);

    return 0;
}