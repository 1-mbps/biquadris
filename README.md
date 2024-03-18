# Biquadris

## Board
11 columns, 15 rows, with 3 extra before first block so total 18

Specifications:

```
Level: X
Score: X
-----------
(empty row 1)
(empty row 2)
(empty row 3)
(block to be dropped)
(rows until end of 15)
-----------
Next:
  L
LLL
```

For example:
```
Level: 1
Score: 0
-----------



TTT
 T








OO
OO
OO
OOIIII
-----------
Next:
  L
LLL
```

There are 18 rows between the two dashed lines.

## Blocks
Rotation:
- Clockwise: lower right corner takes place of lower left corner
- Counterclockwise: top left corner replaces lower left corner

### Rotation algorithm

Idea: store blocks as an adjacency list.
When rotating:

Clockwise - from the lower right corner, move
neighbor to the left -> top
on top -> right
to the right -> below
below -> to the left

Then do this recursively on each neighbor.
If ANY number is out of bounds, the rotation is invalid.

Represent blocks as a class.

