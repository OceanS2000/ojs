#!/bin/python3

from UnionFind import qu as UF
import unittest

class KnownResults(unittest.TestCase):
  number_of_vertices = 5
  set_of_edges = ((1,2),(2,3),(1,3),(4,0))
  
  def test_known_results(self):
    '''UF should give known result with known input'''
    UF_problem = UF(self.number_of_vertices)
    for p, q in self.set_of_edges:
      UF_problem.union(p, q)
    self.assertEqual(UF_problem.count, 2)
    
if __name__ == '__main__':
  unittest.main()
