all:
	g++ -I. main.cpp -o app

.PHONY: test

test:
	g++ -I. test.cpp -o test
	clear && ./test || true

clean:
	rm -f app
	rm -f test
