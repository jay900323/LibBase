#ifndef _ZX_ZIP_H_
#define _ZX_ZIP_H_

#include "zx_base.h"

class BASE_CLASS ZxZip
{
public:
	ZxZip();
	~ZxZip();
	/**
	* @brief  ��ȡ��ǰ��ѹ�ļ�����ѹ���ļ���״̬��Ϣ
	*/
	std::string get_file_status() const;
	/*
	* @brief  ��ȡѹ������ȫ��ע���ı�
	*/
	std::string get_global_comment() const;

	/**
	* @brief ѹ���ļ� �����ļ��� �ڲ��Զ��ж�
	* @param strSourceFile Ҫ��ѹ�����ļ����ļ�·��ȫ��
	* @param strSaveFile Ҫ���ɵ�zipѹ������ȫ·��
	* @return ʧ�ܷ��� false �ɹ����� true
	*/
	bool compress_zip_package(const std::string strSourceFile, const std::string strSaveFile);
	
	/**
	* @brief ��ѹzip ���ļ���ָ��·��
	* @param strSourceZipPath Ҫ����ѹ��zip�ļ���ȫ·��
	* @param strDestZipPath ��Ҫ��ѹ���ı���·��
	* @param �ɹ����� ��ѹ�ļ������� ʧ�ܷ��� null
	*/
	DWORD uncompress_zip_package(const std::string strSourceZipPath, const std::string strDestZipPath);

	/*
	@ ѹ���ļ� �����ļ��� �ڲ��Զ��ж�
	@ strSourceFile Ҫ��ѹ�����ļ����ļ�·��ȫ��
	@ strSaveFile Ҫ���ɵ�zipѹ������ȫ·��
	@ nMode ��ʾѹ���ļ������ļ��� 0 ���ļ� 1 ���ļ���
	@ ʧ�ܷ��� false �ɹ����� true
	*/
	bool compress_zip_package_ex(const std::string strSourceFile, const std::string strSaveFile, int nMode);

private:
	/*
	@ ��ǰ������ѹ�ļ�״̬
	*/
	std::string file_status;
	/*
	@ ѹ������ȫ��ע���ı�
	*/
	std::string global_comment;


};


#endif