#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Player.h"

class Table:public std::enable_shared_from_this<Table>
{
public:
	Table(int nr );
	void AddPlayer( std::string name );
	friend std::ostream& operator<<( std::ostream& out, const Table& table );

private:
	int m_Nr;
	std::vector<std::shared_ptr<Player>> m_pPlayers;
};

