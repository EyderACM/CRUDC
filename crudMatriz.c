#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    int price;
    int numberProducts;
    struct node *link;
}*top = NULL;

#define MAX 5

void create();
void delete();
void stack_count();
void destroy();
void update();
void search();
int st_count();

int main(){

    int choice;

    while (1){
        printf("Welcome to the product manager\n");
        printf("1. Create an element \n");
        printf("2. Delete an element \n");
        printf("3. Count/display elements present in stack \n");
        printf("4. Empty and destroy stack \n");
        printf("5. Search ID \n");
        printf("6. Update \n");
        printf("7. Exit \n");
        printf("Enter your choice \n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                create();
                break;
            case 2:
                delete();
                break;
            case 3:
                stack_count();
                break;
            case 4:
                destroy();
                break;
            case 5:
                search();
                break;
            case 6:
                update();
                break;
            case 7:
                exit(0);

            default:
                printf("wrong choice\n");
        }
    }
}

void create(){
    int id,count, nProducts, cost;
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    count = st_count();

    if (count <= MAX - 1){
        printf("\nEnter the ID of the product:\n");
        scanf("%d",&id);
        printf("\nEnter the number of products:\n");
        scanf("%d",&nProducts);
        printf("\nEnter the cost of the product:\n");
        scanf("%d",&cost);
        temp->data = id;
        temp->numberProducts = nProducts;
        temp->price = cost;
        temp->link = top;
        top = temp;
    }
    else
        printf("WARNING: STACK FULL\n");
}

void delete(){
    struct node *temp;
    if (top == NULL){
        printf("**Stack is empty**\n");
    }
    else
    {
        temp = top;
        printf("Value popped out is %d \n",temp->data);
        top = top->link;
        free(temp);
    }
}

void stack_count(){
    int count = 0;
    struct node *temp;
    temp = top;

    while (temp!= NULL){
        printf(" %d\n",temp->data);
        temp = temp->link;
        count++;
    }
    printf("size of stack is %d \n",count);
}

int st_count(){
    int count = 0;
    struct node *temp;
    temp = top;

    while (temp!= NULL){
        temp = temp->link;
        count++;
    }
    return count;
}

void destroy(){
    struct node *temp;
    temp = top;

    while (temp!= NULL){
        delete();
        temp = temp->link;
    }
    printf("stack destroyed\n");

}

void search(){
    int target, targetFound;
    printf("\nEnter the ID of the product:\n");
    scanf("%d",&target);
    struct node *temp;
    if (top == NULL){
        printf("**Stack is empty**\n");
        targetFound = 0;
    }
    else
    {
        temp = top;
        while(temp!=NULL){
        if(temp->data == target){
            printf("ID:%d\n", temp->data);
            printf("Cuantity:%d\n", temp->numberProducts);
            printf("Price:%d\n", temp->price);
            break;
            }
        temp = temp->link;
        }
        free(temp);
}
}

void update(){
 int id, cost, nProducts, target;
 struct node *temp;
 printf("\nEnter the ID of the product:\n");
    scanf("%d",&target);
    if (top == NULL){
        printf("**Stack is empty**\n");
    }
    else
    {
        temp = top;
        while(temp!=NULL){
        if(temp->data == target){
             printf("\nEnter the ID of the product:\n");
 scanf("%d",&id);
 printf("\nEnter the number of products:\n");
 scanf("%d",&nProducts);
 printf("\nEnter the cost of the product:\n");
 scanf("%d",&cost);
 temp->data = id;
 temp->numberProducts = nProducts;
 temp->price = cost;
            break;
            }
        temp = temp->link;
        }
        free(temp);
}

}