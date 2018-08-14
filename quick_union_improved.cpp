/*! \file
 * Description
 */
 
/* INCLUDES */
//#include <cstdlib> // To call atoi()
//#include <fcntl.h> // To call open()
//#include <iomanip> // To call setw()
//#include <iostream> // To call cout/cin
//#include <sstream> // To call stringstream
//#include <stdint.h> // To use uint8_t
//#include <stdlib.h> // To call malloc()/sleep()
//#include <unistd.h> // To call read()
#include "quick_union_improved.hpp"

/* MACROS */

/*! \namespace std */
using namespace std;

/*!
 * \details Constructor of QuickUnionImproved class containing N objects. Set id of each objects to itself.
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
QuickUnionImproved::QuickUnionImproved(int N) {
  this->id = new int[N];
  this->size = new int[N];

  for (int i = 0; i < N; i++) {
    this->id[i] = i;
    this->size[i] = 1;
  }
}

/*!
 * \details Destructor of QuickUnionImproved class
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
QuickUnionImproved::~QuickUnionImproved() {
  delete [] this->id;
  delete [] this->size;
}

/*!
 * \details Chase parent pointers until reach root
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
int QuickUnionImproved::root(int p) {
  while (p != this->id[p])
    p = this->id[p];
    
  return p;
}

/*!
 * \details Connect objects p and q
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
void QuickUnionImproved::connect(int p, int q) {
  int i = root(this->id[p]);
  int j = root(this->id[q]);
	
	if (i == j)
	  return;

  if (this->size[i] < this->size[j]) {
    this->id[i] = j;
    this->size[j] += this->size[i];
  }
  else {
    this->id[j] = i;
    this->size[i] += this->size[j];
  } 
}

/*!
 * \details Return true if objects p and q are connected.
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
bool QuickUnionImproved::connected(int p, int q) {
  return (root(this->id[p]) == root(this->id[q])); // Check if p and q have the same root
}
