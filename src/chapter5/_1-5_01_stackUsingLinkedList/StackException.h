#include <iostream>
#include <exception>

class StackException : public std::exception {
    public:
        StackException(const std::string & err) : msg(err) {}
        const char * what() const noexcept { return msg.c_str(); }
    private:
        std::string msg;
};