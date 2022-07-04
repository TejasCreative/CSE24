all:
	g++ main.cpp -o filter

.PHONY: test

test: main.cpp
	g++ test.cpp -o test
	clear && echo "Running Tests:" && ./test --output=color

clean:
	rm -f filter
