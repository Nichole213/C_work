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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "string-decode.h"
#include "cs136-trace.h"

char *str_decode(const char *str) {
    assert(str);
    int len = strlen(str);
    char *result = malloc(len + 1); 
    assert(result);

    int j = 0; 
    for (int i = 0; i < len; i += 2) {
        int count = str[i] - '0';
        char ch = str[i+1];
        for (int k = 0; k < count; ++k) {
            result[j++] = ch;
        }
    }
    result[j] = '\0';
    return result;
}