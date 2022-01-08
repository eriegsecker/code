input = "in.txt"

ans1 = 0
ans2 = 0
XS = [int(x) for x in open(input)]
for i in range(len(XS)):
    if i >= 1 and XS[i] > XS[i-1]:
        ans1 += 1
    if i >= 3 and XS[i] > XS[i-3]:
        ans2 += 1

print("part 1 answer:", ans1)
print("part 2 answer:", ans2)
