// Record.h
#ifndef RECORD
#define RECORD
#include <iostream>
using namespace std;
class Record {
private:
  // add required data members if required
  char *fileName;

public:
  Record(char *str);
  // constructor will create the file with the given file name.
  /// input function will get the multiple data (name
  /// ,address ,age and CGPA )from the user and adds to the
  /// file,
  int record_Input();
  // the function will display the all the data store in file.
  void record_Display();
  /// function will delete the complete record that is data
  /// (name ,address ,age and CGPA ) of person with given
  /// name.
  int delete_Record();
  // function will count the total records stored in the
  // file.
  int record_Count();
  // Allows to search the file with a particular name
  int record_Search();
  // it will allow the user to insert the data (name
  // ,address ,age and CGPA ) after some name in the file
  int record_Insert();
  // it will allow the user to replace the data (name
  // ,address,age and CGPA ) of given name in the file
  void record_Replace();
  ~Record();
};
#endif