#include "assert.h"
#include "math.h" // 引入被测试的头文件

// 测试 add 函数的用例
void test_add(void) {
    // 断言：预期 2+3=5
    assert(add(2, 3) == 5);
    // 断言：预期 (-1)+(-1)=-2
    assert(add(-1, -1) == -2);
    // 断言：预期 0+0=0
    assert(add(0, 0) == 0);
}

// 测试 sub 函数的用例
void test_sub(void) {
    assert(sub(5, 3) == 2);
    assert(sub(3, 5) == -2);
    assert(sub(0, 0) == 0);
}

// 注册测试用例到测试套件
int main(void) {
    // 初始化 CUnit 测试注册表
    test_add();
    test_sub();
    return 0;
}