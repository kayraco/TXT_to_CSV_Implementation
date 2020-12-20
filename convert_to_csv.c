#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert_to_csv.h"

void insert_to_array(char array[1000], char words[1000][1000]);

void load_and_convert(const char* filename) {
    int i;
    char array[1000];
    char names[1000][1000];
    char age[1000][1000];
    char city[1000][1000];
    char* temp1;
    char* temp2;
    char* temp3;
    FILE *f = fopen(filename, "rt");
    FILE *output = fopen("output.csv", "wt");

    if (f == NULL) {
        exit(1);
    }
    
    fgets(array,999,f);
    insert_to_array(array, names);

    fgets(array,999,f);
    insert_to_array(array, age);

    fgets(array,999,f);
    insert_to_array(array, city);

    i = 0;
    while (names[i][0]){
        fputs(names[i], output);
        fputs(", ", output);
        fputs(age[i], output);
        fputs(", ", output);
        fputs(city[i], output);
        fputs("\n\0", output);
        i++;
    }
    fclose(f);
    fclose(output);
}


void insert_to_array(char array[1000], char words[1000][1000]){

    int i = 0;
    int j = 0;
    int count = 0;

    for (i = 0; i < strlen(array); i++){
        if (array[i] == ' ' || array[i] == '\n' || array[i] == '\0'){
            words[count][j] = '\0';
            count++;
            j = 0;
        } else {
            words[count][j] = array[i];
            j++;
        }
    }
}
