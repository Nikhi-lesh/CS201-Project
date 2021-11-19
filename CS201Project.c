#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{ char Name[15];
  char Phnum[11];
  struct Node* prev;
  struct Node* next;
};

  //size of hash table is 26
struct Node** arr; // To globally declare this array , used concept of pointer to a pointer

void Arr() //  Intialise all pointers in the array to NULL
 {
 	int j;
    for(j=0; j<26 ; j++)
        arr[j] = NULL;
 }

int getkey(char ch)//a funtion that returns its position among all alphabets
{
     int count =0;
     char var;
  for(var = 'a' ;var <= 'z';var++)
   {
      if(var == ch)
         { 
          return count;
         }
      count++;
   }
    
}

void Insert()
 {
    struct Node* t = malloc(sizeof(struct Node));
    printf("\nEnter the name(in small letters): ");
    scanf("%s",t->Name);
    printf("\nEnter the phone number: ");
    scanf("%s",t->Phnum);
    t->prev = NULL;
    t->next =NULL;
    
    int index = getkey(t->Name[0]);
    if(arr[index] == NULL)
          arr[index] = t;
     else
     {
         t->next = arr[index];
         arr[index]->prev =t;
         arr[index] =t;
     }
 }


int main()
{
    arr = malloc(26*sizeof(struct Node*)); // Dynamically allocates an array of size 26
    Arr();
    
    int a;
   
    while(1)  //loop runs continuously till user opion 5 or if entered wrong choice
  {
        printf("\n1. To Save a New contact\n ");
        printf("Enter your choice: ");
        scanf("%d",&a);
    switch(a)
    {
        case 1:     
          Insert();
          break;
          
    }
     
  }
    free(arr);
    return 0;
}
