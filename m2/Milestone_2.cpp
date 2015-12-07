// CustomerOrder Milestone - Main Program
// Milestone_2.cpp
// Chris Szalwinski
// v1.0 - 9/11/2015
// v1.1 - 9/11/2015 - customerOrder -> customerOrders for g++ 5.2 compatability (CS)
// v1.2 - 16/11/2015 - add <cstdlib> for exit (CS)
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <memory>
#include "CustomerOrder.h"
#include "Utilities.h"
#include "Item.h"

int main(int argc, char** argv) {
  // process command line arguments
  if (argc != 4) {
    std::cerr << "*** invalid number of arguments ***\n"
      << "Usage: " << argv[0] << " customer_order_file item_file delimiter\n";
    exit(1);
  }
  std::ifstream orderFile(argv[1]);
  if (!orderFile) {
    std::cerr << "*** Cannot open Customer Order file named " << argv[1] << " ***\n";
    exit(2);
  }
  else {
    std::cout << "Command Line Arguments\n----------------------\n";
    std::cout << "Customer Order File Specified = " << argv[1] << "\n";
  }
  std::ifstream itemFile(argv[2]);
  if (!itemFile) {
    std::cerr << "*** Cannot open Item file named " << argv[2] << " ***\n";
    exit(3);
  }
  else
    std::cout << "Item File Specified           = " << argv[2] << "\n";
  Utilities::setDelimiter(argv[3][0]);
  std::cout << "File Record Field Delimiter   = " << argv[3][0] << "\n\n";
  // end of command line processing

  // Retrieve and introduce the Customer CustomerOrder Orders
  //
  std::cout << "*** Retrieve and Introduce the Customer Orders ***\n";
  CustomerOrder::setDelimiter(Utilities::getDelimiter());
  std::vector<CustomerOrder> customerOrders;
  while (orderFile) {
    std::string record;
    std::getline(orderFile, record);
    if (orderFile) {
      try {
        std::unique_ptr<CustomerOrder> customerOrder(new CustomerOrder(record));
        if (!customerOrder->empty())
          customerOrders.push_back(std::move(*customerOrder));
      }
      catch (const std::string& msg) {
        std::cerr << msg << std::endl;
      }
    }
  }

  // // Display the Accepted Customer Orders
  // //
  // std::cout << "\nList of Accepted Customer Orders\n--------------------------------\n";
  // for (auto& s : customerOrders)
  //   s.display(std::cout);
  // 
  // // Retrieve the available Items
  // //
  // std::cout << "\n*** Retrieve the Available Items ***\n";
  // Item::setDelimiter(Utilities::getDelimiter());
  // std::vector<Item> items;
  // while (itemFile) {
  //   std::string record;
  //   std::getline(itemFile, record);
  //   if (itemFile) {
  //     try {
  //       std::unique_ptr<Item> item(new Item(record));
  //       if (!item->empty())
  //         items.push_back(std::move(*item));
  //     }
  //     catch (const std::string& msg) {
  //       std::cerr << msg << std::endl;
  //     }
  //   }
  // }
  // 
  // // List the available Items
  // //
  // std::cout << "\nList of Available Items\n-----------------------\n";
  // for (auto& i : items)
  //   i.display(std::cout, true);
  // 
  // // Fill the Customer Orders with the Available Items
  // //
  // std::cout << "\n*** Process the Customer Orders ***\n";
  // for (auto& i : items)
  //   for (auto& s : customerOrders)
  //     s.fill(i);
  // 
  // // Display the Processed Customer Orders
  // //
  // std::cout << "\nList of Processed Customer Orders\n---------------------------------\n";
  // for (auto& s : customerOrders)
  //   s.display(std::cout);
  // 
  // // Terminate
  // //
  // std::cout << "\nDone!\nPress Enter Key to Exit ... ";
  // char c;
  // std::cin.get(c);
}