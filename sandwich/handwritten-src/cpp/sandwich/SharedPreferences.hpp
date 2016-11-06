/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SharedPreferences.hpp
 * Author: izehi
 *
 * Created on November 3, 2016, 5:06 PM
 */

#ifndef SHAREDPREFERENCES_HPP
#define SHAREDPREFERENCES_HPP

#include "leveldb/db.h"
#include "chef/lib/stl.hpp"

#pragma GCC diagnostic push 
#pragma GCC diagnostic ignored "-Wunused-parameter"

#include <restful_mapper/model.h>
#include <restful_mapper/internal/utf8.h>

#pragma GCC diagnostic pop

using namespace leveldb;
using namespace restful_mapper;

class SharedPreferences
{
public:

    SharedPreferences(const string & root)
    : m_root{root}
    {
    }

private:
    
    template <class T>
    static const std::string &class_name()
    {
        static std::string class_name = type_info_name(typeid (T));
        return class_name;
    }

public:

    template <class T>
    void save(const T & model)
    {

    }

    template <class T>
    void save_all(const HasMany<T> & models)
    {
        cout << models.size();
        /**if (models.size() <= 0)
        {
            return;
        }
        leveldb::DB * db;
        leveldb::Options options;
        options.create_if_missing = true;

        string root = "ll";//m_root + models.begin()->endpoint();
        Status status = DB::Open(options, root, &db);
        if (!status.ok())
        {
            return;
        }
        for (T item : models)
        {
            //string key = item.read_field(item.primary_key());
            //db->Put(WriteOptions(), "3", item.to_json(IGNORE_DIRTY_FLAG));
        }
        delete db;**/
    }

private:
    string m_root;

};

#endif /* SHAREDPREFERENCES_HPP */

