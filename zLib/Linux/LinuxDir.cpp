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

#include <cassert>

#include "LinuxDir.h"
#include "FSException.h"

#if __linux__
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#else
#error This file must be included only on Linux!
#endif

using namespace Zen;

bool LinuxDir::Exists(const std::tstring& path)
{
    struct stat buf;
    if (-1 == lstat((tchar*)path.data(), &buf))
	{
        int error = errno;
        if (error == ENOENT || error == ENOTDIR)
        {
            return false;
        }

        throw FSException(error);
	}

    return S_ISDIR(buf.st_mode);
}

bool LinuxDir::Create(const std::tstring& path)
{
    if (-1 == mkdir((tchar*)path.data(), 0))
	{
        int error = errno;
        //EEXIST = pathname already exists (not necessarily as a directory).
        if (error == EEXIST && Exists(path))
        {
            return false;
        }

        throw FSException(error);
	}

	return true;
}

bool LinuxDir::Remove(const std::tstring& path)
{
    if (-1 == rmdir((tchar*)path.data()))
	{
        int error = errno;
        if (error == ENOENT || error == ENOTDIR)
        {
            return false;
        }

        throw FSException(error);
	}

	return true;
}

std::tstring LinuxDir::GetCurrent()
{
    tchar* curDir = getcwd(NULL, 0);
    if (!curDir)
    {
        int error = errno;
        throw FSException(error);
    }

    std::tstring dirPath(curDir);
    free(curDir);

	return dirPath;
}
