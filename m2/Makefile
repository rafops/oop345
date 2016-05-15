default: test
clean:
	rm -f Milestone_2
build: clean
	g++ -std=c++11 -o Milestone_2 Milestone_2.cpp CustomerOrder.cpp Item.cpp ItemOrder.cpp Utilities.cpp
test: build
	./Milestone_2 CustomerOrders_Clean.dat ItemList_Clean.dat \|
