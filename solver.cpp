// =============================================================================

/* Title   : solver.h
 * Summary : Main method for solving the Feedback Arc Set (FAS)
 * Author  : James Williams
 * Date    : 2015-09-15
 * Version : 1.0
 * 
 * Main method for solving the Feedback Arc Set (FAS).
 */

// =============================================================================
// Headers

#include <string>
 
#include "timing.h"
#include "unpair.h"
#include "graph.h"
#include "fas.h"
#include "gio.h"

// =============================================================================
// Main method
 
// Print usage and exit with status 0
void usage(char* name) {
  printf("usage: %s -i <source file name> -o <output base name> [-w]\n", name);
  printf("computes an approximate solution to the feedback arc set (FAS)\n");
  printf("-w\tsource graph weighted\n");
  exit(0);
}

// Main method for solving the Feedback Arc Set (FAS)
int main(int argc, char *argv[]) {
  
  setbuf(stdout, NULL); // disables buffer so printf displays immediately
  
  // declare variables
  std::string
    source_filename = "./data/USairport2010.edges",
    output_basename = "./data/USairport2010";
  bool weighted = true;
  Graph<double> source_graph, fas_graph, dag_graph;
  
  // parse command line arguments (could use external library)
  for (int i = 1; i < argc; i++) {
    switch(argv[i][1]) {
      case 'i':
        source_filename = argv[i+1];
        i++;
        break;
      case 'o':
        output_basename = argv[i+1];
        i++;
        break;
      case 'w':
        weighted = true;
        break;
      case 'h':
        usage(argv[0]);
      default:
        printf("\nerror: switch %s not recognized\n", argv[i]);
        usage(argv[0]);
    }
  }
  
  // print header
  printf("[%s build: %s %s time: %s]\n", argv[0], __TIME__, __DATE__,
    get_time());
  printf("Loading %s\n", source_filename.c_str());
  
  // =========================================================================
  
  // read source graph and print simple graph summary
  load_graph(source_graph, source_filename, weighted);
  printf("Source graph "); source_graph.summary();
  
  // FAS simple approximation method
  fas_method1(source_graph, fas_graph, dag_graph);
  
  // save output graph and print simple graph summary
  save_graph(fas_graph, output_basename + "-fas.edges", weighted);
  save_graph(dag_graph, output_basename + "-dag.edges", weighted);
  printf("FAS graph "); fas_graph.summary();
  printf("DAG graph "); dag_graph.summary();
  
  // =========================================================================
  
}


// =============================================================================