#ifndef SELECT_H
#define SELECT_H

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
    for(int i = l; i < r; i++){
      int min = i;
      for(int j = i + 1; j < r; j++){
        if(a[j] < a[min]) min = j;
      }
      exch(a[i], a[min]);
  }}

template <class Item>
void show(Item a[], int l, int r){
  for(int i = l; i < r; i++) std::cout << a[i] << " ";
  std::cout << std::endl;
}

#endif
