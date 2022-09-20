#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

namespace MyFind
{

    class Parser final
    {
    public:
        void Parse(int argc, char* argv[], const char* optstring);
        bool IsCaseInsensitive() const;
        bool IsRecursiveMode() const;
        std::string GetProgram() const;
        std::string GetSearchpath() const;
        std::vector<std::string> GetFilenames() const;

    private:
        void ParseOptions(int argc, char* argv[], const char* optstring);
        void TryParseOptions(int argc, char* argv[], const char* optstring);
        void ParseArguments(int argc, char* argv[]);
        void TryParseArguments(int argc, char* argv[]);
        
        bool caseInsensitive = false;
        bool recursiveMode = false;

        std::string program;
        std::string searchpath;
        std::vector<std::string> filenames;
    };

}

#endif