// =============================================================================

/* Title   : timing.h
 * Summary : Helper functions for timing
 * Author  : James Williams
 * Date    : 2015-09-15
 * Version : 1.0
 * 
 * Currently contains a helper function for getting a simple time string, using
 * strftime to format the string to match the __TIME__ and __DATE__ formatting.
 * 
 */

// =============================================================================
// Headers

#ifndef TIMING_H
#define TIMING_H

#include <ctime>
 
// =============================================================================
 // Get simple time string

char * get_time() {
  char *timestr = new char[80];
  time_t rawtime;
  time(&rawtime);
  strftime(timestr, 80, "%H:%M:%S %b %d %G", localtime(&rawtime));
  return timestr;
}

// =============================================================================

#endif

// =============================================================================