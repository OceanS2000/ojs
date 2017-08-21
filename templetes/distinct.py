#!/bin/python3

from random import randint as rand
import math

def expriment(M, N, T):
  for i in range(T):
    number_list = [rand(0, M-1) for i in range(N)]
    number_list.sort()
    distinct = 1
    for j in range(N):
      if number_list[j] != number_list[j-1]:
        distinct += 1
    theoreical = M*(1-math.exp(-(N/M)))
    precision = (distinct-theoreical)/theoreical*100
    print("{0:2}|{1:^10.0f}|{2:^10}|{3:^+6.3f}".format(i,theoreical,distinct,precision))

if __name__ == '__main__':
  N_list = {1000,10000,100000,1000000}
  print(" T|theoreical|empirical |prec %")
  print("--+----------+----------+------")
  for N in N_list:
    M = int(N/2)
    print("N = {}, M = {}".format(N, M))
    expriment(M, N, 5)
    print("--+----------+----------+------")
    print("N = {}, M = {}".format(N, N))
    expriment(N, N, 5)
    print("--+----------+----------+------")
    print("N = {}, M = {}".format(N, 2*N))
    expriment(2*N, N, 5)
    print("--+----------+----------+------")
