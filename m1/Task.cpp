// Milestone 1 - Task Manager - Task Class
// Task.cpp
// Rafael Leme de Moraes
// v1.0 07/12/2015

#include "Task.h"
#include "Utilities.h"

Task::Task(const std::string& record) {
  slots = "1";
  pNextTask[passed] = nullptr;
  pNextTask[redirect] = nullptr;

  Utilities u(field_width);
  size_t next_pos = 0;
  bool more = true;

           name               = u.nextToken(record, next_pos, more);
  if(more) slots              = u.nextToken(record, next_pos, more);
  if(more) nextTask[passed]   = u.nextToken(record, next_pos, more);
  if(more) nextTask[redirect] = u.nextToken(record, next_pos, more);

  field_width = u.getFieldWidth();
}

const std::string& Task::getName() const {
  return name;
}

unsigned int Task::getSlots() const {
  return std::stoi(slots);
}

bool Task::validate(const Task& task) {
  return true; // TODO
}

const Task* Task::getNextTask(Quality quality) const {
  return nullptr; // TODO
}

void Task::display(std::ostream& os) const {
  os << name << std::endl; // TODO
}

void Task::setDelimiter(const char c) {
  delimiter = c;  
}

size_t Task::getFieldWidth() {
  return Task::field_width;
}

bool operator==(const Task& t1, const Task& t2) {
  return false; // TODO
}
