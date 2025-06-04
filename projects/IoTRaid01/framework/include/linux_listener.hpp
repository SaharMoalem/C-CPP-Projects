#ifndef  ILRD_RD1645_LINUX_LISTENER_HPP
#define  ILRD_RD1645_LINUX_LISTENER_HPP

#include "Ilistener.hpp"

namespace ilrd
{
class LinuxListener: public IListener
{
public:
    LinuxListener() = default;
    ~LinuxListener() = default;
    std::vector<std::pair<int, IListener::Mode>> Listen(std::vector<std::pair<int, IListener::Mode>> fd_list);
};
}

#endif