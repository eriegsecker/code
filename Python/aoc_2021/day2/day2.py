import sys

filepath = sys.argv[1] if len(sys.argv)>1 else 'in.txt'

position1 = 0;
depth1 = 0;
position2 = 0;
depth2 = 0;
aim = 0;
for line in open(filepath):
    direction, length = line.split()
    length = int(length)
    if direction == 'forward':
        position1 += length
        position2 += length
        depth2 += length*aim
    elif direction == 'up':
        depth1 -= length
        aim -= length
    else:
        depth1 += length
        aim += length
print(position1*depth1)
print(position2*depth2)
