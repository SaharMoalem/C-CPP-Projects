/*******************************************************************************
 * File Name: AsyncInjection
 * Owner: Sahar Moalem
 * Reviewer: Zack
 * Review status: Approved
 ******************************************************************************/
#ifndef  ILRD_RD1645_ASYNCINJECTION_HPP
#define  ILRD_RD1645_ASYNCINJECTION_HPP

#include <functional>
#include <chrono>

#include "Ischedulertask.hpp"

namespace ilrd
{
using AsyncFunc = std::function<bool()>;

class AsyncInjection
{
public:
    AsyncInjection(AsyncFunc task, std::chrono::milliseconds interval);

private:
    ~AsyncInjection() = default;
    void PerformAction();

    class AsyncInjectionTask: public ISchedulerTask
    {
    public:
        AsyncInjectionTask(AsyncInjection& async);
        void Run() override;

    private:
        AsyncInjection& m_async;
    };

    AsyncFunc m_task;
    std::chrono::milliseconds m_interval;
};
}

#endif