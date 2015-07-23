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

/* The following ifdef block is the standard way of creating macros which make exporting
*  from a DLL simpler. All files within this DLL are compiled with the ZCORE_EXPORTS
*  symbol defined on the command line. This symbol should not be defined on any project
*  that uses this DLL. This way any other project whose source files include this file see
*  ZCORE_API functions as being imported from a DLL, whereas this DLL sees symbols
*  defined with this macro as being exported.
*/

#include <string>
#include "zLib.h"

namespace Zen
{
	class ZLIB_API Dir
	{
	public:
		Dir() = default;
		Dir(Dir&& other);
        explicit Dir(const std::tstring& path) : m_path(path) {}

		Dir& operator=(Dir&& other);

		bool Exists() const;
		bool Create();
		bool Remove();
		std::tstring Name() const { return m_path; }
        std::tstring FullPath() const;

	public:
        static Dir Create(const std::tstring& path);
        static bool Remove(const std::tstring& path);
        static bool Exists(const std::tstring& path);
		static Dir GetCurrent();

	private:
        std::tstring m_path;
	};
}
