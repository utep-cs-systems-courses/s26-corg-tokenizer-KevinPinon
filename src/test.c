// Include your function definitions here or in tokenizer.h
#include <stdio.h>
#include "tokenizer.h"

int space_char(char c);
int non_space_char(char c);

int main() {
    // Test 1: Space characters
    printf("Testing space_char:\n");
    printf("Is ' ' a space? %d (Expected: 1)\n", space_char(' '));
    printf("Is '\\t' a space? %d (Expected: 1)\n", space_char('\t'));
    printf("Is 'A' a space? %d (Expected: 0)\n", space_char('A'));
    printf("Is '\\0' a space? %d (Expected: 0)\n", space_char('\0'));

    printf("\n-------------------\n\n");

    // Test 2: Non-space characters
    printf("Testing non_space_char:\n");
    printf("Is 'A' a non-space? %d (Expected: 1)\n", non_space_char('A'));
    printf("Is '?' a non-space? %d (Expected: 1)\n", non_space_char('?'));
    printf("Is ' ' a non-space? %d (Expected: 0)\n", non_space_char(' '));
    printf("Is '\\0' a non-space? %d (Expected: 0)\n", non_space_char('\0'));

    //Test 3: Toke_start
    char *str = "   Lamo";
    char *start = token_start(str);
    printf("\nOriginal address: %p, Token start address: %p\n", (void*)str, (void*)start);
    printf("The token starts with: %c\n", *start); // Should print 'L'

    //Test 4: Token_terminator
    // Test Case 1: Standard string
    char *str1 = "   Hello World";
    char *start1 = token_start(str1);
    char *term1 = token_terminator(start1);

    printf("Test 1: '   Hello World'\n");
    printf("  Token starts at: '%c'\n", *start1);     // Expected: 'H'
    printf("  Terminator is at: '%c' (space)\n", *term1); // Expected: ' '
    printf("  Word length: %ld\n", term1 - start1);    // Expected: 5

    printf("\n---\n\n");

    // Test Case 2: No leading spaces
    char *str2 = "Computer";
    char *start2 = token_start(str2);
    char *term2 = token_terminator(start2);

    printf("Test 2: 'Computer'\n");
    printf("  Token starts at: '%c'\n", *start2);     // Expected: 'C'
    printf("  Terminator is at: '\\0'\n");            // Expected: end of string
    printf("  Word length: %ld\n", term2 - start2);    // Expected: 8

    printf("\n---\n\n");

    // Test Case 3: Only spaces (Should return NULL)
    char *str3 = "     ";
    char *start3 = token_start(str3);
    
    printf("Test 3: '     ' (Only spaces)\n");
    if (start3 == 0) {
        printf("  Success: token_start returned NULL\n");
    } else {
        printf("  Failure: token_start should be NULL\n");
    }

    //Test 5: count_tokens
    // Test Case 1: Standard sentence
    char *s1 = "Hello world from C";
    printf("Test 1: '%s'\n", s1);
    printf("Expected: 4, Result: %d\n\n", count_tokens(s1));

    // Test Case 2: Excessive whitespace
    char *s2 = "   Multiple   spaces    between words   ";
    printf("Test 2: '%s'\n", s2);
    printf("Expected: 4, Result: %d\n\n", count_tokens(s2));

    // Test Case 3: Tabs and spaces mixed
    char *s3 = "\tTabbed\t  sentence ";
    printf("Test 3: 'Tabbed sentence with tabs'\n");
    printf("Expected: 2, Result: %d\n\n", count_tokens(s3));

    // Test Case 4: Empty or space-only strings
    char *s4 = "     ";
    printf("Test 4: Empty/Space string\n");
    printf("Expected: 0, Result: %d\n\n", count_tokens(s4));

    //Test 6: copy_str
    char *original = "Hello World";
    char *my_copy = copy_str(original, 11); // Should copy "Hello"
    printf("Copy: %s\n", my_copy); // Should print "Hello"
    free(my_copy); // Always free what you malloc!

    //Test 7: Tokenize
    char **result = tokenize("hello world string");
    printf("First word: %s\n", result[0]);  // Should be hello
    printf("Second word: %s\n", result[1]); // Should be world
    printf("Third word: %s\n", result[2]);  // Should be string
    // Don't forget to free later!
 
    return 0;
}
