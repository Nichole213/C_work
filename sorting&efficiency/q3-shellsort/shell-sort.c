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
#include <stdio.h>
#include "shell-sort.h"
#include "cs136-trace.h"

// === HELPER FUNCTIONS =======================================================

// array_print(arr, len) outputs the content of the array arr.
// requires: len must be positive
// effects:  produces output
// time:     O(n)
static void array_print(const int *arr, int len) {
  assert(arr);
  assert(len > 0);
  printf("[%d", *arr);
  for (const int *p = arr + 1; p < arr + len; ++p) {
    printf(", %d", *p);
  }
  printf("]\n");
}

// === MODULE FUNCTIONS =======================================================

void shell_sort(int arr[], int len) {
  // your implementation goes here
}
