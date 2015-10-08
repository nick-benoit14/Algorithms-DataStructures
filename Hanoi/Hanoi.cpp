
#include "Hanoi.h"
#include <iostream>
#include <iomanip>


Hanoi::Hanoi(int n)
  {
    numDisk = n;
    h(n,1,2,3);
  }

int Hanoi::h(int n, int source, int dest, int aux)
  {
    if(n == 0) return n;

    h(n-1,source, aux, dest);
    move(n, source, dest);
    h(n-1, aux, dest, source);
  }


int Hanoi::move(int n, int a, int b)
  {
    int indent = numDisk - n;

    for(int i = 0; i < indent; i++) std::cout <<  "    ";
    std::cout  << "Moved " << n << " from " << a << " to " << b << std::endl;
  }
