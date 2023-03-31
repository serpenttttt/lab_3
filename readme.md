# Changelog

# Lab 3. 
## Task №1
1. Код разбил на функции. К примеру, код следующего содержания: 
```
   string2 = (char *) realloc(string2, sizeof(char) * (k + 1));
   string2[k] = m;
   ++k;
   string2[k] = '\0'; 
``` 
был вынесен в отдельную функцию:
```
    void input_value_into_expanded_string (int k, char value, char *expanded_string) {
      expanded_string = (char *) realloc(expanded_string, sizeof(char) * (k + 1));
      expanded_string[k] = value;
      expanded_string[k + 1] = '\0';
    }
```
2. Проработал случай, когда есть '-':
```
    > -a-z-a0-9-0-
    -abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihgfedcba0123456789876543210-
```
3. Добавил больше комментариев к работе кода, чтобы отпали сомнения про пасту из интернета

## Task #2
Переделал.

Не совсем понял, почему нужно искать вхождения, ведь в задании говорится, что из строки s1 нужно удалить все символы, которые есть в s2.
```
    Напишите программу, удаляющую из строки s1 все символы, которые содержит строка s2.
```


# Building the Project with CMake

## Cloning the Repository

Before start clone the repository to your local computer

``` git clone https://github.com/serpenttttt/lab_3.git ```

## Building the Project with CMake
1. Navigate to the root directory of the project:
   ```cd lab_3```
2. Create a "build" directory:
   ```mkdir build```
3. Navigate to the "build" directory:
   ```cd build```
4. Generate the project files with CMake:
   ```cmake ..```
5. Build the project:
   ```cmake --build .```
6. It works