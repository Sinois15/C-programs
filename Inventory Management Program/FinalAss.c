#include <stdio.h>
#include <math.h>

typedef struct Item{
    char name[20];
    float price;
    int id;
    int stock;
}Item;

Item inventory[255];
FILE *fp;
int count, i;
char choice;

void initFile(){
    fp = fopen("inventory.txt", "w");
    if ((fp == NULL)){
        printf("File could not be opened");
    }
    else{
        fprintf(fp,"%-3s%-25s%-7s%-7s\n", "ID", "Name", "Stock", "Price(RM)");
    }
    fclose(fp);
}

void loadInventory(){
    fp = fopen("inventory.txt", "r");
    if ((fp == NULL)){
        printf("File could not be opened");
    }
    else if (count == 0){
        printf("Inventory is empty.\n");
    }
    else{
        printf("%-3s%-25s%-7s%-7s\n", "ID", "Name", "Stock", "Price(RM)");
        int e = getc(fp) ;
        while(e != EOF){
            
            fscanf(fp, "%3d%25s%5d%7.2f", &inventory[i].id, &inventory[i].name, &inventory[i].stock, &inventory[i].price);
            printf("%-3d%-25s%-7d%-7.2f\n",inventory[i].id, inventory[i].name, inventory[i].stock, inventory[i].price);
            i++;
            e = getc(fp);
        } 
    }
    fclose(fp);
}    


/*void displayInventory(){
    if (count == 0){
        printf("Inventory is empty.\n");
    }
    else{
        printf("%-3s%-25s%-7s%-7s\n", "ID", "Name", "Stock", "Price(RM)");
        for (int i=0; i<count; i++){
            printf("%-3d%-25s%-7d%-7.2f\n",inventory[i].id, inventory[i].name, inventory[i].stock, inventory[i].price);
        }
    }
    
}*/


void addItem(){
    choice = 'y';
    int valid = 1;
    fp = fopen("inventory.txt", "a+");
    if ((fp == NULL)){
        printf("File could not be opened");
    }
    else{
        while (choice == 'y'){
            printf("Enter id of item: ");
            scanf(" %d", &inventory[count].id);
            printf("Enter name of item: ");
            scanf(" %s", &inventory[count].name);
            printf("Enter stock of item: ");
            scanf("%d", &inventory[count].stock);
            printf("Enter price of item: RM");
            scanf("%f", &inventory[count].price);
            fprintf(fp,"%-3d%-25s%-7d%-7.2f\n",inventory[count].id, inventory[count].name, inventory[count].stock, inventory[count].price);
            count++;
            do{
                printf("Add another item? (n to stop / y to continue): ");
                scanf(" %c", &choice);
                if (choice != 'y' && choice != 'n'){
                    printf("Invalid choice!!\n");
                }
            }while (choice != 'y' && choice != 'n');
        }
        
    }
    fclose(fp);
}

void edit(){
    choice = 'y';
    int edit, id, found = 0;
    while (choice == 'y'){
        do{
            printf("Enter ID of item to be edited(-1 to exit):");
            scanf("%d", id);
            if (id == -1){
                break;
            }
            else{
                scanf("%d", edit);
                for (int i = 0; i<count; i++){
                    if (id == inventory[i].id){
                        found = 1;
                        printf("1. ID\n2. Name\n3. Stock\n4. Price\nEnter -1 to exit\n");
                        printf("Enter the number of the data to be edited:");
                        scanf("%d", edit);
                        switch(edit){
                            case 1:
                                printf("Enter new ID: ");
                                scanf("%d", &inventory[i].id);
                                break;
                            case 2:
                                printf("Enter new Name: ");
                                scanf(" %s", &inventory[i].name);
                                break;
                            case 3:
                                printf("Enter new Stock: ");
                                scanf("%d", &inventory[i].stock);
                                break;
                            case 4:
                                printf("Enter new Price: ");
                                scanf("%f", &inventory[i].price);
                                break;
                            case -1:
                                printf("Editing aborted");
                                break;
                            default:
                                printf("Invalid choice");
                        }

                    }
                    fp = fopen("inventory.txt", "w+");
                    if ((fp == NULL)){
                        printf("File could not be opened");
                    }
                    else{
                        int e;
                        while(e != EOF){
                            fscanf(fp, "%3d", &id);
                            if (id == i){
                                fprintf(fp,"%-3d%-25s%-7d%-7.2f\n",inventory[count].id, inventory[count].name, inventory[count].stock, inventory[count].price);
                            }
                            e = getc(fp);
                        }
                        printf("Item info edited.");
                    }
                    fclose(fp);
                    break;
                }
                if(found == 0){
                    printf("Invalid ID!!");
                }
            }
        }while(found == 0);
        
        
        
    }
}





int main(){
    initFile();
    addItem();
    loadInventory();
    edit();
    loadInventory();
    //displayInventory();
    return 0;
}