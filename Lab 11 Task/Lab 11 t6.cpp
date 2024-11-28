#include <stdio.h>
#include <string.h>


struct Invoice {
    char partNumber[20];   
    char partDescription[50]; 
    int quantity;          
    float pricePerItem;    
};


float calculateInvoiceAmount(struct Invoice *invoice) {
    
    if (invoice->quantity <= 0) {
        invoice->quantity = 0;
    }
    if (invoice->pricePerItem <= 0) {
        invoice->pricePerItem = 0.0;
    }
    
    
    return invoice->quantity * invoice->pricePerItem;
}


void displayInvoice(struct Invoice *invoice) {
    printf("\nInvoice Details:\n");
    printf("Part Number: %s\n", invoice->partNumber);
    printf("Part Description: %s\n", invoice->partDescription);
    printf("Quantity: %d\n", invoice->quantity);
    printf("Price per Item: $%.2f\n", invoice->pricePerItem);
    printf("Total Invoice Amount: $%.2f\n", calculateInvoiceAmount(invoice));
}

int main() {
    
    struct Invoice invoice1 = {
        "A1234",              
        "Hammer",           
        10,                   
        15.99               
    };

    struct Invoice invoice2;  

    
    printf("Enter Part Number: ");
    scanf("%s", invoice2.partNumber);

    getchar();  

    printf("Enter Part Description: ");
    fgets(invoice2.partDescription, sizeof(invoice2.partDescription), stdin);
    invoice2.partDescription[strcspn(invoice2.partDescription, "\n")] = '\0';  

    printf("Enter Quantity: ");
    scanf("%d", &invoice2.quantity);

    printf("Enter Price per Item: ");
    scanf("%f", &invoice2.pricePerItem);

    
    displayInvoice(&invoice1);
    displayInvoice(&invoice2);

    return 0;
}
