#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
    int len;            /* current chunk length */
    int total_len;      /* total length of current line */
    int max;            /* maximum length seen so far */

    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;

    // This is the loop for each line
    while ((len = getline(line, MAXLINE)) > 0) {   // loads new line into line
        int current_len = len;
        total_len = len;
        
        // Check if this line continues beyond MAXLINE
        while (len == MAXLINE - 1 && line[len - 1] != '\n') {
            while ((len = getline(line, MAXLINE)) > 0) {
                total_len += len;
                if (len < MAXLINE - 1 || line[len - 1] == '\n')
                    break;
            }
        }

        if (total_len > max) {
            max = total_len;
            copy(longest, line); // Save as much of the line as we can
        }
    }


    if (max > 0) /* there was a line */
        printf("%i", max);
        printf("%s", longest);
    return 0;

}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}