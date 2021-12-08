#pragma once

#include <SFML/Graphics.hpp>
#include "ScreenSize.h"
#include "LevelLoader.h"
#include "Tank.h"

/// <summary>
/// @author RP
/// @date June 2017
/// @version 1.0


/// Example usage:
///		Game game;
///		game.run();
/// </summary>

class Game
{
public:
	/// <summary>
	/// @brief Default constructor that initialises the SFML window, 
	///   and sets vertical sync enabled. 
	/// </summary>
	Game();

	/// <summary>
	/// @brief the main game loop.
	/// 
	/// A complete loop involves processing SFML events, updating and drawing all game objects.
	/// The actual elapsed time for a single game loop results (lag) is stored. If this value is 
	///  greater than the notional time for one loop (MS_PER_UPDATE), then additional updates will be 
	///  performed until the lag is less than the notional time for one loop.
	/// The target is one update and one render cycle per game loop, but slower PCs may 
	///  perform more update than render operations in one loop.
	/// </summary>
	void run();

	/// <summary>
	/// @brief Placeholder to perform updates to all game objects.
	/// </summary>
	/// <param name="time">update delta time</param>
	void update(double dt);

	/// <summary>
	/// @brief Draws the background and foreground game objects in the SFML window.
	/// The render window is always cleared to black before anything is drawn.
	/// </summary>
	void render();

	/// <summary>
	/// @brief Checks for events.
	/// Allows window to function and exit. 
	/// Events are passed on to the Game::processGameEvents() method.
	/// </summary>	
	void processEvents();

	bool isRunning();

protected:
	/// <summary>
	/// @brief Handles all user input.
	/// </summary>
	/// <param name="event">system event</param>
	void processGameEvents(sf::Event&);

	// main window
	sf::RenderWindow m_window;

	// Load the game level data.
	LevelData m_level;

	//background texture 
	sf::Texture m_bgTexture;

	//tank sprite 
	sf::Sprite m_tankSprite;

	//backgroud sprite 
	sf::Sprite m_bgSprite;
	// a container for the wall sprites
	std::vector<sf::Sprite>  m_sprites;
	
	// A texture for the sprite sheet
	sf::Texture m_spriteSheetTexture;

	//Control tank movement
	TankController m_tankController;

	// An instance representing the player controlled tank.
	Tank m_tank;
};
