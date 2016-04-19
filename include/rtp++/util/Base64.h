#pragma once
#include <string>

namespace rtp_plus_plus {

std::string base64_encode(const std::string& s);
std::string base64_encode(unsigned char const* , unsigned int len);
std::string base64_decode(std::string const& s);

} // rtp_plus_plus

