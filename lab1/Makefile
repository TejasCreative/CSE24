all: f2m.cpp m2f.cpp f2c.cpp c2f.cpp slope.cpp
	g++ f2m.cpp -o f2m
	g++ m2f.cpp -o m2f
	g++ f2c.cpp -o f2c
	g++ c2f.cpp -o c2f
	g++ slope.cpp -o slope
	g++ length.cpp -o len

f2m: f2m.cpp
	g++ f2m.cpp -o f2m

m2f: m2f.cpp
	g++ m2f.cpp -o m2f

f2c: f2c.cpp
	g++ f2c.cpp -o f2c

c2f: c2f.cpp
	g++ c2f.cpp -o c2f

slope: slope.cpp
	g++ slope.cpp -o slope

len: length.cpp
	g++ length.cpp -o len

test: test.cpp f2m.cpp m2f.cpp f2c.cpp c2f.cpp
	g++ test.cpp -o test
	clear && echo "Running Tests:" && ./test --output=color
clean:
	rm -f f2m
	rm -f m2f
	rm -f f2c
	rm -f c2f
	rm -f slope
	rm -f len
	rm -f test
