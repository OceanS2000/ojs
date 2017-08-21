#!/bin/python3
from queue import Queue

class eight_problem:
  def __init__(self, status):
    assert type(status) == list,"import must be a list of 9 int"
    self.status = [i for i in status]
    self.edgeTo = None
    self.emptyPlace = status.index(0)
  
  def __eq__(this,that):
    if type(this) == type(that):
      return this.status == that.status
    else:
      return False
  
  def exch(self, pindex, qindex):
    '''exchange shortcut'''
    stat = [self.status[i] for i in range(9)]
    tmp = stat[pindex]
    stat[pindex] = stat[qindex]
    stat[qindex] = tmp
    return eight_problem(stat)
  
  def adj(self):
    if self.emptyPlace == 0:
      return (self.exch(0,1), self.exch(0,3))
    if self.emptyPlace == 1:
      return (self.exch(1,0), self.exch(1,2), self.exch(1,4))
    if self.emptyPlace == 2:
      return (self.exch(2,1), self.exch(2,5))
    if self.emptyPlace == 3:
      return (self.exch(3,0), self.exch(3,6), self.exch(3,4))
    if self.emptyPlace == 4:
      return (self.exch(4,3), self.exch(4,5), self.exch(4,1), self.exch(4,7))
    if self.emptyPlace == 5:
      return (self.exch(5,2), self.exch(5,4), self.exch(5,8))
    if self.emptyPlace == 6:
      return (self.exch(6,7), self.exch(6,3))
    if self.emptyPlace == 7:
      return (self.exch(7,8), self.exch(7,6), self.exch(7,4))
    if self.emptyPlace == 8:
      return (self.exch(8,7), self.exch(8,5))
  
def solve(query):
  status = eight_problem(query)
  standard = eight_problem([1,2,3,4,5,6,7,8,0])
  marked = []
  queue = Queue()
  marked.insert(0,status)
  queue.put(status)
  while not (queue.empty()):
    v = queue.get()
    for w in v.adj():
      if (w not in marked):
        w.edgeTo = v
        marked.insert(0,w)
        queue.put(w)
    if standard in marked:
      break
  i = standard
  while (i != status) and (i != None):
    print(i.status)
    i = i.edgeTo

if __name__ == '__main__':
  import sys
  qry = []
  a_line = sys.stdin.readline()
  while a_line:
    qry.append(int(a_line))
    a_line = sys.stdin.readline()
  solve(qry)
  print(qry)


