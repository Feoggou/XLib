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

#include "Dir.h"
#include "XLib.h"

#ifdef WIN32
#include "WinDir.h"
#else
#error NOT IMPLEMENTED!
#endif

using namespace Zen;

Dir::Dir(Dir&& other)
	: m_path(std::move(other.m_path))
{
}

Dir& Dir::operator=(Dir&& other)
{
	if (this == &other)
		return *this;

	 m_path = std::move(other.m_path);

	return *this;
}

Dir Dir::Create(const std::wstring& path)
{
	Dir dir(path);
	dir.Create();

	return dir;
}

bool Dir::Remove(const std::wstring& path)
{
	return OS(Dir)::Remove(path);
}

std::wstring Dir::FullPath() const
{
	//TODO: name, not path
	return m_path;
}

bool Dir::Exists() const
{
	return Dir::Exists(m_path);
}

bool Dir::Exists(const std::wstring& path)
{
	return OS(Dir)::Exists(path);
}

bool Dir::Create()
{
	return OS(Dir)::Create(m_path);
}

bool Dir::Remove()
{
	return Dir::Remove(m_path);
}

Dir Dir::GetCurrent()
{
	std::wstring path = OS(Dir)::GetCurrent();
	return Dir(path);
}