import random
t = 1
f=open('testcase.in', 'w')
f.write(str(t))
f.write('\n')

for i in range(t):
    n = 100000
    f.write(str(n))
    f.write('\n')
    for j in range(n-1):
        f.write("1 1\n")

    f.write("100000 ")
    for j in range(n):
        f.write("1 ")

    f.write("\n")
f.close()
