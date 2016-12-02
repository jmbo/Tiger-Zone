Tiger-Zone - TEAM H Repository
==================
# Table of Contents
1. [Member List](#Member List)
2. [Architecture/Design Documentation](#Architecture/Design Documentation)
3. [Source Code](#Source Code)

# Member List:

|     Name    	| Username 	    |
|:-----------:	|----------	    |
| Evan Amstutz  | EvanMAmstutz	|
| Bronson Davis | drace128 	    |
| Sarah Garcia  | SarahmGarcia  |
| Thomas Palmer | thomas1242    |
| Zachary Taylor| **REMEMBER**  |
| Kurt Yilmaz   | KurtYilmaz    |

# Architecture/Design Documentation
-Include UML
-Activity Diagram Updated?

# Source Code
- Code is in c++

# Class Descriptions
- Main
- Game
- Player
- Board
  -Subclass
- Deck (only for non-client version)
- Card
- Input/Output
  -Subclass


# Compilation and Run Instructions
## Official Version
### Without GUI (client version)
1. Navigate to Tiger-Zone/src in a command line interface, or an IDE capable of compiling c++ code.
2. Compile with the following tags: '-o tiger -std=c++11' i.e. 'g++ -o tiger -std=c++11'
3. Run on a TigerZone Server with the following arguments i.e. './tiger 100.32.100.961 4444 TIGERZONE TEAMH IAMH'
 1. The IP address of the server
 2. The port number of the server
 3. The tournament password
 4. Your username
 5. Your user password
  

## Extra Stuff
- With GUI (no client)
    - SFML Dependencies: http://www.sfml-dev.org/tutorials/2.4/
    - use main_with_GUI.cpp instead of main.cpp
  
- Test Server

# Testing
- Include Test folder showcasing tests
  ..* Unit tested couts can be viewed in code
  ..* GUI as test
  ..* Server as test
  
# Current Bugs
- Server connection issue, c++ to Java difficulty
