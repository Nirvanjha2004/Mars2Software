# 🚀 Rover Brick: Obstacle Detection Arena Map (C++)

This project simulates the mapping of an arena for the Mars rover named **Brick**, which moves like a king in chess — only in four cardinal directions (North, East, South, West). Based on obstacle coordinates provided in a `.txt` file, we dynamically build a grid marking safe and blocked positions.

---

## 📚 Learning Experience

Through this project, I learned how to:

- Parse input from `.txt` files in C++
- Use dynamic 2D vectors to simulate a matrix/grid
- Work with coordinate transformations in a grid system
- Think from a robotics perspective (reference frames, movement limitations)
- Handle file reading, matrix setup, and visual debugging in C++

---

## 📐 Equations, Theorems & Sketches

### ➕ Coordinate Reference Transformation

To simulate Brick starting from the **center**, we used the formula:

gridSize = 2 × max(distance) + 1 startX = startY = max(distance)

This ensured all directions (N, E, S, W) fit within bounds when converted to grid coordinates.

**Sketch (conceptual)**:

Obstacle coordinates like `2 3 0 3` → mark:
- 2 steps north: `arena[x - 2][y] = 0`
- 3 steps east: `arena[x][y + 3] = 0`
- etc.

---

## ⚠️ Challenges Faced

- Understanding how to convert directional distances into 2D grid coordinates.
- Creating a flexible grid that can dynamically adjust based on input data.
- Making sure edge cases (like obstacles beyond expected range) don’t crash the program.
- Properly visualizing the arena and ensuring obstacle markings matched expected locations.

---

## 💡 My Approach

1. **Read obstacle data** from a `.txt` file (each line containing: N E S W)
2. **Calculate max distance** from any direction to determine the grid size.
3. **Initialize a 2D matrix** with all safe positions (`1`)
4. **Convert obstacle directions** to grid positions based on origin at center.
5. **Mark obstacles as `0`** in the matrix.
6. **Print the grid** for visualization.

---

## 📖 Resources Used

- [GeeksforGeeks – Vectors in C++](https://www.geeksforgeeks.org/vector-in-cpp-stl/)
- [cplusplus.com – File I/O](https://cplusplus.com/doc/tutorial/files/)
- [StackOverflow – Coordinate grid logic](https://stackoverflow.com)
- Mars Rover movement constraints (given in the problem)
---
