#ifndef INSERT_H
#define INSERT_H

#include <iostream>

template <class Item>
  void exch(Item &A, Item &B){
      Item t = A; A = B; B = t;
  }

template <class Item>
void compexch(Item &A, Item &B){
      if(B < A) exch(A, B);
  }

template <class Item>
  void sort(Item a[], int l, int r){
    for(int i = l; i < r; i++)
      for(int j = i; j > l; j--)
        compexch(a[j-1], a[j]);
  }

template <class Item>
void show(Item a[], int l, int r){
  for(int i = l; i < r; i++) std::cout << a[i] << " ";
  std::cout << std::endl;
}

#endif
