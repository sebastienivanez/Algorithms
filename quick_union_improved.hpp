/*! \file
 * Algorithm to solve dynamic connectivity problem
 *
 * Problem:
 *   Given a set of N objects.
 *   . Connect/Union command: connect two objects
 *   . Connected/Find query: Is there a path connecting the two objects ?
 */
#ifndef _QUICK_UNION_IMPROVED_H
#define _QUICK_UNION_IMPROVED_H
   
/* INCLUDES */

/* MACROS */

/*!
 * \details Class QuickUnionImproved
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
class QuickUnionImproved {
  int *id; // Id of object
  int *size; // Size of connected component

  int root(int p); // Private method only accessible by class methods

  public:
    // Constructors
    QuickUnionImproved(int N);
    ~QuickUnionImproved();

    // Set/Get methods

    // Other methods
    void connect(int p, int q);
    bool connected(int p, int q);
};
#endif
