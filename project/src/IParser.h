#ifndef IPARSER_H
#define IPARSER_H

#include <string>
#include <vector>

namespace MyFind
{

    class IParser
    {
    public:
        virtual ~IParser() {}

        /// @brief Parses the command line arguments.
        /// @param argc 
        /// @param argv 
        /// @param optstring 
        virtual void Parse(int argc, char* argv[], const char* optstring) = 0;

        /// @brief Returns whether the flag [-i] has been set or not.
        /// @return 
        virtual bool IsCaseInsensitive() const = 0;

        /// @brief Returns whether the flag [-R] has been set or not.
        /// @return 
        virtual bool IsRecursiveMode() const = 0;

        /// @brief Returns the name of the called program.
        /// @return 
        virtual std::string GetProgram() const = 0;

        /// @brief Returns the searchpath.
        /// @return 
        virtual std::string GetSearchpath() const = 0;

        /// @brief Returns the filenames.
        /// @return 
        virtual std::vector<std::string> GetFilenames() const = 0;

        /// @brief Prints the extracted command line arguments an options.
        virtual void LogResults() const = 0;
    };

}

#endif 