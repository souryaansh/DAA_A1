from igraph import *
import time

'''
taking input
'''
numnodesedges = input().split(" ")
numnodesedges = [int(x) for x in numnodesedges]

'''storing graph'''
g = Graph(numnodesedges[0],directed=True)


for i in  range(0,numnodesedges[1]):
    edge = input().split(" ");
    edge = [int(x) for x in edge]
    g.add_edges([(edge)])


scc = g.clusters(mode=STRONG)
colors = list(RainbowPalette(len(scc)))
colorlabels=[]
count =0

'''assigning colours to each scc'''
for i in range(0,numnodesedges[0]):
    for j in range(0,len(scc)):
        if i in scc[j]:
            colorlabels.append(colors[j])
            break
g.vs['color']=colorlabels

'''plotting'''
print("Plotting.........")

plot(g,mark_groups=scc)