#include "PulsarException.h"
#include <sstream>

PulsarException::PulsarException(int line, const char* file) noexcept : line(line), file(file)
{

}

const char* PulsarException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl << GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* PulsarException::GetType() const noexcept
{
	return "Pulsar Exception";
}

int PulsarException::GetLine() const noexcept
{
	return line;
}

const std::string& PulsarException::GetFile() const noexcept
{
	return file;
}

std::string PulsarException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl << "[Line] " << line;
	return oss.str();
}
