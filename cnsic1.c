#include <stdio.h>
#include <stdbool.h>

void decimalToBinary(int number, char* bits) {
    int i = 0;
    int result = number;
    while(result != 0) {
        int remainder = result % 2;
        if(remainder > 0) {
            bits[i] = '1';
        }
        result = result / 2;
        i++;
    }
}

void printResult(char* bits){
    for(int i = 31; i >= 0; --i) {
        printf("%c", bits[i]);
    }
    printf("\n");
}

void clearBinaryBits(char* bits){
    decimalToBinary(0, &bits[0]);
}

void convertPrintBinary(int number, char* bits) {
    clearBinaryBits(&bits[0]);
    decimalToBinary(number, &bits[0]);
    printResult(&bits[0]);
}

int main(int argc, const char * argv[]){
    int number = 0;
    bool ok = false;
    char bits[32] = { // Least significant bit
                        '0', '0', '0','0','0', '0', '0','0',
                        '0', '0', '0','0','0', '0', '0','0',
                        '0', '0', '0','0','0', '0', '0','0',
                        '0', '0', '0','0','0', '0', '0','0' // Most significatn bit
                    };
    
    while (!ok) {
        printf("\nEnter a number between 0 and 1000: ");
        scanf("%d", &number);
        if(number < 0 || number > 1000) {   
            printf("The number needs to be between 0 and 1000]n");
        } else {
            ok = true;
        }
    }

    // Convert to and display binary
    printf("Binary: ");
    convertPrintBinary(number, &bits[0]);

    // Dsiplay as hex
    printf("Hex: 0x%08X\n", number);

    // Shift the number 10 bits to the left, mask out the lower 10 bits, and OR in the number 0x03FF
    int result = ((number << 10) & 0xFFFFFC00) | 0x03FF;

    // Display results in decimal, bianry and hexidecimal
    printf("The bitwise result in decimal is: %d\n", result);
    printf("The bitwise result in hex is: 0x%08X\n", result);
    printf("The bitwise result in binary is: ");
    convertPrintBinary(result, &bits[0]);

    return 0;
}