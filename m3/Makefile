default: test
clean:
	rm -f Milestone_3
build: clean
	g++ -std=c++11 -o Milestone_3 Milestone_3.cpp ItemManager.cpp OrderManager.cpp TaskManager.cpp CustomerOrder.cpp Item.cpp ItemOrder.cpp Task.cpp Utilities.cpp
test: build
	./Milestone_3 TaskList_Clean.dat CustomerOrders_Clean.dat ItemList_Clean.dat \|
