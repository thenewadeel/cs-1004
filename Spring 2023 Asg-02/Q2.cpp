#include <iostream>
using namespace std;

class String {
  char *data;
  // there is need of more data members, think about them...
  // provide definitions of following functions...
public:
  // default constructor
  String() { cout << "Calling default constructor with args" << endl; }
  // constructor9 String(char *str){cout<<"Calling Fn with args"<<endl;}
  String(char *str) { cout << "Calling constructor9 with args" << endl; }
  // initializes the string with constant cstring
  // copy constructor to initialize the string from existing string
  String(const String &) {
    cout << "Calling  copy constructor with args" << endl;
  }
  // initializes a string of pre-defined size
  String(int x) { cout << "Calling pre-defined size Fn with args" << endl; }
  // returns the character at index [x] in a string
  char getChar(int i) { cout << "Calling getChar with args" << endl; }
  // returns true if string is empty..
  bool isEmpty() { cout << "Calling isEmpty with args" << endl; }
  // Copy one string to another ...
  String &copy_String(const String &) {
    cout << "Calling copy_String with args" << endl;
  }
  // appends a String at the end of the String
  String append_string(const String &str) const {
    cout << "Calling append_string with args" << endl;
  }
  // appends a char at the end of the String
  String append_string(const char &str) const {
    cout << "Calling append_string 2 Fn with args" << endl;
  }
  // appends a String at the end of the String
  String append_string(char *&str) const {
    cout << "Calling append_string 3 Fn with args" << endl;
  }
  // appends a String at the end of the String
  String append_string(string &str) const {
    cout << "Calling append_string 4 Fn with args" << endl;
  }
  // removes the substr from the String
  String remove_string(const String &substr) const {
    cout << "Calling remove_string Fn with args" << endl;
  }
  // removes the substr from the String
  String remove_string(const string &substr) const {
    cout << "Calling remove_string 1 Fn with args" << endl;
  }
  // copies one String to another
  String &assign_string(const String &) {
    cout << "Calling assign_string Fn with args" << endl;
  }
  // copies one c-string to another
  String &assign_string(char *) {
    cout << "Calling assign_string 1 Fn with args" << endl;
  }
  // copies one string to another
  String &assign_string(const string &) {
    cout << "Calling assign_string 2 Fn with args" << endl;
  }
  // returns true if two strings are equal
  bool isEqual(const String &) const {
    cout << "Calling isEqual Fn with args" << endl;
  }
  // returns true if two Strings are equal
  bool isEqual(const string &) const {
    cout << "Calling isEqual 1 Fn with args" << endl;
  }
  // returns true if two strings are equal
  bool isEqual(char *) const {
    cout << "Calling isEqual 2 Fn with args" << endl;
  }
  // returns the index of the character being searched
  int index_At(char) const { cout << "Calling index_At Fn with args" << endl; }
  // returns the start index of the String being searched
  int index_At(const String &) const {
    cout << "Calling index_At 1 Fn with args" << endl;
  }
  // returns the start index of the string being searched
  int index_At(const string &) const {
    cout << "Calling index_At 2 Fn with args" << endl;
  }
  // returns the start index of the c-string being searched
  int index_At(char *) const {
    cout << "Calling index_At 3 Fn with args" << endl;
  }
  // multiples the string by i times and return the string.
  String mul_String(int i) { cout << "Calling mul_String with args" << endl; }
  // returns the length of string
  int length() { cout << "Calling Length Fn with args" << endl; }
  // destructor...
  ~String() { cout << "Calling Destructor with args" << endl; }
}