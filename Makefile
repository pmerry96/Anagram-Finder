default: 
	echo usage: ./anagram

all:
	g++ -o anagrams -std=c++11 main.cpp

run:
	./anagrams

clean: 
	rm -f anagrams
