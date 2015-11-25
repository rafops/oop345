default: test
test: build
	./makeup
build: clean
	# g++ -std=c++11 -o makeup makeup.cpp Vec.cpp
	g++ -std=c++11 -o makeup makeup.cpp
clean:
	rm -f makeup