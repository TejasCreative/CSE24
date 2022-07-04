all: main.cpp
	g++ main.cpp -o app

.PHONY: test
test: main.cpp test.cpp
	g++ test.cpp -o test 
	clear && ./test --output=color

clean:
	rm -f app test