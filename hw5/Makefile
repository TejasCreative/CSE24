all:
	g++ -I. main.cpp -o add

.PHONY: test

test:
	g++ -I. test.cpp -o test
	clear && echo "Running Tests:" && ./test

clean:
	rm -f add
	rm -f test
