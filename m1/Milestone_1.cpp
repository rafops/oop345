// Milestone 1 - Task Manager - Main Program
// milestone_1.cpp
// Chris Szalwinski
// v1.0 24/10/2015
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>
#include "Task.h"
#include "Utilities.h"

int main(int argc, char** argv) {
  // process command line arguments
  if (argc != 3) {
    std::cerr << "*** invalid number of arguments ***\n"
      << "Usage: " << argv[0] << " tasks_file field_delimiter\n";
    return 1;
  }
  std::ifstream taskFile(argv[1]);
  Task::setDelimiter(argv[2][0]);
  if (!taskFile) {
    std::cerr << "*** Cannot open tasks_file named " << argv[1] << " ***\n";
    return 2;
  }
  Utilities::setDelimiter(argv[2][0]);
  // end of command line processing

  // Acquire the Tasks
  //
  std::cout << "Acquiring the Set of Tasks\n--------------------------\n";
  Task::setDelimiter(Utilities::getDelimiter()); // again?
  std::vector<Task> tasks;
  while (taskFile) {
    std::string record;
    std::getline(taskFile, record);
    if (taskFile) { // why we need this besides while(taskFile) ?
      try {
        std::unique_ptr<Task> task(new Task(record));
        if (!task->getName().empty())
          tasks.push_back(std::move(*task));
      }
      catch (const std::string& msg) {
        std::cerr << msg << std::endl;
      }
    }
  }

  // Display the Accepted Set of Tasks
  //
  std::cout << "\nAccepted Set of Tasks\n---------------------\n";
  for (auto& t : tasks)
    t.display(std::cout);

  // Check nextTask
  //
  std::cout << "\nCheck Next Tasks\n----------------\n";
  int nerr = 0;
  for (auto& t : tasks) {
    try {
      std::cout << t.getNextTask(Task::passed)->getName() << std::endl;
      std::cout << t.getNextTask(Task::redirect)->getName() << std::endl;
    }
    catch (const std::string& msg) {
      std::cerr << msg << std::endl;
      nerr++;
      if (nerr > 3) {
        std::cerr << "*** Further checks suspended ***" << std::endl;
        break;
      }
    }
  }

  // Validate the Tasks
  //
  std::cout << "\nValidating the Set of Tasks\n---------------------------\n";
  bool valid = true;
  for (auto i = 0u; i < tasks.size() && valid; i++) {
    bool invalid = true;
    for (auto j = 0u; j < tasks.size() && invalid; j++) {
      if (tasks[i].validate(tasks[j]))
        invalid = false;
    }
    valid = !invalid;
  }
  if (!valid)
    std::cerr << "*** Not all Tasks have been validated ***\n";
  for (auto& t : tasks)
    t.display(std::cout);

  // Terminate
  //
  std::cout << "\nDone!\nPress Enter Key to Exit ... ";
  char c;
  std::cin.get(c);
}
