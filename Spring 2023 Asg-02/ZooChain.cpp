#include "ZooChain.h"

// Default constructor
ZooChain::ZooChain() { start = NULL; }
void ZooChain::add_Cage(char *name, int cageNumber) {
  int namelength = 0;
  while (*(name + namelength) != '\0') {
    namelength++;
  }
  char *newname = new char[namelength + 1];
  ZooCage *cage = new ZooCage;
  for (int i = 0; i <= namelength; i++) {
    *(newname + i) = *(name + i);
  }
  *(newname + namelength) = '\0';

  cage->name = newname;
  cage->cageNumber = cageNumber;
  cage->link = NULL;

  if (start == NULL) {
    start = cage;
  } else {
    ZooCage *last = start;
    while (last->link != NULL) {
      last = last->link;
    }
    last->link = cage;
    last = cage;
  }
}
void ZooChain::print_Chain() {
  for (ZooCage *print = start; print != NULL; print = print->link) {
    cout << print->name << " is in cage number " << print->cageNumber << endl;
  }
}

void ZooChain::delete_Chain(int cageNumber) {
  // If the chain is empty, do nothing
  if (start == NULL) {
    return;
  }

  // If the first cage has the specified cageNumber, delete it
  if (start->cageNumber == cageNumber) {
    ZooCage *temp = start;
    start = start->link;
    delete[] temp->name;
    delete temp;
    cout << "Cage " << cageNumber << " has been deleted from the chain" << endl;
    return;
  }

  ZooCage *current = start->link;
  ZooCage *prev = start;
  while (current != NULL && current->cageNumber != cageNumber) {
    prev = current;
    current = current->link;
  }
  if (current != NULL && current->cageNumber == cageNumber) {
    prev->link = current->link;
    delete[] current->name;
    delete current;
    cout << "Cage " << cageNumber << " has been deleted from the chain" << endl;
  }
  if (current == NULL) {
    cout << "Cage not found in the chain" << endl;
    return;
  }
}

void ZooChain::Sort_Chain() {
  if (start == NULL || start->link == NULL) {
    return;
  }

  //   bool swapped = true;
  //   while (swapped) {
  //     swapped = false;
  //     ZooCage *current = start;
  //     ZooCage *next = NULL;
  //     while (current->link != next) {
  //       if (current->cageNumber > current->link->cageNumber) {
  //         // Swap the cages
  //         ZooCage *temp = current;
  //         current = current->link;
  //         current->link = temp;
  //         swapped = true;
  //       }
  //       current = current->link;
  //       next = current->link;
  //     }
  //   }
}

void ZooChain::update_name_at_cageNumber(int cageNumber, char *name) {
  ZooCage *current = start;

  while (current != NULL && current->cageNumber != cageNumber) {
    current = current->link;
  }

  if (current != NULL && current->cageNumber == cageNumber) {
    delete[] current->name;
    current->name = name;
    cout << endl;
    cout << "Name updated in cage " << cageNumber << endl;
    print_Chain();
  } else {
    cout << "Cage not found in the chain" << endl;
  }
}
void ZooChain::remove_Duplicate() {
  if (start == NULL || start->link == NULL) {
    return;
  }
  ZooCage *current = start;
  while (current != NULL) {
    ZooCage *tem = current;
    while (tem->link != NULL) {
      if (tem->link->cageNumber == current->cageNumber) {
        // Remove the duplicate cage
        ZooCage *temp = tem->link;
        tem->link = tem->link->link;
        delete[] temp->name;
        delete temp;
      } else {
        tem = tem->link;
      }
    }
    current = current->link;
  }
  print_Chain();
}
ZooChain::~ZooChain() {}
