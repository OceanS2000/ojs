#!/bin/python3
import sys
class main:
    (N, a, b) = (int(i) for i in sys.stdin.readline().split(' '))
    
    pa = [int(i) for i in sys.stdin.readline().split(' ')]
    pb = [int(i) for i in sys.stdin.readline().split(' ')]

    (sa, sb) = (0, 0)

    scores = [[0, -1, 1, 1, -1],
              [1, 0, -1, 1, -1],
              [-1, 1, 0, -1, 1],
              [-1, -1, 1, 0, 1],
              [1, 1, -1, -1, 0]]
    
    def calscore(self, ga, gb):
        if (ga == gb):
            return
        if self.scores[ga][gb] == 1:
            self.sa += 1
        if self.scores[ga][gb] == -1:
            self.sb += 1
        return
    
    def main(self):
        for i in range(self.N):
            (ga, gb) = (self.pa[i % self.a], self.pb[i % self.b])
            self.calscore(ga,gb)
    
        print("{} {}".format(self.sa, self.sb))

ans = main()
ans.main()
