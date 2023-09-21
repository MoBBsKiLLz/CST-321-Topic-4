#include <stdio.h>

void main(){
    int binary[10]; // Used to capture the binary code
    int input; // Used to capture the input

    printf("Enter a number between 0 and 1000: ");
    scanf("%d", &input);

    // Convert to binary and add to array
    int toBinary = input;
    int i = 0; // Used to iterate loops
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

    // Print hexadecimal result
    printf("Hexadecimal: 0x%08X\n", input);

    // Shift the number 10 bits to the left, mask out the lower 10 bits, and OR in the number 0x03FF
    int result = ((input << 10) & 0xFFFFFC00) | 0x03FF;

    // Display results in decimal, bianry and hexidecimal
    printf("The bitwise result in decimal is: %d\n", result);
    printf("The bitwise result in hex is: 0x%08X\n", result);
    printf("The bitwise result in binary is: ");

    // Convert to binary and add to array
    int resBinary[20];
    int resToBinary = result;
    i = 0; // Used to iterate loops
    while (resToBinary != 0) {
        resBinary[i] = resToBinary % 2;
        resToBinary = resToBinary / 2;
        i++;
    }

    // Print binary result
    for (i = 19; i >= 0; i--) {
        printf("%d", resBinary[i]);
    }
    printf("\n");

}