## 第一周
+ 首先创建一个非模板的基类，便于给any类使用指针
+ 接着用一个模板类继承这个基类，在模板类中实例化对象，获取对象的值和数据类型
+ 接着写any类
    - any类中包含了一个智能指针成员，这个成员指向了基类成员，因为是虚继承，所以可以指向派生类。
    - any类的其他成员函数还未实现。