#ifndef PARSER_H
#define PARSER_H

#include "IParser.h"

namespace MyFind
{

    class Parser final : public IParser
    {
    public:
        virtual ~Parser() {}

        void Parse(int argc, char* argv[], const char* optstring) override;
        bool IsCaseInsensitive() const override;
        bool IsRecursiveMode() const override;
        std::string GetProgram() const override;
        std::string GetSearchpath() const override;
        std::vector<std::string> GetFilenames() const override;
        void LogResults() const override;

    private:
        void ParseOptions(int argc, char* argv[], const char* optstring);
        void TryParseOptions(int argc, char* argv[], const char* optstring);
        void ParseArguments(int argc, char* argv[]);
        void TryParseArguments(int argc, char* argv[]);
        void PrintUsage(std::string program) const;
        
        bool caseInsensitive = false;
        bool recursiveMode = false;

        std::string program;
        std::string searchpath;
        std::vector<std::string> filenames;
    };

}

#endif