/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PeanutHandler.cpp
 * Author: izehi
 * 
 * Created on October 24, 2016, 2:41 PM
 */

#include "PeanutHandler.hpp"

PeanutHandler::PeanutHandler(const shared_ptr<naomi_gen::Handler> & handler)
: m_handler {handler} {
    
}

PeanutHandler::~PeanutHandler() {
}

void PeanutHandler::handle(const TaskHandler::Task & task) {
    m_handler->post(make_shared<naomi::RunnableHandler>(task));
}