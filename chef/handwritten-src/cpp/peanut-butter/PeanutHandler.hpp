/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PeanutHandler.hpp
 * Author: izehi
 *
 * Created on October 24, 2016, 2:41 PM
 */

#ifndef PEANUTHANDLER_HPP
#define PEANUTHANDLER_HPP

#include "stl.hpp"

using namespace naomi;

class PeanutHandler final : public TaskHandler
{
private:
    shared_ptr<naomi_gen::Handler> m_handler;    
    
public:
    PeanutHandler(const shared_ptr<naomi_gen::Handler> & handler);
    virtual ~PeanutHandler();
    
public:
    virtual void handle(const TaskHandler::Task & task) override;

};

#endif /* PEANUTHANDLER_HPP */

