default: test
clean:
	rm -f Milestone_3
build: clean
	g++ -std=c++11 -o Milestone_3 Milestone_3.cpp CustomerOrder.cpp Item.cpp ItemOrder.cpp Utilities.cpp
test: build
	./Milestone_3 CustomerOrders_Clean.dat ItemList_Clean.dat \|
