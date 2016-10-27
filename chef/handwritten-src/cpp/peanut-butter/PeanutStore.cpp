/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PeanutStore.cpp
 * Author: izehi
 * 
 * Created on October 25, 2016, 2:02 PM
 */

#include "PeanutStore.hpp"

PeanutStore::PeanutStore(const shared_ptr<PeanutHandler> & handler, const shared_ptr<PeanutService> & service) 
: m_handler {handler}, m_service {service} {
}

PeanutStore::~PeanutStore() {
}

map<naomi_gen::module, shared_ptr<PeanutDish>> PeanutStore::getPeanuts() {
    return m_mapper;
}

void PeanutStore::addPeanut(const shared_ptr<PeanutDish> & module_obj, naomi_gen::module module) {
    module_obj->set_handler(m_handler);
    module_obj->set_service(m_service);
    m_mapper.insert( pair<naomi_gen::module, shared_ptr<PeanutDish>>(module, module_obj) );
}

