// =============================================================================

/* Title   : unpair.h
 * Summary : Splits pair return type implicitly
 * Author  : James Williams
 * Date    : 2015-09-15
 * Version : 1.0
 * 
 * Splits pair return type and assigns first and second to separate variables
 * implicitly, using a struct functor to do variable assignment by reference
 * and avoid unnecessary copies.
 * 
 * // declare variables
 * T1 var1;
 * T2 var2;
 * 
 * // unpair values
 * unpair(var1, var2) = ...;
 */

// =============================================================================
// Headers

#ifndef UNPAIR_H
#define UNPAIR_H

#include <utility>

// =============================================================================
// Template functor
 
template <typename T1, typename T2>
struct unpair_functor {
  public:
    T1& a1;
    T2& a2;
  public:
    explicit unpair_functor(T1& a1, T2& a2): a1(a1), a2(a2) { }
    unpair_functor<T1,T2>& operator = (const std::pair<T1,T2>& p) {
      a1 = p.first;
      a2 = p.second;
      return *this;
    }
};

// =============================================================================
// Functor helper

template <typename T1, typename T2>
unpair_functor<T1,T2> unpair(T1& a1, T2& a2) {
  return unpair_functor<T1,T2>(a1, a2);
}

// =============================================================================

#endif

// =============================================================================