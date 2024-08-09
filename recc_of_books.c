#include <stdio.h>
#include <string.h>

#define NUM_USER_GENRES 5//number of inputs taken from user
#define NUM_OTHER_BOOKS 30//no. of predefined books that will be considered
#define RECOMMENDATIONS 5//no. of books to reccommend

typedef struct//typedef stores the data type 'Book' which in turn stores 'title' & 'genre'
{
    char title[50];//each book's title will not be more than 49 characters
    char genre[30];//eac book's genre will not be more than 30 characters
} Book;

void print_genre_list()
{
    printf("Available Genres:\n");
    printf("1. Classic\n");
    printf("2. Historical Fiction\n");
    printf("3. Dystopian\n");
    printf("4. Romance\n");
    printf("5. Adventure\n");
    printf("6. Epic\n");
    printf("7. Psychological Fiction\n");
    printf("8. Coming of Age\n");
    printf("9. Gothic\n");
    printf("10. Fantasy\n");
    printf("11. Philosophical Fiction\n");
    printf("12. Realist Fiction\n");
    printf("\nPlease enter your preferred genres from the list above.\n\n");
}

void get_user_genres(char user_genres[NUM_USER_GENRES][30])//gathers input and stores them in 'num_user_genre' array
{
    print_genre_list(); // Print available genres before taking input
    for (int i = 0; i < NUM_USER_GENRES; i++)
    {
        printf("Enter preferred genre %d: ", i + 1);
        fgets(user_genres[i], 30, stdin);//reads the input
        strtok(user_genres[i], "\n"); // Removes newline (\n) character
    }
}

void recommend_books(char user_genres[NUM_USER_GENRES][30], Book other_books[], Book recommendations[])
{
    int scores[NUM_OTHER_BOOKS] = {0};//keeps "score" of how many times a book matches the user's input

    // Compare user genres with the other books' genres
    for (int i = 0; i < NUM_USER_GENRES; i++)//goes through user's input
    {
        for (int j = 0; j < NUM_OTHER_BOOKS; j++)//goes through predefined book genres
        {//compares the input to available data and increases score by 1 if it matches
            if (strcmp(user_genres[i], other_books[j].genre) == 0) 
        {
                scores[j]++;
        }
        }
    }

    // Find top recommendations
    for (int i = 0; i < RECOMMENDATIONS; i++) {
        int max_index = -1;
        for (int j = 0; j < NUM_OTHER_BOOKS; j++) {
            if (scores[j] > 0 && (max_index == -1 || scores[j] > scores[max_index])) {
                max_index = j;
            }
        }
        if (max_index != -1) {
            recommendations[i] = other_books[max_index];
            scores[max_index] = 0; // Set score to 0 to avoid recommending the same book again
        }
    }
}

void print_recommendations(Book recommendations[]) {
    printf("\nRecommended Books for You:\n");
    for (int i = 0; i < RECOMMENDATIONS; i++) {
        printf("%d. %s\n", i + 1, recommendations[i].title);
    }
}

int main() {
    char user_genres[NUM_USER_GENRES][30];
    Book other_books[NUM_OTHER_BOOKS] = {
        {"The Great Gatsby", "Classic"}, {"To Kill a Mockingbird", "Historical Fiction"}, {"1984", "Dystopian"},
        {"Pride and Prejudice", "Romance"}, {"Moby Dick", "Adventure"}, {"War and Peace", "Historical Fiction"},
        {"The Odyssey", "Epic"}, {"Crime and Punishment", "Psychological Fiction"}, {"The Catcher in the Rye", "Coming of Age"},
        {"Brave New World", "Dystopian"}, {"Jane Eyre", "Gothic"}, {"Wuthering Heights", "Gothic"},
        {"Great Expectations", "Classic"}, {"Anna Karenina", "Romance"}, {"The Hobbit", "Fantasy"},
        {"Fahrenheit 451", "Dystopian"}, {"The Lord of the Rings", "Fantasy"}, {"The Scarlet Letter", "Classic"},
        {"The Grapes of Wrath", "Historical Fiction"}, {"Dracula", "Gothic"}, {"Frankenstein", "Gothic"},
        {"The Picture of Dorian Gray", "Philosophical Fiction"}, {"The Brothers Karamazov", "Philosophical Fiction"},
        {"Don Quixote", "Classic"}, {"Les Misérables", "Historical Fiction"}, {"The Iliad", "Epic"},
        {"Madame Bovary", "Realist Fiction"}, {"The Divine Comedy", "Epic"}, {"A Tale of Two Cities", "Historical Fiction"},
        {"Lolita", "Psychological Fiction"}
    };
    Book recommendations[RECOMMENDATIONS];

    get_user_genres(user_genres);
    recommend_books(user_genres, other_books, recommendations);
    print_recommendations(recommendations);

    return 0;
}
