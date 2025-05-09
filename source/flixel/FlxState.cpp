#include "FlxState.h"

namespace flixel {

void FlxState::update(float elapsed) {
    for (auto member : members) {
        if (member->exists && member->active) {
            member->update(elapsed);
        }
    }
}

void FlxState::draw() {
    for (auto member : members) {
        if (member->exists && member->visible) {
            member->draw();
        }
    }
}

void FlxState::destroy() {
    clear(true);
}

void FlxState::add(FlxBasic* object) {
    if (object != nullptr) {
        members.push_back(object);
    }
}

void FlxState::remove(FlxBasic* object, bool destroy) {
    if (object == nullptr) return;

    auto it = std::find(members.begin(), members.end(), object);
    if (it != members.end()) {
        if (destroy) {
            (*it)->destroy();
            delete *it;
        }
        members.erase(it);
    }
}

void FlxState::clear(bool destroy) {
    if (destroy) {
        for (auto member : members) {
            member->destroy();
            delete member;
        }
    }
    members.clear();
}

}