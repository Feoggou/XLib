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



#include "Finder.h"

#include <iostream>
#include <memory>
#include <cstring>
#include <errno.h>

#include "FSException.h"

using namespace Zen;

#ifdef __linux__
#include <dirent.h>

Results Finder::operator()()
{
    Results r;

    DIR* dirStream = opendir(m_dirPath.c_str());
    if (!dirStream) {
        std::cerr << "opendir: " << strerror(errno) << std::endl;
        return r;
    }

    while (dirent* dirEntry = readdir(dirStream)) {
        ResultItem item;
        item.fullName = dirEntry->d_name;

        if (item.fullName != "." && item.fullName != "..")
            r.push_back(item);
    }

    if (-1 == closedir(dirStream)) {
        std::cerr << "closedir: " <<  strerror(errno) << std::endl;
        return r;
    }

    return r;
}

#else

#include "XWin.h"
#include "WinFinder.h"

Results Finder::operator()()
{
    return WinFind{}.Find();
}

#endif
