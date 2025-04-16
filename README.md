# Forward-Kinematics

1. The robot has four links, each connected using a revolute pair ( like a door hinge)
2. The axis of each joint is perpendicular to the previous joint. 
3. The lengths of the links -’ L’ is 1m each.




![Screenshot from 2025-04-16 14-06-19](https://github.com/user-attachments/assets/523a81ba-0aa0-42c8-aa6e-7f1e31b1278f)
## 🧮 Forward Kinematics Explanation

Each joint introduces a **rotation** followed by a **translation** along the X-axis (link direction). These are represented using `4×4` homogeneous transformation matrices.

The overall transformation from the base to the end-effector is:

