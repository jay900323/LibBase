#ifndef __ZX_SHM_H__
#define __ZX_SHM_H__

#include "zx_base.h"
#ifdef _WIN32
#else
#include <sys/types.h>
#include <sys/shm.h>
#endif
#include "zx_except.h"

using namespace std;

#ifdef _WIN32
#define SHM_KEY const char *
#define SHM_ID	HANDLE
#else
#define SHM_KEY key_t
#define SHM_ID	int
#endif

/////////////////////////////////////////////////
/**
* @file  zx_shm.h
* @brief  �����ڴ��װ��.
*
*/
/////////////////////////////////////////////////

/**
* @brief �����ڴ��쳣��.
*/
struct BASE_CLASS Zx_Shm_Exception : public Exception
{
	Zx_Shm_Exception(const string &buffer) : Exception(buffer) {};
	Zx_Shm_Exception(const string &buffer, int err) : Exception(buffer, err) {};
	~Zx_Shm_Exception() throw() {};
};

/**
* @brief  �����ڴ������࣬˵��:
* 1 �������ӹ����ڴ�, �����ڴ��Ȩ���� 0666
* 2 _bOwner=false: ����ʱ��detach�����ڴ�
* 3 _bOwner=true: ����ʱdetach�����ڴ�
*/
class BASE_CLASS ZxShm
{
public:

	/**
	* @brief ���캯��.
	*
	* @param bOwner  �Ƿ�ӵ�й����ڴ�,Ĭ��Ϊfalse
	*/
	ZxShm(bool bOwner = false) : _bOwner(bOwner), _shmSize(0), _shmKey(0), _bCreate(true), _pshm(NULL), _shemID(0) {}

	/**
	* @brief ���캯��.
	*
	* @param iShmSize �����ڴ��С
	* @param iKey     �����ڴ�Key
	* @throws         TC_Shm_Exception
	*/
	ZxShm(size_t iShmSize, SHM_KEY iKey, bool bOwner = false);

	/**
	* @brief ��������.
	*/
	~ZxShm();

	/**
	* @brief ��ʼ��.
	*
	* @param iShmSize   �����ڴ��С
	* @param iKey       �����ڴ�Key
	* @param bOwner     �Ƿ�ӵ�й����ڴ�
	* @throws           TC_Shm_Exception
	* @return ��
	*/
	void init(size_t iShmSize, SHM_KEY iKey, bool bOwner = false);

	/**
	* @brief �жϹ����ڴ�����ͣ����ɵĹ����ڴ�,���������ϵĹ����ڴ�
	* ��������ɵĹ����ڴ�,��ʱ���Ը�����Ҫ����ʼ��
	*
	* @return  true,���ɹ����ڴ�; false, �����ϵĹ����ڴ�
	*/
	bool iscreate() { return _bCreate; }

	/**
	* @brief  ��ȡ�����ڴ��ָ��.
	*
	* @return   void* �����ڴ�ָ��
	*/
	void *getPointer() { return _pshm; }

	/**
	* @brief  ��ȡ�����ڴ�Key.
	*
	* @return key_t* ,�����ڴ�key
	*/
	SHM_KEY getkey() { return _shmKey; }

	/**
	* @brief  ��ȡ�����ڴ�ID.
	*
	* @return int ,�����ڴ�Id
	*/
	SHM_ID getid() { return _shemID; }

	/**
	*  @brief  ��ȡ�����ڴ��С.
	*
	* return size_t,�����ڴ��С
	*/
	size_t size() { return _shmSize; }

	/**
	*  @brief ��������ڴ棬�ڵ�ǰ�����н�������ڴ�
	* �����ڴ��ڵ�ǰ��������Ч
	* @return int
	*/
	int detach();

	/**
	*  @brief ɾ�������ڴ�.
	*
	* ��ȫɾ�������ڴ�
	*/
	int del();

protected:

	/**
	* �Ƿ�ӵ�й����ڴ�
	*/
	bool            _bOwner;

	/**
	* �����ڴ��С
	*/
	size_t          _shmSize;

	/**
	* �����ڴ�key
	*/
	SHM_KEY           _shmKey;

	/**
	* �Ƿ������ɵĹ����ڴ�
	*/
	bool            _bCreate;

	/**
	* �����ڴ�
	*/
	void            *_pshm;

	/**
	* �����ڴ�id
	*/
	SHM_ID             _shemID;

};


#endif
