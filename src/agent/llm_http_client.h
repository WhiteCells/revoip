#pragma once

#include <boost/asio.hpp>

namespace net = boost::asio;

class LLMHttpClient
{
public:
    LLMHttpClient(net::io_context &ioc);
    ~LLMHttpClient();

private:
    
};