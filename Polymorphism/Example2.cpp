#include <iostream>
#include <queue>
#include <memory>

class BaseTask {
  int complexity;
public:
  /* Base task initializes its instance variable */
  BaseTask(int complexity) : complexity(complexity){}
  virtual ~BaseTask() = default;
  virtual void executeTask() = 0;
};

class TaskA : public BaseTask {
public:
  /* we have to pass the parameter up to the Base Task */
  TaskA(int complexity) : BaseTask(complexity){}
  void executeTask() { std::cout << "start TaskA\n"; }
};

class TaskB : public BaseTask {
  int taskBSpecificParam;
public:
  /* Class B has its own instance variable which is 
  not present in the base class*/
  TaskB(int complexity, int param) : 
  BaseTask(complexity), taskBSpecificParam(param){}
  void executeTask() { 
    std::cout << "start TaskB, specific param value: "
      << taskBSpecificParam << "\n"; 
  }
};

class ObjectFactory {
public:
  std::shared_ptr<BaseTask> createObject(int type) {
    switch (type) {
      case 0:
        return std::make_shared<TaskA>(0);
      case 1:
        return std::make_shared<TaskB>(1, 42);
      default:
        return nullptr;
    }
  }
};

int main() {
  std::queue<std::shared_ptr<BaseTask>> taskQueue;
  
  ObjectFactory factory;
  std::shared_ptr<BaseTask> taskA = factory.createObject(0);
  std::shared_ptr<BaseTask> taskB = factory.createObject(1);
  
  taskQueue.push(taskA);
  taskQueue.push(taskB);
  
  while (!taskQueue.empty()) {
    auto task = taskQueue.front();
    taskQueue.pop();
    if (task) task->executeTask();
  }
}
