#include "Parser.h"

#include <iostream>
#include <memory>

int main(int argc, char* argv[])
{
    std::shared_ptr<MyFind::Parser> parser = std::make_shared<MyFind::Parser>();
    parser->Parse(argc, argv, "iR");

    std::cout << "IsCaseInsensitive() " << parser->IsCaseInsensitive() << std::endl;
    std::cout << "IsRecursiveMode() " << parser->IsRecursiveMode() << std::endl;
    std::cout << "GetProgram() " << parser->GetProgram() << std::endl;
    std::cout << "GetSearchpath() " << parser->GetSearchpath() << std::endl;
    std::cout << "GetFilenames() " << std::endl;
    for (const std::string& filename : parser->GetFilenames())
    {
        std::cout << filename << std::endl;
    }

    return 0;
}