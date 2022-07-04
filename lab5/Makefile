all:
	g++ -I. main.cpp -o inside

.PHONY: test meta_test

test:
	g++ -I. test.cpp -o test
	clear && echo "Running tests:" && ./test --output=color || true

meta_test:
	g++ -I. meta_test.cpp -o meta_test
	clear && echo "Testing your tests:" && ./meta_test --output=color
clean:
	rm -f inside
	rm -f test
	rm -f meta_test