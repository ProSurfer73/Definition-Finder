#include "background.hpp"

void BackgroundTasksManager::addTask(TaskFunction function, void* data)
{
    // 1. let's add the task to the queue.
    tasksQueue.push(std::make_pair(function, data) );

    // 2. let's run the corresponding thread (if not already run).
    if(!backgroundThread.joinable())
        backgroundThread = std::thread(&BackgroundTasksManager::backgroundExecution, this);
}

void BackgroundTasksManager::join()
{
    // Let's wait until our background task is finished.
    backgroundThread.join();
}

void BackgroundTasksManager::backgroundExecution()
{
    // As long as we have atsks to do.
    while(!tasksQueue.empty())
    {
        // Let's get the task.
        std::pair<TaskFunction,void*> mypair = tasksQueue.front();

        // Let's run it.
        (*mypair.first)(mypair.second);

        // Finally, let's remove it from the queue.
        tasksQueue.pop();
    }
}

