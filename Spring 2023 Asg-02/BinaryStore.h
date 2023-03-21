// BinaryStore.h
#ifndef BINARYSTORE
#define BINARYSTORE
#include <iostream>
using namespace std;
int getLength(char *str);
char *fill(char *tgt, char c, int len = 0);
char *concat(char *a, char *b);
char *push_left(char *tgt, char *load);
class BinaryStore {
  int ByteSize = 8, filledAddresses, lengthMax;
  // add suitable member attributes
  char **addresses, **values;

public:
  // constructor which creates the store of length len.
  BinaryStore(int len = 16);
  // add a new address in the list of Binary store.
  void add_Address(char *s);
  // add the byte at newly added address
  // here the first parameter is address and second is byte// Similarly the
  // following code adds byte address and later byte // if address not found add
  // address and byte both // function also overrides the data given at
  // particular byte address.
  void set_Byte(char *address, char *value);
  // Get function will retrieve the byte at a give address ,
  char *Get(char *address);
  // return the BinaryStore as character dynamic array.
  char *ToString();
  // ADD function will take two strings as input parameters and given the binary
  // equivalent in form of string.
  char *Add(char *a, char *b);
  //  comp_EQUAL, comp_AND, and comp_OR function will take two strings as input
  //  parameters and given the binary equivalent in form of string.
  bool comp_EQUAL(char *a, char *b);
  char *comp_AND(char *a, char *b);
  char *comp_OR(char *a, char *b);
  char *comp_NOT(char *a, char *b);
  char *comp_NOT(char *a);
  ~BinaryStore();

  // private:
  char char_OR(char a, char b = '0');
  char char_AND(char a, char b = '0');
  char char_NOT(char a);
};
#endif