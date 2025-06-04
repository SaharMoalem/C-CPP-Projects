/*******************************************************************************
 * File Name: ISchedulerTask
 * Owner: Sahar Moalem
 * Reviewer: 
 * Review status: 
 ******************************************************************************/
#ifndef  ILRD_RD1645_SCHEDULERTASK_HPP
#define  ILRD_RD1645_SCHEDULERTASK_HPP

#include <functional>
#include "Ischedulertask.hpp"

namespace ilrd
{

template<typename ...ARGS>
class SchedulerTask: public ISchedulerTask
{
public:
    explicit SchedulerTask(std::function<void(ARGS...)> task, ARGS... args);
    ~SchedulerTask() = default;
    SchedulerTask(const SchedulerTask& other) = delete;
    SchedulerTask& operator=(const SchedulerTask& other) = delete;

    void Run() override;

private:
    std::function<void(ARGS...)> m_task;
    std::tuple<ARGS...> m_args;
};

template<typename ...ARGS>
SchedulerTask<ARGS...>::SchedulerTask(std::function<void(ARGS...)> task,
                                    ARGS... args): m_task(task), m_args(args) {}

template<typename ...ARGS>
void SchedulerTask<ARGS...>::Run()
{
    std::apply(m_task, m_args);
}
}

#endif