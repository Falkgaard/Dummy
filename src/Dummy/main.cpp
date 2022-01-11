#include <sleepy_discord/sleepy_discord.h>
#include <cstdlib>
#include <iostream>

using namespace::SleepyDiscord;

class DummyBot final: public DiscordClient
{
	using DiscordClient::DiscordClient;
public:
	DummyBot(): isRunning(true) {}
	
	~DummyBot() noexcept = default;
	
	void run() {
		std::cout << "Running bot...";
		DiscordClient::run();
	}
	
	void onMessage( Message msg )  {
		sendMessage( msg.channelID, msg.content );
	}
	
private:
	[[maybe_unused]] bool isRunning;
};

int main() {
	std::cout << "Starting\n";
	DummyBot client { "<<PUT TOKEN HERE>>", USER_CONTROLED_THREADS };
	client.run();
	std::cout << "Exiting\n";
	return EXIT_SUCCESS;
}
