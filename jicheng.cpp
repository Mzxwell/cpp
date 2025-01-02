class Base {
protected:
    int prot_mem;  // 受保护的成员

public:
    friend void clobber(Base&);  // 将 clobber(Base&) 声明为 Base 类的友元函数
};

class Sneaky : public Base {
    friend void clobber(Sneaky&);  // 已经是 Sneaky 类的友元函数

    int j;

    void clobber(Sneaky& s) {
        s.j = s.prot_mem = 0;  // 可以访问 Sneaky 类的成员，包括基类的 protected 成员
    }

    void clobber(Base& b) {
        b.prot_mem = 0;  // 可以访问 Base 类的 protected 成员，因为 clobber(Base&) 是 Base 类的友元
    }
};
