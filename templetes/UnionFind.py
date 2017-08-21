#!/bin/python3

class qu:
  '''Union-Find problem solver
  '''
  def __init__(self,N):
    assert N>0,"N must be more than 0"
    self.count = N
    self.id = [i for i in range(N)]
    
  def connected(self,p,q):
    return self.find(p) == self.find(q)
  
  def find(self,p):
    while (p != self.id[p]):
      p = self.id[p]
    return p
  
  def union(self,p,q):
    pRoot = self.find(p)
    qRoot = self.find(q)
    if (pRoot == qRoot):
      return
    
    self.id[pRoot] = qRoot
    self.count -= 1
    
class wqu:
  '''Union-Find problem solver
  '''
  def __init__(self,N):
    assert N>0,"N must be more than 0"
    self.count = N
    self.id = [i for i in range(N)]
    self.sz = [1 for i in range(N)]
    
  def connected(self,p,q):
    return self.find(p) == self.find(q)
  
  def find(self,p):
    while (p != self.id[p]):
      p = self.id[p]
    return p
  
  def union(self,p,q):
    pRoot = self.find(p)
    qRoot = self.find(q)
    if (pRoot == qRoot):
      return
    
    if (self.sz[pRoot] > self.sz[qRoot]):
      self.id[qRoot] = self.id[pRoot]
    else:
      self.id[pRoot] = self.id[qRoot]
    self.count -= 1

if __name__ == '__main__':
  import sys
  
  line_no = 0
  for a_line in sys.stdin:
    line_no += 1
    if line_no == 1:
      query = qu(int(a_line))
      continue
    
    (pID, qID) = (int(i) for i in a_line.split(' '))
    query.union(pID, qID)
    
  print("{0} components".format(query.count))