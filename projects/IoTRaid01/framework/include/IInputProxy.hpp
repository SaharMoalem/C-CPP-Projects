/*******************************************************************************
 * File Name: IInputProxy
 * Owner: Sahar Moalem
 * Reviewer: 
 * Review status: 
 ******************************************************************************/
#ifndef  ILRD_RD1645_IInputProxy_HPP
#define  ILRD_RD1645_IInputProxy_HPP

#include <memory>

#include "ITaskArgs.hpp"

namespace ilrd
{
enum FDMODE {
        WRITE,
        READ
    };

class IInputProxy
{
public:
    virtual std::shared_ptr<ITaskArgs> GetTaskArgs(int fd, FDMODE mode) = 0;
};
}

#endif