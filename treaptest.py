#!/bin/python3
from random import random as rand

class Treap:
    """Treap-Tree with methods in alg4"""
    class Node:
        def __init__(self, key, val):
            self.key = key
            self.val = val
            self.priorty = rand()
            self.size = 1
            self.left = None
            self.right = None

        def __repr__(self):
            return key + ' : ' + val

    def __private__getP(self,node):
        if(node == None):
            return -1
        else:
            return node.priorty

    def __private__getsize(self, node):
        if(node == None):
            return 0
        else:
            return node.size

    def __init__(self):
        self.root = None
        self.a = self.Node(1,2)
    
    def __private__rotateR(self, node):
        x = node.left
        node.left = x.right
        x.right = node
        x.size = node.size
        node.size = 1 + self.__private__getsize(node.left) + self.__private__getsize(node.right)
        return x

    def __private__rotateL(self, node):
        x = node.right
        node.right = x.left
        x.left = node
        x.size = node.size
        node.size = 1 + self.__private__getsize(node.left) + self.__private__getsize(node.right)
        return x
    
    def __setitem__(self, key, val):
        self.root = self.__private__put(key, val, self.root)

    def __private__put(self, key, val, node):
        if(node == None):
            return self.Node(key, val)
        if(key < node.key):
            node.left = self.__private__put(key, val, node.left)
        if(key > node.key):
            node.right = self.__private__put(key, val, node.right)
        if(key == node.key):
            node.val = val
            return node
        if(self.__private__getP(node) < self.__private__getP(node.left)):
            self.__private__rotateR(node)
        if(self.__private__getP(node) < self.__private__getP(node.right)):
            self.__private__rotateL(node)
        node.size = self.getsize(node.left) + self.getsize(node.right) + 1
        return node

    def __getitem__(self, key):
        return self.__private__get(key, self.root)

    def __private__get(self, key, node):
        if(node == None):
            return None
        if(key < node.key):
            return self.__private__get(key, node.left)
        if(key > node.key):
            return self.__private__get(key, node.right) 
        if(key == node.key):
            return node.val

    def __delitem__(self, key):
        self.root = self.__private__delete(key, self.root)
        return

    def __private__delete(self, key, node):
        if(node.left == None):
            return node.right
        if(node.right == None):
            return node.left
        if(node.left.key > node.right.key):
            self.__private__RotateR(node)
            
    def __len__(self):
        return self.__private__getsize(self.root)

    def __contains__(self, key):
        return self[key] != None
    
    def __bool__(self):
        return self.__private__getsize(self.root) == 0

    def min(self):
        pass

    def max(self):
        pass

    def rank(self, key):
        pass

    def select(self, rank):
        pass
    
    def size(self):
        return getsize(self.root)

    def __iter__(self):
        pass

if __name__ == '__main__':
    st = Treap()
    from sys import stdin
    for lines in stdin:
        (key, val) = lines.split(' ')
        st[key]=val
    for s in st:
        print("{} {}".format(s, st.get(s)))


