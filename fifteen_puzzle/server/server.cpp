#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <stdexcept>

namespace ba = boost::asio;
const int max = 512;
ba::io_service service;

class talk_to_client : public std::enable_shared_from_this<talk_to_client>, boost::noncopyable
{

public:
	typedef boost::system::error_code error_code;
	typedef std::shared_ptr<talk_to_client> ptr;

	void start()
	{
		std::cout << " Start session " << std::endl;
		started = true;
		do_read();
	}

	static ptr get_new_client()
	{
		ptr new_client(new talk_to_client);
		return new_client;
	}

	void stop()
	{
		std::cout << " Stop session " << std::endl;
		if (!started) return;
		started = false;	
		sock.close();
	}

	ba::ip::tcp::socket & get_sock() { return sock; }

	
private:
	ba::ip::tcp::socket sock;
	char read_buffer[max];
	char write_buffer[max];
	bool started;

	typedef talk_to_client self_type;
	talk_to_client() : sock(service), started(false) {}

	void on_read(const error_code & err, size_t bytes)
	{
		std::cout << " Server is: on_read " << std::endl;

		if ((std::find(read_buffer, read_buffer + bytes, '0') < read_buffer + bytes) || (err))
		{
			std::cout << " Server is: exit " << std::endl;
			stop();
		}
		else
		{
			std::string msg(read_buffer, bytes);
			// send message back
			do_write(" Response from server: " + msg + "\n");
		}
		
	}

	void on_write(const error_code & err, size_t bytes)
	{
		std::cout << " Server is: on_write " << std::endl;
		do_read();
	}

	void do_read()
	{
		std::cout << " Server is: do_read " << std::endl;
			ba::async_read(sock, ba::buffer(read_buffer),
				boost::bind(&self_type::read_complete, shared_from_this(), _1, _2),
				boost::bind(&self_type::on_read, shared_from_this(), _1, _2));
	}

	void do_write(const std::string & msg)
	{
		std::cout << " Server is: do_write " << std::endl;
		std::copy(msg.begin(), msg.end(), write_buffer);	
		sock.async_write_some(ba::buffer(write_buffer, msg.size()),
			boost::bind(&self_type::on_write, shared_from_this(), _1, _2));
	}

	size_t read_complete(const boost::system::error_code & err, size_t bytes)
	{
		std::cout << " Server is: read_complete " << std::endl;
		if (err) return 0;
		bool found = std::find(read_buffer, read_buffer + bytes, '\n') < read_buffer + bytes;
		// we read one-by-one until we get to enter, no buffering
		return found ? 0 : 1;
	}

};


ba::ip::tcp::acceptor acceptor(service, ba::ip::tcp::endpoint(ba::ip::tcp::v4(), 8181));

void handle_accept(talk_to_client::ptr client, const boost::system::error_code & err) {
	client->start();
	talk_to_client::ptr new_client = talk_to_client::get_new_client();
	acceptor.async_accept(new_client->get_sock(), boost::bind(handle_accept, new_client, _1));
	
}

int main()
{
	talk_to_client::ptr client = talk_to_client::get_new_client();
	auto endpoint = acceptor.local_endpoint();
	std::cout << " Port is: " << endpoint.port() << std::endl;
	acceptor.async_accept(client->get_sock(), boost::bind(handle_accept, client, _1));
	service.run();
	
}
