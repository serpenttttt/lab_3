/*
 * Пользователь вводит в консоли 2 строки: s1 и s2.
Напишите программу, удаляющую из строки s1 все символы,
которые содержит строка s2. Удаление символов оформить в виде функции.

Пример:

abcdef

c   de
abf
 *
 */
#include <stdio.h>

void output(char s[]) {
    for(int i = 0; s[i] != '\0'; ++i) {
        printf("%c", s[i]);
    }
    printf("\n");
}

void delete_symbol(char symbol, char string[]) {
    for(int i = 0; string[i] != '\0'; ++i) {
        if (string[i] == symbol) {
            for(int j = i; string[j] != '\0'; ++j) {
                string[j] = string[j + 1];
            }
            i = i - 1;
        }
    }
}

int task2() {
    char s1[100], s2[100];
    char input;
    int i = 0;
    puts("Input s1.");
    while ((input = getchar()) != '\n' && i < 100) { // ввод s1
        s1[i++] = input;
        s1[i] = '\0';
    }
    i = 0;
    puts("Input  s2.");
    while ((input = getchar()) != '\n') { // ввод s2
        s2[i++] = input;
        s2[i] = '\0';
    }
    for (i = 0; s2[i] != '\0'; ++i) {
        for (int j = 0; s1[j] != '\0'; ++j) {
            if (s1[j] == s2[i]) {
                delete_symbol(s2[i], s1);
            }
        }
    }
    puts("Changed s1.");
    output(s1);
    puts("s2.");
    output(s2);
    return 0;
}