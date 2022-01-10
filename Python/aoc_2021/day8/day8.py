import sys

def Substring(a, b):
    count = str()
    for char in a:
        if char in b:
            count += char
    return count

filepath = sys.argv[1] if len(sys.argv)>1 else 'in.txt'

X = [line for line in open(filepath)]

for x in X:
    S, C = x.split(' | ')
    S = sorted(S.split(), key=len)
    C = C.split()
    for s in S:
        s = ''.join(sorted(s))
    for c in C:
        c = ''.join(sorted(c))
    setup = dict({S[0]:1, S[1]:7, S[2]:4, S[9]:8})
    fives = [S[3], S[4], S[5]]
    sixes = [S[6], S[7], S[8]]
    for i in range(len(sixes)):
        if len(Substring(S[0], sixes[i])) == 1:
            setup[sixes[i]] = 6
            del(sixes[i])
            break
    for i in range(len(sixes)):
        if len(Substring(S[2], sixes[i])) == 4:
            setup[sixes[i]] = 9 
            del(sixes[i])
            break
    setup[sixes[0]] = 0 
    for i in range(len(fives)):
        if len(Substring(S[0], fives[i])) == 2:
            setup[fives[i]] = 3
            del(fives[i])
            break
    for i in range(len(fives)):
        if len(Substring(S[2], fives[i])) == 2:
            setup[fives[i]] = 2
            del(fives[i])
            break
    setup[fives[0]] = 5
    for c in C:
        print(setup[c])
    
