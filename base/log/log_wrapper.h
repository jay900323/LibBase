#ifndef _LOG_WRAPPER_H_
#define  _LOG_WRAPPER_H_
#include "appender.h"

class Log : public Logger
{
public:
	Log(char *name, severity_level  level);
	~Log();

	void init_appender();

	void addAppender(Appender* appender);
	void callAppenders(severity_level level, const char *file, int line, const std::string& message) throw();
	void removeAllAppenders();

	severity_level getLogLevel() const { return level; }
	void setLogLineNum(bool loglineNum);
	bool isLogLevelValid(int level);
	/**
	* @brief ������־�ȼ�.
	*
	* @param level �ȼ�
	* @return      �ɹ����÷���0�����򷵻�-1
	*/
	int setLogLevel(int leve);

	/**
	* @brief �����ļ�·��
	*/
	void setPath(const std::string &path);
	/**
	* @brief ��ȡ����С.
	*
	* @return int
	*/
	int getMaxSize();

	/**
	* @brief ��������С.
	*
	* @param maxSize
	*/
	void setMaxSize(int maxSize);

	/**
	* @brief ��ȡ������.
	*
	* @return int
	*/
	int getMaxNum();

	/**
	* @brief �����ļ�����.
	*
	* @param maxNum
	*/
	void setMaxNum(int maxNum);

	void set_log_appender(int append_mode);

	void	debug(const char *file, int line, const char *fmt, ...);
	void	info(const char *file, int line, const char *fmt, ...);
	void	warn(const char *file, int line, const char *fmt, ...);
	void	error(const char *file, int line, const char *fmt, ...);
	void	fatal(const char *file, int line, const char *fmt, ...);
	void log(severity_level level, const char *file, int line, const char *fmt, va_list args);
	// void log(severity_level level, std::string &message);
public:
	/*��־����*/
	char           *name;
	/*��ʼ����־*/
	bool       initialized;
	/*�ϴμ�¼ʱ��*/
	long            last_logged_time;
	/*��¼�ȼ�*/
	severity_level  level;
	/*�Ƿ���Ȩ�޷���*/
	bool accessable;
	/*�����ʽ*/
	int   appender;
	/*���Appender����*/
	AppenderSet log_appenders;
	std::mutex log_mutex;
	/*�ļ�·��*/
	std::string log_path;
	/*�����־�ļ���С*/
	int log_max_size;
	/*�����־�ļ���Ŀ*/
	int log_max_num;
	bool log_line_num;
};

class BASE_CLASS LogManage
{
public:
	LogManage();
	~LogManage();
	std::shared_ptr<Logger> getLogger(std::string name = "root");
private:
	std::mutex log_manage_mutex;
	std::map < std::string, std::shared_ptr<Logger>> logger_dict;
	std::shared_ptr<Logger> root_logger;
};

#endif