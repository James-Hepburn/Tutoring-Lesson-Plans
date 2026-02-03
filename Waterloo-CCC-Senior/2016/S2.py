# ccc senior s2 2016 - https://dmoj.ca/problem/ccc16s2

question = int (input())
n = int (input())
dmojistan = [int (i) for i in input().split()]
pegland = [int (i) for i in input().split()]

dmojistan.sort()
pegland.sort()

if question == 2:
  pegland = pegland[::-1]

speed = 0
for i in range (n):
  speed += max (dmojistan[i], pegland[i])
print (speed)
