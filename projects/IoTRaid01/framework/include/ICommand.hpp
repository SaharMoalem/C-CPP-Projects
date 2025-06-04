/*******************************************************************************
 * File Name: ICommand
 * Owner: Sahar Moalem
 * Reviewer: 
 * Review status: 
 ******************************************************************************/
#ifndef  ILRD_RD1645_ICommand_HPP
#define  ILRD_RD1645_ICommand_HPP

#include <optional>             // optional
#include <memory>

#include "AsyncInjection.hpp"
#include "ITaskArgs.hpp"

namespace ilrd
{
class ICommand
{
public:
    virtual std::optional<std::pair<AsyncFunc, std::chrono::milliseconds>> Run(std::shared_ptr<ITaskArgs> args) = 0;
};
}

#endif