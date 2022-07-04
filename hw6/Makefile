all:
	g++ -I. main.cpp -o replace

.PHONY: test

test:
	g++ -I. test.cpp -o test
	clear && echo "Running Tests:" && ./test

clean:
	rm -f replace
	rm -f test
