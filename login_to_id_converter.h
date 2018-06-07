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

#ifndef CORE_LOGIN_TO_ID_CONVERTER_H
#define CORE_LOGIN_TO_ID_CONVERTER_H

#include <cstdint>
#include <string>

namespace password_hasher
{

uint32_t convert_login_to_id( const std::string & login, bool is_case_sensitive = true );
std::string convert_password_to_hash( const std::string & password );

}

#endif // CORE_LOGIN_TO_ID_CONVERTER_H
