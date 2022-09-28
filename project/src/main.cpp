#include "Forker.h"
#include "Parser.h"

#include <iostream>
#include <memory>

int main(int argc, char* argv[])
{
    // Parse the command line parameters
    std::shared_ptr<MyFind::IParser> parser = std::make_shared<MyFind::Parser>();
    parser->Parse(argc, argv, "iR");
    parser->LogResults();

    // Fork child processes for each filename
    std::shared_ptr<MyFind::IForker> forker = std::make_shared<MyFind::Forker>(parser->GetFilenames());
    forker->Fork();
    
    return 0;
}