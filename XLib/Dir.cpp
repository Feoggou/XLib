#include "Dir.h"

using namespace Zen;

Dir Dir::Create(const std::wstring& path)
{
	return Dir(path);
}

void Dir::Remove(const std::wstring& path)
{
}

std::wstring Dir::Name() const
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
	return true;
}