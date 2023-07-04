#pragma once

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

namespace logging = boost::log;

class test_log
{
public:
    static void run() 
    {
        BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
        BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
        BOOST_LOG_TRIVIAL(info) << "An informational severity message";
        BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
        BOOST_LOG_TRIVIAL(error) << "An error severity message";
        BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";
    }

    void init()
    {
        logging::core::get()->set_filter
        (
            logging::trivial::severity >= logging::trivial::info
        );
    }

};
