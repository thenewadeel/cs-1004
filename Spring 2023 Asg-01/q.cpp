#include "Submission.cpp"
using namespace std;

int main() {
  // Checking for perfect numbers;
  //   for (int n = 2; n < 1000000; n++)
  //     if (isperfectNumber(n))
  //       cout << n << " is a perfect number\n";
  //
  // Checking vowels
  // cout << "Vowels are" << findVowels("aeIOY");
  //
  // Checking Circular FindSubstring
  // char *str = "qwertyuiop", *subStr = "opq";
  // int start = 0, end = 0;
  // cout << "str:" << str;
  // if (FindSubString(str, subStr, start, end)) {
  //   cout << ", Contains:" << subStr << ", at:" << start << "-" << end;
  // } else {
  //   cout << ", DOESNT Contain:" << subStr;
  // }
  //
  // Checking RemoveSentence
  // char *Para = //"asdf";
  //     "A son asked his father (a programmer) why the sun rises in the east, "
  //     "and sets in the west. His response? It works, don’t touch!";
  // char *input = //"sd";
  //     "(a programmer)";
  // cout << "Oringinal Para:\n" << Para << endl;
  // cout << "Sentence Input:" << input << endl;
  // cout << "Processed:\n" << removeSentence(Para, input);

  // 3d Array testing
  // int x = 3, y = 3, z = 4;
  // char ***M = ConvertToDynamic("sbtaicztieahrnltagtsjvehfyf", x, y, z);
  // bool headingX, headingY, headingZ;
  // headingX = headingY = headingZ = true;
  // for (int i = 0; i < x; i++) {
  //   if (headingX) {
  //     cout << "-----X:" << i << "-----" << endl;
  //   }
  //   for (int j = 0; j < y; j++) {
  //     if (headingZ) {
  //       headingZ = false;
  //       cout << "Z:  "
  //            << "|0|1|2|3|4|5" << endl;
  //     }
  //     for (int k = 0; k <= z; k++) {
  //       if (headingY) {
  //         headingY = false;
  //         cout << "Y:" << j << " ";
  //       }
  //       // Print values of the
  //       // memory blocks created
  //       cout << "|" << M[i][j][k];
  //     }
  //     cout << endl;
  //     headingY = true;
  //   }
  //   // cout << endl;
  //   // headingX = true;
  // }

  // Pascal testing
  int r = 4, c = 2;
  cout << "Pascal Fn for Row:" << r << ", Col:" << c << endl;
  cout << "Pascal Output:" << pascal(r, c);
  return 0;
}