#include "Control.h"

/*-------------------------------------------------------------------------------------------------------------------- 
-- FUNCTION: ControlRun
--
-- DATE: 2013/03/11
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: John Payment
--
-- PROGRAMMER: John Payment
--
-- INTERFACE: int ControlRun()
--
-- RETURNS: Returns 0 on normal termination
--
-- NOTES: This is the main Control function that powers the Control Module
----------------------------------------------------------------------------------------------------------------------*/
void* ControlRun(void* vp)
{
	ControlManager manager;
	
	AddStates(manager);
	
	while(manager.CheckState() != 0)
	    sleep(1);

	return NULL;
}

/*-------------------------------------------------------------------------------------------------------------------- 
-- FUNCTION: AddStates
--
-- DATE: 2013/03/11
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: John Payment
--
-- PROGRAMMER: John Payment
--
-- INTERFACE: void AddStates(ControlManager &manager)
--            ControlManager &manager - This is a reference to the ControlManager for the purpose of loading it with States
--
-- RETURNS: void
--
-- NOTES: This adds a list of states to the ControlManager passed in
----------------------------------------------------------------------------------------------------------------------*/
void AddStates(ControlManager &manager)
{
	manager.AddNewState(MakeMenuState());
	manager.AddNewState(MakeLobbyState());
	manager.AddNewState(MakeBuilderState());
	manager.AddNewState(MakePlayerState());
	manager.AddNewState(MakeExitGameState());
}

/*-------------------------------------------------------------------------------------------------------------------- 
-- FUNCTION: MakeMenuState
--
-- DATE: 2013/03/11
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: John Payment
--
-- PROGRAMMER: John Payment
--             Luke Tao
--
-- INTERFACE: ControlState MakeMenuState()
--
-- RETURNS: the State for MenuState
--
-- NOTES: This creates the menuState and loads it with all relevent Controllers
----------------------------------------------------------------------------------------------------------------------*/
ControlState MakeMenuState()
{
	ControlState menuState(true, 10);
	sf::Font font;
	
	Button startButton(11, sf::Vector2f(200,200), sf::Vector2f(200,40), font, "Start Lobby");
	Controller startLobby(MENU_ID, (sf::Keyboard::Key)0, startButton, CallEnterLobbyEvent);
	menuState.AddController(startLobby);
	
	Button exitButton(12, sf::Vector2f(20,20), sf::Vector2f(40,40), font, "Exit Game");	
	Controller exitGame(TERMINATE, (sf::Keyboard::Key)0, exitButton, CallExitGameEvent);
	menuState.AddController(exitGame);
	
	return menuState;
}

/*-------------------------------------------------------------------------------------------------------------------- 
-- FUNCTION: MakeLobbyState
--
-- DATE: 2013/03/11
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: John Payment
--
-- PROGRAMMER: John Payment
--
-- INTERFACE: ControlState MakeLobbyState()
--
-- RETURNS: The state for LobbyState
--
-- NOTES: This creates the lobbyState and loads it with all relevent Controllers
----------------------------------------------------------------------------------------------------------------------*/
ControlState MakeLobbyState()
{
	ControlState lobbyState(true, 20);
	sf::Font font;	
	
	Button joinButton(21, sf::Vector2f(20,20), sf::Vector2f(40,40), font, "Join Game");	
	Controller joinGame(0, (sf::Keyboard::Key)0, joinButton, NULL);
	lobbyState.AddController(joinGame);
	
	Button builderButton(22, sf::Vector2f(20,20), sf::Vector2f(40,40), font, "Builder");	
	Controller builderRole(0, (sf::Keyboard::Key)0, builderButton, NULL);
	lobbyState.AddController(builderRole);
	
	Button playerButton(23, sf::Vector2f(20,20), sf::Vector2f(40,40), font, "Player");	
	Controller playerRole(0, (sf::Keyboard::Key)0, playerButton, NULL);
	lobbyState.AddController(playerRole);
	
	Button switchTeamButton(24, sf::Vector2f(20,20), sf::Vector2f(40,40), font, "Switch Team");	
	Controller switchTeam(0, (sf::Keyboard::Key)0, switchTeamButton, NULL);
	lobbyState.AddController(switchTeam);
	
	Button exitButton(25, sf::Vector2f(20,20), sf::Vector2f(40,40), font, "Exit Game");	
	Controller exitGame(TERMINATE, (sf::Keyboard::Key)0, exitButton, CallExitGameEvent);
	lobbyState.AddController(exitGame);
	
	return lobbyState;
}

/*-------------------------------------------------------------------------------------------------------------------- 
-- FUNCTION: MakePlayerState
--
-- DATE: 2013/03/11
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: John Payment
--
-- PROGRAMMER: John Payment
--
-- INTERFACE: ControlState MakePlayerState()
--
-- RETURNS: The state for PlayerState
--
-- NOTES: This creates the playerState and loads it with all relevent Controllers
----------------------------------------------------------------------------------------------------------------------*/
ControlState MakePlayerState()
{
    sf::Font font;
	ControlState playerState(true, 30);
	
	Button emptyButton(0, sf::Vector2f(0, 0), sf::Vector2f(0, 0), font, "");	
	
	Controller moveLeft(0, sf::Keyboard::Left, emptyButton, CallMoveLeftEvent);
	playerState.AddController(moveLeft);
	
	Controller moveRight(0, sf::Keyboard::Right, emptyButton, CallMoveRightEvent);
	playerState.AddController(moveRight);
	
	Controller moveUp(0, sf::Keyboard::Up, emptyButton, CallMoveUpEvent);
	playerState.AddController(moveUp);
	
	Controller moveDown(0, sf::Keyboard::Down, emptyButton, CallMoveDownEvent);
	playerState.AddController(moveDown);
	
	Controller attackLeft(0, sf::Keyboard::Left, emptyButton, CallAttackLeftEvent);
	playerState.AddController(attackLeft);
		
	Controller attackRight(0, sf::Keyboard::Right, emptyButton, CallAttackRightEvent);
	playerState.AddController(attackRight);
	
	Controller attackUp(0, sf::Keyboard::Up, emptyButton, CallAttackUpEvent);
	playerState.AddController(attackUp);
	
	Controller attackDown(0, sf::Keyboard::Down, emptyButton, CallAttackDownEvent);
	playerState.AddController(attackDown);
	
	Button exitGameClick(31, sf::Vector2f(20,20), sf::Vector2f(40,40), font, "Exit Game");	
	Controller exitGame(EXIT_MENU_ID, (sf::Keyboard::Key) 0, exitGameClick, NULL);
	playerState.AddController(exitGame);
	
	return playerState;
}

/*-------------------------------------------------------------------------------------------------------------------- 
-- FUNCTION: MakeBuilderState
--
-- DATE: 2013/03/11
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: John Payment
--
-- PROGRAMMER: John Payment
--             Luke Tao
--
-- INTERFACE: ControlState MakeBuilderState()
--
-- RETURNS: The state for BuilderState
--
-- NOTES: This creates the builderState and loads it with all relevent Controllers
----------------------------------------------------------------------------------------------------------------------*/
ControlState MakeBuilderState()
{   
    sf::Font font;
    int button[] = { 20, 130, 240, 350, 460, 570, 680 };
    
	ControlState builderState(true, 40);
	
	//Creating builder buttons
    Button buildTowerButton1(BUILDTOWER_1,sf::Vector2f(button[0],ROW1), sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), font, "Tower1");
	Button buildTowerButton2(BUILDTOWER_2,sf::Vector2f(button[1],ROW1), sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), font, "Tower2");
	Button buildTowerButton3(BUILDTOWER_3,sf::Vector2f(button[2],ROW1), sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), font, "Tower3");
	
	//building buttons		
	BuildController buildTower1(0, sf::Keyboard::B, buildTowerButton1, CallBuildTowerEvent);
	BuildController buildTower2(0, sf::Keyboard::B, buildTowerButton2, CallBuildTowerEvent);
	BuildController buildTower3(0, sf::Keyboard::B, buildTowerButton3, CallBuildTowerEvent);
	
	//Adding building tower buttons to controller
	builderState.AddController(buildTower1);
	builderState.AddController(buildTower2);
	builderState.AddController(buildTower3);
	
	
	//Creating creep buttons
	Button buildCreepButton1(BUILDCREEP_1,sf::Vector2f(button[3],ROW1), sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), font, "Creep1");
	Button buildCreepButton2(BUILDCREEP_2,sf::Vector2f(button[4],ROW1), sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), font, "Creep2");
	Button buildCreepButton3(BUILDCREEP_3,sf::Vector2f(button[5],ROW1), sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), font, "Creep3");
	
	//creep buttons
	Controller buildCreep1(0, sf::Keyboard::C, buildCreepButton1, CallBuildCreepEvent);
	Controller buildCreep2(0, sf::Keyboard::C, buildCreepButton2, CallBuildCreepEvent);
	Controller buildCreep3(0, sf::Keyboard::C, buildCreepButton3, CallBuildCreepEvent);
	
	//Adding creep buttons to controller
	builderState.AddController(buildCreep1);
	builderState.AddController(buildCreep2);
	builderState.AddController(buildCreep3);
	
	//Exit game buttons
	Button exitGameButton(ID_QUIT,sf::Vector2f(button[6],ROW2), sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT),  font, "Quit");
	Controller exitGame(EXIT_MENU_ID, (sf::Keyboard::Key) 0, exitGameButton, NULL);
	builderState.AddController(exitGame);
	
	//Path Buttons
	Button hiPathButton(SELECTHIPATH,sf::Vector2f(button[0],ROW2), sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), font, "HiPath");
	Button midPathButton(SELECTMIDPATH,sf::Vector2f(button[1],ROW2), sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), font, "MidPath");
	Button loPathButton(SELECTLOPATH,sf::Vector2f(button[2],ROW2), sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT), font, "LowPath");
	
	return builderState;
}

/*-------------------------------------------------------------------------------------------------------------------- 
-- FUNCTION: MakeExitGameState
--
-- DATE: 2013/03/11
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: John Payment
--
-- PROGRAMMER: John Payment
--             Luke Tao
--
-- INTERFACE: ControlState MakeExitGameState()
--
-- RETURNS: The state for ExitGameState
--
-- NOTES: This creates the exitGameState and loads it with all relevent Controllers
----------------------------------------------------------------------------------------------------------------------*/
ControlState MakeExitGameState()
{
	ControlState exitState(false, 50);
	
	sf::Font font;
	Button returnButton(51, sf::Vector2f(20,20), sf::Vector2f(40,40), font, "Resume Game");
	
	Controller returnToPreviousState(LAST_STATE, (sf::Keyboard::Key) 0, returnButton, NULL);
	exitState.AddController(returnToPreviousState);
	
	Button exitButton(52, sf::Vector2f(20,20), sf::Vector2f(40,40), font, "Exit");
	Controller exitGame(TERMINATE, (sf::Keyboard::Key) 0, exitButton, CallExitGameEvent);
	exitState.AddController(exitGame);
	
	return exitState;
}
