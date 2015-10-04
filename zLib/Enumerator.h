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
    class Enumerator
	{
    public:
        struct Item
        {
            Item() = default;
            Item(const std::tstring& name) : name(name) {}

            std::tstring name;
        };

	public:
        Enumerator() = default;
        Enumerator(Enumerator&& other) = default;

        virtual bool HaveNext() const = 0;
        virtual void Advance()  = 0;
        virtual Item GetItem() const = 0;
	};

    class DirEnumerator : public Enumerator
    {
    public:
        DirEnumerator() : m_haveNext(true) {}
        DirEnumerator(DirEnumerator&& other);

        bool HaveNext() const override { return false; }
        void Advance() override { m_haveNext = false; }

        Item GetItem() const override { Item item; item.name = "OneItem"; return item; }

    private:
        bool m_haveNext;
    };
}
