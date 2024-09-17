#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Customer
{
        char lastName[15];
        char firstName[15];

        unsigned int customerNumber;

        struct 
        {
                char phoneNumber[11];
                char address[50];
                char city[15];
                char state[3];
                char zipCode[6];
        } personal;

} CustomerRecord;

typedef CustomerRecord *CustomerPtr; // Creates type ptr to struct: CustomerPtr

int main (void)
{
        CustomerRecord bob;
        CustomerPtr bill = (CustomerPtr) malloc(sizeof(CustomerRecord)); // don't forget to actually assign to memory location

        // can't assign directly to array type; use strcpy
        strcpy(bob.lastName, "Bobby");
        strcpy(bill->lastName, "Billson");

        strcpy(bob.firstName, "Bob");
        strcpy(bill->firstName, "Bill");

        bob.customerNumber = 69;
        bill->customerNumber = 420;

        strcpy(bob.personal.phoneNumber, "0879214714");
        strcpy(bill->personal.phoneNumber, "0879214714");

        strcpy(bob.personal.address, "Wall Str Row,");
        strcpy(bill->personal.address, "Slum");

        strcpy(bob.personal.city, "Metropolis");
        strcpy(bill->personal.city, "Gotham");

        strcpy(bob.personal.state, "AS");
        strcpy(bill->personal.state, "BT");

        strcpy(bob.personal.zipCode, "80085");
        strcpy(bill->personal.zipCode, "455");

        printf("a. %s\n", bob.lastName);
        printf("b. %s\n", bill->lastName);

        printf("c. %s\n", bob.firstName);
        printf("d. %s\n", bill->firstName);

        printf("e. %d\n", bob.customerNumber);
        printf("f. %d\n", bill->customerNumber);

        printf("g. %s\n", bob.personal.phoneNumber);
        printf("h. %s\n", bill->personal.phoneNumber);

        printf("i. %s\n", bob.personal.address);
        printf("j. %s\n", bill->personal.address);

        printf("k. %s\n", bob.personal.city);
        printf("l. %s\n", bill->personal.city);
        
        printf("m. %s\n", bob.personal.state);
        printf("n. %s\n", bill->personal.state);

        printf("o. %s\n", bob.personal.zipCode);
        printf("p. %s\n", bill->personal.zipCode);

}
