#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//define item structure
typedef struct Item{ 
    char name[20]; //name of item
    float price;   //price of item
    int quantity;  // item quantity
}Item;

//defining receipt structure
typedef struct Receipt{
    Item items[100];
    int iCount;
    int id;
    float total;
    time_t date;
}Receipt;

// global variables
time_t t; //to store current pc time
FILE *fp; //file pointer
int count = 0; //counter
Receipt receipts[255]; //array to store receipts

//method to calculate the total price of a receipt 
void calcTotal(int x){
    //loop until all items in a receipt are read
    for (int i= 0; i<receipts[x].iCount; i++){
        //add sub total of each item to calculate total cost
        receipts[x].total = receipts[x].total + (receipts[x].items[i].price * 
receipts[x].items[i].quantity);
    }
}

//method to save receipt to file
void saveReceipt(int i){
    fp = fopen("receipts.txt", "a+"); //open file for appending
    if (fp == NULL){
        printf("Could not open file.\n");
    }
    else{
        //write receipt details to file
        fprintf(fp,"---------------------\n");
        fprintf(fp,"Receipt\n");
        fprintf(fp,"---------------------\n");
        fprintf(fp, "Date: %s\n", receipts[i].date);  
        fprintf(fp,"+-----------------------------------------------+\n");
        fprintf(fp,"| %-20s | %-11s | %8s |\n", "Item", "Price(RM)", "Quantity");
        fprintf(fp,"+-----------------------------------------------+\n");
        for (int x= 0; x<receipts[i].iCount; x++){
           fprintf(fp,"| %-20s | %-11.2f | %-8d |\n", 
receipts[i].items[x].name, receipts[i].items[x].price, receipts[i].items[x].quantity);
        }
        fprintf(fp,"+-----------------------------------------------+\n");
        fprintf(fp," Total: RM%.2f \n\n\n", receipts[i].total);
       
    }
    fclose(fp); // closing file
}

//method to create receipt
void createReceipt(){
    time(&t); //get current pc time
    receipts[count].date = ctime(&t);//store current pc time
    char choice = 'y';
    while (choice == 'y'){ //loop iterates while user wants to enter item details
        printf("Enter the item name: ");
        scanf("%s", &receipts[count].items[receipts[count].iCount].name);
        printf("Enter the item Price: RM");
        scanf("%f", &receipts[count].items[receipts[count].iCount].price);
        printf("Enter the item quantity: ");
        scanf("%d", &receipts[count].items[receipts[count].iCount].quantity);
        receipts[count].iCount++;
        //asking user if they want to continue entering item details
        do{
            printf("Add another item? (n to stop / y to continue): ");
            scanf(" %c", &choice);
            if (choice != 'y' && choice != 'n'){
                printf("Invalid choice!!\n");
            }
        }while (choice != 'y' && choice != 'n');
    }
    receipts[count].id = count + 1; //set receipt id
    calcTotal(count); //calculate total for current receipt
    saveReceipt(count); //save receipt to file
    count++; //increment receipt counter
}

//method to display receipts
void displayReceipt(int i){
    printf("---------------------\n");
    printf("Receipt\n");
    printf("---------------------\n");
    printf("Date: %s\n", receipts[i-1].date);
    printf("+-----------------------------------------------+\n");
    printf("| %-20s | %-11s | %-8s |\n", "Item", "Price(RM)", "Quantity");
    printf("+-----------------------------------------------+\n");
    for (int x = 0; x<receipts[i-1].iCount; x++){
        printf("| %-20s | %-11.2f | %-8d |\n", receipts[i-1].items[x].name, receipts[i-1].items[x].price, receipts[i-1].items[x].quantity);
    }
    printf("+-----------------------------------------------+\n");
    printf("Total: RM%.2f \n\n\n", receipts[i-1].total);
}


int main(){
    system("cls"); //clear screen
    int choice, id, found;
    printf("---------------------\n");
    printf("RECEIPTS HELPER\n");
    printf("---------------------\n\n");
    while(1){
        //display the actions the user can do
        printf("1. Create Receipt\n2. Display Receipt\n0. exit\n\n");
        printf("Choose an action(0, 1 or 2): "); //asking user which action to perform
        scanf("%d", &choice);
        printf("\n");
        //choose action to perform based on input
        switch(choice){
            case 0:
                printf("Thank you for using me :). See you later.\n\n");
                exit(0); //exits program
                break;
            case 1:
                printf("---------------------\n");
                printf("RECEIPT CREATION\n");
                printf("---------------------\n\n");
                createReceipt(); //start creating receipt
                break;
            case 2:
                found = 0;
                printf("---------------------\n");
                printf("RECEIPT DISPLAY\n");
                printf("---------------------\n\n");
                //checking if any receipts have been created yet
                if(count == 0){
                    printf("No Receipts have been created yet.\n\n");
                }else{ //if receipts have been previously created
                    printf("Enter the receipt id: "); //prompt for receipt id
                    scanf("%d", &id);
                    printf("\n");
                    for (int i = 0; i<=count; i++){
                        if (id == receipts[i].id){ //checking if input corresponds to any stored id
                            displayReceipt(id);
                            found = 1;
                            break;
                        }
                    }
                    if (found == 0){
                        printf("Receipt not found.\n\n");//if entered id is not found
                    }
                    
                }
                break;
            default: 
                printf("Invalid choice!! Try again\n\n"); //if action number entered is not available
        }
    }
    
    return 0;
}
