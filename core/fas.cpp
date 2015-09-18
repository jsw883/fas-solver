// =============================================================================

/* Title   : fas.cpp
 * Summary : Solvers for the Feedback Arc Set (FAS)
 * Author  : James Williams
 * Date    : 2015-09-15
 * Version : 1.0
 * 
 * These solvers for the Feedback Arc Set (FAS) are from the paper by Hassin and
 * Rubinstein, "Approximations for the maximum acyclic subgraph problem" (1994).
 * 
 * Method 1
 * 
 * Let A1 = {(i,j) ∈ A | i < j}, A2 = {(i,j) ∈ A | i > j}. Clearly, (V, A1) and
 * (V, A2) are directed acyclic graphs, and since A1 ∪ A2 = A, we have the bound
 * max(w(A1), w(A2)) ≥ 0.5*w(A), where w(α) is the sum of weights in the induced
 * subgraph (V, α).
 */

// =============================================================================
// Headers
 
#include "fas.h"

// =============================================================================