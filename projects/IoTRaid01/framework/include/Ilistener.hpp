/*******************************************************************************
 * File Name: Listener
 * Owner: Sahar Moalem
 * Reviewer: Alon
 * Review status: Approved
 ******************************************************************************/
#ifndef  ILRD_RD1645_LISTENER_HPP
#define  ILRD_RD1645_LISTENER_HPP

#include <vector>

namespace ilrd
{
class IListener
{
public:
    enum Mode {
        WRITE,
        READ
    };

    virtual std::vector<std::pair<int, Mode>> Listen(std::vector<std::pair<int, Mode>> fd_list) = 0;
};
}

#endif