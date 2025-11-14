#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Prototypes
int get_length(int i, char *argv[]);
void populate_args(int len, int index, char *argv[], int *result);

int main(int argc, char *argv[])
{
  /*
  int max_int = INT_MAX;
  int max_int_length = sizeof(max_int) / sizeof(max_int[0]);
  printf("%d\n", max_int_length);
  */  
  int length = get_length(1, argv);
  int args[length];

  // Pass `args` as the namespace, not a pointer to array!
  populate_args(length, 1, argv, args);

  int i;
  for (i = 0; i < length; i++)
  {
    printf("%d", args[i]);
  }
  printf("\n");
  
  return 0;
}

// Remember: *argv[] is AN ARRAY OF POINTERS TO STRINGS!
// Strings are null-terminated character arrays.
// This means I can test where the string ends by searching for the character literal '\0'
// Pass in *argv as a pointer!
int get_length(int i, char *argv[])
{
  int length = 0;
  while (argv[i][length] != '\0')
  {
    length++; 
  }
  return length;
}

// 
void populate_args(int len, int index, char *argv[], int *args)
{
  int i;
  for (i = 0; i < len; i++) 
  {
    args[i] = argv[index][i] - '0';
  }
}



/*
// Prototypes
void get_size(int *sz_int, int *sz_long, int *sz_long_long);

int main(int argc, char *argv[])
{
  int sz_int, sz_long, sz_long_long;
  get_size(&sz_int, &sz_long, &sz_long_long);
  printf("Size of an int: %d\nSize of a long int: %d\nSize of a long long: %d\n", sz_int, sz_long, sz_long_long);
  printf("The MAX size of an int is: %d\n", INT_MAX);
  return 0;
}

// Function definitions
void get_size(int *sz_int, int *sz_long, int *sz_long_long)
{
  *sz_int = sizeof(int);
  *sz_long = sizeof(long int);
  *sz_long_long = sizeof(long long);
}
*/

