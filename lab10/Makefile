all:
	g++ -I. main.cpp -o play
	
.PHONY: test

test:
	g++ -I. test.cpp -o test
	clear && ./test --output=color || true

clean:
	rm -f play
	rm -r test
