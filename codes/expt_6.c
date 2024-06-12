#include <stdio.h>

int main(){
    char message[100];
    char encrypted[100];
    int key, i;

    printf("Enter the message: ");
    scanf("%s", message);

    printf("Enter the key: ");
    scanf("%d", &key);

    printf("Encrypted message: ");
    for(i = 0; message[i] != '\0'; i++){
        char temp = ((message[i] - 'a' + key) % 26) + 'a';
        encrypted[i] = temp;
        printf("%c", temp);
    }
    encrypted[i] = '\0';

    printf("\nDecrypted message: ");
    for(int i = 0; encrypted[i] != '\0'; i++){
        char temp = ((encrypted[i] - 'a' - key) % 26) + 'a';
        // encrypted[i] = temp;
        printf("%c", temp);
    }
    return 0;
}