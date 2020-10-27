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
	void Set(size_t x)//��1
	{
		size_t index = x / 32;//����������ĵڼ����±괦
		size_t pos = x % 32;//�����ڵڼ�λ
		_bitmap[index] |= (1 << pos);
		_count++;
	}
	void ReSet(size_t x)//��0
	{
		size_t index = x / 32;
		size_t pos = x % 32;
		_bitmap[index] &= ~(1 << pos);
		_count--;
	}
	bool Judge(size_t x)//�ж�x�Ƿ����
	{
		size_t index = x / 32;
		size_t pos = x % 32;
		return _bitmap[index] & (1 << pos);
	}
private:
	std::vector<int> _bitmap;
	size_t _count;
};
