/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConfigModule.hpp
 * Author: izehi
 *
 * Created on October 27, 2016, 11:49 PM
 */

#ifndef CONFIGMODULE_HPP
#define CONFIGMODULE_HPP

#include "chef/lib/stl.hpp"
#include "response.hpp"
#include "intention.hpp"
#include "chef/MasterChefModule.hpp"

#include "curl_easy.h"
#include "curl_exception.h"

class ConfigModule : public MasterChefModule<ConfigModule>
{
public:
    ConfigModule();
    virtual ~ConfigModule();

public:
    virtual void set_intentions(map<naomi_gen::intention, intent_map> * mapper) override;

public:
    void testing(const shared_ptr<naomi_gen::Response>& callback);

};

#endif /* CONFIGMODULE_HPP */

