#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int p;
int r;

int *resource = NULL;
int *available = NULL;
int *max = NULL;
int *allocated = NULL;
int *need = NULL;


void params(){
int rUnit;

printf("\n Enter number of processes: ");
scanf("%d", &p);
printf("\n Enter number of resources: ");
scanf("%d", &r);
resource = malloc((p * r) * sizeof(int));
max = malloc((p * r) * sizeof(int));
allocated = malloc((p * r) * sizeof(int));

printf("\nEnter number of units for resources (r0 to r%d): ", r-1);
for (int i = 0; i < r; i++){
    scanf("%d", &rUnit);
    resource[i] = rUnit;
    //available[i] = rUnit;
}

printf("\nunits for resources: ");
for(int i = 0; i<r; i++){
printf("%d ", resource[i]);
}

for(int i = 0; i<p; i++){
    printf("\nEnter maximum number of units process p%d will request from each resource(r0 to r%d): ", i, r-1);
    for(int j = 0; j<r; j++){
        scanf("%d", &max[i*r+j]);
    }
}

printf("\nMax Array: ");
for (int i = 0; i < p; i++)
{
    printf("\n%d %d %d", max[i*r+0], max[i*r+1], max[i*r+2]);
}

for(int i = 0; i<p; i++){
    printf("\nEnter number of units of each resource (r0 to r%d) allocated to process p%d: ", r-1, i);
    for (int j = 0; j<r; j++)
    {
        scanf("%d", &allocated[i*r+j]);
    }
    
}

printf("\nAllocated Array");
for (int i = 0; i < p; i++)
{
    printf("\n%d %d %d", allocated[i*r+0], allocated[i*r+1], allocated[i*r+2]);
}

paramDisplay();

}

void paramDisplay(){
    printf("\n          Max Claim           Current                 Potential ");
    printf("\n      r0    r1    r2     "); printf(" r0    r1    r2      "); printf("    r0     r1     r2");
    printf("\n----------------------------------------------------------------------------");
    for(int i = 0; i<p; i++){
        //                    Max Claim                 Current
        //          p    r0     r1     r2        r0     r1      r2
        printf("\np%d    %d     %d     %d       %d      %d      %d", i, max[i*r+0], max[i*r+1], max[i*r+2], allocated[i*r+0], allocated[i*r+1], allocated[i*r+2]);
    }

}

int main(){ //test input: 1 5 3 10 5 7 7 5 3 3 2 2 9 0 2 2 2 2 4 3 3 0 1 0 2 0 0 3 0 2 2 1 1 0 0 2
    bool menu = true;
    int menuop;

    while (menu == true)
    {
        printf("\nBanker's Algorithm\n--------------------");
        printf("\n1)Enter Parameters\n2)Determine Safe Sequence\n3)Quit Program\n");
        scanf("%d", &menuop);

        if (menuop == 1)
        {
            printf("1 Chosen\n");
            params();
        } else if (menuop == 2)
        {
            printf("2 Chosen\n");
        } else if (menuop == 3)
        {
            printf("Program Successfully Quit.\n");
            menu = false;
        } else {
            printf("Error: Enter a number 1-3");
        }
        
    }
    

    return 1;
}