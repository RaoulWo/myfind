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
        void Child(const std::string& filename) const;
        std::string SearchForFileInPath(const std::string& file, const std::string& path) const;
        std::string ToUpper(const std::string& str) const;

        bool caseInsensitive = false;
        bool recursiveMode = false;

        std::string searchpath;
        std::vector<std::string> filenames;
    };

}

#endif