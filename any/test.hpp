#pragma once
#include<iostream>
#include<typeinfo>
#include<memory>
template<typename T> class test
{
private:
    T object_value;
public:
    test(T data) : object_value(data){};
    T& value(){
        return object_value;
    }
    const std::type_info & type() const{
        return typeid(object_value);
    }
};