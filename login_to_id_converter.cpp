/*

Password hasher.

Copyright (C) 2016 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

// $Revision: 9299 $ $Date:: 2018-06-05 #$ $Author: serge $

#include "login_to_id_converter.h"  // self

#include <functional>               // std::hash
#include <algorithm>                // std::transform
#include <string>
//#include <iostream>                 // DEBUG

#define MODULENAME      "convert_login_to_id"

extern "C"
{
#include "sha256.h" // sha256_init
    uint32_t crc32(uint32_t crc, const void *buf, size_t size);
}

namespace password_hasher
{

uint32_t crc32( const std::string & s )
{
    auto res = ::crc32( 0, s.c_str(), s.size() );

    return res;
}

std::string to_lower( const std::string & s )
{
    std::string res = s;

    std::transform( res.begin(), res.end(), res.begin(), ::tolower );

    return res;
}

uint32_t convert_login_to_id( const std::string & login, bool is_case_sensitive )
{
    auto l = is_case_sensitive ? login : to_lower( login );

    //std::cout << "l " << l << " login " << login << " is_case_sensitive " << (int) is_case_sensitive << std::endl;

    auto res = crc32( l );

    return res;
}

std::string sha256( const std::string & s )
{
    BYTE buf[SHA256_BLOCK_SIZE];
    SHA256_CTX ctx;

    sha256_init( &ctx);
    sha256_update( &ctx, reinterpret_cast<const BYTE*>( s.c_str() ), s.size() );
    sha256_final( &ctx, buf);

    return std::string( reinterpret_cast<const char*>( & buf ), SHA256_BLOCK_SIZE );
}

std::string convert_password_to_hash( const std::string & password )
{
    return sha256( password );
}

}
