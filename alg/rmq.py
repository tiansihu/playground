#!/usr/bin/env python

import math

def pre_process(array):
    length = len(array)
    p = int(math.log(length, 2)) + 1
    
    ret = []
    for i in range(length):
        ret.append([-1] * p)

    for i in range(length):
        ret[i][0] = array[i]

    return ret

def get_value(preproc, start, power):
    if preproc[start][power] < 0:
        preproc[start][power] = max(get_value(preproc, start, power - 1), get_value(preproc, start + 2 **(power - 1), power - 1))

    return preproc[start][power]
        
def rmq(preproc, start, length):
    if length == 1:
        return preproc[start][0]

    k = int(math.log(length, 2)) 
    return max(get_value(preproc, start, k), get_value(preproc, start + length - 2 ** k, k))

if __name__ == "__main__":
    array = [4, 1, 3, 7, 81, 1, 1, 5, 7];

    preproc = pre_process(array)

    length = len(array)

    for i in range(length):
        for j in range(1, length - i + 1):
            r = rmq(preproc, i, j)
            print "%d:%d %d" % (i, j, r)

