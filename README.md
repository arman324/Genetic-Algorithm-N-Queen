# Genetic-Algorithm-N-Queens
### Solving n queen problem with Genetic Algorithm

## Overview
### N-queens puzzle:
The N-queens puzzle is the problem of placing N chess queens on an N*N chessboard so that no two queens threaten each other; thus, a solution requires that no two queens share the same row, column, or diagonal.
### Genetic algorithm:
Genetic algorithms are commonly used to generate high-quality solutions to optimization and search problems by relying on biologically inspired operators such as mutation, crossover, and selection. (for more information, you can use this [link](https://en.wikipedia.org/wiki/Genetic_algorithm)). 

## Goal
In this project, I have used the Genetic algorithm to solve the N-queens puzzle. I have implemented two selection methods, two different types of crossover and, two mutation methods. In the table below, you can see how to run each model.


## How to Run
1. ``gcc -Wall -o output main.c init.c random.c eval.c stats.c gen.c select.c xover.c rep.c``
2. ``./output [enter number 1 or 2 or 3]``

| Mode Number  | Selection | Crossover | Mutation |
| ------------- | ------------- | ------------- | ------------- |
| `./output 1` | Tournament Selection | Two-Point | Uniform |
| `./output 2` | Roulette Wheel | One-Point | Uniform |
| `./output 3` | Tournament Selection | Two-Point | Swap Mutation |

## THE BEST ANSWER 🎉
```diff
+ THE BEST ANSWER is for mode number 1, It can solve the 88-Queens Problem
```
88-Queens is a version of the N-Queens puzzle on an 88x88 chessboard with 88 queens. The object is to calculate positions for all 88 queens such that no queen is attacking any other queen.

---
## Mode number 1️⃣:
| Population Size | MaxGen | pCross | Start pMut |
| ------------- | ------------- | ------------- | ------------- |
| 1000 | 1000 | 0.8 | 0.001 |

If maxFitness > 0.97 then pMut = 0.01;

### Output:
| N-Queens Problem | Result |
| ------------- | ------------- |
| n = 8 | Global Optimal in 14th generation |
| n = 9 | Global Optimal in 36th generation |
| n = 11 | Global Optimal in 104th generation |
| n = 20 | Global Optimal in 71th generation |
| n = 25 | Local Optimal with 0.9966 fitness |
| n = 30 | Global Optimal in 942th generation |
| n = 40 | Local Optimal with 0.9974 fitness |
| n = 45 | Global Optimal in 159th generation |
| n = 48 | Global Optimal in 240th generation |
| n = 50 | Local Optimal with 0.9991 fitness |
| n = 75 | Local Optimal with 0.9996 fitness |
| n = 80 | Global Optimal in 870th generation |
| n = 88  🎉 | Global Optimal in 745th generation |
| n = 100 | Local Optimal with 0.9993 fitness |

--- 
## Mode number 2️⃣:
| Population Size | MaxGen | pCross | Start pMut |
| ------------- | ------------- | ------------- | ------------- |
| 1000 | 1000 | 0.8 | 0.001 |

If maxFitness > 0.97 then pMut = 0.01;

### Output:
| N-Queens Problem | Result |
| ------------- | ------------- |
| n = 8 | Global Optimal in 67th generation |
| n = 9 | Global Optimal in 46th generation |
| n = 10 | Global Optimal in 173th generation |
| n = 11 | Global Optimal in 467th generation |
| n = 12 | Global Optimal in 252th generation |
| n = 13 | Local Optimal with 0.96 fitness |
| n = 14 | Global Optimal in 739th generation |
| n = 15 | Local Optimal with 0.97 fitness |

---
## Mode number 3️⃣:
| Population Size | MaxGen | pCross | Start pMut |
| ------------- | ------------- | ------------- | ------------- |
| 1000 | 1000 | 0.8 | 0.001 |

If maxFitness > 0.97 then pMut = 0.01;

### Output:
| N-Queens Problem | Result |
| ------------- | ------------- |
| n = 8 | Global Optimal in 9th generation |
| n = 9 | Global Optimal in 35th generation |
| n = 10 | Global Optimal in 45th generation |
| n = 25 | Local Optimal with 0.9966 fitness |
| n = 50 | Local Optimal with 0.9934 fitness |

---

## Support
Reach out to me at riasiarman@yahoo.com
