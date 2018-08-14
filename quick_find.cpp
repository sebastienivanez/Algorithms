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

  for (int i = 0; i < N; i++)
    this->id[i] = i;
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
 * \details Connect objects x and y
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
void QuickFind::connect(int x, int y) {
  int xid = this->id[x];
  int yid = this->id[y];
		
  for (int i = 0; i < this->size; i++)
    if (this->id[i] == xid)
      this->id[i] = yid;
}

/*!
 * \details Return true if objects x and y are connected
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
bool QuickFind::connected(int x, int y) {
  return this->id[x] == this->id[y];
}
