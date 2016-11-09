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
#include "simple_cursor.hpp"

#include "chef/lib/stl.hpp"
#include "chef/MasterChefModule.hpp"

#include "CurlUtil.hpp"

#include "Stores.hpp"
#include "ResponseObject.hpp"
#include "SharedPreferences.hpp"

class ConfigModule : public MasterChefModule<ConfigModule> {
    using package_mapper = map<naomi_gen::package, package_map>;

public:
    ConfigModule();

public:
    virtual void set_packages(package_mapper * mapper) override;

public:
    void get_stores(const shared_ptr<MasterChefHandler>& handler,
            const unordered_map<string, string>& params,
            const shared_ptr<naomi_gen::ServiceBinder>& callback);

private:
    
    shared_ptr<naomi_gen::SimpleCursor> save_stores(const HasMany<Stores> & stores);

    void load_store_list(const shared_ptr<MasterChefHandler>& handler,
            const shared_ptr<naomi_gen::ServiceBinder>& callback);

};

#endif /* CONFIGMODULE_HPP */

