#pragma once

#include <boost/asio.hpp>

namespace net = boost::asio;

class TTSHttpClient
{
public:
    TTSHttpClient(net::io_context &ioc);
    ~TTSHttpClient();

private:
};