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

#include "load_type.hpp"
#include "service_binder.hpp"
#include "package.hpp"

#include "chef/lib/stl.hpp"
#include "BaseModule.hpp"
#include "Stores.hpp"
#include "ResponseObject.hpp"
#include "SharedPreferences.hpp"

#include "curl_ios.h"
#include "curl_easy.h"
#include "curl_exception.h"
#include "curl_header.h"

class ConfigModule : public BaseModule<ConfigModule>
{
    using package_mapper = map<naomi_gen::package, package_map>;

public:
    ConfigModule();

public:
    virtual void set_packages(package_mapper * mapper) override;

public:
    void testing(const shared_ptr<MasterChefHandler>& handler,
            const unordered_map<string, string>& params,
            const shared_ptr<naomi_gen::ServiceBinder>& callback);

};

#endif /* CONFIGMODULE_HPP */

