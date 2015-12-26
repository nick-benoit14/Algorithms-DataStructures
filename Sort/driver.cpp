#include <iostream>
#include <stdlib.h>
#include "SelectionSort.h"

int main(int argc, char* argv[]){
  int i, N = atoi(argv[1]), M = 0,  sw = atoi(argv[2]);
  int *a = new int[N];

  if(sw) for(i = 0; i < N; i++)
      a[i] = 1000 * (1.0 * rand() / RAND_MAX);

  else{while(std::cin >> a[M] && M < N) M++;}

  sort(a, 0, N-1);
  show(a, 0, N-1);
}
