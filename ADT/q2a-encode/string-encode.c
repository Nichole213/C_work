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
#include "string-encode.h"
#include "cs136-trace.h"

char *str_encode(const char *str) {
    assert(str);
    int len = strlen(str);
    char *result = malloc(len * 2 + 1);  
    assert(result);

    if (len == 0) {
        result[0] = '\0';
        return result;
    }

    int j = 0;
    char prev_char = str[0];
    int count = 1;

    for (int i = 1; i < len; ++i) {
        if (str[i] == prev_char) {
            ++count;
        } else {
            result[j++] = '0' + count;
            result[j++] = prev_char;
            prev_char = str[i];
            count = 1;
        }
    }
    result[j++] = '0' + count;
    result[j++] = prev_char;
    result[j] = '\0';

    return result;
}