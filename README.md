# fdf
Fil De Fer, iron wire, commonly known as wireframe. My first project in the world of computer graphics.

Important part of the project was validating provided 'maps' for consistent input. The trickiest part was adhering to School 42 C norms (small size of function, forbiddance of 'for' loop) when coding Bresenham's line algorithm.

This project requires School 42 homebrew minilibX library (included) and was only tested in macOS El Capitan / Sierra environment.

Please, compile using Makefile (type 'make' in console while in project folder)
./test_maps folder provides some examples to test on

**Example 1. It will launch wireframe logo of School 42**
> ./fdf /test_maps/42.fdf

**Example 2. Same logo but with color overriden to red (last 3 parameters require int from 0 to 255)**
> ./fdf /test_maps/42.fdf 255 0 0
 
**Controls:**
- **/** toggles legend
- **NUM_/** toggles diagonal lines of wireframe
- **NUM_*** toggles ortho and parallel projections
- **NUM_4 / NUM_6** rotations on Y axis
- **NUM_2 / NUM_8** rotations on X axis
- **NUM_7 / NUM_9** rotations on Z axis
- **NUM_1 / NUM_3** scaling
- **ESC** exits the program
