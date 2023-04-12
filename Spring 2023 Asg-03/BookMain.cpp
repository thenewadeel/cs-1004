// Q3. Implementation of a Book (100 Marks)
// You will implement 3 classes namely Line, Page and Book. A book will store a
// certain number of pages and each page will contain a certain number of lines.
// For example a book can have 10 pages with 20 lines per each page. All the
// classes that you will implement must offer the following overloading
// operators
// // ● Copy Constructors,
// Default Constructors,
// Parameterised Constructors and
// Destructors for each of the class Implementation. (10 Marks)
// ● An overloaded += operator that will add to the existing content of a page.
// (40 marks) ○ Adding a text (char array) to a page would first add the text to
// the first Available line and the overflowed text should automatically move to
// the next line. ○ Adding a line (Line object) to a page ○ Adding a page to a
// book. The existing page must be filled first before moving to the next page.
// ○ Note: If adding a word to a line is exceeding the maximum
// characters (40) in a line the whole word should be part of the next
// line.
// ● An overloaded = that will replace the content of a page/line. (10 Marks)
// ● An overloaded [] to access a specific page/line (20 Marks)
// ○ For Example Book[page][line] -> Book[2][1] should give me the second
// line on the 3rd page.
// ● An overloaded + to add 2 specific books. (15 Marks)
// ○ This is not provided in the sample int main() below, however your code
// should be able to concatenate 2 books and assign it to the 3rd book
// without editing the content of the first 2 books.
// ● Overloaded << operator to output the content of the book. (5 Marks)
// Constraint you must follow
// - A line must have a maximum of 40 characters.
// - A page must have a maximum of 20 lines.
// - In case of adding content to a page or a line the overflowed text must be
// written at the next available page/line. Note: Provide 3 header files
// (Page.h, Line.h, and Book.h ) 4 cpp Files (Page.cpp, Line.cpp, Book.cpp, and
// BookMain.cpp). Keep the code generic so your program could be tested during
// demos.

// #include "Line.cpp"

// #include "Page.cpp"

#include "Book.cpp"

#include <iostream>
using namespace std;

int main() { // insert code here...
  cout << "OOOOOOOOOOOOOOOOOOOOO";

  char *str =
      "I think having someone in your life to look up to is one of the most ";
  while (getLength(str) > 0) {
    char *token = tokenPop(str);
    cout << "tok:" << token << endl << "\nStr:" << str << endl;
    str = remove_substring(str, token);
    ;
  }
  Line l1 = Line("popopopop");
  //   l1.debugOut();
  l1 += "xpxpxp";
  //   l1.debugOut();
  Page page(3);
  Page p, p2, p3, p4;
  p.debugOut();
  p += "I think having someone in your life to look up to is one of the most "
       "important things. We all admire people like Linus Torvalds and Bill "
       "Gates but trying to make them your role models can be demotivating. "
       "Bill Gates began coding at age 13 and formed his first venture at age "
       "17.";
  cout << "\n------------------------------\n";
  p.debugOut();
  p2 +=
      "Having a local hero or mentor is more helpful. Because you're both "
      "living in the same community, there's a greater chance there won't be "
      "such a large gap to discourage you. A local mentor probably started "
      "coding around the age you did and was unlikely to start a big venture.";
  p3 += "First, because their stories seemed like fantasy to me, and second, I "
        "couldn't reach them. I chose my mentors and role models to be those "
        "near my reach. Choosing a role model doesn't mean you just want to "
        "get to where they are and stop. Success is step by step.";
  p4 += "You probably can't get one-on-one advice from someone like Bill "
        "Gates. You can get the advice they're giving to the public at "
        "conferences, which is great, too. I always follow smart people.";
  Book b(3);
  b += p2;
  b += p;
  b += p3;
  b[2] += p4;
  b[2][2] = "I am editing this line using subscripts.";
  b[2] += "Adding this text to existing line of page number 3 and overflowed "
          "text must go to next line";
  Line l("Adding a new line to an existing page.");
  Line l2("This is line 2.");
  b[1] += l;
  b[1] += l2;
  b[1] += l;
  cout << b;
  return 0;
}
// Output should be the following of the above main:
// -------------- Page 1--------------
// Having a local hero or mentor is more
// helpful. Because you're both living in
// the same community, there's a greater
// chance there won't be such a large gap
// to discourage you. A local mentor
// probably started coding around the age
// you did and was unlikely to start a big
// Venture. I think having someone in your
// life to look up to is one of the most
// important things. We all admire people
// like Linus Torvalds and Bill Gates but
// trying to make them your role models
// can be demotivating. Bill Gates began
// coding at age 13 and formed his first
// venture at age 17. First, because their
// stories seemed like fantasy to me, and
// second, I couldn't reach them. I chose
// my mentors and role models to be those
// near my reach. Choosing a role model
// doesn't mean you just want to get to
// -------------- Page 2--------------
// where they are and stop. Success is
// step by step. Adding a new line to an
// existing page.This is line 2.Adding a
// new line to an existing page.
// -------------- Page 3--------------
// You probably can't get one-on-one advice
// from someone like Bill Gates. You can
// I am editing this line using subscripts.
// public at conferences, which is great,
// too. I always follow smart people.Adding
// this text to existing line of page
// number 3 and overflowed text must go to
// next line