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
    mapper->insert(pair<naomi_gen::package, package_map>(action::STORE_LIST, &ConfigModule::testing));
}

void ConfigModule::testing(const shared_ptr<MasterChefHandler>& handler,
        const unordered_map<string, string>& params,
        const shared_ptr<naomi_gen::ServiceBinder>& callback) {
    using curl::curl_easy;
    using curl::curl_ios;

    ostringstream str;
    curl_ios<ostringstream> writer(str);

    curl_easy easy(writer);
    easy.add<CURLOPT_URL>("http://payporte.com/connector/config/get_stores");

    if (callback->load_type() == naomi_gen::load_type::LAZY) {
        handler->handle([callback] () {
            callback->on_load("hello bruh!!!", nullptr);
        });
    }

    curl::curl_header header;
    curl::curl_form form;

    using curl_pair = curl::curl_pair<CURLformoption, string>;

    header.add("token: 50a868a0f44374e524ae8c2506aa8b4e");
    header.add("Accept: application/json");

    for (auto itr = params.begin(); itr != params.end(); ++itr) {
        curl_pair name(CURLFORM_COPYNAME, itr->first);
        curl_pair value(CURLFORM_COPYCONTENTS, itr->second);

        form.add(name, value);
    }
    easy.add<CURLOPT_FOLLOWLOCATION>(1L);
    easy.add<CURLOPT_HTTPPOST>(form.get());
    easy.add<CURLOPT_SSL_VERIFYPEER>(false);
    easy.add<CURLOPT_HTTPHEADER>(header.get());

    try {
        easy.perform();
        const char * s = str.str().c_str();
        handler->handle([callback, s] () {
            callback->on_load(s, nullptr);
        });
    } catch (curl::curl_easy_exception error) {
        handler->handle([callback] () {
            callback->on_load("failed", nullptr);
        });
    }
}



