#pragma once
template <typename T>
T ReadOffset(DWORD Class, DWORD Offset)
{
	T value = *(T*)(*(DWORD*)(Class) + Offset);
	return value;
}

class Memory {
	public:
};