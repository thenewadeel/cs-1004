#include "Book.h"

Book::Book() { cout << "\nBook def constructor called."; }
Book::Book(int numberOfPages) {
  cout << "\nBook constructor 1 called pagesNumber:" << numberOfPages;
  //   pages = new Page[numberOfPages];
  pageIndex = 0;
}
Book Book::operator+=(const Page &pg) {
  cout << "\nBook += op called:";
  debugOut(1);
}
Page &Book::operator[](const int pageNumber) {}
void Book::debugOut(int clean) const {
  cout << "\n__________Book_________________" << endl;
  cout << "Book Meta:";
  cout << "Number of Pages:" << pageIndex;
  cout << "\tMax Pages:" << maxPages;
  //   Page *pages;
}
ostream &operator<<(ostream &input, const Book &){};
istream &operator>>(istream &ouput, Book &){};