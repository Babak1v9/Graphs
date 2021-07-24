# Graphs

Project from my first year at FHTW. This program should solve the TSP (Travelling salesman problem) with two different alogrithms:
* Enumeration
* Nearest Neighbour Heuristic

## Usage

./TSP.exe -n|-e filename

Either choose -n for Nearest neighbour heuristic or -e for Enumeration, then specify the file name.
Feel free to add your own with some different Graphs.

## How it works

The program is reading n two-dimensional nodes which represant cities from the specified file.
It then builds an adjacency matrix of an complete, unconnected, weighted graph.
On the basis of the matrix, the TSP will then be solved.

Output of the program:
* Adjadcency matrix
* Order of visited nodes (cities)
* Total length of the trip (NNH) or the best trip (enumeration)
* CPU Time

## Contributers
* Sven P.
