// Book.h
#ifndef BOOK
#define BOOK
#include "Page.cpp"
#include <iostream>
using namespace std;

class Book {
private:
  int maxPages = 100;
  int pageIndex = 0;
  Page *pages;
  //   int b, a;

public:
  Book();
  Book(int numberOfPages);
  Book operator+=(const Book &rhs);
  Book operator+=(const Page &rhs);
  //   Book operator+=(const Line &rhs);
  Page &operator[](int pageNumber);
  friend ostream &operator<<(ostream &input, const Book &);
  friend istream &operator>>(istream &ouput, Book &);
  void debugOut(int clean = 0) const;
};

#endif