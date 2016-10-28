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

ConfigModule::~ConfigModule() {
}

void ConfigModule::set_intentions(map<naomi_gen::intention, intent_map>* mapper) {
    mapper->insert(pair<naomi_gen::intention, intent_map>(action::STORE_LIST, &ConfigModule::testing));
}

void ConfigModule::testing(const shared_ptr<naomi_gen::Response>& callback) {
    using curl::curl_easy;
    using curl::curl_ios;
    using curl::curl_easy_exception;
    using curl::curlcpp_traceback;

    ostringstream str;
    curl_ios<ostringstream> writer(str);

    curl_easy easy(writer);

    easy.add<CURLOPT_URL>("http://www.google.ng");
    easy.add<CURLOPT_FOLLOWLOCATION>(1L);
    try {
        easy.perform();
    } catch (curl_easy_exception error) {
    }
    get_handler()->handle([callback, &str] () {
        callback->on_load(str.str());
    });
}