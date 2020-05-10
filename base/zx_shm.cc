#include "zx_shm.h"
#include <cassert>
#include <errno.h>


ZxShm::ZxShm(size_t iShmSize, SHM_KEY iKey, bool bOwner)
{
	init(iShmSize, iKey, bOwner);
}

ZxShm::~ZxShm()
{
	if (_bOwner)
	{
		detach();
	}
}

void ZxShm::init(size_t iShmSize, SHM_KEY iKey, bool bOwner)
{
	assert(_pshm == NULL);

	_bOwner = bOwner;

#ifdef _WIN32
	HANDLE hFile = INVALID_HANDLE_VALUE;

	//����Ķ�дȨ����������ʴ˿��ڴ�Ľ���
	//�����Ϊֻ�������н���ֻ��ֻ��Ȩ��
	_shemID = ::CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, iShmSize, iKey);
	if (_shemID == NULL)
	{
		_bCreate = false;
		//�����ڴ��Ѵ�������ͼ����
		_shemID = OpenFileMapping(FILE_MAP_WRITE | FILE_MAP_READ, FALSE, iKey);
		if (_shemID == NULL) {
			throw Zx_Shm_Exception("[ZxShm::init()] OpenFileMapping error", GetLastError());
		}
	}
	else {
		_bCreate = true;
	}

	if((_pshm = MapViewOfFile(_shemID, FILE_MAP_WRITE | FILE_MAP_READ, 0, 0, 0)) == NULL)
	{
		throw Zx_Shm_Exception("[ZxShm::init()] MapViewOfFile error", errno);
	}

	_shmSize = iShmSize;
	_shmKey = iKey;
#else
	//ע��_bCreate�ĸ�ֵλ��:��֤���߳���һ�������ʱ��Ҳ����������
	//��ͼ����
	if ((_shemID = shmget(iKey, iShmSize, IPC_CREAT | IPC_EXCL | 0666)) < 0)
	{
		_bCreate = false;
		//�п������Ѿ�����ͬ����key_shm,����ͼ����
		if ((_shemID = shmget(iKey, iShmSize, 0666)) < 0)
		{
			throw Zx_Shm_Exception("[ZxShm::init()] shmget error", errno);
		}
	}
	else
	{
		_bCreate = true;
	}

	//try to access shm
	if ((_pshm = shmat(_shemID, NULL, 0)) == (char *)-1)
	{
		throw Zx_Shm_Exception("[ZxShm::init()] shmat error", errno);
	}
#endif
	_shmSize = iShmSize;
	_shmKey = iKey;

}

int ZxShm::detach()
{
	int iRetCode = 0;
	if (_pshm != NULL)
	{
#ifdef _WIN32
		::UnmapViewOfFile(_pshm);
		::CloseHandle(_shemID);
#else
		// ��һ�����̲�����Ҫ�����ڴ��ʱ����������shmdt()ϵͳ����ȡ������Σ�
		// ���ǣ��Ⲣ���Ǵ��ں�������ɾ������Σ����ǰ����shmid_ds�ṹ��
		// shm_nattch���ֵ��1�������ֵΪ0ʱ���ں˲Ŵ�������ɾ����������
		iRetCode = shmdt(_pshm);
#endif
		_pshm = NULL;
	}

	return iRetCode;
}

int ZxShm::del()
{
	int iRetCode = 0;
	if (_pshm != NULL)
	{
#ifdef _WIN32
		::UnmapViewOfFile(_pshm);
		::CloseHandle(_shemID);
#else
		// IPC_RMID ����ʵ���ϲ����ں�ɾ��һ���Σ����ǽ���������α��Ϊɾ��
		//ʵ�ʵ�ɾ�����������һ�������뿪��������ʱ��
		iRetCode = shmctl(_shemID, IPC_RMID, 0);
#endif
		_pshm = NULL;
	}

	return iRetCode;
}

