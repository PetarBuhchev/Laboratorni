#include <stdio.h>

int main(void) {
    char name[] = "Petar Buhchev";

    printf("%c", *name);
    printf("%c", *(name + 1));
    printf("%c", *(name + 7));
    
    char *namePtr; // Деклариране на указател към char
    namePtr = name; // namePtr е указател към първия елемент на масива name
    printf("%c", *namePtr); // Достъп до първия елемент на масива чрез указателя
    printf("%c", *(namePtr + 1)); // Достъп до втория елемент на масива чрез указателя
    printf("%c", *(namePtr + 7)); // Достъп до осмия елемент на масива чрез указателя
    return 0;
}