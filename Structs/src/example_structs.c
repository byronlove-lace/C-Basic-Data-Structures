#include<stdio.h>

typedef struct Inventory
{
        char partName[30];
        int partNumber;
        float price;
        int stock;
        int reorder;
} Inventory;

typedef union Types
{
        char c;
        short s;
        long b;
        float f;
        double d;
} Types;

typedef struct Address
{
  char streetAddress[25];
  char city[20];
  char state[3];
  char zipCode[6];
} Address;

typedef struct Student
{
       char firstName[15];
       char lastName[15];
       Address homeAddress;
} Student;

int main (void)
{


}
