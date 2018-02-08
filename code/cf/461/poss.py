#!/usr/bin/env python
# coding=utf-8

import os
os.getcwd()
f = open('./out','r')
qq = []
for i in f:
    i = i[:-1]
    qq.append(i)
    qq.append(',')
print(qq)
f.close()

f = open('./oo','w')
for i in qq:
    f.write(i)
f.close()
