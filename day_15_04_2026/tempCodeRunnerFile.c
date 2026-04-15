#include <stdio.h>
#include <string.h>

struct Books {
    char title[100]; // Increased size to accommodate longer book titles (max 99 chars + null terminator)
    char author[40];
    char theme[100]; // Increased size to accommodate longer themes (max 99 chars + null terminator)
    int id_book;
} ;

void printBookDetails(struct Books book) {
    printf("ID: %d\n", book.id_book);
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Theme: %s\n", book.theme);
}

int main() {
    struct Books book1;
    struct Books book2;

    // Assigning values to book1
    strcpy(book1.title, "The Great Gatsby");
    strcpy(book1.author, "F. Scott Fitzgerald");
    strcpy(book1.theme, "Classic Literature");
    book1.id_book = 1;

    // Assigning values to book2
    strcpy(book2.title, "To Kill a Mockingbird");
    strcpy(book2.author, "Harper Lee");
    strcpy(book2.theme, "Classic Literature");
    book2.id_book = 2;

    // Printing book details
    printBookDetails(book1);
    printf("\n"); // Adding a newline for better readability
    printBookDetails(book2);

    return 0;
}