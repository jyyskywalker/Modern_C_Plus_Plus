class placeholder 
{ 
public: // structors 
    virtual ~placeholder()      { 
    } 
public: // queries 
    virtual const std::type_info & type() const = 0; 
    virtual placeholder * clone() const = 0; 
}; 

template<typename ValueType> 
class holder : public placeholder 
{ 
public: // structors 
    holder(const ValueType & value): held(value) 
    { 
    } 
public: // queries 
    virtual const std::type_info & type() const { 
        return typeid(ValueType); 
    } 
    virtual placeholder * clone() const { 
        return new holder(held); 
    } 
public: // representation 
    ValueType held; 
};


class My_any
{
    placeholder * content_obj;
public:
    template <typename T>
    My_any(T const& a_right):content_obj(new T(a_right))
    {}

    template <typename T>
    My_any & operator = (T const& a_right) {
        delete content_obj;
        content_obj = new T(a_right);
        return *this;
    }

    My_any(My_any const& a_right)
      : content_obj(a_right.content_obj ? 
          a_right.content_obj->clone() : 0)
    {        
    }

    std::type_info& type() const {
        return content_obj ? content_obj->type() : typeid(void);
    }
};
