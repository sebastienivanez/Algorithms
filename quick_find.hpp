/*! \file
 * Algorithm to solve dynamic connectivity problem
 *
 * Problem:
 *   Given a set of N objects.
 *   . Union command: connect two objects
 *   . Find/connected query: Is there a path connecting the two objects ?
 */
#ifndef _QUICK_FIND_H
#define _QUICK_FIND_H
   
/* INCLUDES */

/* MACROS */

/*!
 * \details Class QuickFind
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
class QuickFind {
  int *id; // Id of object
  int size; // Number of objects

  public:
    // Constructors
    QuickFind(int N);
    ~QuickFind();

    // Set/Get methods

    // Other methods
    void connect(int x, int y);
    bool connected(int x, int y);
};
#endif
