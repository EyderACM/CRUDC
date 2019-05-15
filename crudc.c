#include <stdio.h>
#include <stdlib.h>

struct item {
    int id;
    int quantity;
    float price;
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


int find(LinkedList*);
void addManager(LinkedList*);
int update(LinkedList*);
void supr(LinkedList*);
void freeList(LinkedList*);
void printMainMenu(int *choice, LinkedList*);
void printItem(Node* item);
void createNode(Node* myItem);
void printAll(LinkedList*);
int compareTo(Item* firstItem, Item* secondItem);

int main()
{
    int choice = 1;
    LinkedList miLista;
    miLista.head = NULL;
    while(choice != 6){
       printMainMenu(&choice, &miLista);
    }
    freeList(&miLista);
}

void createNode(Node* myItem){
    int id, quantity, price;
    printf("\nEnter the id of the product\n");
    scanf("%d", &id);
    printf("\nEnter the quantity of products\n");
    scanf("%d", &quantity);
    printf("\nEnter the price of the product\n");
    scanf("%d", &price);

    myItem->data.id = id;
    myItem->data.quantity = quantity;
    myItem->data.price = price;
    myItem->next = NULL;
}

void printAll(LinkedList* miLista){
    Node* current;
    current = miLista->head;
    while(current != NULL){
        printItem(current);
        current = current->next;
    }
}

void addManager(LinkedList *miLista){
    int doneCorrectly = 0, wasFound = 0;
    Node* newNode = (Node*)malloc(sizeof(Node));
    createNode(newNode);

    if(miLista->head == NULL || miLista->head->data.id >= newNode->data.id){
        newNode->next = miLista->head;
        miLista->head = newNode;
        doneCorrectly = 1;
    }
    if(doneCorrectly == 0){
        Node* current;
        current = miLista->head;
        while(current->next != NULL && compareTo(newNode, current->next)){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        doneCorrectly = 1;
    }
    doneCorrectly ? printf("Added successfully\n") : printf("Something went wrong\n");
}

int find(LinkedList *miLista){
    int precio, cantidad, searchedId, posicion = -1;
    printf("\nIntroduce the ID of the searched product\n");
    scanf("%d", &searchedId);
    Node* current = (Node*)malloc(sizeof(Node));
    current = miLista->head;
    while(current != NULL){
        posicion++;
        if(current->data.id == searchedId){
            printItem(current);
            break;
        }
        current = current->next;
    }
    free(current);
    return posicion;
}

void printItem(Node* item){
    printf("\nItem %d \n", item->data.id);
    printf("Quantity: %d \n", item->data.quantity);
    printf("price: %f \n\n", item->data.price);
}

int update(LinkedList *miLista){
    int searchedId, toChange, valueChanged, posicion = 0, found = 0;
    posicion = find(miLista);
    Node* current = miLista->head;
    current = miLista->head;

    while(posicion > 0){
        posicion--;
        current = current->next;
    }
    current = NULL;
    if(posicion == 0){
        miLista->head = NULL;
    }

    free(current);
    if(posicion != -1){
        addManager(miLista);
        found = 1;
    }
    return found;
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

int compareTo(Item *firstItem, Item *secondItem){
    int comparasion = 0;
    if(firstItem->id > secondItem->id){
        comparasion = 1;
    }else if(firstItem->id < secondItem->id) {
        comparasion = -1;
    }
    return comparasion;
}

void printMainMenu(int *choice, LinkedList *miLista){
    int dummy = 0, result = 0;
        printf("**********************************************");
        printf("\n*  Welcome to the product manager            *\n");
        printf("*  Select 1 to find a product                *\n");
        printf("*  Select 2 to add a product                 *\n");
        printf("*  Select 3 to update a product information  *\n");
        printf("*  Select 4 to delete a product              *\n");
        printf("*  Select 5 to Print all info                *\n");
        printf("*  Select 6 to exit                          *\n");
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
                result = update(miLista);
                result ? printf("\nItem was updated\n") : printf("\nItem wasn't found!\n");
                break;
            case 4:
                supr(miLista);
                break;
            case 5:
                printAll(miLista);
                break;
        }
}
