/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MasterChefHandler.hpp
 * Author: izehi
 *
 * Created on October 24, 2016, 2:41 PM
 */

#ifndef MasterChefHANDLER_HPP
#define MasterChefHANDLER_HPP

#include "lib/stl.hpp"

using namespace naomi;

class MasterChefHandler final : public TaskHandler
{
private:
    shared_ptr<naomi_gen::Handler> m_handler;    
    
public:
    MasterChefHandler(const shared_ptr<naomi_gen::Handler> & handler);
    virtual ~MasterChefHandler();
    
public:
    virtual void handle(const TaskHandler::Task & task) override;

};

#endif /* MasterChefHANDLER_HPP */

