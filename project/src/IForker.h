#ifndef IFORKER_H
#define IFORKER_H

namespace MyFind
{

    class IForker
    {
    public:
        virtual ~IForker() {}

        /// @brief Forks a child process for each filename
        virtual void Fork() const = 0;
    };

}


#endif