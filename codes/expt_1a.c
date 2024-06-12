// Program to demonstrate bit stuffing and destuffing
#include <stdio.h>

int main(){
    int N = 0, bit = 0, ones_count = 0, zero_detected = 0, index = 0, index2 = 0;
    // Reading the frame size;
    printf("Enter frame size: ");
    scanf("%d", &N);
    // Defining the array size for the data_frame
    int new_size = (int) N/6 + N;
    int stuffed_data_frame[new_size];
    int destuffed_data_frame[N];
    // Read the dataframe and bit stuff it simultaneously
    printf("Enter the data frame (%d space separated bits): ", N);
    for(int i = 0; i < N; i++){
        scanf("%d", &bit);
        // If incoming bit is zero, reset ones count and zero_detected is true
        if(bit == 0){
            ones_count = 0; zero_detected = 1;
            stuffed_data_frame[index++] = bit;
        } else if(ones_count == 4){
            ones_count = 0; zero_detected = 0;
            stuffed_data_frame[index++] = bit;
            stuffed_data_frame[index++] = 0;
        } else{
            stuffed_data_frame[index++] = bit;
            ones_count = (zero_detected) ? ++ones_count : ones_count;
        }
    }
    // Print stuffed data
    printf("\nStuffed Data : ");
    for(int i = 0; i < index; i++)
        printf("%d", stuffed_data_frame[i]);
    // Print framed data by adding flags
    printf("\nFramed Data : 01111110");
    for(int i = 0; i < index; i++)
        printf("%d", stuffed_data_frame[i]);
    printf("01111110\n");

    // Bit destuffing
    for(int i = 0; i < index; i++){
        bit = stuffed_data_frame[i];

        if(bit == 0){
            ones_count = 0; zero_detected = 1;
            destuffed_data_frame[index2++] = bit;
        } else if(ones_count == 4){
            ones_count = 0; zero_detected = 0;
            destuffed_data_frame[index2++] = bit;
            i++;
        } else{
            destuffed_data_frame[index2++] = bit;
            ones_count = (zero_detected) ? ++ones_count : ones_count;
        }
    }
    printf("Destuffed Data : ");
    for(int i = 0; i < index2; i++)
        printf("%d", destuffed_data_frame[i]);
    return 0;
}