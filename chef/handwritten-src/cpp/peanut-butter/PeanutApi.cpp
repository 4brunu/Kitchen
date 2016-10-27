/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PeanutApi.cpp
 * Author: izehi
 * 
 * Created on October 24, 2016, 9:30 AM
 */

#include "PeanutApi.hpp"

PeanutApi::PeanutApi(const string & root,
            const shared_ptr<Handler> & handler, 
            const shared_ptr<Service> & service) {
    m_handler = make_shared<PeanutHandler>(handler);
    m_service = make_shared<PeanutService>(service);
    
    cout << root;
    m_application = make_shared<PeanutSheaButter>(m_handler, m_service);
}

PeanutApi::~PeanutApi() {
    
}

shared_ptr<Sandwich> PeanutApi::get_application() {
    return m_application;
}

shared_ptr<Api> Api::get_instance(const string & root, 
        const shared_ptr<Handler> & handler, 
        const shared_ptr<Service> & service) {
	return make_shared<PeanutApi>(root, handler, service);
}

