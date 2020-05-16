#pragma once
#include<string>
#include<exception>
namespace DataStruct {
	class DataStructException :public std::exception
	{
		using std::exception::exception;
	public:
		explicit DataStructException(const unsigned int ex_code = 0,
			const char* const exception_arg = "unknow error") :
			exception_code(ex_code) {
			this->exception_msg.push_back('\n');
			this->exception_msg.insert(0,
				"ERROR CODE:" + std::to_string(this->exception_code) + "\n" +
				"ERROR MSG:" + exception_arg);
		}
		virtual const char* what()const noexcept override {
			return exception_msg.c_str();
		}
		unsigned int exception_code;
		std::string exception_msg;
	};
}