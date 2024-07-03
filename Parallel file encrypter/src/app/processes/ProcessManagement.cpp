#include "ProcessManagent.hpp"
#include <iostream>
#include <cstring>
#include <sys/wait.h>
#include "../cncryptDecrypt/Cryption.hpp"

ProcessManagement::ProcessManagement() {}

bool ProcessManagement::executeTasks()
{
    taskQueue.push(std::move(task));
    return true;
}

void ProcessManagement::executeTasks()
{
    while (!taskQueue.empty())
    {
        std::unique_ptr<Task> TaskToExecute = std::move(taskQueue.front());
        taskQueue.pop();
        std::cout << "Executing task:" << taskToExecute->toString() << std::endl;
        executeCryption(tasktoExecute->toString());
    };
};