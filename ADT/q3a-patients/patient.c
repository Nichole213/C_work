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
#include "patient.h"
#include "cs136-trace.h"

// Hint: think about how the existance of MAX_NAME_LEN affects runtime behaviour
const int MAX_NAME_LEN = 30;

struct patient {
    int priority;
    char *name;
};

struct patient *patient_read(void) {
    struct patient *p = malloc(sizeof(struct patient));
    p->name = malloc(MAX_NAME_LEN + 1); 
    assert(p->name);
    scanf("%d %s", &(p->priority), p->name);
    return p;
}

struct patient *patient_clone(const struct patient *p) {
    assert(p);
    struct patient *clone = malloc(sizeof(struct patient));
    clone->priority = p->priority;
    clone->name = malloc(MAX_NAME_LEN + 1); 
    assert(clone->name);
    strncpy(clone->name, p->name, MAX_NAME_LEN);
    clone->name[MAX_NAME_LEN] = '\0'; 
    return clone;
}

void patient_destroy(struct patient *p) {
    assert(p);
    free(p->name);
    free(p);
}

void patient_print(const struct patient *p) {
    assert(p);
    printf("(%d) %s\n", p->priority, p->name);
}