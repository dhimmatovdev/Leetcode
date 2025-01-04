class TaskManager {
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& task : tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];
            taskMap[taskId] = {userId, priority};
            taskQueue.push({priority, taskId, userId});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {userId, priority};
        taskQueue.push({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        int userId = taskMap[taskId].first;
        taskMap[taskId] = {userId, newPriority};
        taskQueue.push({newPriority, taskId, userId});
    }

    void rmv(int taskId) {
        taskMap.erase(taskId);
    }

    int execTop() {
        while (!taskQueue.empty()) {
            auto [priority, taskId, userId] = taskQueue.top();
            taskQueue.pop();
            if (taskMap.find(taskId) != taskMap.end() && taskMap[taskId].first == userId && taskMap[taskId].second == priority) {
                taskMap.erase(taskId);
                return userId;
            }
        }
        return -1;
    }

private:
    map<int, pair<int, int>> taskMap; // taskId -> (userId, priority)
    priority_queue<tuple<int, int, int>> taskQueue; // (priority, taskId, userId)
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId, taskId, priority);
 * obj->edit(taskId, newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
©leetcode