#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
 
int main(int argc, char *argv[])
// JPEG start with 0xff, 0xd8, 0xff, and the fourth one is 0xe0/0xe1...
// last byte is 0xe0/0xe1...
// There are 512 byte in the card.raw file.
{
    if (argc != 2){
        printf("Usage: ./recover card.raw\n");
        return 1;
    }
    
    char *input_file_name = argv[1];
    FILE *input_pointer = fopen(input_file_name, "r");

    if (input_pointer == NULL){
        printf("Invalid input file\n");
        return 2;
    }

    BYTE buffer[512];
    int count = 0;
    FILE *img_pointer = NULL;
    char file_name[8];
    
    while (fread(&buffer, 512, 1, input_pointer) == 1){
        if (buffer[0] == '0xff' && buffer[1] == '0xd8' && buffer[2] == '0xff' && (buffer[3] & 0xf0) == 0xe0){
            if (!(count == 0)){
                fclose(img_pointer);
            }

            sprintf(file_name, "%03i.jpg", count);
            img_pointer = fopen(file_name, "w");
            count++;
        }

        if (!(count == 0)){
            fwrite(&buffer, 512, 1, img_pointer);
        }
    }

    fclose(input_pointer);
    fclose(img_pointer);
    printf("Succeed!");
    return 0;

}