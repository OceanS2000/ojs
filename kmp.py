#/usr/bin/env python3

class KMP:
    """Knuth-Morris-Pratt algorithm"""
    def __init__(self, pat):
        self.pat = pat
        M = len(pat)
        self.dfa = [[0]*M]*256
        self.dfa[pat[0]][0] = 1
        X = 0
        for j in range(M):
            for c in range(256):
                self.dfa[c][j] = self.dfa[c][X]
            self.dfa[pat[j]][j] = j+1
            
            X = self.dfa[pat[j]][X]

    def __call__(self, txt):
        N = len(txt)
        M = len(self.pat)
        j = 0
        for i in range(N):
            j = self.dfa[txt[i]][j]
            if j == M:
                return i - M
        return N

if __name__ == '__main__':
    from sys import stdin
    pat = stdin.readline().rstrip().encode("ascii")
    txt = stdin.readline().rstrip().encode("ascii")
    kmp = KMP(pat)
    offset = kmp(txt)
    print(kmp.dfa[1])
    for i in range(offset):
        print(' ', end='')
    print(pat.decode("ascii"))
