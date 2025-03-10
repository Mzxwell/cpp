#include "MessageQueueManager.h"

// Message 类的实现

Message::Message(const char *d, int p) {
    // ODO: Task 1-1
    if(d){
        data=new char[strlen(d)+1];
        strcpy(data,d);
        priority=p;
    }else data=nullptr;
}

Message::Message(Message &&other) noexcept:data(other.data),priority(other.priority) {other.data=nullptr;
    // ODO: Task 1-2
}

Message &Message::operator=(Message &&other) noexcept {
    // ODO: Task 1-2
    if(this!=&other){
        delete[] data;
        data=other.data;
        priority=other.priority;
        other.data=nullptr;
    }
    return *this;
}

Message::~Message() {
    delete[] data;
}

// MessageQueueManager 类的实现
MessageQueueManager::MessageQueueManager() {}

void MessageQueueManager::addMessage(Message m) {
    // ODO: Task 2
    auto it=std::lower_bound(messages.begin(),messages.end(),m,[](const Message &l,const Message &r){return l.priority<r.priority;});
    messages.insert(it,std::move(m));
}

MessageQueueManager::MessageQueueManager(MessageQueueManager &&other) noexcept {
    // ODO: Task 3-1
    messages=std::move(other.messages);
}

MessageQueueManager &
MessageQueueManager::operator=(MessageQueueManager &&other) noexcept {
    // ODO: Task 3-2
    if(this!=&other)
        messages=std::move(other.messages);
    return *this;
}

void MessageQueueManager::printMessages() const {
    for (const auto &msg : messages) {
        std::cout << "Message: " << msg.data << ", Priority: " << msg.priority
                  << std::endl;
    }
}

MessageQueueManager::~MessageQueueManager() {
    std::cout << "Destructing MessageQueueManager" << std::endl;
}