all:
	g++ insert.cpp -o insert
	g++ erase.cpp -o erase
	g++ replace.cpp -o replace

insert: insert.cpp
	g++ insert -o insert

erase: erase.cpp
	g++ erase.cpp -o erase

replace: replace.cpp
	g++ replace -o replace

.PHONY: test_all test_insert test_erase test_replace
test_all:
	g++ test_all.cpp -o ./test_all 
	clear && echo "Running All Tests:" && ./test_all --output=color

test_insert:
	g++ test_insert.cpp -o ./test_insert 
	clear && echo "Testing Insert:" && ./test_insert --output=color

test_erase:
	g++ test_erase.cpp -o ./test_erase 
	clear && echo "Testing Erase:" && ./test_erase --output=color

test_replace:
	g++ test_replace.cpp -o ./test_replace 
	clear && echo "Testing Replace:" && ./test_replace --output=color

clean:
	rm -f insert
	rm -f erase
	rm -f replace
	rm -f test_insert
	rm -f test_erase
	rm -f test_replace
	rm -f test_all