# Forward-Kinematics

1. The robot has four links, each connected using a revolute pair ( like a door hinge)
2. The axis of each joint is perpendicular to the previous joint. 
3. The lengths of the links -’ L’ is 1m each.




![Screenshot from 2025-04-16 14-06-19](https://github.com/user-attachments/assets/523a81ba-0aa0-42c8-aa6e-7f1e31b1278f)
## Forward Kinematics Explanation
Each joint introduces a **rotation** followed by a **translation** along the X-axis (link direction). These are represented using `4×4` homogeneous transformation matrices.
The overall transformation from the base to the end-effector is: T = T₁ · T₂ · T₃ · T₄
Where:
- `T₁ = Rz(j₁) · Transₓ(L)`
- `T₂ = Ry(j₂) · Transₓ(L)`
- `T₃ = Rx(j₃) · Transₓ(L)`
- `T₄ = Ry(j₄) · Transₓ(L)`

Each `R` is a rotation matrix about the respective axis, and `Transₓ(L)` is a translation along the X-axis by length `L`.

To compute the end-effector position:

[ x ] [ 0 ] [ y ] = T · [ 0 ] [ z ] [ 0 ] [ 1 ] [ 1 ]

Then extract the final `(x, y, z)` position from the resulting vector.

```markdown
$$ T = T_1 \cdot T_2 \cdot T_3 \cdot T_4 $$


