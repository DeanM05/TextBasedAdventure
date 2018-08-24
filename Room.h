#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
using namespace std;
using std::vector;

class Room {

private:

	map<string, Room*> exits;
	string exitString();
    vector <Item> itemsInRoom;


public:
    int numberOfItems();
    string description;
    int id;
    Room(string description, int id);
    int getID();
	void setExits(Room *north, Room *east, Room *south, Room *west);
    string shortDescription();
	Room* nextRoom(string direction);
    void addItem(Item *inItem);
    string displayItem();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);
};

#endif
