/*******************************************************************************
 * File Name: InputMediator
 * Owner: Sahar Moalem
 * Reviewer: 
 * Review status: 
 ******************************************************************************/
#ifndef  ILRD_RD1645_INPUTMEDIATOR_HPP
#define  ILRD_RD1645_INPUTMEDIATOR_HPP

#include <memory>

#include "IInputProxy.hpp"
#include "Ilistener.hpp"


namespace ilrd
{
class InputMediator
{
public:
    InputMediator(std::shared_ptr<IInputProxy> input_proxy);
    void ReactorCallback(int fd, IListener::Mode mode);

private:
    std::shared_ptr<IInputProxy> m_input_proxy;
};
}

#endif