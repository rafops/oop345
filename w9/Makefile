default: test
clean:
	rm -f w9
build: clean
	g++ -std=c++11 -o w9 w9.cpp
test: build
	./w9 Descriptions.dat Prices.dat