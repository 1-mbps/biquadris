# Biquadris

Try to work on your own branch to avoid merge conflicts.

Steps for pushing to the repo:
```
git add [file you want to add]
```
Once you're done adding everything, write a commit message
```
git commit -m "commit message"
```
and then push
```
git push origin [branch name]
```
If pushing to main, `git push origin main`

Run `git branch [branch_name]` to create a new branch and `git checkout [other branch]` to switch to another branch. Note that you have to push all your changes first before checking out otherwise everything will get lost. I learned this the hard way over co-op

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

### Implementation

We have an 18x11 char array `grid`. Each entry in the grid is either a character (S, I, J, whatever else) corresponding to a block or a space.

Note that blocks are not stored anywhere on the grid. Once the player is done editing it (moving left and right or rotating) and has dropped it, its coordinates are marked on the grid and the block object itself goes out of scope, which automatically frees it.

## Blocks
Rotation:
- Clockwise: lower right corner takes place of lower left corner
- Counterclockwise: top left corner replaces lower left corner

### Rotation algorithm

Used this for rotation algorithm:
https://en.wikipedia.org/wiki/Rotation_of_axes_in_two_dimensions



<!-- ### Dropping

Store the states of each cell in a dictionary `grid_dict`.

After rotation is confirmed, keep track of coordinates of the block's lower boundary.

Then, iteratively lower the block.
If every cell in the block's lower boundary is free (according to the dictionary), try to keep going. If not, stop.
Then update `grid_dict` to show the block's final coordinates as being filled.

Also, keep track of how many blocks in each row are full.
After a block is dropped, add the width of the block in each row.
if all 11 columns full, clear row:
-go over every block
-recursively go over every cell and change coordinates accordingly

or just loop over `grid_dict`, making the state of each cell equal to the state of what's above -->

