#ifndef _ZX_DIRENT_H
#define _ZX_DIRENT_H
	
#ifdef _WIN32

#include <sys/types.h>
#include "zx_base.h"

struct dirent
{
	long d_ino;              /* inode number*/
	off_t d_off;             /* offset to this dirent*/
	unsigned short d_reclen; /* length of this d_name*/
	unsigned char d_type;    /* the type of d_name*/
	char d_name[256];          /* file name (null-terminated)*/
};

typedef struct _dirdesc {
	int     dd_fd;      /** file descriptor associated with directory */
	long    dd_loc;     /** offset in current buffer */
	long    dd_size;    /** amount of data returned by getdirentries */
	char    *dd_buf;    /** data buffer */
	int     dd_len;     /** size of data buffer */
	long    dd_seek;    /** magic cookie returned by getdirentries */
	int finished;
	HANDLE handle;
	struct dirent entry;
} DIR;
#endif

# define __dirfd(dp)    ((dp)->dd_fd)

#ifdef _WIN32
BASE_API DIR *z_opendir(const char *name);
BASE_API struct dirent *z_readdir(DIR *dp);
BASE_API int z_closedir(DIR *d);
BASE_API int z_readdir_r(DIR *dp, struct dirent* entry, struct dirent **result);
#else
#define z_opendir opendir
#define z_readdir readdir
#define z_closedir closedir
#define z_readdir_r readdir_r
#endif

/*
* @brief ��ȡ��ǰĿ¼�µ������ļ���Ŀ¼����������Ŀ¼
   @return int  �ļ���Ŀ¼��Ŀ��-1-ʧ��
*/
BASE_API int z_scandir(const char *dirname, struct dirent **namelist[], int *pfiles, int *pvector_size, int(*selector)(const char *dirname, const struct dirent *entry), int(*compare)(const struct dirent **a, const struct dirent **b));
/*
* @brief �ݹ�ɨ��Ŀ¼
  @return int  �ļ���Ŀ¼��Ŀ
*/
BASE_API int z_scandir_recursive(const char *dirname, struct dirent **namelist[], int *nfiles, int *vector_size, int(*selector)(const char *dirname, const struct dirent *entry), int(*compare)(const struct dirent **a, const struct dirent **b));
/*
* @brief �ͷ�dirent����
*/
BASE_API void free_dirent_list(struct dirent **namelist[], int nfiles);
/*
* @brief ��ȡ��ǰ���̵�������·��
   @return int  �ļ���Ŀ¼��Ŀ
   @return int  0 - �ɹ�
*/
BASE_API int z_get_exec_path(char *dir, int len);
/*
* @brief ���õ�ǰ����Ŀ¼
  @return int  0 - �ɹ�
*/
BASE_API int z_chdir(const char *dir);

/**
* @brief �ж�Ŀ¼�Ƿ����
*
* @param dirname ҪĿ¼����
* @return bool  0-�����ɹ� ��-1-����ʧ��
*/
BASE_API int z_dir_access(const char *dirname);
/**
* @brief ����Ŀ¼, ���Ŀ¼�Ѿ����ڷ���0
*
* @param sFullPath Ҫ������Ŀ¼����
* @return int  0-�ɹ� ��-1-ʧ��
*/
BASE_API int z_mkdir(const char *dirname);

/**
* @brief ѭ������Ŀ¼, ���Ŀ¼�Ѿ�����
*
* @param sFullPath Ҫ������Ŀ¼����
* @return int  0-�ɹ� ��-1-ʧ��
*/
BASE_API int z_mkdir_recursive(const char *path);

/**
* @brief ɾ��Ŀ¼
*
* @param dir Ҫɾ����Ŀ¼����
* @return int  0-�ɹ� ��-1-ʧ��
*/
BASE_API int z_remove_dir(const  char *dir);
/**
* @brief �ݹ�ɾ��Ŀ¼����Ŀ¼�µ������ļ�����Ŀ¼
*
* @param dir Ҫɾ����Ŀ¼����
* @return int  0-�ɹ� ��-1-ʧ��
*/
BASE_API int z_delete_dir_recursive(const char *dirname);

#endif
