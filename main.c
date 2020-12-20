#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert_to_csv.h"
#include "read_csv.h"


void find_name(const char* csv_filenmae, const char* name);
void add_record(const char* csv_filename, const char* name, const int age, const char* city);
void delete_record(const char* csv_filename, const char* name);

int main()
{
 /* Question 1 */
 load_and_convert("input.txt");
 /* Question 2 */
 read_csv("output.csv");
 /* Question 3.1 */
 find_name("output.csv", "Maria");
 find_name("output.csv", "Jason"); //Jason doesn't exist
 /* Question 3.2 */
 add_record("output.csv", "Jason", 36, "Skookumchuk");
 read_csv("output.csv"); // to print to the screen
 /* Question 3.3 */
 delete_record("output.csv", "Maria");
 read_csv("output.csv"); // to print to the screen
 return 0;
}

void find_name(const char* csv_filenmae, const char* name) {
    FILE *f = fopen("output.csv", "rt");
    if (f == NULL) exit(1);
    char array[1000];
    int i, count=0;

    fgets(array, 999, f);
    while(!feof(f)){
        if (strstr(array, name) != 0){
            printf("%s", array);
            count++;
        }
        fgets(array,999,f);    
    }
    if (count == 0) {
        printf("Name not found\n");
    }
    printf("\n");
    fclose(f);
}

void add_record(const char* csv_filename, const char* name, const int age, const char* city) {
    FILE *output = fopen("output.csv", "at");
    if (output == NULL) exit(1);

// Convert int to string
    char temp[50];
    sprintf(temp, "%d", age);
// Print into csv file
    fputs(name, output);
    fputs(", ", output);
    fputs(temp, output);
    fputs(", ", output);
    fputs(city, output);
    fputs("\n\0", output);

    fclose(output);
}
void delete_record(const char* csv_filename, const char* name) {
    FILE *f = fopen("output.csv", "rt");
    FILE *new = fopen("temp.csv", "wt");
    if (f == NULL) exit(1);
    char array[1000];
    int size = 0,check = 0, i=0, ret;

    fgets(array,999,f);
    while(!feof(f)) {
        if (strstr(array,name) != 0 && check == 0)  {
            check++;
            fgets(array,999,f);
        } else {
            fputs(array, new);
            fgets(array,999,f);
        }
    }
    fclose(f);
    fclose(new);
    ret = remove("output.csv");
    rename("temp.csv", "output.csv");
}
