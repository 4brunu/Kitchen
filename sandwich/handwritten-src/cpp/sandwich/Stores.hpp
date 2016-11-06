/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stores.hpp
 * Author: izehi
 *
 * Created on November 1, 2016, 12:24 PM
 */

#ifndef STORES_HPP
#define STORES_HPP

#include "chef/lib/stl.hpp"
#include "RestModel.hpp"

class Stores : public RestModel<Stores>
{
public:
    Field<string> m_store_id;
    Field<string> m_store_name;
    Field<string> m_store_code;

public:

    Stores()
    {
    }

    virtual void map_set(Mapper &mapper) const
    {
        mapper.set("store_id", m_store_id);
        mapper.set("store_name", m_store_name);
        mapper.set("store_code", m_store_code);
    }

    virtual void map_get(const Mapper &mapper)
    {
        mapper.get("store_id", m_store_id);
        mapper.get("store_name", m_store_name);
        mapper.get("store_code", m_store_code);
    }

public:

    virtual string endpoint() const
    {
        return "/store_list";
    }

    virtual string primary_key() const
    {
        return "store_id";
    }

};

#endif /* STORES_HPP */

