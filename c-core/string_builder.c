/*
 * String Builder in C99
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* str;
    size_t len;
    size_t cap;
} StringBuilder;

StringBuilder sb_create(void) {
    StringBuilder sb;
    sb.cap = 32;
    sb.len = 0;
    sb.str = (char*)malloc(sb.cap);
    sb.str[0] = '\0';
    return sb;
}

void sb_append(StringBuilder* sb, const char* text) {
    size_t added = strlen(text);
    while (sb->len + added + 1 > sb->cap) {
        sb->cap *= 2;
        sb->str = (char*)realloc(sb->str, sb->cap);
    }
    memcpy(sb->str + sb->len, text, added + 1);
    sb->len += added;
}
