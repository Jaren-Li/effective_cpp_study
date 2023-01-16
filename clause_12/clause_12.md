<!--
 * @Author: dumdum && 1242579562@qq.com
 * @Date: 2023-01-16 20:54:24
 * @LastEditors: dumdum && 1242579562@qq.com
 * @LastEditTime: 2023-01-16 23:25:39
 * @FilePath: \code\effective_cpp_study\clause_12\clause_12.md
 * @Description: 
-->
# cluse_12
当使用拷贝构造还有拷贝赋值的时候，不要忘了将每一个成分都要复制

比如私有变量，base class等

特别是有继承关系的，如果没有将父类也进行复制，那么父类就会调用默认构造函数，造成一些潜在的问题

并且不要尝试使用某个copying函数实现另一个copying函数，假如有相似功能部分，应放进第三个函数中，供两个copying函数使用