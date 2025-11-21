#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Prototypes
void print_int_loop(int len, int *arr); // Helper function to print int arrays.
void print_type(int is_int); // Print out the data type of the input.
int get_length(int i, char *argv[]); // Get length of 1st command line arg.
int convert_to_int_arr(int n, int len, int *arr); // Convert int to array of ints -> returns length of array.
int convert_argv(int len, char *argv[], int *arr); // Convert the 1st command line arg to array of ints.
int compare_arg_vs_max_int(int arg_length, int int_max_length, int *args, int *int_max_arr); // Compare array containing the values of the input and INT_MAX.

// Main
int main(int argc, char *argv[])
{ 
  int int_max = INT_MAX;
  int int_max_arr[12];
  int int_max_length = convert_to_int_arr(int_max, 12, int_max_arr); // Get length of INT_MAX - function populates array with discrete ints.
  int arg_length = get_length(1, argv);
  int args[arg_length];
  
  convert_argv(arg_length, argv, args); // Populate args array with discrete ints, i.e., {123} becomes {1, 2, 3}.

  int is_int = compare_arg_vs_max_int(arg_length, int_max_length, args, int_max_arr);
  
  // Tests
  print_int_loop(int_max_length, int_max_arr);
  printf("length of arg: %d\n", arg_length); 
  printf("int_max length: %d\n", int_max_length);
  printf("args array:\n");
  print_int_loop(arg_length, args);
  print_type(is_int);
  return 0;
}

// Function Definitions
void print_int_loop(int len, int *arr)
{
  int i;
  for (i = 0; i < len; i++)  
  {
    printf("arr[%d]: %d\n", i, arr[i]);
  }
}

void print_type(int is_int)
{
  printf("is_int: %d\n", is_int);
  if (is_int == 0)
  {
    printf("Type is long long\n");
  }
  if (is_int == 1)
  {
    printf("Type is int\n");
  }
}

int get_length(int i, char *argv[])
{
  int length = 0;
  while (argv[i][length] != '\0')
  {
    length++; 
  }
  return length;
}

// Function expects type "pointer to int" (int*) and arr will be passeds as the namespace of the array.
// Once arr is passed, its namespace decays to a pointer to the first element: arr[0].
int convert_to_int_arr(int n, int len, int *arr)
{
  // Convert input n to null-terminated char array.
  char separate_chars[len];
  sprintf(separate_chars, "%d", n);

  // Populate external array with ints
  int i = 0;
  while (separate_chars[i] != '\0')
  {
    arr[i] = separate_chars[i] - '0';
    i++;
  }
  return i;
}

// argv[] is passed to the function as an array of character pointers.
// Using array subscript notation, the function dereferences, first, the pointer to the second char array within argv, and then the first character in that char array..
int convert_argv(int len, char *argv[], int *arr)
{
  int i = 0;
  while (i < len) 
  {
    arr[i] = argv[1][i] - '0';
    i++;
  }
  return 0;
}

int compare_arg_vs_max_int(int arg_length, int int_max_length, int *args, int *int_max_arr)
{
  if (arg_length < int_max_length)
  {
    return 1; // Return 1 for is_int = true
  }
  if (arg_length > int_max_length)
  {
    return 0; // Return 0 for is_int = false -> input type is long long 
  }
  
  int i;
  for (i = 0; i < arg_length; i++)
  {
    if (args[i] > int_max_arr[i]) 
    {
      return 0; // Return 0 for is_int = false -> input type is long long
    }
  }
  return 1; // Return 1 for is_int = true -> args[] == int_max_arr[]
}
