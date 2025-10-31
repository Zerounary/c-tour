#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../src/math.h" // 引入被测试的头文件

// 测试 add 函数的用例
void test_add(void) {
    // 断言：预期 2+3=5
    CU_ASSERT_EQUAL(add(2, 3), 5);
    // 断言：预期 (-1)+(-1)=-2
    CU_ASSERT_EQUAL(add(-1, -1), -2);
    // 断言：预期 0+0=0
    CU_ASSERT_EQUAL(add(0, 0), 0);
}

// 测试 sub 函数的用例
void test_sub(void) {
    CU_ASSERT_EQUAL(sub(5, 3), 2);    // 5-3=2
    CU_ASSERT_EQUAL(sub(3, 5), -2);   // 3-5=-2
    CU_ASSERT_EQUAL(sub(0, 0), 0);    // 0-0=0
}

// 注册测试用例到测试套件
int main(void) {
    // 初始化 CUnit 测试注册表
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // 创建测试套件（类似测试组）
    CU_pSuite suite = CU_add_suite("math_test_suite", NULL, NULL);
    if (NULL == suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // 向套件添加测试用例
    if (NULL == CU_add_test(suite, "test add function", test_add) ||
        NULL == CU_add_test(suite, "test sub function", test_sub)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // 运行测试（基础模式，输出到控制台）
    CU_basic_set_mode(CU_BRM_VERBOSE); // 详细输出模式
    CU_basic_run_tests();

    // 清理资源
    CU_cleanup_registry();
    return CU_get_error();
}