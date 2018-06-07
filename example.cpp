#include <iostream>
#include <string>

#include <boost/algorithm/hex.hpp>      // boost::hex

#include "login_to_id_converter.h"      //

int main( int argc, const char* argv[] )
{
    if( argc != 3 )
    {
        std::cout << "USAGE: example <login> <password>" << std::endl;
        return 0;
    }

    std::string login       = argv[1];
    std::string password    = argv[2];

    std::cout << "login     = " << login << std::endl;
    std::cout << "password  = " << password << std::endl;

    auto login_hash     = password_hasher::convert_login_to_id( login );
    auto login_hash_i   = password_hasher::convert_login_to_id( login, false );
    auto password_hash  = password_hasher::convert_password_to_hash( password );

    auto password_hash_hex = boost::algorithm::hex( password_hash );

    std::cout << "login hash    = " << login_hash << std::endl;
    std::cout << "login hash    = " << login_hash_i << " (case insensitive)" << std::endl;
    std::cout << "password hash = " << password_hash_hex << std::endl;

    return 0;
}
