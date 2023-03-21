// test ----a-zx-a-j0-1-7-8-9-1----
#include <stdio.h>
#include <malloc.h>

int task1() {
    char *string1; // указатель на динамический массив
    char string2[100];
    int amount = 0;
    char input;  // переменная для считывания посимвольно
    char lower_value = 0, upper_value = 0; // переменные "от", "до"

    puts("Input length of the statement.");
    if (scanf("%d", &amount)) {
        string1 = (char *) malloc((amount + 1) * sizeof(char)); // выделение памяти
        puts("Input string.");
        int i = 0;
        getchar();
        while ((input = getchar()) != '\n') { // ввод s1
            string1[i] = input;
            i = i + 1;
        }
        string1[i] = '\0';

        int count = 0; // отвечает за количество элементов, которые необходимы для развертывания
        int k = 0; // счетчик
        for (int j = 0; string1[j] != '\0'; ++j) {
            if (string1[j] != '-') {                                                             // -a-b-; -f-hg-x
                lower_value = upper_value;
                upper_value = string1[j];
                count += 1;
            }
            if (count == 2) { // Если есть 2 элемента, то в string2[k] записываются значения
                if (lower_value < upper_value) {
                    for (char m = lower_value; m <= upper_value; ++m) {
                        string2[k] = m;
                        ++k;
                        string2[k] = '\0';
                    }
                    count = 0;
                } else {
                    for (char m = lower_value; m >= upper_value; --m) {
                        string2[k] = m;
                        ++k;
                        string2[k] = '\0';
                    }
                    count = 0;
                }
                if (string1[j + 1] == '-') {
                    j -= 1;
                    k -= 1; // чтобы лишний раз C не выводить (-a-c-f- -> abcCdef)
                    string2[k + 1] = '\0';
                }

            }
        }
        printf("%s", string2);
        free(string1);
    } else {
        puts("Error, rerun the program and check values, which you fill in");
    }
    return 0;
}