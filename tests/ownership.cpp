#define main solution_main
#include "../main.cpp"
#undef main
#include <cassert>

int main()
{
    mystring empty;
    assert(empty.get_len() == 0 && empty[0] == '\0');
    empty.ADD(empty);
    std::string input = "abc";
    mystring original(input);
    mystring copy(original);
    original.ADD(original);
    assert(original.get_len() == 6 && original[3] == 'a');
    assert(copy.get_len() == 3 && copy[3] == '\0');
    empty = copy;
    copy = copy;
    copy.ADD(original);
    assert(empty.get_len() == 3 && copy.get_len() == 9);
    assert(empty < original && !(original < empty));
    assert(!(empty < empty));
    assert(empty[-1] == '\0');
}
