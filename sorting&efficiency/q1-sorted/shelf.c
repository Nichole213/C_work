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
#include <stdbool.h>
#include <assert.h>
#include "shelf.h"
#include "box.h"
#include "cs136-trace.h"

// maximum number of boxes that can be stored on the shelf
static const int SHELF_CAPACITY = 10;

// See box.h for documentation.
struct shelf shelf_init(void) {
    struct shelf sh;
    sh.count = 0;
    for (int i = 0; i < SHELF_CAPACITY; i++) {
        sh.pboxes[i] = NULL;
    }
    return sh;
};

// See box.h for documentation.
// This function fails if the shelf capacity has been exceeded.
bool shelf_push(struct shelf *sh, char id, int volume, int weight) {
    assert(sh);
    if (sh->count >= SHELF_CAPACITY) {
        return false;
    }
    struct box new_box = box_init(id, volume, weight);
    sh->boxes[sh->count] = new_box;
    sh->pboxes[sh->count] = &sh->boxes[sh->count];
    sh->count++;
    return true;
}

// See box.h for documentation.
// This function fails if the shelf is empty.
bool shelf_pop(struct shelf *sh, struct box *popped) {
    assert(sh);
    assert(popped);
    if (sh->count == 0) {
        return false;
    }
    sh->count--;
    *popped = *sh->pboxes[sh->count];
    for (int i = 0; i < sh->count; i++) {
        sh->pboxes[i] = &(sh->boxes[i]);
    }
    return true;
}

// See box.h for documentation.
// This function fails if the shelf is empty.
bool shelf_top(const struct shelf *sh, const struct box **top) {
    assert(sh);
    assert(top);
    if (sh->count == 0) {
        return false;
    }
    *top = &(sh->boxes[sh->count - 1]);
    return true;
}

// See box.h for documentation.
void shelf_sort(struct shelf *sh, int(comp)(const struct box *, const struct box *)) {
    for (int i = 0; i < sh->count; i++) {
        for (int j = i + 1; j < sh->count; j++) {
            if (comp(sh->pboxes[i], sh->pboxes[j]) > 0) {
                struct box *temp = sh->pboxes[i];
                sh->pboxes[i] = sh->pboxes[j];
                sh->pboxes[j] = temp;
            }
        }
    }
}

// See box.h for documentation.
void shelf_print(const struct shelf *sh) {
    assert(sh);
    printf("=== SHELF (actual) =========\n");
    for (int i = 0; i < sh->count; ++i) {
        box_print(&(sh->boxes[i]));
    }
    printf("============================\n");
}

// See box.h for documentation.
void shelf_print_refs(const struct shelf *sh) {
    assert(sh);
    printf("=== SHELF (references) =====\n");
    for (int i = 0; i < sh->count; ++i) {
        box_print(sh->pboxes[i]);
    }
    printf("============================\n");
}