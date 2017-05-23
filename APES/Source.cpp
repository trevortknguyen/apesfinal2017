#include <iostream>
#include <map>
#include <algorithm>
#include <string>

namespace quiz {
	std::string name;
	std::map<std::string, std::string> m;
}

void load_data() {
	using namespace quiz;
	m.insert(std::pair<std::string, std::string>("Which Iowa Republican created the act that prohibits trade in wildlife, fish, and plants that have been illegally taken, possessed, transported, or sold?", "lacey"));

	m.insert(std::pair<std::string, std::string>("\"A proper management of the truffula forestry is imperative due to their role in the economic boon of Thneedville.\" - What type of value do the truffula trees have?", "instrumental"));

	m.insert(std::pair<std::string, std::string>("\"The lemonsnouts are beautiful creatures. Never has our planet encountered such a diverse lifeform. We must save them.\" - What type of value do the lemonsnouts have?", "intrinsic"));

	m.insert(std::pair<std::string, std::string>("The jabberwockies have been hunted incessantly and are almost endangered, in fact, they are believed to be SOON on the brink of extinction. What is the status of the jabberwocky species?", "threatened"));

	m.insert(std::pair<std::string, std::string>("\"The abominable snowmen can be very useful actually. Their organs can be harvested to make our delicious snowcones. I am in favor of farming them rather than hunting them in the wild for a controlled resource.\" - what type of value do the snowmen have?", "instrumental"));

	m.insert(std::pair<std::string, std::string>("The rabbits in Australia have been causing problems since they were brought in the 18th century. They really really like to eat grass. What type of species are they?", "invasive"));

	m.insert(std::pair<std::string, std::string>("\"The chupacabras are an extreme threat to little children as they enjoy abducting them in the night. However, we shouldn't hunt them to extinction because no other species is like it.\" What type of value do the chupacabras have?", "intrinsic"));

	m.insert(std::pair<std::string, std::string>("The trout are need high levels of oxygen in the water to breathe. If the dissolved oxygen levels go down by just a fraction, we start getting fish kills. What type of species do the trout function as?", "indicator"));

	m.insert(std::pair<std::string, std::string>("Unicorns' horns are very valuable and are now very popular as home decor. What type of value do they have?", "instrumental"));

	m.insert(std::pair<std::string, std::string>("Pegasi will only eat a very special Greek meadow grass that grows near grape vines. For that reason, their geographic distribution is extremely limited. In regards to their diet, what type of species is a pegasus?", "specialist"));

	m.insert(std::pair<std::string, std::string>("Removing dead logs, twigs, weeds, and other plant life for the sake of having a beautiful lawn that the homeowners association is considered ecological ________.", "simplification"));

	m.insert(std::pair<std::string, std::string>("Building a huge wall between the United States and Mexico would prevent wildlife in addition to humans from crossing the border easily. This is bad because it would result in ecological ___________.", "fragmentation"));

	m.insert(std::pair<std::string, std::string>("The Ebola crisis was highly contained to specific regions in West Africa. It does not compare to crises such as influenza or smallpox. In respect to the geographic distribution, what type of \"-demic\" was this?", "epidemic"));

	m.insert(std::pair<std::string, std::string>("Humans are what type of \"-demic\" species? Hint: Where are they?", "pandemic"));

}

/**
* Assumes that the iterator is not at the end of the line.
* It will prompt the user the next question on the iterator and
* return 1 if the user is correct and 0 if the user is incorrect.
*/
int ask_question(std::map<std::string, std::string>::iterator it) {
	std::cout << std::endl;
	std::cout << it->first << std::endl;
	std::string response;
	std::getline(std::cin, response);

	std::cout << std::endl;

	std::transform(response.begin(), response.end(), response.begin(), ::tolower);

	if (response == (it->second)) {
		std::cout << "Impressive, " << quiz::name << "." << std::endl;
		return 1;
	}
	else {
		std::cout << "I am sorry. That wasn't quite it. I'll have to reset your score." << std::endl;
		return 0;
	}
}

int main() {
	std::cout << "Hello, I see you found my clue. (press enter)" << std::endl;
	std::cin.get();
	std::cout << "How shall I address you? (type your name)" << std::endl;
	std::getline(std::cin, quiz::name);
	std::cout << "Nice to meet you, " << quiz::name << ". You need to answer ten questions correctly in a row to receive my information. Every answer will be one word, with no spaces. Every time you answer incorrectly, you must start from the beginning. If you are ready, let's start. (press enter)" << std::endl;
	std::cin.get();

	load_data();

	int progress = 1;

	std::map<std::string, std::string>::iterator it;
	it = m.begin();

	// runs the loop until the user progress reaches ten
	while (progress <= 10) {
		std::cout << std::endl;
		std::cout << "Riddle me this: (" << progress << " out of 10)" << std::endl;

		if (it == m.end()) {
			it = m.begin();
		}

		if (ask_question(it)) {
			++progress;
		}
		else {
			progress = 1;
		}

		++it;
	}

	std::cout << "You beat me, " << quiz::name << ". The key is in the drawer to the left of the fume hood." << std::endl;

	std::cin.ignore(INT_MAX);
	std::cin.get();
	return 0;
}