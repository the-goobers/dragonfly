all:
	clang++ -std=c++20 $(shell find . -type f -name "*.cpp") -o build/program
