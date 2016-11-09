/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MasterChefApi.cpp
 * Author: izehi
 * 
 * Created on October 24, 2016, 9:30 AM
 */

#include "include/chef/MasterChefApi.hpp"

MasterChefApi::MasterChefApi(const string & root,
            const shared_ptr<Handler> & handler, 
            const shared_ptr<Service> & service) : m_root { move(root) } {
    
    m_application = make_shared<MasterChef>(m_root, handler, service);
}

shared_ptr<Chef> MasterChefApi::get_chef() {
    return m_application;
}

shared_ptr<Api> Api::get_instance(const string & root, 
        const shared_ptr<Handler> & handler, 
        const shared_ptr<Service> & service) {
	return make_shared<MasterChefApi>(root, handler, service);
}

