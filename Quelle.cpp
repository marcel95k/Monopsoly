/*
TODO:
	1) NOCH 5 FELDER HINZUFUEGEN
	2)GRUPPENZAEHLER PROGRAMMIEREN
		Zumachen mit 2D Array (Row 1 = Grundstück, Row 2 = Besitzer)
	3)Universales Check Feld
		Checks:
			Besitzer (wenn ja dann Miete)
			Ob ganz Gruppe vom gleichen Besitzer beherrscht wird
	4) Universales Check Feld für Geld
	5) Universales Main Info
	6) DEAL PROGRAMMIEREN
		Wenn auf Grdstk mit zahlen dann:
			mit abkaufen
			miete aussetzen / miete auf raten (check feld vor deinem Zug mit entweder Bezahlen oder neuer Deal)
	7) BANK / ZINSEN FELD PROGRAMMIEREN




 */

 // START 22.03.2021
 // LETZE BEARBEITUNG 8.04.2021

#include<iostream>
#include<time.h>
#include<conio.h>
using namespace std;


// Base Class
class classMonopoly
{
private:
	int didWeInit = 0;
	/*


		LocationChecker
		What if Lot, Event, etc....
			Preis, Miete, Hauspreis
			Group
			Besitzer
			Hauseranzahl

		Main Info
			SpielerName
			SpielerGeld
				Future: Offene Zahlungen

		2 Wuerfel
			Pasch



	*/

	/*
	* Field 0: GO
	* Field 1: Uppertown
	* Field 2: Communityfield
	* Field 3: Lowertown
	* Field 4: Income Taxes
	* Field 5: Trainstation
	* Field 6: Cork
	* Field 7: Eventfield
	* Field 8: Limerick
	* Field 9: Dublin
	* Field 10: Gulag Visit
	* Field 11: Cairo
	* Field 12: Bank
	* Field 13: Luxor
	* Field 14: Damanhur
	* Field 15: Airport
	* Field 16: Miskolc
	* Field 17: Eventfield
	* Field 18: Debrecen
	* Field 19: Szeged
	* Field 20: Free Parking
	* Field 21: Aden
	* Field 22: Eventfield
	* Field 23: Taiz
	* Field 24: Hudaida
	* Field 25: Port
	* Field 26: Bergen
	* Field 27: Stavanger
	* Field 28: Bank
	* Field 29: Oslo
	* Field 30: GULAG
	* Field 31: Dessie
	* Field 32: Gondar
	* Field 33: Communityfield
	* Field 34: Mekele
	* Field 35: Spacecenter
	* Field 36: Eventfield
	* Field 37: Talsi
	* Field 38: Additional Taxes
	* Field 39: Daugavpils
	*/
	// TOWNSFIELDS
	string field1 = "Upper Town";
	string field3 = "Lower Town";
	string field5 = "Trainstation";
	string field6 = "Cork";
	string field8 = "Limerick";
	string field9 = "Dublin";
	string field11 = "Cairo";
	string field13 = "Luxor";
	string field14 = "Damanhur";
	string field15 = "Airport";
	string field16 = "Miskolc";
	string field18 = "Debrecen";
	string field19 = "Szeged";
	string field21 = "Aden";
	string field23 = "Taiz";
	string field24 = "Hudaida";
	string field25 = "Port";
	string field26 = "Bergen";
	string field27 = "Stavanger";
	string field29 = "Oslo";
	string field31 = "Dessie";
	string field32 = "Gondar";
	string field34 = "Mekele";
	string field35 = "Spacecenter";
	string field37 = "Talsi";
	string field39 = "Daugavpils";

	// EVENTFIELDS
	string fieldGo = "GO";
	string fieldCommunity = "Community Field";
	string fieldEvent = "Event Field";
	string fieldBank = "Bank";
	string fieldIncTaxes = "Income Taxes";
	string fieldAddTaxes = "Additional Tazes";
	string fieldFreeParking = "Free Parking";
	string fieldGulag = "Gulag";
	string fieldGulagVisit = "Gulag Visit";

	string fields[40] = { fieldGo, field1, fieldCommunity, field3, fieldIncTaxes, field5, field6, fieldEvent, field8, field9, fieldGulagVisit, field11, fieldBank, field13, field14, field15, field16, fieldEvent, field18, field19, fieldFreeParking, field21, fieldEvent, field23, field24, field25, field26, field27, fieldBank, field29, fieldGulag, field31, field32, fieldCommunity, field34, field35, fieldEvent, field37, fieldAddTaxes, field39 };
	string initFields[2][40];

	// DICE CONFIG 
	int dice1;
	//int* dice1Ptr = &dice1;
	int dice2;
	//int* dice2Ptr = &dice2;
	int diceSum;
	//int* diceSumPtr = &diceSum;

	public:

	// Declaration of functions of classMonopoly
	void fieldAction(int field, int player);
	void fieldActionBuyField(); // If not bought, the player has the opt. to buy it.
	void fieldActionSellField(); // If bought by the crrt. player, he/she has the opt. to sell it.
	void fieldActionSold(); // If crrt. player does not posses, but is possesed by somebody else, he needs to pay RENT.
	void fieldActionBuyHouse(); // If the crrt. player already posseses the field, he has the opt. to buy a house.
	void fieldActionSellHouse(); // If the crrt.player already posseses the field, he has the opt. to sell a house.
	// Constructor definition
	classMonopoly()
	{
		// Fill every space of the initFields Array with the space of the fields Array
		for (int x = 0; x < 40; x++)
		{
			initFields[0][x] = fields[x];
		}

	}

	string getInitFields(int valueField)
	{
		return initFields[1][valueField];
	}


	/*
	//int arrayPlayer[6] = { player1, player2, player3, player4, player5, player6 };

	// arrayPlayerLocation Row 0 = the current location of the player
	// arrayPlayerLocation Row 1 =	if 0 the current player DIDN'T roll the dice 
	//								if 1 the current player DID roll the dice

	//int arrayPlayerLocation[6] = { player1Location, player2Location, player3Location, player4Location, player5Location, player6Location };
	// initArrayPlayerLocation[0][0] = Row of PlayerLocation1
	// initArrayPlayerLocation[1][0] = Row of already rolled (if [1][0] Player1 already rolled) (holds 0 (not rolled) 1 (already rolled))
	//int initArrayPlayerLocation[2][6];
	*/
	/*
	Grundstueck
	Preis, Miete, Hauspreis
		Group
		Besitzer
		Hauseranzahl
	*/

	//
	// LOT VALUES
	//

	int lotPrice;
	int lotRent;
	int lotHousePrice;
	int lotGroup;

	//
	// FIELD INITIALIZATION
	//




	//
	// PLAYER CONFIGURATION
	//

	

};
//FUNCTIONS	
	
// Child Class
class classPlayer: public classMonopoly
{
	// PLAYER CONFIG
	//int player = 1;
	int playerLocation = 0;

	string name;
public:
	classPlayer(string valueName)
	{
		name = valueName;


	}
	

};
int main()
{
	
	classMonopoly objectGame();
	classPlayer objectPlayer1("Adam");
	classPlayer objectPlayer2("Eva");
	
	object
	int playerAmount = 0;
	cin >> playerAmount;
	//cin >> playerAmount;
	string players[playerAmount];

	/*
	// Init of arrayPlayerLocation Row 0 = current player location
	for (int x = 0; x < 6; x++)
	{
		initArrayPlayerLocation[0][x] = arrayPlayerLocation[x];
	}
	*/
	int input;
	int y = 1; // will be checked against initArrayPlayerLocation[1][x]
	int z = 1; // will be checked if last player already rolled
	int diff;
	for (int x = 0; x < 6; x++)
	{
		if (y == gameMonopoly.initArrayPlayerLocation[1][x])
		{
			if (z == gameMonopoly.initArrayPlayerLocation[1][5]) // checking if the last player already rolled - if yes we need to flush the 1st row to make it possible that everybody can roll again
			{
				gameMonopoly.initArrayPlayerLocation[1][0] = 0;
				gameMonopoly.initArrayPlayerLocation[1][1] = 0;
				gameMonopoly.initArrayPlayerLocation[1][2] = 0;
				gameMonopoly.initArrayPlayerLocation[1][3] = 0;
				gameMonopoly.initArrayPlayerLocation[1][4] = 0;
				gameMonopoly.initArrayPlayerLocation[1][5] = 0;
			}
		}
		srand(time(NULL));
		gameMonopoly.dice1 = rand() % 6 + 1; // procudes values in the range from 1 to 6
		gameMonopoly.dice2 = rand() % 6 + 1; // procudes values in the range from 1 to 6
		gameMonopoly.diceSum = gameMonopoly.dice1 + gameMonopoly.dice2;

		gameMonopoly.initArrayPlayerLocation[0][x] = gameMonopoly.initArrayPlayerLocation[0][x] + gameMonopoly.diceSum;
		gameMonopoly.initArrayPlayerLocation[1][x] = 1;


		input = _getch();
		if (gameMonopoly.initArrayPlayerLocation[0][x] > 39)
		{
			diff = gameMonopoly.initArrayPlayerLocation[0][x] - 39;
			gameMonopoly.initArrayPlayerLocation[0][x] = 0;
			gameMonopoly.initArrayPlayerLocation[0][x] = diff;
		}
		cout << "\nPLAYER " << x << " LOCATION: " << gameMonopoly.initArrayPlayerLocation[0][x] << "\n";
		cout << gameMonopoly.initFields[0][gameMonopoly.initArrayPlayerLocation[0][x]]; // Showing Player location with initFields
		cout << "\nDicesum: " << gameMonopoly.diceSum;
		gameMonopoly.fieldAction(gameMonopoly.initArrayPlayerLocation[0][x], gameMonopoly.arrayPlayer[x]);
		}

		cout << "\n\nAUSSERHALB DER SCHLEIFE";
}
	//
	// LOT INITIALIZATION
	//


void classMonopoly::fieldAction(int field, int player)
{
	cout << "\nFIELDS NUMBER ARRAY: " << fields[field];
	cout << "\nFIELD NUMBER : " << field;

	
	/*
	Group 1:
		Lot 1: 600
		Lot 2: 800 (+200)
	Group 2:
		Lot 1/2: 1000 (Old Price + 200)
		Lot 3: 1200 (+200)

	Default Values:
	House Price: 500 (+500 each row)
	Base Rent: 20 (+20 each group)

	Last Row, Last Lots Exception:
	Price: +300 after that +500
	Rent: 10% of Price
	*/
	int fieldUpperTown = 600;
	int fieldLowerTown = 800;
	int fieldTrainstation = 2000;
	int fieldCork = 1000;
	int fieldLimerick = 1000;
	int fieldDublin = 1200;
	int fieldCairo = 1400;
	int fieldLuxor = 1400;
	int fieldDamanhur = 1600;
	int fieldAirport = 2000;
	int fieldMiskolc = 1800;
	int fieldDebrecen = 1800;
	int fieldSzeged = 2000;
	int fieldAden = 2200;
	int fieldTaiz = 2200;
	int fieldHudaida = 2400;
	int fieldPort = 2000;
	int fieldBergen = 2600;
	int fieldStavanger = 2600;
	int fieldOslo = 2800;
	int fieldDessie = 3000;
	int fieldGondar = 3000;
	int fieldMekele = 3200;
	int fieldSpacecenter = 2000;
	int fieldTalsi = 3500;
	int fieldDaugavpils = 4000;

	// EVENTFIELDS
	int fieldGO = 2000;
	int fieldCommunity = 0;
	int fieldEvent = 0;
	int fieldBank = 0;
	int fieldIncTaxes = 1000;
	int fieldAddTaxes = 2000;
	int fieldFreeParking = 0;
	int fieldGulag = 0;
	int fieldGulagVisit = 0;

	int fieldNumber[40] ={fieldGO,fieldUpperTown,fieldCommunity,fieldLowerTown,fieldIncTaxes,fieldTrainstation,fieldCork,fieldEvent,fieldLimerick,fieldDublin,fieldGulagVisit,fieldCairo,fieldBank,fieldLuxor,fieldDamanhur,fieldAirport,fieldMiskolc,fieldEvent,fieldDebrecen,fieldSzeged,fieldFreeParking,fieldAden,fieldEvent,fieldTaiz,fieldHudaida,fieldPort,fieldBergen,fieldStavanger,fieldBank,fieldOslo,fieldGulag,fieldDessie,fieldGondar,fieldCommunity,fieldMekele,fieldSpacecenter,fieldEvent,fieldTalsi,fieldAddTaxes,fieldDaugavpils};

	int fieldChoice;
	cout << "\nYou landed on " << classMonopoly::fields[field] << "\nWhat do you want to do?";
	cout << "\nBuy (1)";
	cout << "\nContinue (2)";
	cin >> fieldChoice;
	if (fieldChoice == 1)
	{

	}
	else if (fieldChoice == 2)
	{
		main();
	}

	cout << "\nThe property " << field << " belongs to you.\nWhat do you want to do?";
	cout << "\nBuy house (1)";
	// To do: Group check if the player is allowed to buy a house.
	cout << "\nSell house (2)";
	cout << "\nSell property (3)";
	cout << "\nContionue (4)";
	cin >> fieldChoice;

	cout << "\nThe property " << field << " belongs to " << player << ".\nYou need to pay rent!";
	cout << "\nPay (1)";
	// To do: Check if the player is able to pay.
	cin >> fieldChoice;
}
void classMonopoly::fieldActionBuyField()
{

}
void classMonopoly::fieldActionSellField()
{

}
void classMonopoly::fieldActionSold()
{

}
void classMonopoly::fieldActionBuyHouse()
{

}
void classMonopoly::fieldActionSellHouse()
{

}



/*	Grundstueck
Preis, Miete, Hauspreis
Group
	Besitzer
	Hauseranzahl
*/




// 2) GRUPPENZAEHLER PROGRAMMIEREN
//
// Zumachen mit 2D Array(Row 1 = Grundstück, Row 2 = Besitzer)



// Deleted things

// Was used to init the fields
/*do
	{
		// Fill every space of the initFields Array with the space of the fields Array
		for (int x = 0; x < 40; x++)
		{
			gameMonopoly.initFields[0][x] = gameMonopoly.fields[x];
		}

		// Init of arrayPlayerLocation Row 0 = current player location
		for (int x = 0; x < 6; x++)
		{
			gameMonopoly.initArrayPlayerLocation[0][x] = gameMonopoly.arrayPlayerLocation[x];
		}
		gameMonopoly.didWeInit += 1;
	} 	while (gameMonopoly.didWeInit == 0);
	*/
