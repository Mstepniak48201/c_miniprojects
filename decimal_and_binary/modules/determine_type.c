#include <stdio.h>
#include <stdlib.h>

// Prototypes
void get_size(int *sz_int, int *sz_long, int *sz_long_long);

int main(int argc, char *argv[])
{
  int sz_int, sz_long, sz_long_long;
  get_size(&sz_int, &sz_long, &sz_long_long);
  printf("Size of an int: %d\nSize of a long int: %d\nSize of a long long: %d\n", sz_int, sz_long, sz_long_long);
  return 0;
}

// Function definitions
void get_size(int *sz_int, int *sz_long, int *sz_long_long)
{
  *sz_int = 1;
  *sz_long = 2;
  *sz_long_long = 3;
}

