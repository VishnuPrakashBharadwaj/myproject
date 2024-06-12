#include <stdio.h>

int main(){
    int sz;
    printf("Enter number of characters in data frame: "); 
    scanf("%d",&sz); 
    char data_frame[sz]; 
    char esc='}', flag='~';
    printf("enter data sequence: "); 
    scanf("%s", data_frame);
    printf("Escape char: %c\nFlag char: %c\n", esc, flag);

    
    return 0;
}