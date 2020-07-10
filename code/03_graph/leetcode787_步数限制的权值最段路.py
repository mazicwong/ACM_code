#!/usr/bin/env python
# coding=utf-8

# https://leetcode.com/problems/cheapest-flights-within-k-stops/discuss/115541/JavaPython-Priority-Queue-Solution
# Idea
# It happen to be the same idea of Dijkstra's algorithm, but we need to keep the path

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        # 步数限制的权值最短路
        # delete vis[] in dijkstra
        f = collections.defaultdict(dict)
        for u,v,w in flights:
            f[u][v] = w
        heap = [(0, src, K+1)]
        while(heap):
            w,to,step = heapq.heappop(heap)
            if to == dst:
                return w
            if step>0:
                for v in f[to]:
                    heapq.heappush(heap, (w + f[to][v], v, step-1))
        return -1
