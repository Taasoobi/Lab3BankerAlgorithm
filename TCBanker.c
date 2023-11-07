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



}

int main(){
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