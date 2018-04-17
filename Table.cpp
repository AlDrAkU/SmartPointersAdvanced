#include "Table.h"



Table::Table( int nr ): m_Nr(nr )
{
}


void Table::AddPlayer( std::string name )
{
	std::shared_ptr<Player> pNewPlayer{ std::make_shared<Player>( name ) };
	pNewPlayer->SetTable( this->shared_from_this() );
	if ( !m_pPlayers.empty( ) )
	{
		std::weak_ptr<Player> pPrevPlayer = m_pPlayers.back( );
		std::weak_ptr<Player> pFirstPlayer = pPrevPlayer.lock()->GetLeftPlayer();
		m_pPlayers.push_back( pNewPlayer );
		pPrevPlayer.lock()->SetLeftPlayer( pNewPlayer ); 
		pNewPlayer->SetLeftPlayer( pFirstPlayer.lock() ); // last one refers to first one
	}
	else
	{
		pNewPlayer->SetLeftPlayer( pNewPlayer ); // when only 1 player then it is it's own neighbour
		m_pPlayers.push_back( pNewPlayer );
	}
}

std::ostream& operator<<( std::ostream& out, const Table& table )
{
	out << "Players at table ";
	out << table.m_Nr << ": \n";
	for ( std::shared_ptr<Player> pPlayer : table.m_pPlayers )
	{
		out << "-> " << (*pPlayer) << '\n';
	}
	return out;
}