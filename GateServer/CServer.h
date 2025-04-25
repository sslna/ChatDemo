#pragma once
#include "const.h"

class CServer :public std::enable_shared_from_this<CServer>
{
public:
	CServer(boost::asio::io_context& ioc, unsigned short& port);//上下文 端口
	void Start();
private:
	tcp::acceptor _acceptor;//接收器 接收对端的连接
	net::io_context& _ioc;
	//tcp::socket _socket;//用来复用
};

