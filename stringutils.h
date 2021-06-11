#pragma once
#include <algorithm>
#include <codecvt>
#include <sstream>
#include <string>
#include <vector>

/*
MIT License

Copyright (c) 2021 Northwind Industries

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

namespace string
{
	template <typename T>
	std::string str(T str)
	{
		std::stringstream s;
		s << str;
		return s.str();
	}

	std::string to_string(std::wstring str);
	std::wstring to_wstring(std::string str);

	std::vector<std::string> split(std::string str, std::string delimiter);
	std::vector<std::wstring> split(std::wstring str, std::wstring delimiter);

	bool find(std::string haystack, std::string needle);
	bool find(std::wstring haystack, std::wstring needle);

	bool starts_with(std::string str, std::string prefix);
	bool starts_with(std::wstring str, std::wstring prefix);

	bool ends_with(std::string str, std::string suffix);
	bool ends_with(std::wstring str, std::wstring suffix);
	
}

// Convert a wide string into a normal string
std::string string::to_string(std::wstring str)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> convert;
	return convert.to_bytes(str);
}

// Convert a normal string into a wide string
std::wstring string::to_wstring(std::string str)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> convert;
	return convert.from_bytes(str);
}

// Split a string in a vector by a delimiter
std::vector<std::string> string::split(std::string str, std::string delimiter)
{
	size_t pos_start = 0, pos_end;
	std::string token;
	std::vector<std::string> splitString;

	while ((pos_end = str.find(delimiter, pos_start)) != std::string::npos) {
		token = str.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delimiter.length();
		splitString.push_back(token);
	}

	splitString.push_back(str.substr(pos_start));
	return splitString;
}

// Split a wide string in a vector by a delimiter
std::vector<std::wstring> string::split(std::wstring str, std::wstring delimiter)
{
	size_t pos_start = 0, pos_end;
	std::wstring token;
	std::vector<std::wstring> splitWString;

	while ((pos_end = str.find(delimiter, pos_start)) != std::string::npos) {
		token = str.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delimiter.length();
		splitWString.push_back(token);
	}

	splitWString.push_back(str.substr(pos_start));
	return splitWString;
}

// Small wrapper function for string.find()
bool string::find(std::string haystack, std::string needle)
{
	if (haystack.find(needle) != std::string::npos) {
		return true;
	}
	return false;
}

// Small wrapper function for wstring.find()
bool string::find(std::wstring haystack, std::wstring needle)
{
	if (haystack.find(needle) != std::string::npos) {
		return true;
	}
	return false;
}

// Small wrapper function for checking if a string starts with another string
bool string::starts_with(std::string str, std::string prefix)
{
	if (str.rfind(prefix, 0) == 0) {
		return true;
	}
	return false;
}

// Small wrapper function for checking if a wide string starts with another wide string
bool string::starts_with(std::wstring str, std::wstring prefix)
{
	if (str.rfind(prefix, 0) == 0) {
		return true;
	}
	return false;
}

// Check if a string ends with another string
bool string::ends_with(std::string str, std::string suffix)
{
	auto it = suffix.begin();
	return str.size() >= suffix.size() &&
                std::all_of(std::next(str.begin(), str.size() - suffix.size()), str.end(), [&it](const char & c){
                    return c == *(it++);
        } );
}

// Check if a wide string ends with another wide string
bool string::ends_with(std::wstring str, std::wstring suffix)
{
	auto it = suffix.begin();
	return str.size() >= suffix.size() &&
		std::all_of(std::next(str.begin(), str.size() - suffix.size()), str.end(), [&it](const char& c) {
		return c == *(it++);
			});
}


// Don't be rude, I'm not a C++ god nor I pretend to be ;)