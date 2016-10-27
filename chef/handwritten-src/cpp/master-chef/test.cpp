/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   test.h
 * Author: izehi
 *
 * Created on October 25, 2016, 6:40 PM
 */

#ifndef TEST_H
#define TEST_H

#include "include/chef/lib/stl.hpp"
#include "response.hpp"
#include "intention.hpp"
#include "include/chef/MasterChefModule.hpp"

#include "curl_easy.h"
#include "curl_exception.h"

class test final : public MasterChefModule<test> {
public:

    test() {

    }

    virtual ~test() {

    }

private:

    void testing(const shared_ptr<naomi_gen::Response>& callback) {
        using curl::curl_easy;
        using curl::curl_ios;
        using curl::curl_easy_exception;
        using curl::curlcpp_traceback;

        ostringstream str;
        curl_ios<ostringstream> writer(str);

        curl_easy easy(writer);

        easy.add<CURLOPT_URL>("http://www.google.it");
        easy.add<CURLOPT_FOLLOWLOCATION>(1L);
        try {
            easy.perform();
        } catch (curl_easy_exception error) {
        }
        get_handler()->handle([callback, &str] () {
            callback->on_load(str.str());
        });
    }

public:

    virtual void set_intentions(map<naomi_gen::intention, intent_map> * mapper) override {
        cout << mapper->size();
        mapper->insert(pair<naomi_gen::intention, intent_map>(action::STORE_LIST, &test::testing));
    }

    virtual void serve(naomi_gen::intention intent, const shared_ptr<naomi_gen::Response>& callback) override {
        map<naomi_gen::intention, intent_map> mapper = get_mapper();
        set_intentions(&mapper);

        intent_map task = mapper.at(intent);
        get_service()->handle([&, task, callback] () {
            ((* this).*task)(callback);
        });
    }

};

#endif /* TEST_H */

