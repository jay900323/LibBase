#ifndef __ZX_UTILS_H
#define __ZX_UTILS_H

#ifndef __USE_XOPEN
#define __USE_XOPEN
#endif

#include "zx_base.h"
#include <vector>
#include <string>
#include <map>
#include <time.h>
using namespace std;


/**
* @brief  ���������࣬�ṩ��һЩ�ǳ������ĺ���ʹ��.
*
* ��Щ���������Ծ�̬�����ṩ�� �������¼��ֺ���:
*
* Trim�ຯ��,��Сдת������,�ָ��ַ���������ֱ�ӷָ��ַ�����
*
* ���ֵȣ�,ʱ����غ���,�ַ���ת������,�������ַ�����ת����,
*
* �滻�ַ�������,Ipƥ�亯��,�ж�һ�����Ƿ���������
*/
class BASE_CLASS ZxBase
{
public:

	/**
	* @brief  ȥ��ͷ���Լ�β�����ַ����ַ���.
	*
	* @param sStr    �����ַ���
	* @param s       ��Ҫȥ�����ַ�
	* @param bChar   ���Ϊtrue, ��ȥ��s��ÿ���ַ�; ���Ϊfalse, ��ȥ��s�ַ���
	* @return string ����ȥ������ַ���
	*/
	static string trim(const string &sStr, const string &s = " \r\n\t", bool bChar = true);

	/**
	* @brief  ȥ����ߵ��ַ����ַ���.
	*
	* @param sStr    �����ַ���
	* @param s       ��Ҫȥ�����ַ�
	* @param bChar   ���Ϊtrue, ��ȥ��s��ÿ���ַ�; ���Ϊfalse, ��ȥ��s�ַ���
	* @return string ����ȥ������ַ���
	*/
	static string trimleft(const string &sStr, const string &s = " \r\n\t", bool bChar = true);

	/**
	* @brief  ȥ���ұߵ��ַ����ַ���.
	*
	* @param sStr    �����ַ���
	* @param s       ��Ҫȥ�����ַ�
	* @param bChar   ���Ϊtrue, ��ȥ��s��ÿ���ַ�; ���Ϊfalse, ��ȥ��s�ַ���
	* @return string ����ȥ������ַ���
	*/
	static string trimright(const string &sStr, const string &s = " \r\n\t", bool bChar = true);

	/**
	* @brief  �ַ���ת����Сд.
	*
	* @param sString  �ַ���
	* @return string  ת������ַ���
	*/
	static string lower(const string &sString);

	/**
	* @brief  �ַ���ת���ɴ�д.
	*
	* @param sString  �ַ���
	* @return string  ת����Ĵ�д���ַ���
	*/
	static string upper(const string &sString);

	/**
	* @brief  �ַ����Ƿ������ֵ�.
	*
	* @param sString  �ַ���
	* @return bool    �Ƿ�������
	*/
	static bool isdigit(const string &sInput);

	/**
	* @brief  �ַ���ת����ʱ��ṹ.
	*
	* @param sString  �ַ���ʱ���ʽ
	* @param sFormat  ��ʽ
	* @param stTm     ʱ��ṹ
	* @return         0: �ɹ�, -1:ʧ��
	*/
	static int str2tm(const string &sString, const string &sFormat, struct tm &stTm);

	/**
	* @brief GMT��ʽ��ʱ��ת��Ϊʱ��ṹ
	*
	* eg.Sat, 06 Feb 2010 09:29:29 GMT, %a, %d %b %Y %H:%M:%S GMT
	*
	* ������mktime����time_t, ����ע��ʱ�� ������mktime(&stTm)
	*
	* - timezone���ɱ��ص���(time(NULL)ֵ��ͬ) timezone��ϵͳ�� ,
	*
	* ��Ҫextern long timezone;
	*
	* @param sString  GMT��ʽ��ʱ��
	* @param stTm     ת�����ʱ��ṹ
	* @return         0: �ɹ�, -1:ʧ��
	*/
	static int strgmt2tm(const string &sString, struct tm &stTm);

	/**
	* @brief  ʱ��ת�����ַ���.
	*
	* @param stTm     ʱ��ṹ
	* @param sFormat  ��Ҫת����Ŀ���ʽ��Ĭ��Ϊ���ո�ʽ
	* @return string  ת�����ʱ���ַ���
	*/
	static string tm2str(const struct tm &stTm, const string &sFormat = "%Y-%m-%d %H:%M:%S");

	/**
	* @brief  ʱ��ת�����ַ���.
	*
	* @param t        ʱ��ṹ
	* @param sFormat  ��Ҫת����Ŀ���ʽ��Ĭ��Ϊ���ո�ʽ
	* @return string  ת�����ʱ���ַ���
	*/
	static string tm2str(const time_t &t, const string &sFormat = "%Y-%m-%d %H:%M:%S");

	/**
	* @brief  ��ǰʱ��ת���ɽ��ո�ʽ�ַ���
	* @param sFormat ��ʽ��Ĭ��Ϊ���ո�ʽ
	* @return string ת�����ʱ���ַ���
	*/
	static string now2str(const string &sFormat = "%Y-%m-%d %H:%M:%S");

	/**
	* @brief  ʱ��ת����GMT�ַ�����GMT��ʽ:Fri, 12 Jan 2001 18:18:18 GMT
	* @param stTm    ʱ��ṹ
	* @return string GMT��ʽ��ʱ���ַ���
	*/
	static string tm2GMTstr(const struct tm &stTm);

	/**
	* @brief  ʱ��ת����GMT�ַ�����GMT��ʽ:Fri, 12 Jan 2001 18:18:18 GMT
	* @param stTm    ʱ��ṹ
	* @return string GMT��ʽ��ʱ���ַ���
	*/
	static string tm2GMTstr(const time_t &t);

	/**
	* @brief  ��ǰʱ��ת����GMT�ַ�����GMT��ʽ:Fri, 12 Jan 2001 18:18:18 GMT
	* @return string GMT��ʽ��ʱ���ַ���
	*/
	static string now2GMTstr();

	/**
	* @brief  ��ǰ������(������)ת�����ַ���(%Y%m%d).
	*
	* @return string (%Y%m%d)��ʽ��ʱ���ַ���
	*/
	static string nowdate2str();

	/**
	* @brief  ��ǰ��ʱ��(ʱ����)ת�����ַ���(%H%M%S).
	*
	* @return string (%H%M%S)��ʽ��ʱ���ַ���
	*/
	static string nowtime2str();

	/**
	* @brief  ��ȡ��ǰʱ��ĵĺ�����.
	*
	* @return int64_t ��ǰʱ��ĵĺ�����
	*/
#ifndef _WIN32
	static int64_t now2ms();
#endif
	/**
	* @brief  ȡ����ǰʱ���΢��.
	*
	* @return int64_t ȡ����ǰʱ���΢��
	*/
#ifndef _WIN32
	static int64_t now2us();
#endif

	/**
	* @brief T��ת�����ַ�����ֻҪT�ܹ�ʹ��ostream������<<����,�����Ա��ú���֧��
	* @param t Ҫת��������
	* @return  ת������ַ���
	*/
	template<typename T>
	static string tostr(const T &t);

	/**
	* @brief  vectorת����string.
	*
	* @param t Ҫת����vector�͵�����
	* @return  ת������ַ���
	*/
	template<typename T>
	static string tostr(const vector<T> &t);

	/**
	* @brief  ��map���Ϊ�ַ���.
	*
	* @param map<K, V, D, A>  Ҫת����map����
	* @return                    string ������ַ���
	*/
	template<typename K, typename V, typename D, typename A>
	static string tostr(const map<K, V, D, A> &t);

	/**
	* @brief  map���Ϊ�ַ���.
	*
	* @param multimap<K, V, D, A>  map����
	* @return                      ������ַ���
	*/
	template<typename K, typename V, typename D, typename A>
	static string tostr(const multimap<K, V, D, A> &t);

	/**
	* @brief  pair ת��Ϊ�ַ�������֤map�ȹ�ϵ��������ֱ����tostr�����
	* @param pair<F, S> pair����
	* @return           ������ַ���
	*/
	template<typename F, typename S>
	static string tostr(const pair<F, S> &itPair);

	/**
	* @brief  container ת�����ַ���.
	*
	* @param iFirst  ������
	* @param iLast   ������
	* @param sSep    ����Ԫ��֮��ķָ���
	* @return        ת������ַ���
	*/
	template <typename InputIter>
	static string tostr(InputIter iFirst, InputIter iLast, const string &sSep = "|");

	/**
	* @brief  ����������ת�����ַ���.
	*
	* @param buf     ������buffer
	* @param len     buffer����
	* @param sSep    �ָ���
	* @param lines   ���ٸ��ֽڻ�һ��, Ĭ��0��ʾ������
	* @return        ת������ַ���
	*/
	static string bin2str(const void *buf, size_t len, const string &sSep = "", size_t lines = 0);

	/**
	* @brief  ����������ת�����ַ���.
	*
	* @param sBinData  ����������
	* @param sSep     �ָ���
	* @param lines    ���ٸ��ֽڻ�һ��, Ĭ��0��ʾ������
	* @return         ת������ַ���
	*/
	static string bin2str(const string &sBinData, const string &sSep = "", size_t lines = 0);

	/**
	* @brief   �ַ���ת���ɶ�����.
	*
	* @param psAsciiData �ַ���
	* @param sBinData    ����������
	* @param iBinSize    ��Ҫת�����ַ�������
	* @return            ת�����ȣ�С�ڵ���0���ʾʧ��
	*/
	static int str2bin(const char *psAsciiData, unsigned char *sBinData, int iBinSize);

	/**
	* @brief  �ַ���ת���ɶ�����.
	*
	* @param sBinData  Ҫת�����ַ���
	* @param sSep      �ָ���
	* @param lines     ���ٸ��ֽڻ�һ��, Ĭ��0��ʾ������
	* @return          ת����Ķ���������
	*/
	static string str2bin(const string &sBinData, const string &sSep = "", size_t lines = 0);

	/**
	* @brief  �滻�ַ���.
	*
	* @param sString  �����ַ���
	* @param sSrc     ԭ�ַ���
	* @param sDest    Ŀ���ַ���
	* @return string  �滻����ַ���
	*/
	static string replace(const string &sString, const string &sSrc, const string &sDest);

	/**
	* @brief  �����滻�ַ���.
	*
	* @param sString  �����ַ���
	* @param mSrcDest  map<ԭ�ַ���,Ŀ���ַ���>
	* @return string  �滻����ַ���
	*/
	static string replace(const string &sString, const map<string, string>& mSrcDest);

	/**
	* @brief ƥ����.�ָ����ַ�����pat��*�����ͨ���������ǿյ��κ��ַ���
	* sΪ��, ����false ��patΪ��, ����true
	* @param s    ��ͨ�ַ���
	* @param pat  ��*��ƥ����ַ���������ƥ��ip��ַ
	* @return     �Ƿ�ƥ��ɹ�
	*/
	static bool matchPeriod(const string& s, const string& pat);

	/**
	* @brief  ƥ����.�ָ����ַ���.
	*
	* @param s   ��ͨ�ַ���
	* @param pat vector�е�ÿ��Ԫ�ض��Ǵ�*��ƥ����ַ���������ƥ��ip��ַ
	* @return    �Ƿ�ƥ��ɹ�
	*/
	static bool matchPeriod(const string& s, const vector<string>& pat);

	/**
	* @brief  �ж�һ�����Ƿ�Ϊ����.
	*
	* @param n  ��Ҫ���жϵ�����
	* @return   true������������false��ʾ������
	*/
	static bool isPrimeNumber(size_t n);

	/**
	* @brief  daemon
	*/
#ifndef _WIN32
	static void daemon();
#endif
	/**
	* @brief  ���Թܵ��쳣
	*/
#ifndef _WIN32
	static void ignorePipe();
#endif
	/**
	* @brief  ��һ��string����ת��һ���ֽ� .
	*
	* @param sWhat Ҫת�����ַ���
	* @return char    ת������ֽ�
	*/
	static char x2c(const string &sWhat);

	/**
	* @brief  ��С�ַ��������ֽ�����֧��K, M, G���� ����: 1K, 3M, 4G, 4.5M, 2.3G
	* @param s            Ҫת�����ַ���
	* @param iDefaultSize ��ʽ����ʱ, ȱʡ�Ĵ�С
	* @return             �ֽ���
	*/
	static size_t toSize(const string &s, size_t iDefaultSize);

	/**
	* @brief  �ָ��ַ���
	* @param s            ���ָ����ַ���
	* @param v �������
	* @param sep �ָ��ַ���
	* @return             ��
	*/
	static void strsplit(const std::string& s, std::vector<std::string>& v, const std::string& sep);

	/**
	* @brief  �ж��ַ����Ƿ���ĳ���ַ�����ͷ
	* @param str            Դ�ַ���
	* @param prefix ��ͷ����
	* @return     bool
	*/
	bool start_with(const std::string &str, const std::string &prefix);

	/**
	* @brief  �ж��ַ����Ƿ���ĳ���ַ�������
	* @param str            Դ�ַ���
	* @param prefix ��������
	* @return     bool
	*/
	bool end_with(const std::string &str, const std::string &suffix);
};

#endif

