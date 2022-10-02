#include "Forker.h"

#include <iostream>

#include <filesystem>
#include <cctype>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

namespace MyFind
{

    Forker::Forker(
            std::string searchpath, 
            std::vector<std::string> filenames, 
            bool caseInsensitive, 
            bool recursiveMode)
    { 
        this->searchpath = searchpath;
        this->filenames = filenames;
        this->caseInsensitive = caseInsensitive;
        this->recursiveMode = recursiveMode;
    }

    void Forker::Fork() const
    {
        pid_t pid, wpid;
        int status = 0;

        for(const std::string& filename : this->filenames)
        {
            pid = fork();
            switch (pid)
            {
            case -1:
                // Error forking process
                std::cerr << "Child process could not be forked" << std::endl;
                exit(EXIT_FAILURE);
            case 0:
                // Child process
                this->Child(filename);
                break;
            default:
                // Parent process
                break;
            }
        }

        while ((wpid = wait(&status)) > 0);
    }

    void Forker::Child(const std::string& filename) const
    {    
        std::string result = SearchForFileInPath(filename, this->searchpath);

        std::cout << getpid() << ": " << filename << ": " << result << std::endl;
        exit(EXIT_SUCCESS);
    }

    std::string Forker::SearchForFileInPath(const std::string& file, const std::string& path) const
    {
        std::string filename = (this->caseInsensitive ? ToUpper(file) : file);

        for (const auto& entry : std::filesystem::directory_iterator(path))
        {
            std::string entryname = (this->caseInsensitive ? ToUpper(entry.path().filename().string()) : entry.path().filename().string());

            if (filename == entryname)
            {
                return std::filesystem::canonical(entry.path()).string();
            }

            if (this->recursiveMode && entry.is_directory())
            {
                return SearchForFileInPath(file, entry.path().string());
            }
        }

        return "NOT FOUND";
    }

    std::string Forker::ToUpper(const std::string& str) const
    {
        std::string result = str;

        for (char& c : result)
        {
            c = toupper(c);
        }

        return result;
    }
}