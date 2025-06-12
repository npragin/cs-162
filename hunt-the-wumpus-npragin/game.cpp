#include <iostream>
#include <vector>
#include <cstdlib>
#include "game.hpp"
#include "./events/gold.hpp"
#include "./events/bats.hpp"
#include "./events/stalactites.hpp"
#include "./events/wumpus.hpp"
#include "./events/escape_rope.hpp"
#include "./events/arrow.hpp"
#include "room.hpp"
//#include <ncurses.h>

// game implementation

game::game(int width, int height, bool debug) :
		width(width),
		height(height),
		debug(debug),
		cave(height, std::vector<room*>(width, nullptr)) {
	//Initialize rooms
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cave.at(i).at(j) = new room();
		}
	}

	//Initialize Wumpus
	std::vector<int> randRoom = get_rand_room();
	w = new wumpus(randRoom.at(0), randRoom.at(1));
	cave.at(randRoom.at(1)).at(randRoom.at(0))->set_event(w);

	//Initialize player
	randRoom = get_rand_room();
	escape_rope_x = randRoom.at(0);
	escape_rope_y = randRoom.at(1);
	p = new player(escape_rope_x, escape_rope_y);
	cave.at(escape_rope_y).at(escape_rope_x)->set_event(new escape_rope());

	//Initialize rest of events
	std::vector<event*> events = {
		new bats(),
		new bats(),
		new stalactites(),
		new stalactites(),
		new gold(),
		new arrow(),
		new arrow()
	};
	
	for (int i = 0; i < 7; i++) {
		randRoom = get_rand_room();
		room* r = cave.at(randRoom.at(1)).at(randRoom.at(0));

		r->set_event(events.back());
		events.pop_back();
	}
}

game::~game() {
	delete p;
}

void game::operator=(const game& g) {
	cave = std::vector<std::vector<room*>>(g.height, std::vector<room*>(g.width, nullptr));
	p = g.p;
	w = g.w;
	width = g.width;
	height = g.height;
	debug = g.debug;
	escape_rope_x = g.escape_rope_x;
	escape_rope_y = g.escape_rope_y;
	cave = g.cave;
}

game::game(const game& g):
	cave(g.cave),
	p(g.p),
	w(g.w),
	width(g.width),
	height(g.height),
	debug(g.debug),
	escape_rope_x(escape_rope_x),
	escape_rope_y(escape_rope_y) {}

void game::display_game() const{
	std::cout << std::endl << std::endl;
	std::cout << "Arrows remaining: " << p->get_arrows() << std::endl;

	std::string row_border = "--";
	for (int i = 0; i < this->width; ++i) {
		row_border += "-----";
	}

	std::cout << row_border << std::endl;
	for (int i = 0; i < this->height; ++i) {
		std::cout << "||";
		for (int j = 0; j < this->width; ++j) {
			//Print player
			if (i == p->get_location().at(1) && j == p->get_location().at(0)) {
				std::cout << "*";
			} else {
				std::cout << " ";
			}

			// Print event char if event exists
			if (debug && cave.at(i).at(j)->contains_event()) {
				std::cout << cave.at(i).at(j)->get_event_char();
			} else {
				std::cout << " ";
			}

			std::cout << " ||";
		}
		std::cout << std::endl;
		std::cout << row_border << std::endl;
	}
}

bool game::check_win() const{
	return p->get_escaped() || w->is_dead();
}

bool game::check_lose() const{
	return p->is_dead();
}

bool game::is_direction(char c) {
	return c == 'w' ||
		c == 'a' ||
		c == 's' ||
		c == 'd';
}

char game::to_lower(char direction) {
	if (direction >= 'A' && direction <= 'Z') {
		return direction + ('a' - 'A');
	}
	return direction;
}

std::vector<int> game::get_rand_room() {
	int randX = std::rand() % width;
	int randY = std::rand() % height;

	while (cave.at(randY).at(randX)->contains_event()) {
		randX = std::rand() % width;
		randY = std::rand() % height;
	}

	return std::vector<int>{randX, randY};
}

bool game::can_move_in_direction(char direction) {
	switch (direction) {
		case 'w':
			return p->get_location().at(1) > 0;
		case 'a':
			return p->get_location().at(0) > 0;
		case 's':
			return p->get_location().at(1) + 1 < height;
		case 'd':
			return p->get_location().at(0) + 1 < width;
		default:
			return false;
	}
}

bool game::is_valid_action(char action) {
	if (this->is_direction(action)) {
		char direction = action;
		return this->can_move_in_direction(direction);
	} else if (action == 'f') {
		return p->get_arrows() > 0;
	}
	return false;
}

void game::print_action_error(char action) {
	if (this->is_direction(action)) {
		std::cout << "You can't move in that direction!" << std::endl <<
			std::endl;
	} else if (action == 'f') {
		std::cout << "You're out of arrows!" << std::endl << std::endl;
	} else {
		std::cout << std::endl << "That's an invalid input!" << std::endl
			<< std::endl;
	}
}

char game::get_player_action() { 
	//TODO: EC: ncurses shit
	char action;
	bool first = true;

	// initscr(); // Initialize ncurses
    // cbreak(); // Disable line buffering
	// noecho(); // Don't echo key presses
    // keypad(stdscr, TRUE); // Enable keyboard input

	do {
		if (!first) {
			char previous_action = action;
			this->print_action_error(previous_action);
		}
		first = false;

		std::cout << std::endl << std::endl << "What would you like to do?" <<
			std::endl << std::endl;
		std::cout << "w: move up" << std::endl;
		std::cout << "a: move left" << std::endl;
		std::cout << "s: move down" << std::endl;
		std::cout << "d: move right" << std::endl;
		std::cout << "f: fire an arrow" << std::endl;

		std::cin >> action;
		// action = getch();
		action = this->to_lower(action);
	} while (!this->is_valid_action(action));

	// endwin();
	return action;
}

char game::get_arrow_fire_direction() {
	char direction;
	bool first = true;
	do {
		if (!first) {
			std::cout << std::endl << "That's an invalid input!" <<
				std::endl << std::endl;
		}
		first = false;

		std::cout << std::endl << std::endl <<
			"What direction would you like to fire the arrow?" << std::endl <<
			std::endl;
		std::cout << "w: up" << std::endl;
		std::cout << "a: left" << std::endl;
		std::cout << "s: down" << std::endl;
		std::cout << "d: right" << std::endl;

		std::cin >> direction;
		direction = this->to_lower(direction);
	} while (!this->is_direction(direction));

	return direction;
}

void game::move_up() {
	p->move('w');
}

void game::move_down() {
	p->move('s');
}

void game::move_left() {
	p->move('a');
}

void game::move_right() {
	p->move('d');
}

void game::move(char direction) {
	if (direction == 'w') {
		this->move_up();
	} else if (direction == 'a') {
		this->move_left();
	} else if (direction == 's') {
		this->move_down();
	} else {
		this->move_right();
	}
}

void game::fire_arrow_up() {
	int playerX = p->get_location().at(0);
	int playerY = p->get_location().at(1);
	int i = 0;
	
	//Loop 3 times or until player's location + number of spaces arrow travels is the edge
	for (; i < 3 && playerY - i > 0; i++) {
		room* r = cave.at(playerY - i).at(playerX);
		if (r->get_event_char() == 'W') {
			w->kill();
			return;
		}
	}

	//Place arrow randomly if room contains an event
	if (cave.at(playerY - i).at(playerX)->contains_event()) {
		std::vector<int> randRoom = get_rand_room();

		cave.at(randRoom.at(1)).at(randRoom.at(0))->set_event(new arrow());
	} else {
		cave.at(playerY - i).at(playerX)->set_event(new arrow());
	}
}

void game::fire_arrow_down() {
	int playerX = p->get_location().at(0);
	int playerY = p->get_location().at(1);
	int i = 0;
	
	//Loop 3 times or until player's location + number of spaces arrow travels is the edge
	for (; i < 3 && playerY + i + 1 < height; i++) {
		room* r = cave.at(playerY + i).at(playerX);
		if (r->get_event_char() == 'W') {
			w->kill();
			return;
		}
	}

	//Place arrow randomly if room contains an event
	if (cave.at(playerY + i).at(playerX)->contains_event()) {
		std::vector<int> randRoom = get_rand_room();

		cave.at(randRoom.at(1)).at(randRoom.at(0))->set_event(new arrow());
	} else {
		cave.at(playerY + i).at(playerX)->set_event(new arrow());
	}
}

void game::fire_arrow_left() {
	int playerX = p->get_location().at(0);
	int playerY = p->get_location().at(1);
	int i = 0;
	
	//Loop 3 times or until player's location + number of spaces arrow travels is the edge
	for (; i < 3 && playerX - i > 0; i++) {
		room* r = cave.at(playerY).at(playerX - i);
		if (r->get_event_char() == 'W') {
			w->kill();
			return;
		}
	}

	//Place arrow randomly if room contains an event
	if (cave.at(playerY).at(playerX - i)->contains_event()) {
		std::vector<int> randRoom = get_rand_room();

		cave.at(randRoom.at(1)).at(randRoom.at(0))->set_event(new arrow());
	} else {
		cave.at(playerY).at(playerX - i)->set_event(new arrow());
	}
}

void game::fire_arrow_right() {
	int playerX = p->get_location().at(0);
	int playerY = p->get_location().at(1);
	int i = 0;
	
	//Loop 3 times or until player's location + number of spaces arrow travels is the edge
	for (; i < 3 && playerX + i + 1 < width; i++) {
		room* r = cave.at(playerY).at(playerX + i);
		if (r->get_event_char() == 'W') {
			w->kill();
			return;
		}
	}

	//Place arrow randomly if room contains an event
	if (cave.at(playerY).at(playerX + i)->contains_event()) {
		std::vector<int> randRoom = get_rand_room();

		cave.at(randRoom.at(1)).at(randRoom.at(0))->set_event(new arrow());
	} else {
		cave.at(playerY).at(playerX  + i)->set_event(new arrow());
	}
}

void game::fire_arrow(char direction) {
	if (direction == 'w') {
		this->fire_arrow_up();
	} else if (direction == 'a') {
		this->fire_arrow_left();
	} else if (direction == 's') {
		this->fire_arrow_down();
	} else {
		this->fire_arrow_right();
	}

	p->shoot();

	if (!w->is_dead()) {
		std::vector<int> wumpLoc = w->get_location();

		w->set_location(get_rand_room()); //Change wumpus coords
		cave.at(wumpLoc.at(1)).at(wumpLoc.at(0))->set_event(nullptr, false);
		cave.at(w->get_location().at(1)).at(w->get_location().at(0))->set_event(w);
	}
}

std::vector<char> game::get_free_adjacent_rooms(int x, int y) {
	std::vector<char> vec = {};

	if (y - 1 >= 0 && !cave.at(y - 1).at(x)->contains_event())
		vec.push_back('w');
	if (y + 1 < height && !cave.at(y + 1).at(x)->contains_event())
		vec.push_back('s');
	if (x - 1 >= 0 && !cave.at(y).at(x - 1)->contains_event())
		vec.push_back('a');
	if (x + 1 < width && !cave.at(y).at(x + 1)->contains_event())
		vec.push_back('d');

	return vec;
}

std::string game::get_percepts(int x, int y) {
	std::string str = "";

	if (y - 1 >= 0 && cave.at(y - 1).at(x)->contains_event())
		str += cave.at(y - 1).at(x)->get_event_percept();
	if (y + 1 < height && cave.at(y + 1).at(x)->contains_event())
		str += cave.at(y + 1).at(x)->get_event_percept();
	if (x - 1 >= 0 && cave.at(y).at(x - 1)->contains_event())
		str += cave.at(y).at(x - 1)->get_event_percept();
	if (x + 1 < width && cave.at(y).at(x + 1)->contains_event())
		str += cave.at(y).at(x + 1)->get_event_percept();

	return str;
}

void game::player_death() {
	std::pair<bool, int> pair = p->reset_inventory();

	//Replace gold
	if (pair.first) {
		std::vector<int> randRoom = get_rand_room();
		cave.at(randRoom.at(1)).at(randRoom.at(0))->set_event(new gold());
	}

	//Replace arrows
	for (int i = 0; i < pair.second; i++) {
		std::vector<int> randRoom = get_rand_room();
		cave.at(randRoom.at(1)).at(randRoom.at(0))->set_event(new arrow());
	}

	//Respawn player at escape rope
	p->set_location(std::vector<int>{escape_rope_x, escape_rope_y});
}

void game::play_game(){
	while (!this->check_win() && !this->check_lose()) {
		// Print game board
		this->display_game();

		// Print percepts
		std::cout << get_percepts(
			p->get_location().at(0),
			p->get_location().at(1)
		);

		// Ask player for their action
		char action = this->get_player_action();

		// Process action
		if (this->is_direction(action)) {
			// W/A/S/D = move player
			char direction = action;
			this->move(direction);
		} else {
			// F = prompt for arrow fire direction and fire arrow
			char direction = this->get_arrow_fire_direction();
			this->fire_arrow(direction);
		}

		//Move Wumpus
		std::vector<int> wumpLoc = w->get_location();

		w->move(get_free_adjacent_rooms(wumpLoc.at(0), wumpLoc.at(1))); //Change wumpus coords
		cave.at(wumpLoc.at(1)).at(wumpLoc.at(0))->set_event(nullptr, false); //Wumpus leaves
		cave.at(w->get_location().at(1)).at(w->get_location().at(0))->set_event(w); //Wumpus enters

		// If the user is on a space with an event, trigger its encounter
		room* playerRoom = cave.at(p->get_location().at(1)).at(p->get_location().at(0));
		int lives = p->get_lives();
		if (playerRoom->contains_event()) {
			playerRoom->encounter_event(*p);
			if (lives != p->get_lives()) {
				player_death();
			}
		}

	}
}