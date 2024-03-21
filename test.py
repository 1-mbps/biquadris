from typing import List, Tuple

def rotate_cl(p: Tuple[int, int]) -> Tuple[int, int]:
    return p[1], -p[0]

def rotate_ccl(p: Tuple[int, int]) -> Tuple[int, int]:
    return -p[1], p[0]

def convert(p):
    return (-p[1], p[0])

# Assuming xy_coords is a list of tuples
shapes = {
    'J': [(-1, 0), (-1, -1), (0, -1), (1, -1)],
    'L': [(-1, -1), (0, -1), (1, -1), (1, 0)],
    'O': [(0, 0), (-1, 0), (0, -1), (-1, -1)],
    'S': [(0, 0), (1, 0), (0, -1), (-1, -1)],
    'Z': [(-1, 0), (0, 0), (0, -1), (1, -1)],
    'T': [(-1, 0), (0, 0), (1, 0), (0, -1)]
}
clockwise = True  # Example value

rotations = {}

for k in shapes:
    temp = [shapes[k]]
    rot = shapes[k]
    for i in range(3):
        rot = [rotate_cl(j) for j in rot]
        temp.append(rot)
    # for i in range(len(temp)):
    #     for j in range(i):
    #         temp[i][j] = convert(temp[i][j])
    rotations[k] = temp

def replace(s):
    s = str(s)
    for c in ['[', '(']:
        s = s.replace(c, '{')
    for c in [']', ')']:
        s = s.replace(c, '}')
    return s

for x in rotations:
    print(f"case '{x}':")
    print("xy_coords = "+replace([convert(i) for i in shapes[x]])+';')
    print("rotations = {")
    for r in rotations[x]:
        print(replace([convert(i) for i in r])+',')
    print("};")
    print("break;")
