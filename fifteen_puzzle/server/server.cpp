#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>

namespace ba = boost::asio;
typedef boost::shared_ptr<ba::ip::tcp::socket> socket_ptr;

void startSession(socket_ptr sock)
{
	try
	{
			while (true)
			{
				char data[512];
				sock->read_some(ba::buffer(data));
				ba::write(*sock, ba::buffer("response: "));
			}
	}
	catch (boost::system::system_error e)
	{
		std::cout << " Error! " << std::endl;
	}
}
	


int main()
{
	ba::io_service service;
	ba::ip::tcp::endpoint ep(ba::ip::tcp::v4(), 100);
	ba::ip::tcp::acceptor acc(service, ep);
	while (true)
	{
		socket_ptr sock(new ba::ip::tcp::socket(service));
		acc.accept(*sock);
		boost::thread(boost::bind(startSession, sock));
	}
	return 0;
}

