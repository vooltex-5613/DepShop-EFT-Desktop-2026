#include <stdio.h>
#include <string.h>

typedef struct {
    char title[60];
    char author[50];
    int year;
    double rating;
} Book;

void printBook(const Book *book) {
    printf("%-25s | %-18s | %d | %.1f\n",
           book->title,
           book->author,
           book->year,
           book->rating);
}

int main() {
    Book books[] = {
        {"The Silent Ocean", "James Carter", 2021, 8.7},
        {"Digital Dreams", "Emily Stone", 2023, 9.1},
        {"Beyond Tomorrow", "Daniel Brooks", 2020, 8.5},
        {"The Last Journey", "Michael Reed", 2024, 9.3}
    };

    int count = sizeof(books) / sizeof(books[0]);
    double total_rating = 0.0;
    int best_index = 0;

    printf("Book Collection\n");
    printf("===============\n");

    for (int i = 0; i < count; i++) {
        printBook(&books[i]);
        total_rating += books[i].rating;

        if (books[i].rating > books[best_index].rating) {
            best_index = i;
        }
    }

    printf("===============\n");
    printf("Books: %d\n", count);
    printf("Average Rating: %.2f\n", total_rating / count);
    printf("Top Book: %s\n", books[best_index].title);
    printf("Top Rating: %.1f\n", books[best_index].rating);

    return 0;
}