cnt = 1
mp = {}
name11 = ['a', 'b', 'c', 'e']
name22 = ['b', 'a', 'd', 'd']
name1 = []
name2 = []
for i in name11:
    if i in mp.keys():
        name1.append(mp[i])
    else:
        mp[i] = cnt
        name1.append(cnt)
        cnt += 1
for i in name22:
    if i in mp.keys():
        name2.append(mp[i])
    else:
        mp[i] = cnt
        name2.append(cnt)
        cnt += 1
cnt -= 1
print(cnt)    # 5
print(name1)  # [1, 2, 3, 4]
print(name2)  # [2, 1, 5, 5]

# Call in main() if define init function
fa = [i for i in range(cnt + 1)]
rank = [0] * (cnt + 1)

def find(x): # one line for unite-find
    # return x==fa[x]?x:fa[x]=find(fa[x])
    if x == fa[x]:
        return x
    else:
        fa[x] = find(fa[x])
        return fa[x]

def unite(x, y):
    x, y = find(x), find(y)
    # if x!=y:
    #     fa[y]=x
    if rank[x] > rank[y]:
        fa[y] = x
    else:
        fa[x] = y
        if rank[x] == rank[y]:
            rank[y] += 1

for i, j in zip(name1, name2):
    # print(i, j)
    unite(i, j)

# dont use set() here
print(sum([i==fa[i] for i in range(1, cnt+1)]))