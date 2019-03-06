#include <iostream>
#include <queue>
#include <memory>

class BaseTask {
public:
  BaseTask(){}

  /* 
  Virtual destructors are useful when you might potentially 
  delete an instance of a derived class through a pointer to the base class.
  Doing so might cause undefined behaviour
  */
  virtual ~BaseTask() = default;

  /* will have to be overridden in any case */
  virtual void executeTask() = 0;

  /* Only if not overridden, Base class' implementation will be called */
  virtual void executeNonPureVirtualTask(){
  	std::cout << "BaseTask::executeNonPureVirtualTask()" << std::endl;
  }

  /* Even if overridden, Base class' implementation will be called  */
  void doNonVirtualTask(){
  	std::cout << "BaseTask::doNonVirtualTask()" << std::endl;
  }
};

class TaskA : public BaseTask{
public:
  TaskA(){}
  void executeTask(){
  	std::cout << "Executing task A" << std::endl;
  }
  /* will never be called */
  void doNonVirtualTask(){
  	std::cout << "TaskA::doNonVirtualTask()" << std::endl;
  }
};

class TaskB : public BaseTask{
public:
  TaskB(){}
  void executeTask(){
  	std::cout << "Executing task B" << std::endl;
  }
  void executeNonPureVirtualTask(){
  	std::cout << "TaskB-overloaded executeNonPureVirtualTask()" << std::endl;
  }

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
    if (task){
    	task->executeTask();
    	task->executeNonPureVirtualTask();
    	task->doNonVirtualTask();
    	std::cout << std::endl;
    }
  }

}
