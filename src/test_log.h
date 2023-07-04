#pragma once

#include <boost/log/trivial.hpp>

class test_log
{
public:
    static void run()
    {
        test_log o;
        o.run();
    }

    void init()
    {
        BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
        BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
        BOOST_LOG_TRIVIAL(info) << "An informational severity message";
        BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
        BOOST_LOG_TRIVIAL(error) << "An error severity message";
        BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";
    }

};
