/*******************************************************************************
 * File Name: Logger
 * Owner: Sahar Moalem
 * Reviewer: Shani
 * Review status: Approved
 ******************************************************************************/
#ifndef  ILRD_RD1645_LOGGER_HPP
#define  ILRD_RD1645_LOGGER_HPP

#include <string>
#include <fstream>
#include <thread>

#include "handleton.hpp"
#include "waitable_queue.hpp"

namespace ilrd
{
class Logger
{
public:
    ~Logger();

    enum Severity
    {
        DEBUG,
        WARNING,
        ERROR,
        NUM_OF_SEVERITIES
    };

    void Log(const std::string& message, Severity sev);

private:
    friend class Handleton;
    Logger();
    Logger(const Logger& other) = delete;
    Logger& operator=(const Logger& other) = delete;

    struct Message
    {
        std::chrono::time_point<std::chrono::system_clock> time_created;
        std::string text;
        Severity sev;
    };

    void LoggerRun();
    void LogMessageTask(Message& message);

    WaitableQueue<Message> m_queue;
    std::ofstream s_logger;
    bool m_running;
    std::thread m_thread;

    static std::string s_sev_lut[NUM_OF_SEVERITIES];
};

}

#endif