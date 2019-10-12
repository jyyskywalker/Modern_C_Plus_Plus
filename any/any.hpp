#include <iostream>
#include <typeinfo>
#include <memory>
namespace jyy
{
    class any{
        private:
            shared_ptr<value_base> p1;
    // 指针用于运行时多态
        public:
            any() : {
                
            }
            any operator=() {}
            emplace() {}
            reset() {}
            swap() {}
            bool has_value() {}
            std::type_info type() {}
            ~any()
    };

    class value_base{
        private:

        public:
            virtual int get_value()=0;
            virtual int get_type()=0;
    };

    template <typename T> class value_holder : public base{
        private:
            T object_value;
            type_info object_type;
        public:
            holder(T object) : object_value(object){
                object_type = typeid(object);
            }
    // 还要有一个复制构造函数
            virtual T get_value(*this){
                return *this->object_value;
            }
            virtual std::type_info get_type(*this){
                return *this->object_type;
            }
        ~holder();
    };
}