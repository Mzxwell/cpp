//
// Created by Jinx on 24-11-7.
//

#include <cassert>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

class MemoryContext {
public:
    /**
     * @param parent 父节点，可能为 nullptr
     */
    MemoryContext(MemoryContext *parent);

    ~MemoryContext();

    // 禁止拷贝和移动
    MemoryContext(const MemoryContext &) = delete;

    MemoryContext &operator=(const MemoryContext &) = delete;

    MemoryContext(MemoryContext &&) = delete;

    MemoryContext &operator=(MemoryContext &&) = delete;

    using chunk_id_t = std::string;

    void alloc(const chunk_id_t &chunk_id);

private:
    // 注意输出描述中的说明，你需要在此处使用何种数据结构
    std::vector<MemoryContext *> children_;   // List of child memory contexts
    std::vector<std::string> allocations_;  // Allocated memory chunks
};

MemoryContext::MemoryContext(MemoryContext *parent) {
    if (parent)parent->children_.push_back(this);
}

MemoryContext::~MemoryContext() {
    for (MemoryContext *child: children_)
        delete child;
    for (auto it = allocations_.rbegin(); it != allocations_.rend(); ++it) {
        std::cout << "Chunk " << *it << " freed." << std::endl;
    }
}

void MemoryContext::alloc(const chunk_id_t &chunk_id) {
    allocations_.push_back(chunk_id);
}

void test_1() {
    std::unique_ptr<MemoryContext> A = std::make_unique<MemoryContext>(nullptr);
    A->alloc("1");
    A->alloc("2");
    A->alloc("3");
}

void test_2() {
    std::unique_ptr<MemoryContext> A = std::make_unique<MemoryContext>(nullptr);
    MemoryContext *B = new MemoryContext(A.get());
    MemoryContext *C = new MemoryContext(B);

    A->alloc("1");
    A->alloc("2");
    A->alloc("3");
    B->alloc("1/1");
    B->alloc("1/2");
    B->alloc("1/3");
    C->alloc("1/1/1");
    C->alloc("1/1/2");
    C->alloc("1/1/3");
}

void test_3() {
    std::unique_ptr<MemoryContext> A = std::make_unique<MemoryContext>(nullptr);
    MemoryContext *B = new MemoryContext(A.get());
    MemoryContext *C = new MemoryContext(A.get());
    MemoryContext *D = new MemoryContext(B);
    MemoryContext *E = new MemoryContext(C);
    MemoryContext *F = new MemoryContext(C);
    MemoryContext *G = new MemoryContext(E);

    A->alloc("1");
    A->alloc("2");
    A->alloc("3");
    B->alloc("1/1");
    C->alloc("1/2");
    D->alloc("1/1/1");
    D->alloc("1/1/2");
    G->alloc("1/2/1/1");
}

void test_4() {
    std::unique_ptr<MemoryContext> A = std::make_unique<MemoryContext>(nullptr);
    MemoryContext *B = new MemoryContext(A.get());
    MemoryContext *C = new MemoryContext(A.get());
    MemoryContext *D = new MemoryContext(B);
    MemoryContext *E = new MemoryContext(B);
    MemoryContext *F = new MemoryContext(C);
    MemoryContext *G = new MemoryContext(C);

    A->alloc("1");
    A->alloc("2");
    A->alloc("3");
    B->alloc("1/1");
    C->alloc("1/2");
    D->alloc("1/1/1");
    D->alloc("1/1/3");
    E->alloc("1/1/2");
    F->alloc("1/2/1");
    G->alloc("1/2/3");
    G->alloc("1/2/5");
    G->alloc("1/2/2");
    G->alloc("1/2/4");
}

void test_5() {
    std::unique_ptr<MemoryContext> A = std::make_unique<MemoryContext>(nullptr);
    MemoryContext *B = new MemoryContext(A.get());
    MemoryContext *C = new MemoryContext(A.get());
    MemoryContext *D = new MemoryContext(B);
    MemoryContext *G = new MemoryContext(C);

    A->alloc("2");
    A->alloc("1");
    A->alloc("3");
    A->alloc("4");
    B->alloc("2/1");
    B->alloc("3/5");
    C->alloc("1024/2");
    C->alloc("1024/1");
    G->alloc("8192/1/4095");
}

#define REGISTER_TEST_CASE(name) \
  { #name, name }

int main() {
    std::unordered_map<std::string, std::function<void()>>
            test_functions_by_name = {
            REGISTER_TEST_CASE(test_1), REGISTER_TEST_CASE(test_2),
            REGISTER_TEST_CASE(test_3), REGISTER_TEST_CASE(test_4),
            REGISTER_TEST_CASE(test_5),
    };

    std::string test_case_name;
    std::cin >> test_case_name;
    auto it = test_functions_by_name.find(test_case_name);
    assert(it != test_functions_by_name.end());
    auto fn = it->second;
    fn();
}