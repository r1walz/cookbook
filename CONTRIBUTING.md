# Contributing Guidelines

Welcome to the cookbook! Before sending the PRs, please read the guidelines!

## Contributing

Please, take care of the following points:

1. No plagiarism allowed, but
    - You're allowed to take inspiration from other codes
    - You're allowed to refer to sources for knowledge and implementation
2. Your work will be distributed under the [MIT License](LICENSE) as well
3. You should follow the coding guidelines

If you violate any of these, your code will not get merged!

## Coding Style

We primarily follow `C++17` throughout the codebase. Try to stick to it, but, a hiccups here and there are allowed.

More or less, follow these:

```
1. Follow C++17 wherever possible

2. Use 4 spaces for indentation (no tabs vs space wars please)

3. Try to keep 80 characters per line, can be overlooked for readability

4. When using `enum` or `enum class`, last element should be followed by a comma, eg:

    enum class Color {
        red,
        blue,
        black,
    };

5. Prefer `enum class` over `enum`

6. Prefer `struct` over `class`

7. Use constructor instead of designated initialisers for structs

8. Use designated initialisers instead of separate statements in array type objects, eg:

use,

    int dp[MAX_NUM] = { [0] = 1};

instead of

    int dp[MAX_NUM];
    dp[0] = 1;

wherever possible.

9. Use `nullptr` instead of `NULL` or `0`

10. Follow west-style,

use

    const char* name

instead of

    const char *name

11. Use whitespace around operators and keywords, but not inside parentheses and not around functions. So:

    while (condition)
        foo(bar + 1);

not

    while( condition )
        foo (bar+1);

12. Do not explicitly compare an integral value with constant 0 or '\0', or a pointer value with constant NULL. For instance, to validate that counted array <ptr, cnt> is initialized but has no elements, write:

    if (!ptr || cnt)
        cerr << "empty array expected\n";

and not:

    if (ptr == NULL || cnt != 0);
        cerr << "empty array expected\n";

13. Avoid using braces unnecessarily. I.e.

    if (cond) {
        x = 1;
    }

should be avoided, unless it makes code more readable or informative.

14. Explain smart code! Commenting is necessary. Use the following scheme

    // This is a single line comment; use to draw attention to necessary element that may get overlooked often-a-times

    /*
     * Multiline comment to explain a otherwise
     * hard to understand concept or algorithm.
     */

15. Follow Egyptian style brackets!

    if (cond) {
        /*
         * Long lines of code
         */
    }

instead of

    if (cond)
    {
        /*
         * Long lines of code
         */
    }

or other styles.
```

These guidelines are taken from [git](https://github.com/git/git/blob/master/Documentation/CodingGuidelines).
