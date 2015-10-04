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

#include "Enumerator.h"
#include "zLib.h"

#if 0
#ifdef WIN32
#include "WinDir.h"
#elif defined(__linux__)
#include "LinuxDir.h"
#else
#error NOT IMPLEMENTED!
#endif
#endif

using namespace Zen;

DirEnumerator::DirEnumerator(DirEnumerator&&)
    /*: m_path(std::move(other.m_path))*/
{
}
