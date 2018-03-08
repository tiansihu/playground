#!/usr/bin/env python

import math

class RMQ:
    def __init__(self, array):
        length = len(array)
        p = int(math.log(length, 2)) + 1
    
        self.preproc = []
        for i in range(length):
            self.preproc.append([-1] * p)

        for i in range(length):
            self.preproc[i][0] = array[i]

    def get_value(self, start, power):
        if self.preproc[start][power] < 0:
            self.preproc[start][power] = max(self.get_value(start, power - 1), 
                    self.get_value(start + 2 **(power - 1), power - 1))
        return self.preproc[start][power]
        
    def rmq(self, start, length):
        if length == 1:
            return self.preproc[start][0]

        k = int(math.log(length, 2)) 
        return max(self.get_value(start, k), self.get_value(start + length - 2 ** k, k))

if __name__ == "__main__":
    array = [4, 1, 3, 7, 81, 1, 1, 5, 7];

    rmq = RMQ(array)

    length = len(array)

    for i in range(length):
        for j in range(1, length - i + 1):
            r = rmq.rmq(i, j)
            print "%d:%d %d" % (i, j, r)

