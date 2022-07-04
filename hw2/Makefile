all:
	g++ -o app main.cpp
run:
	g++ -o app main.cpp && clear && ./app

test: test.cpp main.cpp
	g++ -o test test.cpp && clear && ./test

clean:
	rm -f app test