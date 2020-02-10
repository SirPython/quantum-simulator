Quantim code specs:

- Code is read left to right as opposed to top to bottom
- Each line denotes operations on a new quantum register
- Gates that operate on more than one register use parentheses () with numbers
inside to indicate which other qubit is being affected (0-index, from the top)
- In running, gates that line up "vertically" will be run "simultaneously."
Vertically as in: two gates that are both the nth gate in their row will be
treated as running as the same time -- except measurement.
- The first line of the source file must indicate the number of qubit registers
being used.
- If a qubit is being affected by another register's binary gate, simply
leave an _ instead of a command in the same "column"

Gates are as follows:
H - hadamard
X - pauli x
Y - pauli y
Z - pauli z
C? - controlled pauli gate (X, Y, or Z)