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
        Forker(std::vector<std::string> filenames);
        virtual ~Forker() {}

        void Fork() const override;

    private:
        void Child(std::string filename) const;
        void Parent() const;

        std::vector<std::string> filenames;
    };

}

#endif