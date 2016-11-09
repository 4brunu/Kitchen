/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CurlUtil.hpp
 * Author: constantine
 *
 * Created on November 8, 2016, 10:56 AM
 */

#ifndef CURLUTIL_HPP
#define CURLUTIL_HPP

#include "chef/lib/stl.hpp"

#include "curl_ios.h"
#include "curl_easy.h"
#include "curl_pair.h"
#include "curl_form.h"
#include "curl_exception.h"
#include "curl_header.h"

using namespace curl;

class CurlUtil {
    using curl_pair = curl::curl_pair<CURLformoption, string>;

    string m_header_accept = "Accept: application/json";
    string m_base_url = "http://payporte.com/connector/";
    string m_header_credential = "token: 50a868a0f44374e524ae8c2506aa8b4e";

public:

    CurlUtil(const string & url, const unordered_map<string, string>& params)
    : m_url{url}, m_params{params}
    {
    }

    void make_request() {
        curl_form form;
        curl_header header;

        curl_ios<ostringstream> writer(m_response);
        m_easy = make_shared<curl_easy>(writer);

        string url = m_base_url + m_url;
        
        m_easy->add<CURLOPT_URL>(url.c_str());
        m_easy->add<CURLOPT_FOLLOWLOCATION>(1L);
        m_easy->add<CURLOPT_SSL_VERIFYPEER>(false);

        header.add(m_header_accept);
        header.add(m_header_credential);

        for (auto itr = m_params.begin(); itr != m_params.end(); ++itr) {
            curl_pair name(CURLFORM_COPYNAME, itr->first);
            curl_pair value(CURLFORM_COPYCONTENTS, itr->second);

            form.add(name, value);
        }
        m_easy->add<CURLOPT_HTTPPOST>(form.get());
        m_easy->add<CURLOPT_HTTPHEADER>(header.get());
        
        m_easy->perform();
    }

    string get_response() {
        return m_response.str();
    }

private:

    shared_ptr<curl_easy> m_easy;

private:

    string m_url;
    ostringstream m_response;

private:

    unordered_map<string, string> m_params;

};


#endif /* CURLUTIL_HPP */

