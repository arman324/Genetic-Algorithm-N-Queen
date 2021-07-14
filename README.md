# Genetic-Algorithm-N-Queens
### Solving n queen problem with Genetic Algorithm

## Overview
*

## How to Run
1. ``gcc -Wall -o output main.c init.c random.c eval.c stats.c gen.c select.c xover.c rep.c``
2. ``./output [enter number 1 or 2 or 3]``

| Mode Number  | Selection | Crossover | Mutation |
| ------------- | ------------- | ------------- | ------------- |
| `./output 1` | Tournament Selection | Two-Point | Uniform |
| `./output 2` | Roulette Wheel | One-Point | Uniform |
| `./output 3` | Tournament Selection | Two-Point | Swap Mutation |


## Mode number 1:
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
| n = 88 (THE BEST ANSWER) | Global Optimal in 745th generation |
| n = 100 | Local Optimal with 0.9993 fitness |

## Mode number 2:

## Mode number 3:


## Support
Reach out to me at riasiarman@yahoo.com
