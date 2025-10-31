add_rules("mode.debug", "mode.release")

set_project("c-test-demo")
set_version("1.0.0")
set_languages("c99")


-- 1. 定义被测试的核心库（将源文件编译为静态库，方便测试目标链接）
target("math")
    set_kind("static") -- 静态库，供测试代码链接
    add_files("src/*.c") -- 源文件
    add_includedirs("src") -- 头文件目录（供测试代码引用）

target("app")
    set_kind("binary")
    add_files("src/*.c")

-- 3. 定义测试目标
target("test_math")
    set_kind("binary") -- 测试程序为可执行文件
    add_files("test/*.c") -- 测试代码
    add_deps("math") -- 依赖核心库（被测试代码）
    set_runargs("--verbose") -- 测试程序运行参数（可选，让 CUnit 输出详细日志）

-- 4. 注册测试目标（可选，方便用 xmake test 命令运行）
add_tests("math_test", "$(builddir)/test_math")