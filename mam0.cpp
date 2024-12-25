#include "mqm.h"

// Message 类的实现

Message::Message(const char *d, int p) : priority(p) {
    data = new char[strlen(d) + 1];
    strcpy(data, d);
}

Message::Message(Message &&other) noexcept: data(other.data), priority(other.priority) {
    other.data = nullptr;
}

Message &Message::operator=(Message &&other) noexcept {
    if (this != &other) {
        priority = other.priority;
        data = other.data;
        other.data = nullptr;
    }
    return *this;
}

Message::~Message() {
    delete[] data;
}

// MessageQueueManager 类的实现
MessageQueueManager::MessageQueueManager() {}

void MessageQueueManager::addMessage(Message m) {
    int i;
    for (i = 0; i < messages.size(); i++)if (messages[i].priority > m.priority)break;
    messages.insert(messages.cbegin() + i, std::move(m));
}

MessageQueueManager::MessageQueueManager(MessageQueueManager &&other) noexcept {
    messages=std::move(other.messages);
}

MessageQueueManager &
MessageQueueManager::operator=(MessageQueueManager &&other) noexcept {
    if(this!=&other)
    messages=std::move(other.messages);
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