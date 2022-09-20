#include "Parser.h"

#include <algorithm>
#include <getopt.h>
#include <iostream>
#include <stdexcept>

namespace MyFind
{
    
    void Parser::Parse(int argc, char* argv[], const char* optstring)
    {
        this->ParseOptions(argc, argv, optstring);
        this->ParseArguments(argc, argv);
    }

    bool Parser::IsCaseInsensitive() const
    {
        return this->caseInsensitive;
    }

    bool Parser::IsRecursiveMode() const
    {
        return this->recursiveMode;
    }

    std::string Parser::GetProgram() const
    {
        return this->program;
    }

    std::string Parser::GetSearchpath() const
    {
        return this->searchpath;
    }

    std::vector<std::string> Parser::GetFilenames() const
    {
        return this->filenames;
    }

    void Parser::ParseOptions(int argc, char* argv[], const char* optstring)
    {
        try
        {
            this->TryParseOptions(argc, argv, optstring);
        }
        catch(const std::runtime_error& e)
        {
            std::cerr << e.what() << '\n';
            exit(EXIT_FAILURE);
        }
        
    }

    void Parser::TryParseOptions(int argc, char* argv[], const char* optstring)
    {
        char option;
        while ((option = getopt(argc, argv, optstring)) != EOF)
        {
            switch (option)
            {
                case ('i'):
                    this->caseInsensitive = true;
                    break;
                case('R'):
                    this->recursiveMode = true;
                    break;
                default:
                    throw std::runtime_error("Invalid options"); 
            }
        }
    }

    void Parser::ParseArguments(int argc, char* argv[])
    {
        try
        {
            this->TryParseArguments(argc, argv);
        }
        catch(const std::runtime_error& e)
        {
            std::cerr << e.what() << '\n';
            exit(EXIT_FAILURE);
        }
        
    }

    void Parser::TryParseArguments(int argc, char* argv[])
    {
        // Extract program name
        this->program = argv[0];

        if (argc <= 1) throw std::runtime_error("Invalid arguments");
        
        // Extract options (-i, -R, -iR, -Ri)
        std::vector<std::string> vec;
        for (int i = 1; i < argc; i++)
        {
            vec.push_back(argv[i]);
        }

        if (this->caseInsensitive)
        {
            std::string opt = "-i";
            std::vector<std::string>::iterator it = std::find(vec.begin(), vec.end(), opt);
            if (it != vec.end()) vec.erase(it);
        }

        if (this->recursiveMode)
        {
            std::string opt = "-R";
            std::vector<std::string>::iterator it = std::find(vec.begin(), vec.end(), opt);
            if (it != vec.end()) vec.erase(it);
        }

        if (this->caseInsensitive && this->recursiveMode)
        {
            std::string opt1 = "-iR";
            std::vector<std::string>::iterator it1 = std::find(vec.begin(), vec.end(), opt1);
            if (it1 != vec.end()) vec.erase(it1); 

            std::string opt2 = "-Ri";
            std::vector<std::string>::iterator it2 = std::find(vec.begin(), vec.end(), opt2);
            if (it2 != vec.end()) vec.erase(it2); 
        }

        if (vec.size() == 0) throw std::runtime_error("Invalid arguments");

        // Extract searchpath
        this->searchpath = vec.at(0);
        vec.erase(vec.begin());

        if (vec.size() == 0) throw std::runtime_error("Invalid arguments");

        // Extract filenames
        for (const std::string& filename : vec)
        {
            this->filenames.push_back(filename);
        }
    }

}