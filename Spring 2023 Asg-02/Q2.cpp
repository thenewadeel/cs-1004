#include <iostream>
using namespace std;

class String {
  char *data;
  // there is need of more data members, think about them...
  // provide definitions of following functions...
public:
  // default constructor
  String() {
    cout << "Calling default constructor with args:" << endl;
    data = new char[1];
    data[0] = '\0';
  }
  // constructor9 String(char *str){cout<<"Calling Fn with args:"<<endl;}
  String(char *str) {
    cout << "Calling constructor9 with args:" << endl;
    int i = 0, len = length(str);
    if (len < 1)
      String();
    else {
      data = new char[len];
      for (int i = 0; i < len; i++) {
        data[i] = str[i];
      }
    }
  }
  // initializes the string with constant cstring
  // copy constructor to initialize the string from existing string
  String(const String &source) {
    cout << "Calling  copy constructor with args:" << endl;
    String(source.data);
  }
  // initializes a string of pre-defined size
  String(int x) {
    cout << "Calling pre-defined size Fn with args:" << endl;
    if (x > 0) {
      data = new char[x];
      data = fill(data, '*', x);
    }
  }
  // returns the character at index [x] in a string
  char getChar(int i) {
    cout << "Calling getChar with args:" << endl;
    if (i > 0 && i < length())
      return data[i];
  }
  // returns true if string is empty..
  bool isEmpty() {
    cout << "Calling isEmpty with args:" << endl;
    return length() == 0;
  }
  // Copy one string to another ...
  String &copy_String(const String &source) {
    cout << "Calling copy_String with args:" << source.data << endl;
    int len = length(source.data);
    if (len < 1)
      cout << "err: input string invalid";
    else {
      data = new char[len];
      for (int i = 0; i < len; i++) {
        data[i] = source.data[i];
      }
    }
  }
  // appends a String at the end of the String
  String append_string(const String &str) const {
    cout << "Calling append_string with args:" << endl;
  }
  // appends a char at the end of the String
  String append_string(const char &str) const {
    cout << "Calling append_string 2 Fn with args:" << endl;
  }
  // appends a String at the end of the String
  String append_string(char *&str) const {
    cout << "Calling append_string 3 Fn with args:" << endl;
    char *s = str;
    // data = concat(data, s);
  }
  // appends a String at the end of the String
  String append_string(string &str) const {
    cout << "Calling append_string 4 Fn with args:" << endl;
    // char *s = str.data();
    // data = concat(data, s);
  }
  // removes the substr from the String
  String remove_string(const String &substr) const {
    cout << "Calling remove_string Fn with args:" << endl;
  }
  // removes the substr from the String
  String remove_string(const string &substr) const {
    cout << "Calling remove_string 1 Fn with args:" << endl;
  }
  // removes the substr from the String
  String remove_string(const char *substr) const {
    cout << "Calling remove_string 1 Fn with args:" << endl;
  }
  // copies one String to another
  String &assign_string(const String &source) {
    cout << "Calling assign_string Fn with args:" << endl;
    // String(source);
  }
  // copies one c-string to another
  String &assign_string(char *s) {
    cout << "Calling assign_string 1 Fn with args:" << endl;
    // String(s);
  }
  // copies one string to another
  String &assign_string(const string &) {
    cout << "Calling assign_string 2 Fn with args:" << endl;
  }
  // returns true if two strings are equal
  bool isEqual(const String &b) const {
    cout << "Calling isEqual Fn with args:" << endl;
    // if (length() != length(b.data)) {
    return false;
    // } else {
    // cout << "checking strs...";
    // }
  }
  // returns true if two Strings are equal
  bool isEqual(const string &) const {
    cout << "Calling isEqual 1 Fn with args:" << endl;
  }
  // returns true if two strings are equal
  bool isEqual(char *s) const {
    cout << "Calling isEqual 2 Fn with args:" << endl;
    // if (length() != length(s)) {
    //   return false;
    // } else {
    cout << "checking strs...";
    // }
  }
  // returns the index of the character being searched
  int index_at(char c) const {
    cout << "Calling index_at Fn with args:" << endl;
    // for (int i = 0; i < length(); i++) {
    //   if (data[i] == c)
    //     return i;
    // }
    return -1;
  }
  // returns the start index of the String being searched
  int index_at(const String &) const {
    cout << "Calling index_at 1 Fn with args:" << endl;
  }
  // returns the start index of the string being searched
  int index_at(const string &) const {
    cout << "Calling index_at 2 Fn with args:" << endl;
  }
  // returns the start index of the c-string being searched
  int index_at(char *) const {
    cout << "Calling index_at 3 Fn with args:" << endl;
  }
  // multiples the string by i times and return the string.
  String mul_String(int i) { cout << "Calling mul_String with args:" << endl; }
  // returns the length of string
  int length() {
    cout << "Calling Length Fn with args:" << endl;
    return length(data);
  }
  int length(char *str) {
    cout << "Calling Length Fn with args:" << endl;
    // int getLength(char *str) {
    int i = 0;
    if (str) {
      while (str[i++]) {
        if (i > 1000) // upper safety limit
          break;
      }
      return i - 1;
    }
    return 0;
  }
  char *fill(char *tgt, char c, int len = 0) {
    int lengthTgt;
    if (len == 0)
      lengthTgt = length();
    else
      lengthTgt = len;
    char *result = new char[lengthTgt];
    for (int i = 0; i < lengthTgt; i++) {
      result[i] = c;
    }
    return result;
  }
  char *concat(char *a, char *b) {
    int lengthA = length(a);
    int lengthB = length(b);
    char *result = new char[lengthA + lengthB];
    for (int i = 0; i < lengthA; i++) {
      result[i] = a[i];
    }
    for (int i = 0; i < lengthB; i++) {
      result[lengthA + i] = b[i];
    }
    // cout << endl << a << " + " << b << " = " << result;
    return result;
  }
  char *push_left(char *tgt, char *load) {
    int lengthTgt = length();
    int lengthLoad = length();
    // cout << endl << tgt << " < " << load; //<< " = " << result;
    char *result = new char[lengthTgt + lengthLoad];
    return concat(load, tgt);
  }
  char *getdata() {
    cout << "Returning from getdata():" << data << endl;
    return data;
  }
  // destructor...
  ~String() { cout << "Calling Destructor with args:" << endl; }
};