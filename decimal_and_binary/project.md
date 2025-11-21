# Decimal and Binary Project

## Project Goal
Write a program in C that converts an input number from decimal to binary, or vice versa.

The program should take two command line arguments:  
1. The letter "d" or "b", case insensitive, to indicate whether the number to be converted will be in Decimal or Binary form.
2. A number *n*: 

The program converts *n* from decimal to binary or the reverse, and prints out:  
"The number *n* has been converted from *decimal/binary* to *decimal/binary*. The result is *converted number*"

If the program doesn't receive two command line args, it should return an error message: "Please input correct number of arguments." and return 1.

## Decision Log
- long int:  
This program will consider ints larger than 4 bytes to be long longs. I am in a bit over my head at this point, If I am understanding correctly, it has been nearly 20 years since 32 bit systems were widely produced, and the data type `long int` is an artifact of that era. I am doing this to learn, not to be a perfectionist, and 64 bit systems are the standard, so that is where I will focus.

- strtol():
I will not use `strtol()` in this program. `strtol()` is capable of taking in a string and outputting long int as a binary or decimal. The problem is that using `strtol()` negates the point of writing this program: to learn. Using `strtol()` to convert a char to a long and casting to int, but not using its capability to output the desired format (decimal or binary) seems silly! And deciding to use `strtol()` to output the desired format means the program is complete. As the point of writing this program is to learn, I will find another way to accomplish the goal.

## Starting Point  
The first thing to do, it seems to me, is to determine the type of the number inputted by the user:
- int
- ~~long int~~
- long long

## Module List
[ ] **Error Checker**  
  [ ] If first arg isn't "d" or "b", print "Please input 'd' or 'b' to indicate whether number input will be decimal or binary."  
    - return 0  
  [ ] If second arg contains anything but 0-9 digits, print "Please input a number as the second arg."  
    - return 0
 
[ ] **Determine Data Type of Number Input**  
  [ ] Takes "d" or "b" arg to indicate if number input will be Decimal or Binary (unsure if this is relevant)  
  [ ] Determines the limits of the C implementation for int and long long data types  
  [ ] Determines whether the number arg is an int or long long.  
  [ ] Converts the number input from char to the appropriate data type

## Module Plans

### Determine Data Type of Number Input
Starter Logic:  
```
// Pseudo code
int INT_MAX
int int_length = length of INT_MAX
int argv_length = length of number arg of argv
int equality_counter = 0

if argv_length < int_length:
  convert to int
  return
if argv_length > int_length:
  convert to long long
  return
else
  int max_int[] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7}
  int arg_contents[argv_length] = {// array of contents of argv[i]}
  for i = 0; i < 10; i++
    if max_int[i] > arg_contents[i]
      convert to int
      return 0
    else if arg_contents[i] > max_int[i]
      convert to long long
      return 0
    else
      equality_counter++
if equality_counter == max_int length
  convert to int
  return 0
```

### Planning Update 10.17
Goal: Determine data type of command line argument  
- To get, To do:  
[X] Length of `INT_MAX`  
[X] Length of `argv[1]`- The command line arg when running the program.  
    [ ] Compare them to determine if type `int` or `long long`.  

[X] Array of ints from `INT_MAX`. 
[X] Array of ints from `argv[1]`.  
    [ ] Compare them to determine if type `int` or `long long`.


- Refinements:  
[ ] Error handling: single command line arg required, must be digits only
[ ] Accept negative numbers  
[ ] Strip leading zeros

