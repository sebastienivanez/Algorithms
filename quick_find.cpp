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
#include "quick_find.hpp"

/* MACROS */

/*! \namespace std */
using namespace std;

/*!
 * \details Constructor of QuickFind class containing N objects
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
QuickFind::QuickFind(int N) {
  this->id = new int[N];
  this->size = N;

  for (int i = 0; i < N; i++) {
    this->id[i] = i; // Set id of each objects to itself
    this->cost++;
  }
}

/*!
 * \details Destructor of QuickFind class
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
QuickFind::~QuickFind() {
  delete [] this->id;
}

/*!
 * \details Connect objects p and q
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
void QuickFind::connect(int p, int q) {
  int pid = this->id[p];
  int qid = this->id[q];
		
  for (int i = 0; i < this->size; i++) {
    this->cost++;
    if (this->id[i] == pid) {
      this->id[i] = qid; // Change all entries with id[p] to id[q]
    }
  }
}

/*!
 * \details Return true if objects p and q are connected
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
bool QuickFind::connected(int p, int q) {
  return this->id[p] == this->id[q]; // check wether p and q are in the same component
}
