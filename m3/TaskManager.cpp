// Milestone 3 - Managers - Task Manager Class
// TaskManager.cpp
// Rafael Leme de Moraes
// v1.0 07/12/2015

#include "Task.h"
#include "ItemManager.h" 
#include "TaskManager.h"
#include <algorithm>

void TaskManager::push_back(Task&& task) {
  tasks.push_back(std::move(task));
}

std::vector<Task>::iterator TaskManager::begin() {
  return tasks.begin();
}

std::vector<Task>::iterator TaskManager::end() {
  return tasks.end();
}

const std::vector<Task>::const_iterator TaskManager::cbegin() const {
  return tasks.cbegin();
}

const std::vector<Task>::const_iterator TaskManager::cend() const {
  return tasks.cend();
}

void TaskManager::display(std::ostream& os) const {
  for(auto& i: tasks) i.display(os);
}

void TaskManager::validate(std::ostream& os) {
  /* copied from Milestone_1.cpp :) */
  bool valid=true;
  for(auto i=0u; i<tasks.size() && valid; ++i) {
    bool invalid = true;
    for(auto j=0u; j<tasks.size() && invalid; ++j) {
      if(tasks[i].validate(tasks[j])) invalid = false;
    }
    valid = !invalid;
  }
  if(!valid) std::cerr << "*** Not all Tasks have been validated ***" << std::endl;
}

void TaskManager::display(std::ostream& os) const {
  for(auto& i: tasks) i.display(os);
}

void validate(const TaskManager& taskManager, const ItemManager& itemManager, std::ostream& os) {
  for(auto i=itemManager.cbegin(); i!=itemManager.cend(); ++i) {
    const auto& item = *i;
    auto hasTask = [&](const task& task) {
      return task.getName()==item.getDestination();
    };
    if(std::find_if(taskManager.cbegin(), taskManager.cend(), hasTask)==taskManager.cend()) {
      os << task[j] << " is unavailable" << std::endl;
    }
  }
}
