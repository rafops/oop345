#pragma once
// Task Milestone - Task Interface
// Task.h
// Chris Szalwinski
// v1.0 - 24/10/2015
// v1.1 - 12.11.2015
#include <iostream>
#include <string>

class Task {
  std::string name;
  std::string slots;
  std::string nextTask[2];
  const Task* pNextTask[2];
  static char delimiter;
  // The display member function uses this field width to align the output
  // across all of the records retrieved from the data file.
  static size_t field_width;
public:
  enum Quality {
    passed,
    redirect
  };
  // The constructor initializes the number of slots to a default value of 1
  // and the pointers to the next tasks to safe addresses.
  Task(const std::string& record);
  // returns the name of the task
  const std::string& getName() const;
  // returns the number of product slots in the task (converts from a string)
  unsigned int getSlots() const;
  // attempts to validate a next task in the current object by comparing the
  // Task referenced in its parameter to the next tasks stored upon
  // instantiation.  If one of these tasks has the same name as that
  // referenced, this function sets the corresponding pointer to the address of
  // the referenced task.
  bool validate(const Task& task);
  // returns the address of the next task depending on the parameter received.
  // This function reports an exception as shown in the sample output below if
  // the addressed of that next task has not been determined
  const Task* getNextTask(Quality quality) const; 
  // inserts into the referenced ostream object a full description of the task
  // as shown in the sample output listed below:
  // - if the task has been validated - uses the pointer(s) to the next task(s)
  // - if the task has not been validated - uses the name(s) of the next
  //   task(s) and appends a note that validation is still required
  void display(std::ostream&) const;
  // reset the delimiter for all objects in this class to the character
  // received
  static void setDelimiter(const char c);
  // returns the field width for all objects in this class
  static size_t getFieldWidth();
};

// returns true if the tasks referenced in its parameters have the same name
bool operator==(const Task&, const Task&);
