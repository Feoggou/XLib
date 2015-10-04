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
#include "zLib.h"

namespace Zen
{
    class ZLIB_API Enumerator
	{
    public:
        struct Item
        {
            std::tstring name;
        };

        class iterator
        {
        public:
            iterator(bool isEnd = false) : m_isEnd(isEnd) {}

            bool operator!=(const iterator& other)
            {
                return m_isEnd != other.m_isEnd;
            }

            iterator& operator++()
            {
                m_isEnd = true;
                return *this;
            }

            Item operator*()
            {
                Item item;
                item.name = "OneItem";

                return item;
            }

        private:
            bool m_isEnd;
        };

	public:
        Enumerator() = default;
        Enumerator(Enumerator&& other);

        iterator begin() { return iterator(); }
        iterator end() { return iterator(/*is end*/ true); }
	};
}
