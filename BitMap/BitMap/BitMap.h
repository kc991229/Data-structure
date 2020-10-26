#include <iostream>
#include <vector>

class BitMap
{
public:
	BitMap(size_t N)
	{
		_bitmap.resize(N / 32 + 1, 0);
		_count = 0;
	}
	void Set(size_t x)//置1
	{
		size_t index = x / 32;//计算在数组的第几号下标处
		size_t pos = x % 32;//计算在第几位
		_bitmap[index] |= (1 << pos);
		_count++;
	}
	void ReSet(size_t x)//置0
	{
		size_t index = x / 32;
		size_t pos = x % 32;
		_bitmap[index] &= ~(1 << pos);
		_count--;
	}
	bool Judge(size_t x)//判断x是否存在
	{
		size_t index = x / 32;
		size_t pos = x % 32;
		return _bitmap[index] & (1 << pos);
	}
private:
	std::vector<int> _bitmap;
	size_t _count;
};
