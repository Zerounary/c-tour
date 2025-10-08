-- 1. 基本项目设置
set_project("c-tour")
set_version("1.0.0")
set_languages("c++17")

-- 2. 添加依赖包
add_requires("fmt", "catch2")

-- 3. 定义静态库 mathlib
target("mathlib")
    set_kind("static")
    add_files("src/mathlib/src/*.cpp")
    add_includedirs("src/mathlib/include", {public = true})

-- 4. 定义控制台应用程序
target("console_app")
    set_kind("binary")
    add_files("src/app/main.cpp")
    -- 添加对 mathlib 和 fmt 的依赖
    add_deps("mathlib")
    add_packages("fmt")

-- 5. 定义测试
target("math_tests")
    set_kind("binary")
    add_files("tests/*.cpp")
    add_deps("mathlib")
    -- 让 catch2 包提供 main 函数
    add_packages("catch2", {configs = {main = true}})
    set_group("tests")