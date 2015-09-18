Feedback Arc Set (FAS)
======================

This repository contains a approximate solvers for the Feedback Arc Set (FAS),
from the paper [Approximations for the maximum acyclic subgraph problem](http://www.shlomir.com/papers/acyclic.pdf)
by Hassin and Rubenstein (1994). Currently, only the first and trivial method
has been implemented.

However, this exercise also provided an opportunity to build an efficient and
straightforward graph class using C++11, and the [core](./core) classes and
functions are intended to be improved and reused for later graph related work
such as fully contained, highly efficient graph algorithms.

### Dependencies ###

All you need is gcc / g++ greater than 4.8.

```bash
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt-get install gcc-5 g++-5
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-5 50
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-5 50
```

### Build ###

It's easy, and usage is contained in [solver.cpp](solver.cpp) already.

```bash
make
./solver
cat ./datasets/karate-club/karate.edges
cat ./datasets/karate-club/karate-fas.edges
cat ./datasets/karate-club/karate-dag.edges
```