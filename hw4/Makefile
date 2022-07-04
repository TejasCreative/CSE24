all: main.cpp
	g++ main.cpp -o seglen

.PHONY: test
test:
	g++ test.cpp -o test
	clear && echo "Running Tests:" && ./test --output=color

clean:
	rm -f seglen
	rm -f test
