/*******************************************************************************
 * File Name: ITaskArgs
 * Owner: Sahar Moalem
 * Reviewer: 
 * Review status: 
 ******************************************************************************/
#ifndef  ILRD_RD1645_ITASKARGS_HPP
#define  ILRD_RD1645_ITASKARGS_HPP

namespace ilrd
{
class ITaskArgs
{
public:
    virtual int GetKey() const = 0;
};
}

#endif