#include <iostream>
using namespace std;

struct book {
    int pages;
    unsigned int pub_date;
    string title;
    unsigned int num_authors;
    string * authors;
};

void print_book_info(book* bk) {
    cout << "Book Title is: " << bk->title << endl;
    cout << "It has " << bk->pages << " and was published in " << bk->pub_date << endl;
}

int main() {
    book bk1;
    bk1.title = "Harry Potter";
    bk1.pages = 336;
    bk1.pub_date = 1997;
    bk1.num_authors = 1;
    string* str_ptr = new string;
    *str_ptr = "JK Rowling";
    bk1.authors = str_ptr;

    print_book_info(&bk1);


    // clean up memory 
    delete str_ptr;

    return 0;  
}