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

#include <string>

#if !WIN32
#error This file must be included only on Windows!
#endif

namespace Zen
{
	class WinDir
	{
	public:
		// Creates a Directory of the given path. If a directory with the same name already exists, the function returns false.
		// If there is an error, an exception is thrown. If the directory is created, it returns true.
		static bool Create(const std::wstring& path);
		// Removes a Directory of the given path. If no directory with the name, the function returns false.
		// If there is an error, an exception is thrown. If the directory is removed, it returns true.
		static bool Remove(const std::wstring& path);
		static bool Exists(const std::wstring& path);

		static std::wstring GetCurrent();
	};
}