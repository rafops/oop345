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
  static size_t field_width;
public:
  enum Quality {
    passed,
    redirect
  };
  Task(const std::string& record);
  const std::string& getName() const;
  unsigned int getSlots() const;
  bool validate(const Task& task);
  const Task* getNextTask(Quality quality) const; 
  void display(std::ostream&) const;
  static void setDelimiter(const char c);
  static size_t getFieldWidth();
};

bool operator==(const Task&, const Task&);
