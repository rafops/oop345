default: test
clean:
	rm -f Milestone_1
build: clean
	#g++ -std=c++0x -o Milestone_1 Milestone_1.cpp Task.cpp Utilities.cpp
	clang++ -std=c++11 -o Milestone_1 Milestone_1.cpp Task.cpp Utilities.cpp
test: build
	./Milestone_1 TaskList_Clean.dat '|'
