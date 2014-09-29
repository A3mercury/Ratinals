#pragma once

// T is a parameterized type
template<typename T>
class Pile
{
public:
	Pile(void);
	virtual ~Pile(void);
	void Toss(T newItem);
	T Tip() const;
	T Burn();
	T getCount() const;
private:
	T list[1000];
	int count;
};

