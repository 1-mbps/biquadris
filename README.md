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

## UML diagram

`Block` is a concrete subclass. It has a composition relationship with Board.
`Board` is an abstract base class. It has two subclasses, `BasicBoard` and `Decorator`.

Note that abstract base class = never instantiated. Make a board using the `BasicBoard` class. This allows us to add decorators.

`Decorator` has a subclass for each special action and _probably_ each level.
Haven't worked out how levels will work yet but probably like this (discuss?)

`Board` also has a class `GraphicsDisplay` as an observer.

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

Blocks are stored as smart pointers in a vector `blocks`. Storing blocks will be useful in addressing this from the PDF


>Question: How could you design your system (or modify your existing design) to allow for some generated blocks to disappear from the screen if not cleared before 10 more blocks have fallen? Could the generation of such blocks be easily confined to more advanced levels?

Linked list of special action decorators?

## Blocks
Rotation:
- Clockwise: lower right corner takes place of lower left corner
- Counterclockwise: top left corner replaces lower left corner

### Design

The Block class has a composition relationship with the Board class. It has no identity outside of a Board.

This design maximizes cohesion and minimizes coupling by ensuring that **all logic for editing blocks is done within the Block class**. If a Block is rotated or moved, the Block is solely responsible for calculating its new position. The Board is only involved at the end of the process, when it receives the block's new coordinates.

This approach has several advantages. For one, it allows us to write any function for editing a block - including resizing or deleting - without ever having to touch the Board class. It also ensures that the Block class is completely encapsulated, since no other routine can interfere with its logic.

### Rotation

Used this for rotations:
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

## Testing

Things to test:
- Clearing multiple rows at once
- Rotate every block every possible combination
- Do on all levels, all special actions

