/*******************************************************************************
 * File Name: ISchedulerTask
 * Owner: Sahar Moalem
 * Reviewer: 
 * Review status: 
 ******************************************************************************/
#ifndef  ILRD_RD1645_ISCHEDULERTASK_HPP
#define  ILRD_RD1645_ISCHEDULERTASK_HPP

namespace ilrd
{
class ISchedulerTask
{
public:
    virtual void Run() = 0;
};
}

#endif