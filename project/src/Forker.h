#ifndef FORKER_H
#define FORKER_H

#include "IForker.h"

#include <string>
#include <vector>

namespace MyFind
{
    
    class Forker final : public IForker
    {
    public:
        Forker(
            std::string searchpath, 
            std::vector<std::string> filenames, 
            bool caseInsensitive, bool 
            recursiveMode);
        virtual ~Forker() {}

        void Fork() const override;

    private:
        void Child(std::string filename) const;
        void Parent() const;

        bool caseInsensitive = false;
        bool recursiveMode = false;

        std::string searchpath;
        std::vector<std::string> filenames;
    };

}

#endif