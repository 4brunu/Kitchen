/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ConfigModule.cpp
 * Author: izehi
 *
 * Created on October 27, 2016, 11:49 PM
 */

#include "ConfigModule.hpp"

ConfigModule::ConfigModule() {
}

void ConfigModule::set_packages(package_mapper* mapper) {
    mapper->insert(pair<naomi_gen::package, package_map>(action::STORE_LIST,
            &ConfigModule::get_stores));
}

/**
 * 
 * @param handler
 * @param params
 * @param callback
 */
void ConfigModule::get_stores(const shared_ptr<MasterChefHandler>& handler,
        const unordered_map<string, string>& params,
        const shared_ptr<naomi_gen::ServiceBinder>& callback) {

    CurlUtil curl_util("config/get_stores", params);
    if (callback->load_type() == naomi_gen::load_type::LAZY) {
        load_store_list(handler, callback);
    }
    
    ResponseObject<Stores> response;
    shared_ptr<naomi_gen::SimpleCursor> stores;

    try {
        curl_util.make_request();     
        response.parse(curl_util.get_response().c_str()); 
   
        stores = save_stores(response.m_data);
        handler->handle([callback, response, stores] () {
            
            callback->on_load(response.m_message, false, stores);
        });
    } catch (curl::curl_easy_exception error) {

        handler->handle([callback, error] () {
            callback->on_error(string("Error in connection: ") + error.what());
        }); 
    }
}

/**
 * 
 * @param stores
 * @return 
 */
shared_ptr<naomi_gen::SimpleCursor> ConfigModule::save_stores(
        const HasMany<Stores> & stores) {
    SharedPreferences preferences(get_path());
    preferences.save_all<Stores>(stores);
    
    return preferences.get_all<Stores>();
}

/**
 * 
 * @param handler
 * @param callback
 */
void ConfigModule::load_store_list(const shared_ptr<MasterChefHandler>& handler,
        const shared_ptr<naomi_gen::ServiceBinder>& callback) {
    SharedPreferences preferences(get_path());
    
    shared_ptr<naomi_gen::SimpleCursor> cursor = preferences.get_all<Stores>();
    handler->handle([callback, cursor] () {

        callback->on_load("CACHED", true, cursor);
    });
}



