#include "Player.h"



Player::Player( std::string name ): m_Name(name ),m_pLeftPlayer{  }
{
}

void Player::SetTable( std::shared_ptr<Table> pTable )
{
	m_pTable = pTable;
}

void Player::SetLeftPlayer( std::shared_ptr<Player> pLeftPlayer )
{
	m_pLeftPlayer = pLeftPlayer;
}

std::shared_ptr<Player> Player::GetLeftPlayer( ) const
{
	return m_pLeftPlayer.lock();
}

std::string Player::GetName( ) const
{
	return m_Name;
}

std::ostream& operator<<(  std::ostream& out, const Player& player )
{
	out << player.GetName( );
	out << " has player " << player.GetLeftPlayer( )->GetName( ) << " at the left side";
	return out;
}
