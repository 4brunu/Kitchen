/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BaseModule.hpp
 * Author: izehi
 *
 * Created on October 30, 2016, 11:07 PM
 */

#ifndef BASEMODULE_HPP
#define BASEMODULE_HPP

#include "chef/lib/stl.hpp"
#include "chef/MasterChefModule.hpp"

#include "curl_ios.h"
#include "curl_easy.h"
#include "curl_pair.h"
#include "curl_form.h"
#include "curl_exception.h"
#include "curl_header.h"

template <class T>
class BaseModule : public MasterChefModule<T>
{
public:

    BaseModule()
    {
    }

    virtual ~BaseModule()
    {
    }

public:

    bool execute(curl::curl_easy easy, 
            curl::curl_header header, 
            const unordered_map<string, string>& param)
    {
        curl::curl_form form;
        
        using curl_pair = curl::curl_pair<CURLformoption, string>;
        
        header.add(m_header_token);
        header.add(m_header_accept);
        
        for (auto itr = param.begin(); itr != param.end(); ++itr) {
            curl_pair name(CURLFORM_COPYNAME, itr->first);
            curl_pair value(CURLFORM_COPYCONTENTS, itr->second);
            
            form.add(name, value);
        }
        easy.add<CURLOPT_FOLLOWLOCATION>(1L);
        easy.add<CURLOPT_HTTPPOST>(form.get());
        easy.add<CURLOPT_SSL_VERIFYPEER>(false);
        easy.add<CURLOPT_HTTPHEADER>(header.get());

        try
        {
            easy.perform();
            return true;
        } catch (curl::curl_easy_exception error)
        {
            return false;
        }
    }

public:

    bool execute(curl::curl_easy easy, 
            const unordered_map<string, string>& param)
    {
        curl::curl_header header;
        return execute(easy, header, param);
    }

private:
    string m_header_accept = "Accept: application/json";
    string m_header_token = "token: 50a868a0f44374e524ae8c2506aa8b4e";
};

#endif /* BASEMODULE_HPP */

