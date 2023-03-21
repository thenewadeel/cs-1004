#include <iostream>
using namespace std;
bool GLOBAL_DEBUG = true;
class String {
  char *data;
  // there is need of more data members, think about them...
  // provide definitions of following functions...
public:
  // default constructor
  String() {
    if (GLOBAL_DEBUG)
      cout << "Calling default constructor with args:" << endl;
    data = new char[1];
    data[0] = '\0';
  }
  // constructor9 String(char *str){cout<<"Calling Fn with args:"<<endl;}
  String(char *str) {
    if (GLOBAL_DEBUG)
      if (GLOBAL_DEBUG)
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
    if (GLOBAL_DEBUG)
      cout << "Calling  copy constructor with args:" << endl;
    // String(source.data);
    int l = length(source.data);
    data = new char[l];
    // cout << "I:";
    for (int i = 0; i < l; i++) {
      data[i] = source.data[i];
    }
  }
  // initializes a string of pre-defined size
  String(int x) {
    if (GLOBAL_DEBUG)
      cout << "Calling pre-defined size Fn with args:" << endl;
    if (x > 0) {
      data = new char[x];
      // data = fill(data, '*', x);
    }
  }
  // returns the character at index [x] in a string
  char getChar(int i) {
    if (GLOBAL_DEBUG)
      cout << "Calling getChar with args:" << endl;
    if (i >= 0 && i < length())
      return data[i];
  }
  // returns true if string is empty..
  bool isEmpty() {
    if (GLOBAL_DEBUG)
      cout << "Calling isEmpty with args:" << endl;
    return length() == 0;
  }
  // Copy one string to another ...
  String &copy_String(const String &source) {
    if (GLOBAL_DEBUG)
      cout << "Calling copy_String with args:" << source.data << endl;
    int len = length(source.data);
    if (len < 1)
      if (GLOBAL_DEBUG)
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
    if (GLOBAL_DEBUG)
      cout << "Calling append_string with args:" << &str << endl;
    append_string_main(str.data);
  }
  // appends a char at the end of the String
  String append_string(const char &str) const {
    if (GLOBAL_DEBUG)
      cout << "Calling append_string 2 Fn with args:" << &str << endl;
    char *t = new char[1];
    t[0] = str;
    append_string_main(t);
  }
  // appends a String at the end of the String
  String append_string_main(char *c) const {
    if (GLOBAL_DEBUG)
      cout << "Calling append_string_main Fn with args:" << c << endl;
    // char *s = str;
    char *d = concat(data, c);
    int l = length(d);
    for (int i = 0; i < l; i++) {
      data[i] = d[i];
    }
  }
  // appends a String at the end of the String
  String append_string(char *&str) const {
    if (GLOBAL_DEBUG)
      cout << "Calling append_string 3 Fn with args:" << endl;
    char *s = str;
    // data = concat(data, s);
  }
  // appends a String at the end of the String
  String append_string(string &str) const {
    if (GLOBAL_DEBUG)
      cout << "Calling append_string 4 Fn with args:" << endl;
    const char *c = str.data();
    char *t = new char[str.length()];
    for (int i = 0; i < str.length(); i++) {
      t[i] = str[i];
    }
    append_string_main(t);
  }
  // removes the substr from the String
  String remove_string(char substr) const {
    if (GLOBAL_DEBUG)
      cout << "Calling remove_string charFn with args:" << substr << endl;
    // int length_tgt = length(substr.data);
    int l = length();
    bool found = false;
    int index = -1;
    for (int i = 0; i < l; i++) {
      if (data[i] == substr) {
        found = true;
        index = i;
        break;
      } else
        continue;
    }
    if (found) {
      char *temp = new char[length() - 1];
      for (int i = 0; i < index; i++) {
        temp[i] = data[i];
      }
      for (int i = index; i < length() - 1; i++) {
        temp[i] = data[i + 1];
      }
      for (int i = 0; i < length(temp); i++)
        data[i] = temp[i];
      data[length() - 1] = '\0';
      // cout << "DATA:" << data;
      // cout << "TEMP:" << temp;
    }

    // char *temp = new char[length_tgt];
    // for (int i = 0; i < length_tgt; i++)
    // temp[i] = substr.data[i];
    // remove_string_main(temp);
  } // removes the substr from the String
  String remove_string(const String &substr) const {
    if (GLOBAL_DEBUG)
      cout << "Calling remove_string Fn with args:" << substr.data
           << ", of length:" << length(substr.data) << endl;
    int length_tgt = length(substr.data);
    int l = length();
    char *temp = new char[length_tgt];
    for (int i = 0; i < length_tgt; i++)
      temp[i] = substr.data[i];
    remove_string_main(temp);
  }
  // removes the substr from the String
  String remove_string(const string &substr) const {
    if (GLOBAL_DEBUG)
      cout << "Calling remove_string 1 Fn with args:" << substr << "OOO"
           << endl;
    int length_tgt = substr.length();
    int l = length();
    char *temp = new char[length_tgt];
    for (int i = 0; i < length_tgt; i++)
      temp[i] = substr[i];
    remove_string_main(temp);
  }
  // main removes the substr from the String
  String remove_string_main(char *str) const {
    if (GLOBAL_DEBUG)
      cout << "Calling remove_string_main Fn with args:" << str
           << ", DATA:" << data << endl;
    int l2 = length() - length(str);
    char *temp = new char[l2];
    int sp = index_at(str);
    if (sp >= 0) {
      for (int i = 0; i < sp; i++) {
        temp[i] = data[i];
      }
      for (int i = sp + length(str); i < length(); i++) {
        temp[i - length(str)] = data[i];
      }
      // char *data = new char[l2];
      int i = 0;
      for (i = 0; i < length(); i++) {
        data[i] = temp[i];
      }
      data[i] = '\0';
      cout << "NEW DATA:" << data;
      // assign_string_main(data);
    }
  }
  // removes the substr from the String
  String remove_string(const char *substr) const {
    if (GLOBAL_DEBUG)
      cout << "Calling remove_string 1x Fn with args:" << substr << endl;
  }
  // copies one String to another
  String &assign_string(const String &source) {
    if (GLOBAL_DEBUG)
      cout << "Calling assign_string Fn with args:" << endl;
    assign_string_main(source.data);
  }
  // copies one c-string to another
  String &assign_string(char *s) {
    if (GLOBAL_DEBUG)
      cout << "Calling assign_string 1 Fn with args:" << endl;
    assign_string_main(s);
  }
  // copies one string to another
  String &assign_string(const string &s) {
    if (GLOBAL_DEBUG)
      cout << "Calling assign_string 2 Fn with args:" << endl;
    int l = s.length();
    char *temp = new char[l];
    for (int i = 0; i < l; i++) {
      temp[i] = s[i];
    }
    assign_string_main(temp);
  }
  // main str copier
  String assign_string_main(char *str) {
    int i = 0;
    int l = length(str);
    data = new char[l];
    for (i = 0; i < l; i++) {
      data[i] = str[i];
    }
    data[i] = '\0';
  }
  // returns true if two strings are equal
  bool isEqual(const String &b) const {
    if (GLOBAL_DEBUG)
      cout << "Calling isEqual Fn with args:" << endl;
    // if (length() != length(b.data)) {
    return false;
    // } else {
    // cout << "checking strs...";
    // }
  }
  // returns true if two Strings are equal
  bool isEqual(const string &) const {
    if (GLOBAL_DEBUG)
      cout << "Calling isEqual 1 Fn with args:" << endl;
  }
  // returns true if two strings are equal
  bool isEqual(char *s) const {
    if (GLOBAL_DEBUG)
      cout << "Calling isEqual 2 Fn with args:" << endl;
    int l = length(data);
    int l2 = length(s);
    if (l != l2) {
      return false;
    } else {
      // cout << "checking strs...";
      for (int i = 0; i < l; i++) {
        if (data[i] != s[i])
          return false;
      }
      return true;
    }
  }
  // returns the index of the character being searched
  int index_at(char c) const {
    if (GLOBAL_DEBUG)
      cout << "Calling index_at Fn with args:" << endl;
    for (int i = 0; i < length(data); i++) {
      if (data[i] == c)
        return i;
    }
    return -1;
  }
  // returns the start index of the String being searched
  int index_at(const String &str) const {
    if (GLOBAL_DEBUG)
      cout << "Calling index_at 1 Fn with args:" << endl;
    return index_at(str.data);
  }
  // returns the start index of the string being searched
  int index_at(const string &str) const {
    if (GLOBAL_DEBUG)
      cout << "Calling index_at 2 Fn with args:" << endl;
    const char *c = str.c_str();
    int i = 0, j = 0;
    for (i = 0; i < length(data); i++) {
      if (data[i] == str[0]) {
        for (j = 0; j < str.length(); j++) {
          if (data[i + j] == str[j]) {
            continue;
          } else
            break;
        }
        if (j == str.length()) {
          return i;
        }
      }
    }
    return -1;
  }
  // returns the start index of the c-string being searched
  int index_at(char *str) const {
    if (GLOBAL_DEBUG)
      cout << "Calling index_at 3 Fn with args:" << str
           << " of length:" << length(str) << endl;
    int i = 0, j = 0;
    for (i = 0; i < length(data); i++) {
      if (data[i] == str[0]) {
        for (j = 0; j < length(str); j++) {
          if (data[i + j] == str[j]) {

            continue;
          } else
            break;
        }
        if (j == length(str)) {
          return i;
        }
      }
    }
    return -1;
  }
  // multiples the string by i times and return the string.
  String mul_String(int i) {
    if (GLOBAL_DEBUG)
      cout << "Calling mul_String with args:" << endl;
  }
  // returns the length of string
  int length() const {
    if (GLOBAL_DEBUG)
      cout << "Calling Length Fn with args:" << endl;
    return length(data);
  }
  int length(char *str) const {
    if (GLOBAL_DEBUG)
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
  char *concat(char *a, char *b) const {
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
    if (GLOBAL_DEBUG)
      cout << "Concatenated:" << a << ", " << b << " into:" << result;
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
    if (GLOBAL_DEBUG)
      cout << "Concatenated:" << a << ", " << b << " into:" << result;
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
    if (GLOBAL_DEBUG)
      cout << "Returning from getdata():" << data << endl;
    return data;
  }
  // destructor...
  ~String() {
    if (GLOBAL_DEBUG)
      cout << "Calling Destructor with args:" << endl;
  }
};