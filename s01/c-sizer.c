#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

/// spec_size(spec)
///    Return the size of the C struct specified by `spec`, as compiled on
///    an x86-64 machine. `spec` is a string of characters where each character
///    corresponds to a struct member of some fundamental type:
///
///         `c`    char (or signed char, unsigned char)
///         `s`    short (or unsigned short)
///         `i`    int (or unsigned int)
///         `l`    long (or unsigned long)
///         `z`    size_t
///         `f`    float
///         `d`    double
///         `p`    pointer
///
///    If a character is followed by a number, that represents an array. For
///    instance, `c20i10` represents an array of 20 chars followed by an
///    array of 10 ints.
///
///    Thus, `spec_size("c")` should return 1, since `sizeof(char) == 1`.
///    `spec_size("cic")` should return 12, since
///    `sizeof(struct { char a; int b; char c; }) == 12`.
///
///    The function may return 0 if `spec` is invalid (or it may crash, or
///    do anything else).
///
///    ADVANCED FEATURES! Implement one or more of these if you have time.
///    (1) Support nested structs: `"{ci}"` is a nested struct containing
///        a char and an int. Note that `spec_size("cci")` should differ
///        from `spec_size("c{ci}")`; why?
///    (2) Support arrays of nested structs: `"{ci}20"` is an array of 20
///        `{ci}`s.
///    (3) Support unions: `"<ci>"` is a union of a char and an int;
///        `spec_size("<ci>")` should equal 4.
///
///    You should implement this function using computer arithmetic and your
///    knowledge of C data representation. You can test your knowledge using
///    the C compiler. However, it is also instructive to *implement* this
///    function using the C compiler. The function could generate a C
///    file that prints the size of the specified struct, then compile that
///    file, run the resulting executable, and parse and return the result!
///    Try `man system` and `man popen`.

size_t spec_size(const char* spec) {
    (void) spec;
    // YOUR CODE HERE
    return 0;
}


/// spec_print(spec, ptr)
///    Print the contents of the memory located at `ptr`, as interpreted
///    by `spec`. (See `spec_size` for the definition of `spec`.)
///    For example:
///
///        int i = 10;
///        spec_print("i", &i);
///
///    might print something like
///
///        7fffffabc int 10
///
///    (assuming `i` is located at address 0x7fffffabc), and
///
///        struct { char c; int d; } x = { 'A', 24 };
///        spec_print("ci", &x);
///
///    might print something like
///
///        7ffffffabc char A
///        7ffffffac0 int 24
///
///    You'll need to add your own tests of `spec_print`.

void spec_print(const char* spec, const void* data) {
    (void) spec, (void) data;
    // YOUR CODE HERE
}


int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i)
        printf("%8zu %s\n", spec_size(argv[i]), argv[i]);
}
