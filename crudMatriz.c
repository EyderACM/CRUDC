#include <stdio.h>
#include <stdlib.h>

struct item{
    int ID;
    float price;
    int cuantity;
};

typedef struct item Item;

Item* createItem();
int addItem(Item** array, int counter, int maxSize);

int searchID(Item** array, int maxSize);
void update(Item** array, int maxSize);
int erase(Item** array, int counter, int maxSize);

int main(){

    int choice;

    int counter = 0;
    int maxSize = 0;
    int flagSuccesAdd = 0;
    printf("Welcome, please type the size of the list:\n");
    scanf("%d",&maxSize);
    Item *array[maxSize];
    while (1){
        printf("Welcome to the product manager\n");
        printf("1. Create an element \n");
        printf("2. Update an element \n");
        printf("3. Search an element \n");
        printf("4. Delete an element \n");
        printf("5. --- \n");
        printf("6. --- \n");
        printf("7. Exit \n");
        printf("Enter your choice \n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            flagSuccesAdd = addItem(array,counter,maxSize);
            if(flagSuccesAdd == 1){
                printf("\nSuccess!\n");
                printf("ID: %d\n", array[counter]->ID);
                printf("Cuantity: %d\n", array[counter]->cuantity);
                printf("Price: %f\n\n", array[counter]->price);
                counter = counter + 1;
            } else {
                printf("Hmm, it seems that there's no more room in the list.\n");
            }
                break;
            case 2:
            update(array,maxSize);
                break;
            case 3:
            searchID(array,maxSize);
                break;
            case 4:
            flagSuccesAdd = erase(array,counter,maxSize);
            if(flagSuccesAdd == 1){
                counter = counter - 1;
            }
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                exit(0);
            default:
                printf("wrong choice\n");
        }
    }
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
    element->cuantity = nProducts;
    return element;
}

int addItem(Item** array, int counter, int maxSize){
    int flag = 0;
    if(counter < maxSize){
        Item* element = createItem();
        *(array+counter) = element;
        flag = 1;
    }
    return flag;
}

int searchID(Item** array, int maxSize){
    int counter = 0;
    int target = 0;
    printf("Enter the ID of the target product:\n");
    scanf("%d",&target);
    while(counter!=maxSize){
        if((*(array+counter))->ID == target){
            printf("\nFound:\n");
            printf("ID: %d\n", array[counter]->ID);
            printf("Cuantity: %d\n", array[counter]->cuantity);
            printf("Price: %f\n\n", array[counter]->price);
            break;
        }
    counter = counter + 1;
    }
    if(counter == maxSize){
        printf("\nSorry, that ID is not correct.\n");
        counter = -1;
    }
    return counter;
}

void update(Item** array, int maxSize){
    int id;
    int nProducts;
    float cost;
    int target = searchID(array,maxSize);
    if(target!=-1){
        printf("Enter the new ID of the product:\n");
        scanf("%d",&id);
        printf("Enter the new number of products:\n");
        scanf("%d",&nProducts);
        printf("Enter the new cost of the product:\n");
        scanf("%f",&cost);
        (*(array+target))->ID = id;
        (*(array+target))->price = cost;
        (*(array+target))->cuantity = nProducts;
        printf("\nNew Information:\n");
        printf("ID: %d\n", array[target]->ID);
        printf("Cuantity: %d\n", array[target]->cuantity);
        printf("Price: %f\n\n", array[target]->price);
    }
}
int erase(Item** array, int counter, int maxSize){
    int flag = 0;
    int target = searchID(array,maxSize);
    if(target!=-1){
        free(*(array+target));
        printf("The item has been erased.\n");
        if(target!=maxSize-1){
            while(target!=counter){
                (*(array+target))->ID = (*(array+target+1))->ID;
                (*(array+target))->cuantity = (*(array+target+1))->cuantity;
                (*(array+target))->price = (*(array+target+1))->price;
                target = target + 1;
            }
            free(*(array+target));
        }
        flag = 1;
    }
    return flag;
}

}

int addItem(Item** array, int counter, int maxSize){
int flag = 0;
if(counter < maxSize){
    Item* element = createItem();
    *(array+counter) = element;
    flag = 1;
}
return flag;
}

