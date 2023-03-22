// ZooChain.h
#ifndef ZOOCHAIN
#define ZOOCHAIN
#include <iostream>
using namespace std;
struct ZooCage {
  char *name;
  int cageNumber;
  ZooCage *link;
};
class ZooChain {

public:
  ZooCage *start;
  // Default constructor
  ZooChain();
  void add_Cage(char *name, int cageNumber); /*This member function will take
  the name and cageNumber of Animal as input parameter. It creates the ZooCage
  instance. If the new Zoocage instance is the first in the chain then the
  pointer “start“ will point to it.Otherwise a new instance is attached at the
  end of the existing chain.*/
  void print_Chain(); // It prints all the animals with their cage number in the
                      // chain.
  void delete_Chain(int cageNumber); /* This member function will take the
 cageNumber of Animal as input parameter. It deletes the mentioned cageNumber
 from the chain of ZooCage instances.And rejoins the remaining chain.*/
  void Sort_Chain(); // It sort all the elements in the chain based upon their
                     // cageNumber.
  void update_name_at_cageNumber(int cageNumber, char *name);
  void remove_Duplicate(); // It removes all the duplicates in the chain.
  ~ZooChain();
};
#endif