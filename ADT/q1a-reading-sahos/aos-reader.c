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
#include "aos-reader.h"
#include "string-reader.h"
#include "cs136-trace.h"

// Below is the partial memory diagram at the end of read_saohs, just before
//   returning to main:9.
//
// === HEAP ===============
// | addr_1 |        "CS" |
// |  ...   |     ...     |
// | addr_2 |       "136" |
// |  ...   |     ...     |
// | addr_3 |         "!" |
// |  ...   |     ...     |
// === STACK ==============
// read_saohs
//     saohs: [addr_0]
//     len:   4
//     r/a:   main: 9
// -----------------------------
// main
//     saohs: {addr_1,
//             addr_2,
//             addr_3,
//             NULL}   [addr_0]
//     r/a:   OS
// ============================
void read_saohs(char **saohs, int len) {
    assert(saohs);
     for (int i = 0; i < len; i++) {
        char *line = read_single_line();
        if (line == NULL) {
            break;
        }
        saohs[i] = line;
    }
}

void destroy_saohs(char **saohs, int len) {
    assert(saohs);
    for (int i = 0; i < len; i++) {
        free(saohs[i]);
    }
}