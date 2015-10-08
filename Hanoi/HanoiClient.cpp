#include <iostream>
#include <stdlib.h>     /* atoi */
#include "Hanoi.h"


int main(int argc, char *argv[])
  {
    int n = atoi(argv[1]);
    Hanoi a(n);
    return 0;
  }
