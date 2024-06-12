#include <stdio.h>
#include <string.h>

// Function to perform XOR operation
void xorOperation(char *dividend, char *divisor, int divisorLength) {
    for (int i = 0; i < divisorLength; i++) {
        dividend[i] = (dividend[i] == divisor[i]) ? '0' : '1';
    }
}

// Function to calculate CRC
void calculateCRC(char *dataword, char *divisor, char *remainder) {
    int datawordLength = strlen(dataword);
    int divisorLength = strlen(divisor);
    
    // Create a temporary dividend array
    char dividend[128];
    strcpy(dividend, dataword);

    // Append (divisorLength - 1) zeros to the dividend
    for (int i = 0; i < divisorLength - 1; i++) {
        dividend[datawordLength + i] = '0';
    }
    dividend[datawordLength + divisorLength - 1] = '\0';

    // Copy the initial dividend to the remainder
    strncpy(remainder, dividend, divisorLength);
    remainder[divisorLength] = '\0';

    // Perform the division using XOR
    for (int i = 0; i < datawordLength; i++) {
        // If the leading bit is '1', perform XOR with the divisor
        if (remainder[0] == '1') {
            xorOperation(remainder, divisor, divisorLength);
        }
        
        // Shift left and bring down the next bit from the dividend
        for (int j = 0; j < divisorLength - 1; j++) {
            remainder[j] = remainder[j + 1];
        }
        remainder[divisorLength - 1] = dividend[i + divisorLength];
    }

    // Perform the final XOR operation if necessary
    if (remainder[0] == '1') {
        xorOperation(remainder, divisor, divisorLength);
    }

    // Remove the leading bit
    for (int i = 0; i < divisorLength - 1; i++) {
        remainder[i] = remainder[i + 1];
    }
    remainder[divisorLength - 1] = '\0';
}

int main() {
    char dataword[128];
    char divisor[128];
    char remainder[128];

    // Input dataword and divisor
    printf("Enter the dataword: ");
    scanf("%s", dataword);
    printf("Enter the divisor: ");
    scanf("%s", divisor);

    // Calculate CRC
    calculateCRC(dataword, divisor, remainder);

    // Print the result
    printf("The CRC is: %s\n", remainder);

    // Append the CRC to the dataword
    strcat(dataword, remainder);

    // Print the final codeword
    printf("The codeword is: %s\n", dataword);

    return 0;
}




/*
int main(){
    int dataword_size, divisor_size, new_size;

    printf("Enter Dataword and Divisor size (space separated): ");
    scanf("%d %d", &dataword_size, &divisor_size);

    new_size = dataword_size + divisor_size - 1;
    int data_word[new_size];
    int divisor[divisor_size];
    int remainder[divisor_size];

    printf("Enter Dataword: ");
    for(int i = 0; i < dataword_size; i++)
        scanf("%d", &data_word[i]);
    
    for(int i = dataword_size; i < new_size; i++)
        data_word[i] = 0;

    printf("Enter Divisor: ");
    for(int i = 0; i < divisor_size; i++)
        scanf("%d", &divisor[i]);

    // CRC algorithm


    return 0;
}*/