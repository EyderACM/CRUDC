#include <stdio.h>
#include <stdlib.h>

struct item{
    int ID;
    float price;
    int quantity;
};

typedef struct item Item;

typedef struct {
    Item **array;
    int counter;
    int maxSize;
} ArrayList ;


void inicialize(ArrayList *content);
Item* createItem();
int addItem(ArrayList content);
int searchID(ArrayList content);
void update(ArrayList content);
int erase(ArrayList content);
int compareTo(Item *firstItem, Item *secondItem);
int swap(Item *itemOne, Item *itemTwo);
void heapsort(ArrayList content);
void heapify(ArrayList content, int root);
void printAll(ArrayList content);

int main(){

    ArrayList content;
    inicialize(&content);
    content.array = (Item**)malloc(sizeof(Item**)*content.maxSize);

    int choice;
    int flagSuccesAdd = 0;
    while (1){
        printf("Welcome to the product manager\n");
        printf("1. Create an element \n");
        printf("2. Update an element \n");
        printf("3. Search an element \n");
        printf("4. Delete an element \n");
        printf("5. Sort elements by ID\n");
        printf("6. Print all elements in the list \n");
        printf("7. Exit \n");
        printf("Enter your choice \n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            flagSuccesAdd = addItem(content);
            if(flagSuccesAdd == 1){
                printf("\nSuccess!\n");
                printf("ID: %d\n", content.array[content.counter]->ID);
                printf("Quantity: %d\n", content.array[content.counter]->quantity);
                printf("Price: %f\n\n", content.array[content.counter]->price);
                content.counter = content.counter + 1;
            } else {
                printf("Hmm, it seems that there's no more room in the list.\n");
            }
                break;
            case 2:
            update(content);
                break;
            case 3:
            searchID(content);
                break;
            case 4:
            flagSuccesAdd = erase(content);
            if(flagSuccesAdd == 1){
                content.counter = content.counter - 1;
            }
                break;
            case 5:
            heapsort(content);
            printf("\nSort Completed!\n\n");
                break;
            case 6:
            printAll(content);
                break;
            case 7:
                exit(0);
            default:
                printf("wrong choice\n");
        }
    }
}

void inicialize(ArrayList *content){
    content->counter = 0;
    content->maxSize = 0;
    content->array = NULL;
    printf("Welcome, please type the size of the list:\n");
    scanf("%d", &content->maxSize);
	content->array = (Item**)malloc(sizeof(Item**)*content->maxSize);
}

Item* createItem(){
    int id;
    int nProducts;
    float cost;

    printf("Enter the ID of the product:\n");
    scanf("%d",&id);
    printf("Enter the number of products:\n");
    scanf("%d",&nProducts);
    printf("Enter the cost of the product:\n");
    scanf("%f",&cost);
    Item* element = (Item*)malloc(sizeof(Item));

    element->ID = id;
    element->price = cost;
    element->quantity = nProducts;
    return element;
}

int addItem(ArrayList content){
    int flag = 0;
    if(content.counter < content.maxSize){
        Item* element = createItem();
        *(content.array+content.counter) = element;
        flag = 1;
    }
    return flag;
}

int searchID(ArrayList content){
    int counter = 0;
    int target = 0;
    printf("Enter the ID of the target product:\n");
    scanf("%d",&target);
    while(counter < content.maxSize){
        if(content.array[counter]->ID == target){
            printf("\nFound:\n");
            printf("ID: %d\n", content.array[counter]->ID);
            printf("Quantity: %d\n", content.array[counter]->quantity);
            printf("Price: %f\n\n", content.array[counter]->price);
            break;
        }
    counter = counter + 1;
    }
    if(counter == content.maxSize){
        printf("\nSorry, that ID is not correct.\n");
        counter = -1;
    }
    return counter;
}

void update(ArrayList content){
    int id;
    int nProducts;
    float cost;
    int target = searchID(content);
    if(target!=-1){
        printf("Enter the new ID of the product:\n");
        scanf("%d",&id);
        printf("Enter the new number of products:\n");
        scanf("%d",&nProducts);
        printf("Enter the new cost of the product:\n");
        scanf("%f",&cost);
        (*(content.array+target))->ID = id;
        (*(content.array+target))->price = cost;
        (*(content.array+target))->quantity = nProducts;
        printf("\nNew Information:\n");
        printf("ID: %d\n", content.array[target]->ID);
        printf("Quantity: %d\n", content.array[target]->quantity);
        printf("Price: %f\n\n", content.array[target]->price);
    }
}
int erase(ArrayList content){
    int flag = 0;
    int target = searchID(content);
    if(target!=-1){
        free(*(content.array+target));
        printf("The item has been erased.\n");
        if(target < content.maxSize-1){
            while(target < content.counter-1){
                content.array[target]->ID = content.array[target+1]->ID;
                content.array[target]->quantity = content.array[target+1]->quantity;
                content.array[target]->price = content.array[target+1]->price;
                target = target + 1;
            }
            free(*(content.array+target));
        }
        flag = 1;
    }
    return flag;
}

int compareTo(Item *firstItem, Item *secondItem){
    int comparasion = 0;
    if(firstItem->price > secondItem->price){
        comparasion = 1;
    }else if(firstItem->price < secondItem->price) {
        comparasion = -1;
    }
    return comparasion;
}

int swap(Item *itemOne, Item *itemTwo){
    int flag = 0;
    if(itemOne != NULL && itemTwo != NULL){
        Item temp = *itemOne;
        *itemOne = *itemTwo;
        *itemTwo = temp;
        flag = 1;
    }
    return flag;
}

void heapsort(ArrayList content){
    for(int i = content.counter / 2 - 1; i >= 0; i--){
        heapify(content, i);
    }
    for(int i = content.counter - 1; i >= 0; i--){
        swap(content.array[0], content.array[i]);
        heapify(content, 0);
    }
}

void heapify(ArrayList content, int root){
    int smallest = root;
    int left = 2*root + 1;
    int right = 2*root + 2;
    if(left < content.counter && content.array[left]->ID < content.array[smallest]->ID){
        smallest = left;
    }
    if(right < content.counter && content.array[right]->ID < content.array[smallest]->ID){
        smallest = right;
    }

    if(smallest != root){
        swap(content.array[root], content.array[smallest]);
        heapify(content, smallest);
    }
}

void printAll(ArrayList content){
    for(int i = 0; i < content.counter; i++){
        printf("\nItem %d", i);
        printf("\nID = %d", content.array[i]->ID);
        printf("\nPrice = %f", content.array[i]->price);
        printf("\nQuantity = %d\n", content.array[i]->quantity);
    }
}


