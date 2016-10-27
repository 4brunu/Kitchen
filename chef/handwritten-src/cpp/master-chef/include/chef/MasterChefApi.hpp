/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MasterChefApi.hpp
 * Author: izehi
 *
 * Created on October 24, 2016, 9:30 AM
 */

#ifndef MasterChefAPI_HPP
#define MasterChefAPI_HPP

#include "lib/stl.hpp" 
#include "api.hpp"
#include "handler.hpp"
#include "service.hpp"

#include "MasterChefHandler.hpp"
#include "MasterChef.hpp"

using namespace naomi_gen;

class MasterChefApi : public Api
{
public:
    virtual shared_ptr<Chef> get_chef() override;

public:
    MasterChefApi(const string & root,
            const shared_ptr<Handler> & handler, 
            const shared_ptr<Service> & service);
    
    virtual ~MasterChefApi();
    
private:
    string name;
    
private:
    shared_ptr<MasterChefHandler> m_handler;
    shared_ptr<MasterChefService> m_service;
    shared_ptr<MasterChef> m_application;
};

#endif /* MasterChefAPI_HPP */

