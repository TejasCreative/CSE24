all:
	g++ -I. main.cpp -o calc

.PHONY: test_add test_avg test_max test_min test_main test

test_add:
	g++ -I. test_add.cpp -o test_add
	clear && echo "Testing addUp function:" && ./test_add --output=color
	@rm -f test_add

test_avg:
	g++ -I. test_avg.cpp -o test_avg
	clear && echo "Testing average function:" && ./test_avg --output=color
	@rm -f test_avg

test_max:
	g++ -I. test_max.cpp -o test_max
	clear && echo "Testing max function:" && ./test_max --output=color
	@rm -f test_max

test_min:
	g++ -I. test_min.cpp -o test_min
	clear && echo "Testing min function:" && ./test_min --output=color
	@rm -f test_min

test_main:
	g++ -I. test_main.cpp -o test_main
	clear && echo "Testing main.cpp" && ./test_main --output=color
	@rm -f test_main

test:
	g++ -I. test.cpp -o test_all
	clear && echo "Running all tests:" && ./test_all --output=color
	@rm -f test_all

clean:
	rm -f calc
	rm -f test_add
	rm -f test_avg
	rm -f test_max
	rm -f test_min
	rm -f test_main
	rm -f test_all
