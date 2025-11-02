#!/bin/bash

echo "=== Starting Build Process ==="

echo "Compiling matrix.cpp..."
g++ -c -I./include -Wall -Wextra -std=c++11 ./src/matrix.cpp -o ./obj/matrix.o
if [ $? -eq 0 ]; then
	echo "matrix.cpp compiled successfully"
else
	echo "Error compiling matrix.cpp"
	exit 1
fi

echo "Compiling main.cpp..."
g++ -c -I./include -Wall -Wextra -std=c++11 ./src/main.cpp -o ./obj/main.o
if [ $? -eq 0 ]; then
	echo "main.cpp compiled successfully"
else
	echo "Error compiling main.cpp"
	exit 1
fi

echo "Linking object files..."
g++ obj/matrix.o ./obj/main.o -o ./bin/matrix_program
if [ $? -eq 0 ]; then
	echo "Program linked successfully"
else
	echo "Error linking program"
	exit 1
fi

echo "=== Build Completed Successfully ==="
echo "Executable: bin/matrix_program"
