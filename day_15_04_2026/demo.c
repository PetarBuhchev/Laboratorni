struct Books {
    char title[40];
    char author[20];
    char theme[30];
    int book_id;
} ;

int main() {
    struct Books book1;
    struct Books book2;

    // Assigning values to book1
    strcpy(book1.title, "The Great Gatsby");
    strcpy(book1.author, "F. Scott Fitzgerald");
    strcpy(book1.theme, "Classic Literature");
    book1.book_id = 1;

    // Assigning values to book2
    strcpy(book2.title, "To Kill a Mockingbird");
    strcpy(book2.author, "Harper Lee");
    strcpy(book2.theme, "Classic Literature");
    book2.book_id = 2;

    // Printing book details
    printf("Book 1:\nTitle: %s\nAuthor: %s\nTheme: %s\nBook ID: %d\n\n",
           book1.title, book1.author, book1.theme, book1.book_id);

    printf("Book 2:\nTitle: %s\nAuthor: %s\nTheme: %s\nBook ID: %d\n",
           book2.title, book2.author, book2.theme, book2.book_id);

    return 0;
}