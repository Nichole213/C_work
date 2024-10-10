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
#include "sequence.h"
#include "cs136-trace.h"

// The maximum number of values that can be stored in a sequence.
static const int SEQUENCE_MAX_LENGTH = 100;

struct sequence seq_init(void) {
    struct sequence seq;
    seq.length = 0;
    return seq;
}

// See sequence.h for documentation.
int sequence_length(const struct sequence *seq){
	assert(seq);
    return seq->length;
}

// See sequence.h for documentation.
char sequence_item_at(const struct sequence *seq, int pos){
	assert(seq);
    assert(pos >= 0 && pos < seq->length);
    return seq->data[pos];
}

// See sequence.h for documentation.
bool sequence_insert_at(struct sequence *seq, int pos, char value){
	assert(seq);
    assert(pos >= 0 && pos <= seq->length);
	if (seq->length >= SEQUENCE_MAX_LENGTH) {
        return false;
    }
    for (int i = seq->length; i > pos; --i) {
        seq->data[i] = seq->data[i - 1];
    }
    seq->data[pos] = value;
    seq->length++;
    return true;
}

// See sequence.h for documentation.
char sequence_remove_at(struct sequence *seq, int pos){
	assert(seq);
    assert(pos >= 0 && pos < seq->length);
    char removed = seq->data[pos];
    for (int i = pos; i < seq->length - 1; ++i) {
        seq->data[i] = seq->data[i + 1];
    }
    seq->length--;
    return removed;
}

// See sequence.h for documentation.
void sequence_print(const struct sequence *seq){
	assert(seq);
	if (seq->length == 0) {
		printf("[empty]\n");
	} else {
		printf("[%d]:", seq->length);
		for (const char *p = seq->data; p < seq->data + seq->length; ++p) {
			printf("%c", *p);
		}
		printf("\n");
	}
}
