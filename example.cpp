#include <iostream>
#include <string>

#include <boost/algorithm/hex.hpp>      // boost::hex

#include "login_to_id_converter.h"      //

void test_login( const std::string & login, bool case_sensitive )
{
    std::cout << "login         = " << login << std::endl;

    auto hash       = password_hasher::convert_login_to_id( login, case_sensitive );

    std::cout << "login hash    = " << hash;

    if( case_sensitive == false )
    {
        std::cout << " (case insensitive)";
    }

    std::cout << std::endl;
}

void test_password( const std::string & password )
{
    std::cout << "password      = " << password << std::endl;

    auto hash       = password_hasher::convert_password_to_hash( password );

    auto hash_hex   = boost::algorithm::hex( hash );

    std::cout << "password hash = " << hash_hex << std::endl;
}

void test_1()
{
    test_login( "aaa", true );
}

void test_2()
{
    test_login( "aaA", true );
}

void test_3()
{
    test_login( "aaA", false );
}

void test_4()
{
    test_password( "xxx" );
}

void test_5()
{
    test_password( "xxy" );
}

int main( int argc, const char* argv[] )
{
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();

    return 0;
}
