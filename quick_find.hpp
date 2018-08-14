/*! \file
 * Algorithm to solve dynamic connectivity problem
 *
 * Problem:
 *   Given a set of N objects.
 *   . Connect/Union command: connect two objects
 *   . Connected/Find query: Is there a path connecting the two objects ?
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
  int cost; // Calculate number of iteration for cost

  public:
    // Constructors
    QuickFind(int N);
    ~QuickFind();

    // Set/Get methods
    int getCost() {return cost;}

    // Other methods
    void connect(int p, int q);
    bool connected(int p, int q);
};
#endif
