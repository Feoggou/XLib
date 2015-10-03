/*
*  Copyright 2015 Samuel Ghineț
*  
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*  
*      http://www.apache.org/licenses/LICENSE-2.0
*  
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
*/

#include "Path.h"
#include "zLib.h"
#include "FSException.h"

using namespace Zen;

bool Path::isAbsolute(const std::tstring &path)
{
    if (path.empty())
        throw FSException(2);

#if WIN32
    if (path.length() < 3)
        return true;

    return (path.at(1) == ':' && path.at(2) == '\\');
#else
    return (path.at(0) == '/');
#endif
}
