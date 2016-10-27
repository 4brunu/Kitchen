/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MasterChefHandler.cpp
 * Author: izehi
 * 
 * Created on October 24, 2016, 2:41 PM
 */

#include "include/chef/MasterChefHandler.hpp"

MasterChefHandler::MasterChefHandler(const shared_ptr<naomi_gen::Handler> & handler)
: m_handler {handler} {
    
}

MasterChefHandler::~MasterChefHandler() {
}

void MasterChefHandler::handle(const TaskHandler::Task & task) {
    m_handler->post(make_shared<naomi::RunnableHandler>(task));
}