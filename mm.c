#include <stdio.h>

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
    for(int i = 15; i >= 0; --i) {
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

void main() {
    int input;
    char bits[16] = { // Least significant bit
                        '0', '0', '0', '0', '0', '0', '0', '0',
                        '0', '0', '0', '0', '0', '0', '0', '0' // Most significatn bit
                    };

    // Prompt user
    printf("Enter the number 4095 or 8191: ");
    scanf("%d", &input);

    //Display in binary
    printf("Binary: ");
    convertPrintBinary(input, &bits[0]);

    // Display in hex
    printf("Hex: 0x%08X\n", input);

    // Virtual and physical tables
    int vEntries = 1048575 / input;
    int pEntries = 524287 / input;
    int virtual[vEntries][input];
    int physical[pEntries][input];

    int a = 0; // Address value in decimal
    
    // Loop through entries
    for(int i = 0; i < pEntries; i++) {
        // Loop through pages
        for(int j = 0; j < input; j++) {
            virtual[i][j] = i;
            physical[i][j] = a;
            a++;
        }
    }

    int hexInput;
    printf("Enter a hex value from 0x00000000 to 0x000FFFFF: ");
    scanf("%X", &hexInput);

    // Display in hex
    printf("Hex: 0x%08X\n", hexInput);

    // Get entry and offset
    int entry = hexInput / input;
    int offset = hexInput - (input * entry);
    if (hexInput > 0 && physical[entry][offset] == 0) {
        printf("Currently on Disk\n");
    } else {
        printf("Physical Address: 0x%08X\n", physical[entry][offset]);
    }
}