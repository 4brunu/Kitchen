/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ResponseObject.hpp
 * Author: izehi
 *
 * Created on November 1, 2016, 11:11 AM
 */

#ifndef RESPONSEOBJECT_HPP
#define RESPONSEOBJECT_HPP

#include "leveldb/db.h"
#include "chef/lib/stl.hpp"

#pragma GCC diagnostic push 
#pragma GCC diagnostic ignored "-Wunused-parameter"

#include <restful_mapper/model.h>
#include <restful_mapper/internal/utf8.h>

#pragma GCC diagnostic pop

using namespace leveldb;
using namespace restful_mapper;

template<class T>
class ResponseObject {
public:
    
    HasMany<T> m_data;

public:
    
    string m_status;
    string m_message;

public:

    bool parse(const string& response) {
        Json::Parser parser(response);
        
        vector<Json::Node> data = parser.find("data").to_array();
        vector<Json::Node> messages = parser.find("message").to_array();
        
        m_message = messages[0].to_string();
        m_status = parser.find("status").to_string();
        
        for (auto itr = data.begin(); itr != data.end(); ++itr) {
            T model;
            model.from_json(itr->dump());
            
            m_data.push_back(model);
        }
        return true;
    }

};

#endif /* RESPONSEOBJECT_HPP */


