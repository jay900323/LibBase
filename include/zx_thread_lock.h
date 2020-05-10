#ifndef _ZX_LOCK_H
#define _ZX_LOCK_H

#include "zx_base.h"
#include "zx_except.h"

using namespace std;
/**
* @brief  ���쳣
*/
struct ZxLockException : public Exception
{
	ZxLockException(const string &buffer) : Exception(buffer) {};
	ZxLockException(const string &buffer, int err) : Exception(buffer, err) {};
	~ZxLockException() throw() {};
};

/**
* @brief  ��ģ�����������������ʹ�ã�
* ����ʱ�������������ʱ�����
*/
template <typename T>
class ZxLockT
{
public:

	/**
	* @brief  ���캯��������ʱ����
	*
	* @param mutex ������
	*/
	ZxLockT(const T& mutex) : _mutex(mutex)
	{
		_mutex.lock();
		_acquired = true;
	}

	/**
	* @brief  ����������ʱ����
	*/
	virtual ~ZxLockT()
	{
		if (_acquired)
		{
			_mutex.unlock();
		}
	}

	/**
	* @brief  ����, ����Ѿ�����,���׳��쳣
	*/
	void acquire() const
	{
		if (_acquired)
		{
			throw ZxLockException("thread has locked!");
		}
		_mutex.lock();
		_acquired = true;
	}

	/**
	* @brief  ��������.
	*
	* @return  �ɹ�����true�����򷵻�false
	*/
	bool tryAcquire() const
	{
		_acquired = _mutex.tryLock();
		return _acquired;
	}

	/**
	* @brief  �ͷ���, ���û���Ϲ���, ���׳��쳣
	*/
	void release() const
	{
		if (!_acquired)
		{
			throw ZxLockException("thread hasn't been locked!");
		}
		_mutex.unlock();
		_acquired = false;
	}

	/**
	* @brief  �Ƿ��Ѿ�����.
	*
	* @return  ����true�Ѿ����������򷵻�false
	*/
	bool acquired() const
	{
		return _acquired;
	}

protected:

	/**
	* @brief ���캯��
	* ���������Բ�������TC_LockT����
	*
	*/
	ZxLockT(const T& mutex, bool) : _mutex(mutex)
	{
		_acquired = _mutex.tryLock();
	}

private:

	// Not implemented; prevents accidental use.
	ZxLockT(const ZxLockT&);
	ZxLockT& operator=(const ZxLockT&);

protected:
	/**
	* ������
	*/
	const T&        _mutex;

	/**
	* �Ƿ��Ѿ�����
	*/
	mutable bool _acquired;
};

#endif