#!/usr/bin/env python
# coding=utf-8
t=int(input())
for i in range(t):
    x=int(input())
    a=int(input())
    y=int(input())
    b=int(input())
    if(x == pow(y,b/a)):
        print("Yes")
    else:
        print("No")

