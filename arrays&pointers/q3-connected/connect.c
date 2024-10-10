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
#include "connect.h"
#include "cs136-trace.h"

const char NONE = '_';
const char RED = 'R';
const char YELLOW = 'Y';

// The number of pieces that have to be in a straight line (horizontal of
//   vertical) in order to win the game.
static const int WINLENGTH = 4;

// The width / number of columns of the Connect Four board.
static const int WIDTH = 7;

// The height / number of rows of the Connect Four board.
static const int HEIGHT = 6;

// get_char(board, c, r) returns the player who's piece is in column c and
//   row r.
// requires: c must be between 0 (inclusive) and WIDTH (exclusive)
//           r must be between 0 (inclusive) and HIGHT (exclusive)
static char get_char(const char *board, int c, int r) {
    assert(board);
    assert(c >= 0 && c < WIDTH);
    assert(r >= 0 && r < HEIGHT);
    return board[c + WIDTH * r];
}

// See connect.h for documentation.
struct connect connect_init() {
    struct connect my_game;
    
    for (int i = 0; i < WIDTH * HEIGHT; ++i) {
        my_game.board[i] = NONE;
    }

    my_game.current_player = RED;
    return my_game;
}

// See connect.h for documentation.
bool connect_drop_piece(struct connect *cf, int col) {
    assert(cf);
    assert(col >= 0 && col < WIDTH);
    for (int r = HEIGHT - 1; r >= 0; --r) {
        if (get_char(cf->board, col, r) == NONE) {
            cf->board[col + WIDTH * r] = cf->current_player;
            if (cf->current_player == RED) {
                cf->current_player = YELLOW;
            } else {
                cf->current_player = RED;
            }
            return true;
        }
    }
    return false;
}

// See connect.h for documentation.
char connect_has_won(const struct connect *cf) {
    assert(cf);
    const char *board = cf->board;
    
    // Check horizontal lines
    for (int r = 0; r < HEIGHT; ++r) {
        for (int c = 0; c <= WIDTH - WINLENGTH; ++c) {
            char curr = get_char(board, c, r);
            if (curr == NONE) {
                continue;
            }
            int count = 1;
            for (int i = 1; i < WINLENGTH; ++i) {
                if (get_char(board, c + i, r) != curr) {
                    break;
                }
                count++;
            }
            if (count == WINLENGTH) {
                return curr;
            }
        }
    }
    
    // Check vertical lines
    for (int c = 0; c < WIDTH; ++c) {
        for (int r = 0; r <= HEIGHT - WINLENGTH; ++r) {
            char curr = get_char(board, c, r);
            if (curr == NONE) {
                continue;
            }
            int count = 1;
            for (int i = 1; i < WINLENGTH; ++i) {
                if (get_char(board, c, r + i) != curr) {
                    break;
                }
                count++;
            }
            if (count == WINLENGTH) {
                return curr;
            }
        }
    }
    
    // Check diagonal lines (top-left to bottom-right)
    for (int r = 0; r <= HEIGHT - WINLENGTH; ++r) {
        for (int c = 0; c <= WIDTH - WINLENGTH; ++c) {
            char curr = get_char(board, c, r);
            if (curr == NONE) {
                continue;
            }
            int count = 1;
            for (int i = 1; i < WINLENGTH; ++i) {
                if (get_char(board, c + i, r + i) != curr) {
                    break;
                }
                count++;
            }
            if (count == WINLENGTH) {
                return curr;
            }
        }
    }
    
    // Check diagonal lines (top-right to bottom-left)
    for (int r = 0; r <= HEIGHT - WINLENGTH; ++r) {
        for (int c = WINLENGTH - 1; c < WIDTH; ++c) {
            char curr = get_char(board, c, r);
            if (curr == NONE) {
                continue;
            }
            int count = 1;
            for (int i = 1; i < WINLENGTH; ++i) {
                if (get_char(board, c - i, r + i) != curr) {
                    break;
                }
                count++;
            }
            if (count == WINLENGTH) {
                return curr;
            }
        }
    }
    return NONE;
}

// See connect.h for documentation.
bool connect_has_finished(const struct connect *cf) {
    assert(cf);
    if (connect_has_won(cf) != NONE)
        return true;
    for (int i = 0; i < WIDTH * HEIGHT; ++i) {
        if (cf->board[i] == NONE)
            return false;
    }
    return true;
}

// See connect.h for documentation.
void connect_print(struct connect *cf) {
    assert(cf);
    for (int r = 0; r < HEIGHT; ++r) {
        printf("|");
        for (int c = 0; c < WIDTH; ++c) {
            printf(" %c |", get_char(cf->board, c, r));
        }
        printf("\n");
    }
    printf("%c", cf->current_player);
    for (int w = 0; w < 4 * WIDTH - 1; ++w) {
        printf("-");
    }
    printf("%c\n\n", cf->current_player);
}