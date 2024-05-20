<h1 align="center">Sandbox App Plugin - Picture Encoder</h1>
<h2>Description</h2>
<b>Sandbox App Plugin - Picture Encoder</b> is an internal plugin for my <a href="https://github.com/MariaChemerys/Sandbox_Clone_iOS">iOS Sandbox Clone app</a> which contains a gallery of pictures that can be colored by numbers. Since the pictures consisted of colored squares, it was necessary to know the coordinates of each color to construct them. Thus, the purpose of this plugin was to <strong><em>identify the coordinates of squares of each color, extract them and arrange in a systematic way (create a new .txt file that contained a string where this information was encoded)</strong></em>.<br>

<h2>Picture Encoding Algorithm Used in the Plugin</h2>
1. The function <b>readNumbersFromFile</b> reads a text file containing rows of integers separated by commas. Each integer represents a colored square in the picture. The function stores these integers in a 2D vector. <br>
2. The function <b>convertCoordinatesToStringArray</b> processes the 2D vector to generate a string array where each string at index i contains the coordinates (row, column) of all occurrences of the integer i in the grid. This effectively maps each color (integer) to its coordinates in the grid. <br>
3. The function <b>writeStringArrayToFile</b> writes the string array to a specified output file. Each string is written on a new line, followed by an asterisk ('*'). Empty strings are represented by 'n'. <br>

<h2>Short Summary of the Encoding Algorithm</h2>
The program reads a grid of integers from a file (representing colored squares), converts the grid into a list of coordinates for each number, and writes these coordinates to an output file. Each integer's coordinates are stored in a string array where the index corresponds to the integer value, thus encoding the positions of each color in the grid.  <br>

<h2>Technologies Used</h2>
<p align="left">
  <img src="https://img.shields.io/badge/Visual%20Studio-7509b0?style=for-the-badge" alt="Visual Studio" />
  <img src="https://img.shields.io/badge/C++-24b8f2?style=for-the-badge" alt="C++" />
</p>
