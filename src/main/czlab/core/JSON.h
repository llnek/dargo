/* Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Copyright (c) 2013-2016, Kenneth Leung. All rights reserved. */

#pragma once
//////////////////////////////////////////////////////////////////////////////

#include "nlohmann/json.hpp"
#include "aeon/fusilli.h"
NS_ALIAS(j, nlohmann)

//////////////////////////////////////////////////////////////////////////////
//
#define J__LOOP(it,c) \
    for (j::json::iterator it= c.begin(); it != c.end(); ++it)

#define JS_FLOAT(obj) obj.get<j::json::number_float_t>()
#define JS_INT(obj) obj.get<j::json::number_integer_t>()
#define JS_STR(obj) obj.get<j::json::string_t>()
#define JS_BOOL(obj) obj.get<j::json::boolean_t>()
#define JS_ARR(obj) obj.get<j::json::array_t>()
#define JS_OBJ(obj) obj.get<j::json::object_t>()





