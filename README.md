# TXT_to_CSV_Implementation

Program that implements the needed logic to read a text file and convert it to CSV.

convert_to_csv.c implements the function load_and_convert. 
The code is split into 2: 
  convert_to_csv.c (contains the implementation) 
  convert_to_csv.h (contains the declaration)
  The function takes one arguments that is the name of the input file to be converted, it creates a new csv file called output.csv
  
 *** load_and_convert is the public interface that is called by other modules ***

read_csv.c implements the read_csv function which reads a csv file and prints its 
content to the screen line by line. 
The code is split into 2: 
  read_csv.c (contains the implementation) 
  read_csv.h (contains the declaration)
  
  *** read_csv is the public interface that is called by other modules ***

main.c contains the main function and the following:

  find_name which checks whether a name exists in the csv file, if so prints to screen (prints
  all the records if there are multiple occurences, if not prints, "Name not found")
  
  add_record function which adds a new record to the end of the csv file
  
  delete_record function which deletes a record from the csv file
  
