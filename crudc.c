#include <stdio.h>
#include <stdlib.h>

struct item {
    int id;
    int cantidad;
    int precio;
};

struct node {
    struct item data;
    struct node *next;
};

struct linkedList {
    struct node *head;
};

typedef struct item Item;
typedef struct node Node;
typedef struct linkedList LinkedList;


void find(LinkedList*);
void addManager(LinkedList*);
void update(LinkedList*);
void supr(LinkedList*);
void freeList(LinkedList*);
void printMainMenu(int *choice, LinkedList*);

int main()
{
    int choice = 1;
    LinkedList miLista;
    miLista.head = NULL;
    while(choice != 5){
       printMainMenu(&choice, &miLista);
    }
    freeList(&miLista);
}

void addManager(LinkedList *miLista){
    int id, quantity, price, doneCorrectly = 0;
    printf("\nEnter the id of the product\n");
    scanf("%d", &id);
    printf("\nEnter the quantity of products\n");
    scanf("%d", &quantity);
    printf("\nEnter the price of the product\n");
    scanf("%d", &price);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data.id = id;
    newNode->data.cantidad = quantity;
    newNode->data.precio = price;
    newNode->next = NULL;

    if(miLista->head == NULL){
        miLista->head;
        miLista->head = newNode;
        doneCorrectly = 1;
    }
    if(doneCorrectly == 0){
        Node* current;
        printf("We got here\n");
        current = miLista->head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
        doneCorrectly = 1;
    }
    doneCorrectly ? printf("Added successfully\n") : printf("Something went wrong\n");
}

void find(LinkedList *miLista){
    int precio, cantidad, searchedId, fueEncontrado = 0;
    printf("\nIntroduce the ID of the searched product\n");
    scanf("%d", &searchedId);
    Node* current = (Node*)malloc(sizeof(Node));
    current = miLista->head;
    while(current != NULL){
        if(current->data.id == searchedId){
            fueEncontrado = 1;
            precio = current->data.precio;
            cantidad = current->data.cantidad;
        }
        current = current->next;
    }
    fueEncontrado ? printf("\nThe price of the product is: %d\nThe quantity is %d\n", precio, cantidad) : printf("Product not found\n");
    free(current);
}

void update(LinkedList *miLista){
    int searchedId, toChange, valueChanged, fueEncontrado = 0;
    printf("\nIntroduce the ID of the searched product to change\n");
    scanf("%d", &searchedId);
    printf("\nIf you desire to change the quantity introduce 0, if you want to change the price introduce 1\n");
    scanf("%d", &toChange);
    toChange ? printf("\nTo what value do you want to change the cost\n") : printf("\nTo what value do you want to change the quantity\n");
    scanf("%d", &valueChanged);

    Node* current = (Node*)malloc(sizeof(Node));
    current = miLista->head;
    while(current != NULL){
        if(current->data.id == searchedId){
            fueEncontrado = 1;
            toChange ? (current->data.precio = valueChanged) : (current->data.cantidad = valueChanged);
        }
        current = current->next;
    }
    fueEncontrado ? printf("\nChanged correctly\n") : printf("Product not found\n");
    free(current);
}

void supr(LinkedList *miLista){
    if(miLista->head == NULL){
        return;
    }

    int searchedId;
    printf("\nIntroduce the ID of the Item you want to delete\n");
    scanf("%d", &searchedId);
    Node* current = (Node*)malloc(sizeof(Node));
    current = miLista->head;
    if(miLista->head->data.id == searchedId){
        miLista->head = miLista->head->next;
        return;
    }

    while (current->next != NULL){
        if(current->next->data.id == searchedId){
            current->next = current->next->next;
            free(current->next);
            return;
        }
        current = current->next;
    }
    free(current);
}

void freeList(LinkedList *miLista){
    Node* temp;
    while(miLista->head != NULL){
        temp = miLista->head;
        miLista->head = miLista->head->next;
        free(temp);
    }
}

void printMainMenu(int *choice, LinkedList *miLista){
    int dummy = 0;
        printf("**********************************************");
        printf("\n*  Welcome to the product manager            *\n");
        printf("*  Select 1 to find a product                *\n");
        printf("*  Select 2 to add a product                 *\n");
        printf("*  Select 3 to update a product information  *\n");
        printf("*  Select 4 to delete a product              *\n");
        printf("*  Select 5 to exit                          *\n");
        printf("**********************************************\n");
        scanf("%d", choice);
        dummy = *choice;
        switch(dummy){
            case 1:
                find(miLista);
                break;
            case 2:
                addManager(miLista);
                break;
            case 3:
                update(miLista);
                break;
            case 4:
                supr(miLista);
                break;
        }
}
