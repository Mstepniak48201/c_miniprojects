# Decimal and Binary Project

## Project Goal
Write a program in C that converts an input number from decimal to binary, or vice versa.

The program should take two command line arguments:  
1. The letter "d" or "b", case insensitive, to indicate whether the number to be converted will be in Decimal or Binary form.
2. A number *n*: 

The program converts *n* from decimal to binary or the reverse, and prints out:  
"The number *n* has been converted from *decimal/binary* to *decimal/binary*. The result is *converted number*"

If the program doesn't receive two command line args, it should return an error message: "Please input correct number of arguments." and return 1.

## Starting Point  
The first thing to do, it seems to me, is to determine the type of the number inputted by the user:
- int
- long int
- long long

## Modules
[ ] **Error Checker**  
  [ ] If first arg isn't "d" or "b", print "Please input 'd' or 'b' to indicate whether number input will be decimal or binary."  
    - return 0  
  [ ] If second arg contains anything but 0-9 digits, print "Please input a number as the second arg."  
    - return 0
 
[ ] **Determine Data Type of Number Input**  
  [ ] Takes "d" or "b" arg to indicate if number input will be Decimal or Binary (unsure if this is relevant)  
  [ ] Determines the limits of the C implementation for int, long int, and long long data types  
  [ ] Determines whether the number arg is an int, long int, or long long  
  [ ] Converts the number input from char to the appropriate data type

   

