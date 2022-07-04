all:
	g++ encode.cpp -I. -o encode 
	g++ decode.cpp -I. -o decode

.PHONY: test

test:
	g++ -I. test.cpp -o test
	clear && echo "Running Tests:" && ./test --output=color || true
clean:
	rm -f decode
	rm -f encode
	rm -f test
