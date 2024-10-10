/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// No collaboration
//
// Name: Nichole Huang
// login ID: n3huang
//////////////////////////////////////////////////////////////////////////////////////////

#include <assert.h>
#include "selectionsort-ptr.h"
#include "cs136-trace.h"


// swap(i, j) swaps the values pointed to by a and b.
// effects:  mutates *a and *b
static void swap(int *i, int *j) {
  assert(i);
  assert(j);
  int tmp = *i;
  *i = *j;
  *j = tmp;
}


// See selectionsort-ptr.h for documentation
void array_sort_ptr(int *start, int *end) {
  assert(start);
  assert(end);
  assert(start <= end);
  for (int *i = start; i < end; ++i) {
    int *smallest = i; 
    for (int *j = i + 1; j <= end; ++j) {
      if (*j < *smallest) {
        smallest = j;
      }
    }
  swap(i, smallest);
  }
}