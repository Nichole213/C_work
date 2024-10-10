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
#include <stdlib.h>
#include "arr-tools.h"
#include "cs136-trace.h"

// See arr-tools.h for documentation.
int minmax_dist(int arr[], int len) {
    assert(arr);
    assert(len > 0);
    if (len == 1) {
        return 0;
    } else if (len == 2) {
        return 1;
    }

    int min = arr[0];
    int max = arr[0];
    for (int i = 0; i < len - 1; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }    
    }

    int min_pos = 0;
    for (int j = 0; j < len; j++) {
        if (arr[j] == min) {
            min_pos = j;
            break;
        }
    }

    int max_pos = 0;
    for (int k = 0; k < len; k++) {
        if (arr[k] == max) {
            max_pos = k;
            break;
        }
    }

    return abs(max_pos - min_pos);
}

// See arr-tools.h for documentation.
int most_occurrences(int arr[], int len) {
    assert(arr);
    assert(len > 0);
    int max_count = 0;      
    int most_fcy = arr[0];   
    int count;
    for (int i = 0; i < len; i++) {
        count = 1;  
        for (int j = i + 1; j < len; j++) {
            if (arr[j] == arr[i])
                count++;
        }
        if (count > max_count || (count == max_count && arr[i] < most_fcy)) {
            max_count = count;
            most_fcy = arr[i];
        }
    }
    return most_fcy;
}

// See arr-tools.h for documentation.
// example: arr [2, 4, 4, 2, 6, 2, 3, 5], wnd_size 2
//               ^                       ->   (2)/1 = 2
//               ^  ^                    -> (2+4)/2 = 3
//                  ^  ^                 -> (4+4)/2 = 4
//                     ^  ^              -> (4+2)/2 = 3
//                        ^  ^           -> (2+6)/2 = 4
//                           ^ ^         -> (6+2)/2 = 4
//                              ^  ^     -> (2+3)/2 = 2(.500)
//                                 ^  ^  -> (3+4)/2 = 4
// example: arr [2, 4, 4, 2, 6, 2, 3, 5], wnd_size 4
//               ^                       ->       (2)/1 = 2
//               ^  ^                    ->     (2+4)/2 = 3
//               ^  ^  ^                 ->   (2+4+4)/3 = 3(.333)
//               ^  ^  ^  ^              -> (2+4+4+2)/4 = 3
//                  ^  ^  ^  ^           -> (4+4+2+6)/4 = 4
//                     ^  ^  ^ ^         -> (4+2+6+2)/4 = 3(.500)
//                        ^  ^  ^  ^     -> (2+6+2+3)/4 = 3(.250)
//                           ^  ^  ^  ^  -> (6+2+3+5)/4 = 4
void moving_average(int arr[], int len, int size) {
    assert(arr);
    assert(len > 0 && len <= 100);
    assert(size > 0);
    int temp[100];
    for (int i = 0; i <= len; i++) {
        int sum = 0;
        int count = 0;
        for (int j = i - size + 1; j <= i; j++) {
            if (j >= 0 && j < len) {
                sum += arr[j];
                count++;
            }
        }
        temp[i] = sum / count;
    }
    for (int i = 0; i < len; i++) {
        arr[i] = temp[i];
    }
}