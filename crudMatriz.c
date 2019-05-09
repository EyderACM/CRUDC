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

