#include "Forker.h"

#include <iostream>
#include <sys/types.h>
#include <unistd.h>

namespace MyFind
{

    Forker::Forker(std::vector<std::string> filenames)
    { 
        this->filenames = filenames;
    }

    void Forker::Fork() const
    {
        pid_t pid;

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
                this->Parent();
            }
        }
    }

    void Forker::Child(std::string filename) const
    {
        // TODO -> Search for file
        


        exit(EXIT_SUCCESS);
    }

    void Forker::Parent() const
    {

    }

}