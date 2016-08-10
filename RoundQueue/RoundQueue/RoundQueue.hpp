#ifndef ROUNDQUEUE_H
#define ROUNDQUEUE_H

#include <cstring>

template <int QUEUELEN = 10, int BUFLEN = 300>
class RoundQueue
{
public:
	RoundQueue()
		: m_front(0)
		, m_rear(0)
	{};
	~RoundQueue(){};

	bool enqueue(char* data, int len)
	{
		if(len > BUFLEN || is_full())
			return false;

		memcpy(m_data[m_rear], data, len);
		m_rear  = (m_rear + 1) % (QUEUELEN + 1);
		return true;
	}

	bool dequeue(char* data, int len)
	{
		if(len > BUFLEN || is_empty())
			return false;

		memcpy(data, m_data[m_front], len);
		m_front = (m_front + 1) % (QUEUELEN + 1);
		return true;
	}

	bool is_full()
	{
		return ((m_rear + 1) % (QUEUELEN + 1) == m_front);
	}

	bool is_empty()
	{
		return m_front == m_rear;
	}

private:
	char m_data[QUEUELEN + 1][BUFLEN];
	int m_front;
	int m_rear;
};

#endif 