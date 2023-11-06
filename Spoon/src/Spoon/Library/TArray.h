#pragma once

template <typename T>
class TArray
{
private:
	typedef T ElementType;

protected:
	ElementType** Items;

	unsigned NbrItems;

public:

	__forceinline ElementType& operator[](unsigned _val) const
	{
		return GetData()[_val];
	}

	__forceinline void Add(ElementType& _val)
	{
		ElementType** tmp = new ElementType[sizeof(ElementType) * (NbrItems + 1)];
		memcpy(tmp, Items, NbrItems * sizeof(ElementType));
		memset(tmp[NbrItems], _val, sizeof(ElementType));
		delete Items;
		++NbrItems;
		Items = tmp;
	}

	__forceinline unsigned Size() const
	{
		return NbrItems;
	}

	__forceinline ElementType* GetData()
	{
		return static_cast<ElementType>(Items);
	}

	typedef ElementType* RangedForIteratorType;

	__forceinline RangedForIteratorType begin() { return RangedForIteratorType (NbrItems, GetData()); }
	__forceinline RangedForIteratorType begin() const { return RangedForIteratorType (NbrItems, GetData()); }
};

