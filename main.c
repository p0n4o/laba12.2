#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "node.h"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"


void append_node(Node** head, Node* new_node) {  // функция для добавления нового узла в конец списка

    if (*head == NULL) {
        *head = new_node;
    }
    else {
        Node* current = *head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = new_node;
        new_node->prev = current;
    }
}

void split_words(Node* head, Node** vowels, Node** consonants) {  // функция для разделения списка на гласные и согласные слова
    Node* cur = head;

    while (cur != NULL) {
        char first = tolower(cur->word[0]);

        if (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u' || first == 'y') {
            // если слово начинается с гласной буквы
            append_node(vowels, createNode(cur->word));
        }
        else {
            // если слово начинается с согласной буквы
            append_node(consonants, createNode(cur->word));
        }
        cur = cur->next;
    }
}

void print_list(Node* head) {  // функция для вывода списка слов
    Node* cur = head;

    while (cur != NULL) {
        printf(ANSI_COLOR_RESET"%s ", cur->word);
        cur = cur->next;
    }
    printf("\n");
}

void free_list(Node* head) {  // функция для освобождения памяти, выделенной под список
    Node* cur = head;

    while (cur != NULL) {
        Node* temp = cur;
        cur = cur->next;
        free(temp);
    }
}

int main() {
    char input[100];
    Node* words = NULL;
    Node* vowels = NULL;
    Node* consonants = NULL;

    printf("Введите строку: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0'; // удаление символа новой строки из ввода

    char* word = strtok(input, " "); // разделение строки на слова

    while (word != NULL) {
        if (is_word(word) == true){
            append_node(&words, createNode(word));
            word = strtok(NULL, " ");
        }
        else{
            printf(ANSI_COLOR_RED "ERROR: Введен некорректный символ.");
            return 0;
        }
    }

    // разделение списка слов на гласные и согласные
    split_words(words, &vowels, &consonants);

    // вывод исходного списка
    printf("Исходный список: ");
    print_list(words);

    // вывод списка слов, начинающихся с гласных
    printf(ANSI_COLOR_GREEN "Список слов, начинающихся с гласных: ");
    print_list(vowels);

    // вывод списка слов, начинающихся с согласных
    printf(ANSI_COLOR_GREEN "Список слов, начинающихся с согласных: ");
    print_list(consonants);

    // освобождение памяти, выделенной под списки
    free_list(words);
    free_list(vowels);
    free_list(consonants);

    return 0;
}
