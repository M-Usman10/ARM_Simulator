#ifndef B_O_H
#define B_O_H
template<class T, class T2>
class my_pair
{
public:
	T first;
	T2 second;
	my_pair()
	{

	}
	my_pair(T f, T2 s)
	{
		first = f;
		second = s;
	}
	bool operator==(const my_pair<T, T2> & p) const
	{
		return first == p.first;
	}
};
struct Coor
{
	float x, y;
	Coor(int x1 = 0, int y1 = 0)

	{
		x = x1;
		y = y1;
	}
};
#endif