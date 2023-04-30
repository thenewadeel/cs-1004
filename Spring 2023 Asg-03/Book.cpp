#include "Book.h"

Book::Book() { cout << "\nBook def constructor called."; }
Book::Book(int numberOfPages) {
  cout << "\nBook constructor 1 called pagesNumber:" << numberOfPages;
  pages = new Page(numberOfPages);
  pageIndex = 0;
}
Book Book::operator+=(const Page &pg) {
  cout << "\nBook += op called:";
  debugOut(1);
}
Book Book::operator+=(const Line &line) {
  cout << "\nBook += line op called:";
  debugOut(1);
}
Page &Book::operator[](const int pageNumber) {
  // return pages[0];
  // pages[pageNumber];
}
void Book::debugOut(int clean) const {
  cout << "\n__________Book_________________" << endl;
  cout << "Book Meta:";
  cout << "Number of Pages:" << pageIndex;
  cout << "\tMax Pages:" << maxPages;
  //   Page *pages;
}
ostream &operator<<(ostream &out, const Book &) {
  out << "PPPPPPPP";
  return out;
};
istream &operator>>(istream &ouput, Book &){};