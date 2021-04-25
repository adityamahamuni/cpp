#include<iostream>
#include<algorithm>
#include<list>
#include<limits>
#include<iomanip>
#include<string>

class Song {
	friend std::ostream& operator<<(std::ostream& os, const Song& s);
	std::string name;
	std::string artist;
	int rating;
public:
	Song() = default;
	Song(std::string name, std::string artist, int rating) : name{name}, artist{artist}, rating{rating}{}

	std::string get_name() const {
		return name;
	}

	std::string get_artist() const {
		return artist;
	}

	int get_rating() const {
		return rating;
	}

	bool operator<(const Song& rhs) const {
		return this->name < rhs.name;
	}

	bool operator==(const Song& rhs)const {
		return   this->name == rhs.name;
	}
};

std::ostream& operator<<(std::ostream& os, const Song& s) {
	os << std::setw(20) << std::left << s.name << std::setw(30) << std::left << s.artist<< std::setw(2) << std::left << s.rating;
	return os;
}

void display_menu() {
	std::cout << "\n F - Play First Song" << std::endl;
	std::cout << "N - Play Next Song" << std::endl;
	std::cout << "P - Play Previous Song" << std::endl;
	std::cout << "A - Add and Play a new Song at current location" << std::endl;
	std::cout << "L - List the current playlist" << std::endl;
	std::cout << "=====================================" << std::endl;

	std::cout << "Enter a selection (Q to Quit): ";
}

void play_current_song(const Song& song) {

	std::cout << "Playing: " << std::endl;
	std::cout << song << std::endl;
}

void display_playlist(const std::list<Song>& playlist, const Song& current_song) {

	for (const auto& song : playlist) {
		std::cout << song << std::endl;
	}

	std::cout << "Current Song: " << std::endl;
	std::cout << current_song << std::endl;
}
/*
int main() {

	std::list<Song> playlist{
		{"God's Plan", "Drake", 5},
		{"Never Be The Same", "Camilla Cabello", 5},
		{"Pray For Me", "The Weekend and K. Lamar", 4},
		{"The Middle", "Zedd, Marren Morris & Grey", 5},
		{"Wait", "Maroon 5", 4},
		{"Whatever It Takes", "Imagine Dragons", 3}
	};

	std::list<Song>::iterator current_song = playlist.begin();
	display_playlist(playlist, *current_song);

	char selection{};

	do {
		display_menu();
		std::cin >> selection;
		selection = std::toupper(selection);

		if (selection == 'F') {
			std::cout << "Playing First Song: " << std::endl;
			play_current_song(*current_song);
		}
		else if (selection == 'N') {
			std::cout << "Playing Next Song: " << std::endl;
			current_song++;

			if (current_song == playlist.end()) {
				std::cout << "Wrapping to start of playlist" << std::endl;
				current_song = playlist.begin();
			}
			play_current_song(*current_song);
		}

		else if (selection == 'P') {
			std::cout << "Playing Previous Song: " << std::endl;

			if (current_song == playlist.begin()) {
				std::cout << "Wrapping to end of playlist: " << std::endl;
				current_song = playlist.end();
			}
			current_song--;

			play_current_song(*current_song);
		}
		else if (selection == 'A') {
			std::string name, artist;
			int rating;

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Adding and Playing new song" << std::endl;
			std::cout << "Enter song name: ";
			std::getline(std::cin, name);

			std::cout << "Enter artist name: ";
			std::getline(std::cin, artist);

			std::cout << "Enter your rating: ";
			std::cin >> rating;

			playlist.insert(current_song, Song(name, artist, rating));
			current_song--;
			play_current_song(*current_song);
		}
		else if (selection == 'L') {
			std::cout << std::endl;
			display_playlist(playlist, *current_song);
		}
		else if (selection == 'Q') {
			std::cout << "Exiting." << std::endl;
		}
		else {
			std::cout << "Illegal Choice, try again.....";
		}

	} while (selection != 'Q');

	std::cout << "Thanks for Listening!" << std::endl;

	return 0;
}*/