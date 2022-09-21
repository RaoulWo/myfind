#include "Parser.h"

#include <iostream>
#include <memory>

int main(int argc, char* argv[])
{
    std::shared_ptr<MyFind::IParser> parser = std::make_shared<MyFind::Parser>();
    parser->Parse(argc, argv, "iR");
    parser->LogResults();

    return 0;
}