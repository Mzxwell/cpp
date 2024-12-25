#include "mqm.h"

// Message 类的实现

Message::Message(const char *d, int p) : data((char *) d), priority(p) {
    // : Task 1-1
}

Message::Message(Message &&other) noexcept: data(other.data), priority(other.priority) {
    other.data = nullptr;
}

Message &Message::operator=(Message &&other) noexcept {
    // : Task 1-2
    return *this;
}

Message::~Message() {
    delete[] data;
}

// MessageQueueManager 类的实现
MessageQueueManager::MessageQueueManager() {}

void MessageQueueManager::addMessage(Message m) {
    // DO: Task 2
}

MessageQueueManager::MessageQueueManager(MessageQueueManager &&other) noexcept {
    // ODO: Task 3-1
}

MessageQueueManager &
MessageQueueManager::operator=(MessageQueueManager &&other) noexcept {
    // ODO: Task 3-2
    return *this;
}

void MessageQueueManager::printMessages() const {
    for (const auto &msg: messages) {
        std::cout << "Message: " << msg.data << ", Priority: " << msg.priority
                  << std::endl;
    }
}

MessageQueueManager::~MessageQueueManager() {
    std::cout << "Destructing MessageQueueManager" << std::endl;
}