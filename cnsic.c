#include <stdio.h>

void main(){
    int binary[10]; // Used to capture the binary code
    int hexadecimal[10];
    int input; // Used to capture the input
    int i = 0; // Used to iterate loops

    printf("Enter a number between 0 and 1000: ");
    scanf("%d", &input);

    // Convert to binary and add to array
    int toBinary = input;
    while (toBinary != 0) {
        binary[i] = toBinary % 2;
        toBinary = toBinary / 2;
        i++;
    }

    // Print binary result
    printf("Binary: ");
    for (i = 9; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");

    int toHex = input;

    // Convert to hexadecimal
    i = 0;
    while (toHex != 0) {
        hexadecimal[i] = toHex % 16;
        toHex = toHex / 16;
        i++;
    }

    // Print hexadecimal result
    printf("Hexadecimal: ");
    for (i = 9; i >= 0; i--) {
        printf("%X", hexadecimal[i]);
    }
    printf("\n");

    // Shitf 10 bits to the lift
    printf("Left shift by 10: %d\n", input << 10);
}