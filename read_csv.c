#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_csv.h"

void read_csv(const char* csv_filename){
    FILE *file = fopen(csv_filename, "rt");
    if (file == NULL) exit(1);  //File empty
    char array[1000];

    fgets(array,999,file);
    while(!feof(file)) {
        fputs(array, stdout);
        fgets(array,999,file);
    }
    printf("\n");
    fclose(file);
}
