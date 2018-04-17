#include <windows.h>
#include <iostream>
#include <memory>

#include "Table.h"
#include "Player.h"
void StartHeapControl( );
void DumpMemoryLeaks( );


void CreateTables( );

int main( )
{
	StartHeapControl( );
	{
		CreateTables( );
	}
	DumpMemoryLeaks( );

	std::cout << "Push ENTER to stop the application\n";
	std::cin.get( );
}

void CreateTables( )
{
	std::vector<std::shared_ptr<Table>> pTables;
	std::cout << "--> Creating tables with players ...\n";
	int nr{ 1 };
	pTables.push_back( std::make_shared<Table>( nr ) );
	++nr;
	pTables.push_back( std::make_shared<Table>( nr ) );
	++nr;
	pTables.push_back( std::make_shared<Table>( nr ) );

	pTables[0]->AddPlayer( "Marleen" );
	pTables[0]->AddPlayer( "Steven" );
	pTables[0]->AddPlayer( "Bart" );
	pTables[0]->AddPlayer( "Koen" );

	pTables[1]->AddPlayer( "Matthieu" );
	pTables[1]->AddPlayer( "Thomas" );
	pTables[1]->AddPlayer( "Stephanie" );

	pTables[2]->AddPlayer( "Regis" );
	pTables[2]->AddPlayer( "Kristel" );

	for ( std::shared_ptr<Table> pTable : pTables )
	{
		std::cout <<  (*pTable) << "\n\n";
	}

	for (std::shared_ptr<Table> i : pTables)
	{
		int num{ i.use_count() };
			
	}
	pTables.clear( );
}

void StartHeapControl( )
{
#if defined(DEBUG) | defined(_DEBUG)
	// Notify user if heap is corrupt
	HeapSetInformation( NULL, HeapEnableTerminationOnCorruption, NULL, 0 );

	// Report detected leaks when the program exits
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	// Set a breakpoint on the specified object allocation order number
	//_CrtSetBreakAlloc( 163 );
#endif
}

void DumpMemoryLeaks( )
{
#if defined(DEBUG) | defined(_DEBUG)
	_CrtDumpMemoryLeaks( );
#endif
}

