LinkedListPalindrome: LinkedListPalindrome.o
	g++ -g -o LinkedListPalindrome.exe LinkedListPalindrome.o -pthread    

LinkedListPalindrome.o: LinkedListPalindrome/LinkedListPalindrome.cpp
	g++ -g  -c -pthread LinkedListPalindrome/LinkedListPalindrome.cpp
