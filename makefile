CC=c++
FLAGS=-Wall -Wextra -Wpedantic -g
OUTPUT11=a
OUTPUT17=${OUTPUT11}
all: cpp11
	${CC} demo.cpp ${FLAGS} -std=c++17 -o ${OUTPUT17}

cpp11:
	${CC} demo.cpp ${FLAGS} -std=c++11 -o ${OUTPUT17}
