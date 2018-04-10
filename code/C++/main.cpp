#include <iostream>
#include "textquery.h"
#include "textquery.cpp"

int main(int argc, char *argv[])
{
    std::ifstream is(argv[1]);
    TextQuery t1(is);
    std::string word;
    Query q = Query("fiery") | Query("bird") | Query("wind");
    std::cout << q << std::endl;
    std::cout << q.eval(t1) << std::endl;
    return 0;
}