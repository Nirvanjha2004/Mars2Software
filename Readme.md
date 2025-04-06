# 🚀 Rover Brick Missions

This comprehensive project is a collection of multiple problems involving the Mars rover "Brick," designed to perform a variety of tasks such as obstacle detection, position correction, encrypted communication decoding, 3D rotation conversion, distance estimation using image processing, and simulation of rover movement on a virtual map.

---

## 📋 Overview

These problems simulate real-world challenges faced by Mars rovers and taught me a great deal about file handling, camera-based distance estimation, coordinate transformations, obstacle detection, and more — all through coding.

---

## 🔍 Mission Details

### 1. Arena Obstacle Mapping (C++)

**Task:**
Read a .txt file that specifies obstacle positions in cardinal directions and construct an n x n matrix where obstacles are marked as 0 and safe positions as 1.

**Concepts Used:**
- File I/O
- Matrix representation of space
- Coordinate transformations
- Grid center as origin

**Challenge:**
Handling directional movements (North, East, South, West) and converting them to matrix indices correctly.

#### 📚 Learning Experience

Through this project, I learned how to:

- Parse input from `.txt` files in C++
- Use dynamic 2D vectors to simulate a matrix/grid
- Work with coordinate transformations in a grid system
- Think from a robotics perspective (reference frames, movement limitations)
- Handle file reading, matrix setup, and visual debugging in C++

#### 📐 Equations, Theorems & Sketches

##### ➕ Coordinate Reference Transformation

To simulate Brick starting from the **center**, we used the formula:

gridSize = 2 × max(distance) + 1 startX = startY = max(distance)

This ensured all directions (N, E, S, W) fit within bounds when converted to grid coordinates.

**Sketch (conceptual)**:

Obstacle coordinates like `2 3 0 3` → mark:
- 2 steps north: `arena[x - 2][y] = 0`
- 3 steps east: `arena[x][y + 3] = 0`
- etc.

#### ⚠️ Challenges Faced

- Understanding how to convert directional distances into 2D grid coordinates.
- Creating a flexible grid that can dynamically adjust based on input data.
- Making sure edge cases (like obstacles beyond expected range) don't crash the program.
- Properly visualizing the arena and ensuring obstacle markings matched expected locations.

#### 💡 My Approach

1. **Read obstacle data** from a `.txt` file (each line containing: N E S W)
2. **Calculate max distance** from any direction to determine the grid size.
3. **Initialize a 2D matrix** with all safe positions (`1`)
4. **Convert obstacle directions** to grid positions based on origin at center.
5. **Mark obstacles as `0`** in the matrix.
6. **Print the grid** for visualization.

### 2. Camera-Based Position Adjustment (C++)

**Task:**
Correct the rover's position based on the detected marker coordinates from its camera to ensure it performs a 360-degree turn exactly over the marker.

**Concepts Used:**
- Vector math
- Coordinate system shift (new reference frame)
- Camera position correction (Z-offset handling)

**Challenge:**
Translating camera frame coordinates to rover frame.

### 3. Message Decryption (C++)

**Task:**
Decrypt a Mars message where each letter was shifted by its position index.

**Concepts Used:**
- ASCII manipulation
- Uppercase conversion
- Reverse Caesar cipher with variable shifts

**Challenge:**
Handling wrap-around of alphabets and maintaining uniform uppercase formatting.

### 4. 3D Rotation System Conversion (C++)

**Task:**
Convert traditional 3D rotation (Euler angles) to 4D Martian rotation using Quaternions to avoid Gimbal lock.

**Concepts Used:**
- Quaternion mathematics
- Euler to Quaternion conversion

**Challenge:**
Understanding the math behind quaternion formation and applying it to simplify orientation.

### 5. Distance Estimation Using Pin-Hole Camera Model (Python)

**Task:**
Detect an arrow in an image and estimate its distance from the rover using the pin-hole camera formula.

**Equation:**
Distance = (Real Width * Focal Length) / Perceived Width

**Challenge:**
- Calibrating focal length using FOV and sensor size.
- Accurately finding perceived width from image bounding box.

**Tools Used:**
- OpenCV
- NumPy

### 6. Rover System Health Check (Bash Script)

**Task:**
Check if battery level is above 20% and whether there's internet connectivity using ping. Log the status.

**Concepts Used:**
- Random number generation in bash
- Network check using ping
- Logging and conditional exit

**Challenge:**
Handling both conditions robustly in a shell script.

---

## 🔧 Additional Terminal Tasks (Linux Commands)

**Covered Commands:**

- Directory creation: `mkdir`, `cd`
- File creation & renaming: `touch`, `mv`
- File listing with patterns: `ls *.log`
- Content viewing: `cat`, `grep`, `wc -l`
- System info: `date`, `top`, `shutdown`
- File/folder deletion: `rm`, `rm -r`

These commands helped me interact with the Linux filesystem efficiently, mimicking rover log analysis.

---

## 📖 Resources Used

- [GeeksforGeeks – Vectors in C++](https://www.geeksforgeeks.org/vector-in-cpp-stl/)
- [cplusplus.com – File I/O](https://cplusplus.com/doc/tutorial/files/)
- [StackOverflow – Coordinate grid logic](https://stackoverflow.com)
- Mars Rover movement constraints (given in the problem)
- OpenCV Documentation
- StackOverflow for Bash scripting help
- Quaternion tutorials: Wikipedia
- Basic image processing with OpenCV

---

## 🧠 Summary of Learnings

- Handling real-world inspired robotic challenges through code
- Gained deeper understanding of camera models and coordinate frames
- Understood the power of scripting and automation
- Enhanced knowledge of 3D mathematics and quaternion logic

---

## ⚙️ How to Run

- **For C++ code:** Use any C++ compiler like g++, or onlineGDB
- **For Python:** Ensure OpenCV is installed, then run using `python filename.py`
- **For Bash:** Use a Linux terminal or Windows with WSL/Terminal emulator
