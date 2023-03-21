// String.h
#ifndef STRING
#define STRING
#include <iostream>
using namespace std;
class String {
  char *data;
  // there is need of more data members, think about them...
  // provide definitions of following functions...
public:
  // default constructor
  String();
  // constructor9 String(char *str){cout<<"Calling Fn with args:"<<endl;}
  // initializes the string with constant cstring
  String(char *str);
  // copy constructor to initialize the string from existing string
  String(const String &source);
  // initializes a string of pre-defined size
  String(int x);
  // returns the character at index [x] in a string
  char getChar(int i);
  // returns true if string is empty..
  bool isEmpty();
  // Copy one string to another ...
  String &copy_String(const String &source);
  // appends a String at the end of the String
  String append_string(const String &str) const;
  // appends a char at the end of the String
  String append_string(const char &str) const;
  // appends a String at the end of the String
  String append_string_main(char *c) const;
  // appends a String at the end of the String
  String append_string(char *&str) const;
  // appends a String at the end of the String
  String append_string(string &str) const;
  // removes the substr from the String
  String remove_string(char substr) const;
  // removes the substr from the String
  String remove_string(const String &substr) const;
  // removes the substr from the String
  String remove_string(const string &substr) const;
  // main removes the substr from the String
  String remove_string_main(char *str) const;
  // removes the substr from the String
  String remove_string(const char *substr) const;
  // copies one String to another
  String &assign_string(const String &source);
  // copies one c-string to another
  String &assign_string(char *s);
  // copies one string to another
  String &assign_string(const string &s);
  // main str copier
  String assign_string_main(char *str);
  // returns true if two strings are equal
  bool isEqual(const String &b) const;
  // returns true if two Strings are equal
  bool isEqual(const string &) const;
  // returns true if two strings are equal
  bool isEqual(char *s) const;
  // returns the index of the character being searched
  int index_at(char c) const;
  // returns the start index of the String being searched
  int index_at(const String &str) const;
  // returns the start index of the string being searched
  int index_at(const string &str) const;
  // returns the start index of the c-string being searched
  int index_at(char *str) const;
  // multiples the string by i times and return the string.
  String mul_String(int i);
  // returns the length of string
  int length() const;
  int length(char *str) const;
  char *fill(char *tgt, char c, int len = 0);
  char *concat(char *a, char *b) const;
  char *concat(char *a, char *b);
  char *push_left(char *tgt, char *load);
  char *getdata();
  // destructor...
  ~String();
};
#endif