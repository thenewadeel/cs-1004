#include "Book.h"

Book::Book(int numberOfPages) {}
Book Book::operator+=(const Page &pg) {}
Page &Book::operator[](const int pageNumber) {}

ostream &operator<<(ostream &input, const Book &){};
istream &operator>>(istream &ouput, Book &){};