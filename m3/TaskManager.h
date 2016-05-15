#pragma once
// Manager Milestone - TaskManager Interface
// TaskManager.h
// Chris Szalwinski
// v1.0 - 16/11/2015
#include <iostream>
#include <vector>

class Task;
class ItemManager;

class TaskManager {
  std::vector<Task> tasks;
public:
  void push_back(Task&&);
  std::vector<Task>::iterator begin();
  std::vector<Task>::iterator end();
  const std::vector<Task>::const_iterator cbegin() const;
  const std::vector<Task>::const_iterator cend() const;
  void validate(std::ostream&);
  void display(std::ostream&) const;
};

void validate(const TaskManager&, const ItemManager&, std::ostream&);
