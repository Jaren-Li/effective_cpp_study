/*
 * @Author: dumdum && 1242579562@qq.com
 * @Date: 2023-01-16 21:02:17
 * @LastEditors: dumdum && 1242579562@qq.com
 * @LastEditTime: 2023-01-16 23:20:27
 * @FilePath: \code\effective_cpp_study\clause_12\clause_12.cpp
 * @Description:
 */
#include <iostream>

class Father
{
public:
    Father(std::string name = "fff", int age = 30) : nameF(name), ageF(age)
    { // 所有变量都得在构造函数赋值，即使没有初始值
        std::cout << "father build" << std::endl;
    }

    Father(const Father &father) : nameF(father.nameF), ageF(father.ageF)
    {                                                  // 注意这里把所有的参数都复制了一遍
        std::cout << "father copy build" << std::endl; // 即使后面在private里添加了变量，也需要在这里手动添加
    }

    Father &operator=(const Father &father)
    {
        std::cout << "father = copy build" << std::endl;
        if (this == &father)
            return *this; // 证同测试，如果是自我赋值，则不做任何事，避免出现指针变量出现错误
        nameF = father.nameF;
        ageF = father.ageF;
        return *this;
    }

    std::string nameF;
    int ageF;
};

/*
公有、私有、保护继承    c++primer P543
各种继承不影响子类对基类的成员的访问，子类对基类的访问权限只在乎基类的成员的访问说明符
但是各种继承影响的是；子类用户（包括子类的子类）对于基类成员的访问权限
注意是    用户     的访问权限！！！！！！
 */
class Child : public Father
{
public:
    Child(std::string nameC = "ccc", int ageC = 5) : nameC(nameC), ageC(ageC)
    {
        std::cout << "child build" << std::endl;
    }

    Child(const Child &child) : nameC(child.nameC), ageC(child.ageC) //, Father(child)              //此处的注释可以解除看效果
    {
        std::cout << "child copy build" << std::endl;
    }

    Child &operator=(const Child &child)
    {
        std::cout << "child = copy build" << std::endl;
        if (this == &child)
            return *this; // 证同测试，如果是自我赋值，则不做任何事，避免出现指针变量出现错误
        // Father::operator=(child); // 此处进行的是父类的赋值,可以尝试注释掉
        nameC = child.nameC;
        ageC = child.ageC;
        return *this;
    }

    void askFatherNA()
    {
        std::cout << "name:" << nameF << ","
                  << "age:" << ageF << std::endl;
    }

private:
    std::string nameC;
    int ageC;
};

int main()
{
    Child child("child", 7);
    child.nameF = "baba";
    child.ageF = 35;
    child.askFatherNA();
    std::cout << "_____________________________" << std::endl;

    // 注意这个才是赋值拷贝
    Child child2;
    child2 = child;
    child2.askFatherNA();
    std::cout << "_____________________________" << std::endl;

    // 这个是拷贝构造，区别在于是否先创建变量
    Child child3 = child;
    child3.askFatherNA();
    std::cout << "_____________________________" << std::endl;
}