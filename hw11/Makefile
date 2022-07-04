all:
	g++ -o app -I. main.cpp

.PHONY: test

test:
	g++ -o test test.cpp 
	clear && echo "Running Tests:" && ./test || true

clean:
	rm -f test
	rm -f app
