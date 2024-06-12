#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() { 
    int i = 1, j = 1, noframes = 10, x, x1 = 10, x2 = 1;

    // Seed the random number generator with the current time
    srand(time(NULL));

    printf("\nNumber of frames is %d",noframes); 
    getch();

    while(noframes>0) { 
        printf("\nsending frame %d",i); 
        x = rand() % 10;
        printf("\nxval: %d", x);
        if(x == 0){ 
            printf("\nwaiting for %d seconds\n", x2); 
            sleep(x2);  
            printf("\nsending frame %d\n",i);
        } 
        printf("\nack for frame %d\n",j); 
        noframes--; 
        i++; 
        j++; 
    } 
    printf("\nEnd of stop and wait protocol\n"); 
    return 0;
}