#include "iostream"

using namespace std;

class MyExceptionBase {
public:
    virtual void show() { cout << "MyExceptionBase" << endl; }
};

class MyExceptionDerived : public MyExceptionBase {
public:
    void show() override { cout << "MyExceptionDerived" << endl; }
};

void f(MyExceptionBase &e) {
    e.show();
    throw e;
}

int main() {
    MyExceptionDerived e;
    try { f(e); }
    catch (MyExceptionDerived &e) {
        e.show();
        cout << "catch MyExceptionDerived" << endl;
    }
    catch (MyExceptionBase &e) {
        e.show();
        cout << "catch MyExceptionBase" << endl;
    }
}
/**
 * 1. MyExceptionDerived:
 *    在 f 函数中，调用 e.show() 时，e 是 MyExceptionDerived 类型的对象，
 *    因此会调用派生类 MyExceptionDerived 的 show() 函数，输出 "MyExceptionDerived"。
 *
 * 2. MyExceptionBase:
 *    在 throw e; 后，发生了对象切割，将 MyExceptionDerived 对象切割为基类 MyExceptionBase 类型的对象。
 *    捕获异常时，基类的 catch 块会匹配成功，调用基类的 show() 函数，输出 "MyExceptionBase"。
 *
 * 3. catch MyExceptionBase:
 *    在基类 catch 块中，打印出 "catch MyExceptionBase"，说明捕获到了基类类型的异常。
 */
