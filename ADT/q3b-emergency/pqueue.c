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

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"
#include "patient.h"
#include "cs136-trace.h"

struct pqueue {
    struct patient **patients;
    int front;
    int back;
    int capacity;
};


struct pqueue *pqueue_create() {
    struct pqueue *pq = malloc(sizeof(struct pqueue));
    pq->capacity = 10;
    pq->patients = malloc(pq->capacity * sizeof(struct patient *));
    pq->front = 0;
    pq->back = 0;
    return pq;
}

void pqueue_destroy(struct pqueue *pq) {
    assert(pq);
    while(!pqueue_empty(pq)) {
        struct patient *p = pqueue_dequeue(pq);
        patient_destroy(p);
    }
    free(pq->patients);
    free(pq);
}

void pqueue_enqueue(struct pqueue *pq, struct patient *p) {
    assert(pq);
    assert(p);
    assert((pq->back + 1) % pq->capacity != pq->front);
    pq->patients[pq->back] = patient_clone(p);
    pq->back = (pq->back + 1) % pq->capacity;
    patient_destroy(p);
}

struct patient *pqueue_dequeue(struct pqueue *pq) {
    assert(pq);
    assert(pq->front != pq->back);
    struct patient *p = pq->patients[pq->front];
    pq->front = (pq->front + 1) % pq->capacity;
    return p;
}

struct patient *pqueue_front(const struct pqueue *pq) {
    assert(pq);
    assert(pq->front != pq->back); 
    return patient_clone(pq->patients[pq->front]);
}

bool pqueue_empty(const struct pqueue *pq) {
    assert(pq);
    return pq->front == pq->back;
}

void pqueue_print(const struct pqueue *pq) {
    assert(pq);
    int current = pq->front;
    printf("Patient queue");
    while (current != pq->back) {
        printf(" -> ");
        patient_print(pq->patients[current]);
        current = (current + 1) % pq->capacity;
    }
    printf("\n");
}