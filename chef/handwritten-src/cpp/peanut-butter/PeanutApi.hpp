/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PeanutApi.hpp
 * Author: izehi
 *
 * Created on October 24, 2016, 9:30 AM
 */

#ifndef PEANUTAPI_HPP
#define PEANUTAPI_HPP

#include "stl.hpp"
#include "api.hpp"
#include "handler.hpp"
#include "service.hpp"

#include "PeanutHandler.hpp"
#include "PeanutSheaButter.hpp"

using namespace naomi_gen;

class PeanutApi : public Api
{
public:
    virtual shared_ptr<Sandwich> get_application() override;

public:
    PeanutApi(const string & root,
            const shared_ptr<Handler> & handler, 
            const shared_ptr<Service> & service);
    
    virtual ~PeanutApi();
    
private:
    string name;
    
private:
    shared_ptr<PeanutHandler> m_handler;
    shared_ptr<PeanutService> m_service;
    shared_ptr<PeanutSheaButter> m_application;
};

#endif /* PEANUTAPI_HPP */

