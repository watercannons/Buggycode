#!/usr/bin/python2

# Stolen from Rodrigo Tocalini

import sys as s

def fusion_sort(left, right=[]):
    '''Sorts a list by dividing it into sublists and
    sorting the sublists when they are small enough
    then merging them'''

    if (len(left) <= 1 and len(right) <= 1):
        return fuse(left, right)

    l = fusion_sort(left[0:len(left)/2-1:1], left[len(left)/2-1::1])
    if len(right) == 0:
        return l
   
    r = fusion_sort(right[0:len(right)/2-1:1], right[len(right)/2-1::1])
    return fuse(l,r)
    
def fuse(left, right):
    '''Fuse two sublists together'''
    list = []
    ri = 0
    li = 0 
    while (li < len(left) and ri < len(right)):
        if left[li] > right[ri]:
            list.append(left[li])
            li += 1
        else:
            list.append(right[ri])
            ri += 1

    if li < len(left):
        return list + left[li:]
    else:
        return list + right[ri:]

print(fusion_sort([1,2,4,5,2,4,1,43,5,43,43]))