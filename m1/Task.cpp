// Milestone 1 - Task Manager - Task Class
// Task.cpp
// Rafael Leme de Moraes
// v1.0 07/12/2015

#include "Task.h"
#include "Utilities.h"

char Task::delimiter = '|';
size_t Task::field_width = 0;

Task::Task(const std::string& record) {
  slots = "1";
  pNextTask[passed] = nullptr;
  pNextTask[redirect] = nullptr;

  size_t next_pos = 0;
  bool more = true;
  Utilities u(field_width);

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
  bool valid = true;
  if(task.name.compare(nextTask[passed])==0) pNextTask[passed] = &task;
  else if(task.name.compare(nextTask[passed])==0) pNextTask[redirect] = &task;
  else valid = false;
  return valid;
}

const Task* Task::getNextTask(Quality quality) const {
  if(pNextTask[quality]==nullptr) {
    throw "*** Validate  [" + nextTask[quality] + "] @ [" + name + "] ***";
  }
  return pNextTask[quality];
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

bool operator==(const Task& task1, const Task& task2) {
  return task1.getName().compare(task2.getName())==0;
}
