#include <iostream>
using namespace std;

class String {
  char *data;
  // there is need of more data members, think about them...
  // provide definitions of following functions...
public:
  // default constructor
  String();
  // constructor9 String(char *str);
  String(char *str);
  // initializes the string with constant cstring
  // copy constructor to initialize the string from existing string
  String(const String &);
  // initializes a string of pre-defined size
  String(int x);
  // returns the character at index [x] in a string
  char getChar(int i);
  // returns true if string is empty..
  bool isEmpty();
  // Copy one string to another ...
  String &copy_String(const String &);
  // appends a String at the end of the String
  String append_string(const String &str) const;
  // appends a char at the end of the String
  String append_string(const char &str) const;
  // appends a String at the end of the String
  String append_string(char *&str) const;
  // appends a String at the end of the String
  String append_string(string &str) const;
  // removes the substr from the String
  String remove_string(const String &substr) const;
  // removes the substr from the String
  String remove_string(const string &substr) const;
  // copies one String to another
  String &assign_string(const String &);
  // copies one c-string to another
  String &assign_string(char *);
  // copies one string to another
  String &assign_string(const string &);
  // returns true if two strings are equal
  bool isEqual(const String &) const;
  // returns true if two Strings are equal
  bool isEqual(const string &) const;
  // returns true if two strings are equal
  bool isEqual(char *) const;
  // returns the index of the character being searched
  int index_At(char) const;
  // returns the start index of the String being searched
  int index_At(const String &) const;
  // returns the start index of the string being searched
  int index_At(const string &) const;
  // returns the start index of the c-string being searched
  int index_At(char *) const;
  // multiples the string by i times and return the string.
  String mul_String(int i);
  // returns the length of string
  int length();
  // destructor...
  ~String();
};