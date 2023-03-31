#include <stdio.h>
#include <stdlib.h>

void output(char s[]) {
    for(int i = 0; s[i] != '\0'; ++i) {
        printf("%c", s[i]);
    }
    printf("\n");
}

void insert_string(char *string) {
    char input;  // Переменная для считывания посимвольно
    for (int i = 0; (input = getchar()) != '\n'; ++i) {
        string = (char *) realloc(string, sizeof(char) * (i + 1));
        string[i] = input;
        string[i + 1] = '\0';
    }
}

void delete_s2_from_s1(int buffer, int length_s2, char *s1, int j) {
    // передвигаем на места символов s2 в s1 следующие за ними значения
    for (int l = 0; l < length_s2; ++l) {
        s1[j] = s1[j+length_s2];
        --j;
    }
    // передвигаем оставшиеся символы
    for (int i = buffer; s1[i] != '\0'; ++i) {
        s1[i] = s1[i+length_s2];
    }
}

int task2() {
    char *s1, *s2;
    s1 = (char *) malloc(sizeof(char) * 1);
    s2 = (char *) malloc(sizeof(char) * 1);
    puts("Input s1.");
    insert_string(s1);
    puts("Input s2.");
    insert_string(s2);
    int length_s2;

    // узнаем длину
    for(int i = 0; s2[i] != '\0'; ++i)
        length_s2 = i + 1;

    int k = 0;
    int buffer;
    for(int j = 0; s1[j] != '\0'; ++j) {
        // перебираем строку s1
        if (s1[j] != s2[k]) {
            continue;
        }
        ++k;
        if (k == length_s2) {
            buffer = j;
            delete_s2_from_s1(buffer, length_s2, s1, j);
            k = 0;
        }
    }

    puts("Changed s1.");
    output(s1);
    puts("s2.");
    output(s2);

    return 0;
}