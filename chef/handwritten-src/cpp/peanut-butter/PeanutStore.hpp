/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PeanutStore.hpp
 * Author: izehi
 *
 * Created on October 25, 2016, 2:02 PM
 */

#ifndef PEANUTSTORE_HPP
#define PEANUTSTORE_HPP

#include "map"
#include "stl.hpp"
#include "module.hpp"
#include "PeanutModule.hpp"
#include "PeanutHandler.hpp"
#include "PeanutService.hpp"

class PeanutStore
{
public:
    map<naomi_gen::module, shared_ptr<PeanutDish>> getPeanuts();

public:
    void addPeanut(const shared_ptr<PeanutDish> & module_obj, naomi_gen::module module);

public:
    PeanutStore(const shared_ptr<PeanutHandler> & handler, const shared_ptr<PeanutService> & service);
    virtual ~PeanutStore();

private:
    shared_ptr<PeanutHandler> m_handler;
    shared_ptr<PeanutService> m_service;

private:
    map<naomi_gen::module, shared_ptr<PeanutDish>> m_mapper;

};

#endif /* PEANUTSTORE_HPP */

