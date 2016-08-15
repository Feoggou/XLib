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

#pragma once

#include <vector>
#include <string>

#include "zLib.h"

namespace Zen
{
    struct ZLIB_API ResultItem
    {
        /* fullName: default value - a) if result = not found / invalid; b) if filter, means 'any' */
        std::tstring fullName;
    };

    typedef std::vector<ResultItem> Results;

    class ZLIB_API IFinder
    {
    public:
        virtual ~IFinder() {}

        virtual Results operator()() = 0;
    };

    class ZLIB_API Finder : public IFinder
    {
    public:
        Finder() : m_dirPath(T(".")) {}
        explicit Finder(const std::tstring& path) : m_dirPath(path) {}

        Results operator()();

    private:
        std::tstring m_dirPath;
    };
}
