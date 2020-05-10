/**
* Tencent is pleased to support the open source community by making Tars available.
*
* Copyright (C) 2016THL A29 Limited, a Tencent company. All rights reserved.
*
* Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
* in compliance with the License. You may obtain a copy of the License at
*
* https://opensource.org/licenses/BSD-3-Clause
*
* Unless required by applicable law or agreed to in writing, software distributed
* under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
* CONDITIONS OF ANY KIND, either express or implied. See the License for the
* specific language governing permissions and limitations under the License.
*/

#ifndef __TC_ENCODER_H_
#define __TC_ENCODER_H_

#include <vector>

#include "zx_except.h"

using namespace std;

	/**
	*  @brief  ת���쳣��
	*/
	struct BASE_CLASS Encoder_Exception : public Exception
	{
		Encoder_Exception(const std::string &buffer) : Exception(buffer) {};
		Encoder_Exception(const std::string &buffer, int err) : Exception(buffer, err) {};
		~Encoder_Exception() throw() {};
	};

	/**
	*  @brief �����ṩ�������ñ����ת��.
	*
	*         Gbk��utf8֮����໥ת�뺯����ͨ����̬�����ṩ.
	*
	*         1��GBK ==> UTF8��ת��
	*
	*         2��UTF8 ==> GBK��ת��
	*/
	class BASE_CLASS ZxEncoder
	{
	public:
		/**
		* @brief  gbk ת���� utf8.
		*
		* @param sOut        ���buffer
		* @param iMaxOutLen  ���buffer���ĳ���/sOut�ĳ���
		* @param sIn         ����buffer
		* @param iInLen      ����buffer����
		* @throws            TC_Encoder_Exception
		* @return
		*/
		static void  gbk2utf8(char *sOut, int &iMaxOutLen, const char *sIn, int iInLen);

		/**
		* @brief  gbk ת���� utf8.
		*
		* @param sIn   ����buffer*
		* @throws      TC_Encoder_Exception
		* @return      ת�����utf8����
		*/
		static string gbk2utf8(const string &sIn);

		/**
		* @brief  utf8 ת���� gbk.
		*
		* @param sOut       ���buffer
		* @param iMaxOutLen ���buffer���ĳ���/sOut�ĳ���
		* @param sIn        ����buffer
		* @param iInLen     ����buffer����
		* @throws           TC_Encoder_Exception
		* @return
		*/
		static void utf82gbk(char *sOut, int &iMaxOutLen, const char *sIn, int iInLen);

		/**
		* @brief  utf8 ת���� gbk.
		*
		* @param sIn  ����buffer
		* @throws     TC_Encoder_Exception
		* @return    ת�����gbk����
		*/
		static string utf82gbk(const string &sIn);

		/**
		* @brief  ��string��\n�滻��,ת���ַ����е�ĳ���ַ�
		*
		* ȱʡ:\n ת��Ϊ \r\0; \rת��Ϊ\,
		*
		* ��Ҫ���ڽ�string��¼��һ�У�ͨ������дbin-log�ĵط�;
		* @param str   ��ת���ַ���
		* @param f     ��Ҫת����ַ�
		* @param t     ת�����ַ�
		* @param u     ���õ�ת���
		* @return str  ת������ַ���
		*/
		static string transTo(const string& str, char f = '\n', char t = '\r', char u = '\0');

		/**
		* @brief  ���滻�����ݻָ�Դ����,�� transTo ���ַ�����ԭ��
		*
		*  ȱʡ:\r\0 ��ԭΪ\n��\r\r��ԭΪ,
		*
		*  ��Ҫ���ڽ�string��¼��һ�У�ͨ������дbin-log�ĵط�
		* @param str  ����ԭ���ַ���(������transTo��õ����ַ���)
		* @param f    ��ת����ַ�
		* @param t    ת�����ַ�
		* @param u    ���õ�ת���
		* @return str ��ԭ����ַ���
		*/
		static string transFrom(const string& str, char f = '\n', char t = '\r', char u = '\0');
	};


#endif


