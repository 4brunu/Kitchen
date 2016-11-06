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

#include "chef/lib/stl.hpp"
#include "RestModel.hpp"

template<class T>
class ResponseObject : public RestModel<ResponseObject<T>>
{
public:
    HasMany<T> m_data;
    Field<string> m_status;
    Field<string> m_message;
    
public:
    virtual void map_set(Mapper &mapper) const
    {
        mapper.set("data", m_data);
        mapper.set("status", m_status);
    }
    
    virtual void map_get(const Mapper &mapper) 
    {
        mapper.get("data", m_data);
        mapper.get("status", m_status);
    }

};

#endif /* RESPONSEOBJECT_HPP */

