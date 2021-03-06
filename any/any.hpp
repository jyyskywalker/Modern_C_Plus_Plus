#pragma once
#include <iostream>
#include <typeinfo>
#include <memory>
class value_base
{

public:
    virtual const std::type_info &type() const = 0;
    virtual value_base *clone() = 0;
    virtual ~value_base();
};

template <typename T>
class value_holder : public value_base
{
private:
    T object_value;
    //因为type_info是const的，所以没法定义一个这种类型的对象去修改
public:
    value_holder(const T& data) : object_value(data){};

    virtual const std::type_info &type() const
    {
        return typeid(object_value);
    }
    T &get_value()
    {
        return object_value;
    }
    virtual value_holder *clone()
    {
        return new value_holder(object_value);
    }
    virtual ~value_holder() {}
};

class any
{
private:
    value_base *object;
    // 指针用于运行时多态
public:
    template <typename T>
    any(const T& a) : object(new value_holder<T>(a)){}
    any operator=(const any &rhs)
    {
        delete object;
        object = rhs.object->clone();
        return *this;
    }
    any emplace() {}
    void reset()
    {
        delete object;
        object = nullptr;
    }
    void swap(any &rhs1, any &rhs2)
    {
        any rhs3 = rhs1;
        rhs1 = rhs2;
        rhs2 = rhs3;
    }
    bool has_value()
    {
        return object != nullptr;
    }
    ~any(){
        delete object;
        object=nullptr;
    }
};