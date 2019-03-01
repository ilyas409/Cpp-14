#include <iostream>
#include <queue>
#include <memory>

class BaseTask {
 public:
  virtual ~BaseTask() = default;
  virtual void executeTask() = 0;
};

class TaskA : public BaseTask {
 public:
  void executeTask() { std::cout << "start TaskA\n"; }
};

class TaskB : public BaseTask {
 public:
  void executeTask() { std::cout << "start TaskB\n"; }
};

class ObjectFactory {
 public:
  std::shared_ptr<BaseTask> createObject(int type) {
    switch (type) {
      case 0:
        return std::make_shared<TaskA>();
      case 1:
        return std::make_shared<TaskB>();
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
