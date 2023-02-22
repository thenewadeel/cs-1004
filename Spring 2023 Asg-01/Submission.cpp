#include <iostream>
using namespace std;
// Helper function to check the length of a string array
int getLength(char *str) {
  int i = 0;
  if (str) {
    while (str[i++]) {
    }
    return i - 1;
  }
  return 0;
}

bool FindSubString(char *Str, char *substr, int &start, int &end) {
  int lengthStr = getLength(Str);
  int lengthSubStr = getLength(substr);
  if (lengthSubStr < lengthStr) {
    start = 0, end = 0;
    // Two pointers to traverse the arrays
    int i = 0, j = 0;
    while (i < lengthStr) {
      if (Str[i] == substr[0]) {
        start = i;
        while (j < lengthSubStr) {
          if (Str[(i + j) % lengthStr] == substr[j]) {
            j++;
            continue;
          } else
            break;
        }
        // cout << "J is:" << j;
        if (j == lengthSubStr) {
          end = (i + j - 1) % lengthStr;
          return true;
        }
      }
      i++;
    }
  }
  start = end = -1;
  return false;
}
char *removeSentence(char *Para, char *input) {
  char *err = "No substring found";
  int start = 0, end = 0;
  if (FindSubString(Para, input, start, end)) {
    int paraLength = getLength(Para);
    // cout << "\nParaSize:" << paraLength;
    int inputLength = getLength(input);
    // cout << "\ninputSize:" << inputLength;
    int trimmedSize = paraLength - inputLength;
    // cout << "\nTrimmedSize:" << trimmedSize;
    // cout << Para << "\n, Contains:\n"
    //  << input << "\n, at:" << start << "-" << end;
    char *result = new char[trimmedSize - 1];
    for (int i = 0; i < trimmedSize; i++) {
      // cout << "\nres:" << result;
      if (i < start) {
        result[i] = Para[i];
      } else {
        result[i] = Para[i + end - start + 2];
      }
    }
    // cout << "\nres:" << result;
    // cout << "\nsizeOfResult:" << sizeof(result);
    return result;
  } else {
    return err;
  }
}
char ***
ConvertToDynamic(char arr[], int x, int y,
                 int z) // Converts 1D Array to 3D dynamically allocated array
{
  // https://www.geeksforgeeks.org/how-to-dynamically-allocate-a-3d-array-in-c/
  // Dimensions of the 3D array provided in function arguments as x,y,z

  // Allocate memory blocks of size
  // x i.e., no of 2D Arrays
  char ***Mat = new char **[x];

  for (int i = 0; i < x; i++) {

    // Allocate memory blocks for
    // rows of each 2D array
    Mat[i] = new char *[y];

    for (int j = 0; j < y; j++) {

      // Allocate memory blocks for
      // columns of each 2D array
      Mat[i][j] = new char[z - 1];
    }
  }

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      for (int k = 0; k < z - 1; k++) {
        // Assign values to the
        // memory blocks created
        Mat[i][j][k] = arr[i * y * (z - 1) + j * (z - 1) + k];
        // last column contains string delimiter character (\0), # is used for
        // readability only, should be changed to \0 before submission
        // https://www.austincc.edu/rickster/COSC1320/handouts/escchar.htm
        Mat[i][j][z - 1] = '#';
      }
    }
  }
  return Mat;
}

bool MatchString3DArray(char ***mat, int xSize, int ySize, int zSize,
                        char *input, int **&resultMat, int &colSize) {
  // Three pointers to traverse the Matrix
  int i = 0, j = 0, k = 0;
  int lengthInput = getLength(input);
  // while (i < xSize) {
  //   if (Str[i] == substr[0]) {
  //     start = i;
  //     while (j < lengthInput) {
  //       if (Str[(i + j) % lengthStr] == substr[j]) {
  //         j++;
  //         continue;
  //       } else
  //         break;
  //     }
  //     // cout << "J is:" << j;
  //     if (j == lengthInput) {
  //       end = (i + j - 1) % lengthStr;
  //       return true;
  //     }
  //   }
  //   i++;
  // }
  return false;
  // 3d Arrays in C
  // https://iq.opengenus.org/3d-array-in-c/
}

void DeleteArray(char ***&arr, int x, int y, int z) {}

bool isperfectNumber(int n) {
  // To store sum of divisors
  int sum = 1;

  // Find all divisors and add them
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      if (i * i != n)
        sum = sum + i + n / i;
      else
        sum = sum + i;
    }
  }
  // If sum of divisors is equal to
  // n, then n is a perfect number
  if (sum == n && n != 1)
    return true;

  return false;
}

int findVowels(char *str) {
  int result = 0, i = 0;
  for (; i < getLength(str); i++) {
    if (str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' ||
        str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' ||
        str[i] == 'u' || str[i] == 'U')
      result++;
  }
  // char *vowels = "aeiou";
  return result;
}

int pascal(int row, int col) {
  // http://proprogrammershub.blogspot.com/2015/05/pascal-triangle-in-c-using-recursive.html
  if (col == 1) {
    return 1;
  } else if (col == row) {
    return 1;
  } else {
    return pascal(row - 1, col) + pascal(row - 1, col - 1);
  }
}

void PrintPattern1(int start, int end) {}
// Program to print the given pattern

void print_stars(int n) {
  if (n == 0)
    return;
  cout << "* ";
  print_stars(n - 1);
}
void print_space(int n) {
  if (n == 0)
    return;
  cout << " "
       << " ";
  print_space(n - 1);
}

// function to print the upper-half of the pattern
void printHollowDiamond_upper(int n, int num) {
  // base case
  if (n == 0)
    return;
  print_stars(n);
  print_space(2 * (num - n) + 1);
  print_stars(n);
  cout << endl;

  // recursively calling pattern_upper()
  printHollowDiamond_upper(n - 1, num);
}

// function to print the lower-half of the pattern
void printHollowDiamond_lower(int n, int num) {
  // base case
  if (n == 0)
    return;
  print_stars(num - n + 1);
  print_space(2 * n - 1);
  print_stars(num - n + 1);
  cout << endl;

  // recursively calling pattern_lower()
  printHollowDiamond_lower(n - 1, num);
}
void printHollowDiamond(int n) {
  printHollowDiamond_upper(n, n);
  printHollowDiamond_lower(n - 1, n);
}
void print_hash(int n) {
  if (n == 0)
    return;
  cout << "# ";
  print_hash(n - 1);
}
void print_dashes(int n) {
  if (n == 0)
    return;
  cout << "- ";
  print_dashes(n - 1);
}
void print_symbol_inc(int n, int limit, char *string) {
  if (n >= limit)
    return;
  cout << string;
  print_symbol_inc(n + 1, limit, string);
}
void print_symbol_dec(int n, int limit, char *string) {
  if (n <= limit)
    return;
  cout << string;
  print_symbol_dec(n - 1, limit, string);
}
void pattern2_line(int start, int level, int total_levels) {
  // cout << "start:" << start << ", lvl:" << level << ", total:" <<
  // total_levels;
  print_symbol_inc(0, total_levels - level, "  ");
  print_symbol_inc(0, 1, "# ");
  print_symbol_inc(0, 1, "- ");
  print_symbol_inc(0, start - 1 - level, "- ");
  print_symbol_inc(0, 2 * level, "* ");
  cout << "| ";
  print_symbol_inc(0, 2 * level, "* ");
  print_symbol_inc(0, start - 1 - level, "- ");
  print_symbol_inc(0, 1, "- ");
  print_symbol_inc(0, 1, "# ");
  cout << endl;
}
void pattern2_upper(int start, int n, int levels) {
  if (n >= levels)
    return;
  pattern2_line(start, n, levels);
  pattern2_upper(start, n + 1, levels);
}
void pattern2_lower(int start, int n, int levels) {
  if (n >= levels)
    return;
  pattern2_line(start, levels - n, levels);
  pattern2_lower(start, n + 1, levels);
}
void PrintPattern2(int start, int levels) {
  //    # - - | - - #
  //  # - * * | * * - #
  //    # - - | - - #
  pattern2_upper(start, 0, levels);
  pattern2_lower(start, 2, levels);
}

void startSnakeGame() // controller of the game
{}