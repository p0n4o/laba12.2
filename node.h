typedef struct Node {  // объявляем структуру
    char word[50];
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(char* word) {  // функция для создания нового узла списка
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

typedef enum { false, true } bool; // объявляем новый тип "bool" для более удобной реализации функции

bool is_word(char *stroke) {  // проверка на то, что строка - целое положительное число
    for (int i = 0; i != strlen(stroke) - 1; i++) {
        if ((int)stroke[i] >= 97 && (int)stroke[i] <= 122 || (int)stroke[i] >= 65 && (int)stroke[i] <= 90) {
        }
        else return false;
    }
    return true;
}