#pragma once
#include <string>
#include <memory>
#include <iostream>
class Table;
class Player
{
public:
	Player( std::string name);
	void SetTable( std::shared_ptr<Table> pTable );
	void SetLeftPlayer( std::shared_ptr<Player> pLeftPlayer );
	std::shared_ptr<Player> GetLeftPlayer(  ) const;
	std::string GetName( ) const;
private:
	std::string m_Name;
	std::weak_ptr<Table> m_pTable;
	std::weak_ptr<Player> m_pLeftPlayer;
};

std::ostream& operator<<( std::ostream& out, const Player& player );