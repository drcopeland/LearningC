#include <stdio.h>

/* copy input to output */

void main() {
    word_length_histogram();
}

void copy_input() {
    int c;

    while ((c = getchar()) != EOF)
        putchar(c);

}

void count_chars() {
    double nc; // or long int

    nc = 0;
    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}

/* count lines in input */
void count_lines() {
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++nl;
    }
    printf("%d\n", nl);
}

void count_blanks() {
    int c, nb;

    nb = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++nb;
    }
    printf("%d\n", nb);
}
/* Ex. 1-8: Write a program to copy its input to its output, replacing
each string of one or more blanks by a single blank. */
void reduce_blanks () {
    int c;
    short is_blank = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (is_blank == 0)
                putchar(c);
        
            is_blank = 1;
        }
        else {
            is_blank = 0;
        }
    }
}

/* Ex. 1-10: Write a program to copy its input to its output, replacing
each tab by \t, each backspace by \b, and each backslash by \\. */
void replace_tbslash() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        }

        else if (c == '\b') {
            putchar('\\');
            putchar('b');
        }

        else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        }

        else
            putchar(c);
    }


}

/* Section 1.5.4: Word Counting */

#define IN 1 // inside a word
#define OUT 0 // outside a word

/* count lines, words, and characters in input */

count_lwc()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}

/* Ex. 1-12: Write a program that prints its input one ward per line. */
one_word_per_line() {
    int c, state;

    state = OUT;
    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN)
                putchar('\n');
            state = OUT;
        }
        else
            putchar(c);
            state = IN;
                
    }
}

/* Sec. 1.6: Arrays */

count_dwo() {
    /* count digits, white space, others */
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }
    printf("diigts =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", whitespace = %d, other = %d\n", nwhite, nother);
}

/* Ex. 1-13: Write a program to print a histogram of the lengths of 
words in its input. */
#define MAX_WORD_LENGTH 10 // Any word of greater length will go into the same bin

word_length_histogram() {    
    int wordlengths[MAX_WORD_LENGTH + 1];
    int c;
    int state, length, i, j, max_length;

    state = OUT;
    length = max_length = 0;

    for (i = 1; i < MAX_WORD_LENGTH + 1; i++)
        wordlengths[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) { // if we just ended a word
                ++wordlengths[length];
                if (wordlengths[length] > max_length) // keep track of biggest count so far
                    max_length = wordlengths[length];
                length = 0; // reset length
            }
            state = OUT;
        }
        else {// if c is a character in a word
            state = IN;
            ++length;
            if (length > MAX_WORD_LENGTH)
                length = MAX_WORD_LENGTH;
        }
    }
    printf("\nHorizontal Histogram of Frequencies: \n \n");
    for (i = 1; i < MAX_WORD_LENGTH; i++) {
        printf("%4d: ", i);
        for (j =0; j < wordlengths[i]; j++)
            printf("*");
        printf("\n");
    }
    printf(">=%2d: ", MAX_WORD_LENGTH);
    for (j =0; j < wordlengths[i]; j++)
        printf("*");
    
    printf("\n\n\n");

    printf("\nVertical Histogram of Word Frequencies: \n\n");
    for (j = 0; j < max_length; j++) {
        for (i = 1; i < MAX_WORD_LENGTH + 1; i++) {
            if (wordlengths[i] < max_length - j)
                printf("  ");
            else
                printf(" *");
        }
        printf("\n");
    }
    for (i = 1; i < MAX_WORD_LENGTH; i++)
        printf("%2d", i);
    printf(" <\n");
}