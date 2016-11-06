/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RestModel.hpp
 * Author: izehi
 *
 * Created on November 1, 2016, 2:26 PM
 */

#ifndef RESTMODEL_HPP
#define RESTMODEL_HPP

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
class RestModel : public Model<T>
{
public:

    RestModel()
    {
    }

    virtual ~RestModel()
    {
        delete m_db;
    }

    static const std::string &class_name()
    {
        static std::string class_name = type_info_name(typeid (T));
        return class_name;
    }

    virtual std::string primary_key() const
    {
        throw std::logic_error(std::string("endpoint not implemented for ") + class_name());
    }

    void initialize(string path)
    {
        leveldb::Options options;
        options.create_if_missing = true;
        m_this = dynamic_cast<T *> (this);

        m_root = path;
        string root = path + m_this->endpoint();
        Status status = DB::Open(options, root, &m_db);

        if (!status.ok())
        {
            throw std::logic_error(std::string("error creating db in ") + class_name());
        }
    }

public:

    void save(string * str)
    {
        string s = m_this->to_json(IGNORE_DIRTY_FLAG);
        str = &s;
        if (str == nullptr) {
            
        }
        //string key = item->read_field(item->primary_key());
        //m_db->Put(WriteOptions(), "2", m_this->to_json(IGNORE_DIRTY_FLAG));
    }

private:
    string m_root;

private:
    T * m_this;
    leveldb::DB * m_db;

public:

    string fetch_model(const string & path)
    {
        leveldb::DB * db;
        leveldb::Options options;
        options.create_if_missing = true;
        T * item = dynamic_cast<T *> (this);

        string res;
        string root = path + item->endpoint();
        Status status = DB::Open(options, root, &db);

        if (status.ok())
        {
            db->Get(leveldb::ReadOptions(), "3", &res);
        }
        delete db;
        return res;
    }

};

#endif /* RESTMODEL_HPP */

