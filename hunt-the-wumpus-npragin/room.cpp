#include "room.hpp"
#include <string>
#include <iostream>

room::room(event* e): e(e) {}

room::~room() {
    if (e) {
        delete e;
    }
}

room::room(const room& r) {
    if (e) {
        delete e;
    }

    e = r.e;
}

void room::operator=(const room& r) {
    if (e) {
        delete e;
    }

    e = r.e;
}

void room::set_event(event* e) {
    if (this->e) {
        delete this->e;
    }

    this->e = e;
}

void room::set_event(event* e, bool b) {
    if (this->e && b) {
        delete this->e;
    }

    this->e = e;
}

char room::get_event_char() const {
    if (e) {
        return e->get_representation();
    }
    return ' ';
}

std::string room::get_event_percept() const {
    if (e) {
        return e->get_percept();
    }
    return "";
}

void room::encounter_event(player& p) {
    if (e) {
        if (e->encounter(p)) {
            delete e;
            e = nullptr;
        }
    }
}

bool room::contains_event() const {
    return e; 
}