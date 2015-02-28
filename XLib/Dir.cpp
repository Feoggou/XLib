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