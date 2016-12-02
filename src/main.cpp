#include "game.h"
#include <sstream>
#include <stdio.h>
#include <iostream>         //allows for basic input/output
#include <stdlib.h>         //allows for use of the exit() function
#include <sys/types.h>      //allows for creation of a TCP socket
#include <sys/socket.h>     //allows for creation of a TCP socket
#include <netinet/in.h>     //allows for use of structs such as sockaddr, sockaddr_in, in_addr
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
using namespace std;

/*argv[0] is the name of the executable*/
/*argv[1] will be the IP address*/
/*argv[2] will be the port number*/
/*argv[3] will be the tournament password*/
/*argv[4] will be our username*/
/*argv[5] will be our password*/

int main(int argc, char *argv[]) 
{
    struct sockaddr_in clientAddress;
    int dataLength = 1000;
    char *data = new char[dataLength];
    char *data_1 = new char[dataLength];
    char *data_2 = new char[dataLength];


    //char data[dataLength];
    string str = "";
    string temp = "";

    string space = " ";
    Input *in = new Input();
    Output *out = new Output();
    int portNumber = atoi(argv[2]);
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock < 0)
    {
        cout << "exit on socket" << endl;
        exit(1);
    }

    clientAddress.sin_addr.s_addr = inet_addr(argv[1]);
    clientAddress.sin_family = AF_INET;
    clientAddress.sin_port = htons(portNumber);
    //inet_pton(AF_INET, argv[1], &clientAddress.sin_addr);
    
    int length, checkConnection;
    length = sizeof(clientAddress);
    checkConnection = connect(sock, (struct sockaddr*)&clientAddress, length);

    if(checkConnection < 0)
    {
        cout << "exit on checkConnection" << endl;
        exit(1);
    }
    else
    {
        cout << "tcp connection established" << endl;
    }




    //Tournament Setup Logging Junk

    recv(sock, data, dataLength, 0);                         // RECEIVE: THIS IS SPARTA
    cout << "server=> " << data << endl;
    str = "JOIN TIGERZONE\n";

    cout << "client=> " << str << endl;
    send(sock, str.c_str(), dataLength, 0);                  // SEND:     JOIN TIGERZONE

    recv(sock, data_1, dataLength, 0);                       // RECEIVE:   HELLO!
    cout << "server=> " << data_1 << endl;

    //temp = "I AM TEAMH IAMH\n";
    temp = "I AM TEAMH IAMH\r";
    //temp = "I AM TEAMH IAMH\r\n";

    //cout << "next message sent to server:"<< temp << endl;

    cout << "client=> " << temp << endl;
    send(sock, temp.c_str(), dataLength, 0);                 // SEND: I AM TEAMH IAMH

   // while(!in->tournyOpen) {
        recv(sock, data_2, dataLength, 0);          
        cout << "server=> " << data_2 << endl;               //RECIEVE: PLEASE WAIT FOR NEXT CHALLNEGE..
        str = string(data_2);
        in->takeInput(str);

        if (str.find("NOPE") != -1 ) {
            cout << "FAILED TO CONNECT TO SERVER" << endl;
            close(sock);
            exit(1);
        }

   // }
    cout << "----------------------------------------------------" << endl;


    /*Here is where the loop will begin*/

    while(in->tournyOpen)
    {
       cout << "tournyOpen is true\n";
        while(in->challengeOpen == false)
        {
            cout << "challengeOpen is false\n";
            recv(sock, data, dataLength, 0);        //NEW CHALLENGE X YOU WILL PLAY X MATCH
            cout << "server=> " << data << endl;
            str = string(data);
            in->takeInput(str);   
            if(in->forfeit == true){break;}         
        }

        while(in->challengeOpen)
        {
            for(int x = 0; x < 3; x++)
            {
                cout << "challengeOpen is true\n";

                recv(sock, data, dataLength, 0);
                cout << "server=> " << data << endl;
                str = string(data);
                in->takeInput(str);
                if(in->forfeit == true)
                {
                    in->challengeOpen = false;
                    break;
                } 
            }

            if(in->forfeit == true)
            {
                in->challengeOpen = false;
                break;
            } 
cout << "in->startTile: " << in->startTile << endl;
            Card * center = new Card(in->convertID(in->startTile));
cout << "instantiate Card\n";
cout << "in->originCoord.first: " << in->originCoord.first << endl;
cout << "in->originCoord.second: " << in->originCoord.second << endl;
cout << "in->origOrientation: " << in->origOrientation << endl;
            Game *game1 = new Game(center, in->originCoord.first, in->originCoord.second, in->origOrientation);       //DOESN'T WORK YET!!!!!!!!
            Game *game2 = new Game(center, in->originCoord.first, in->originCoord.second, in->origOrientation);       //DOESN'T WORK YET!!!!!!!!);       //DOESN'T WORK YET!!!!!!!!
cout << "instantiate 2 new games\n";
            game2->setStartingPlayer(false);            //Offsets the second game to have player 2 go first    
 

            /*Last message received up to this point is: starting tile is XXXX*/

            
            /**/

            recv(sock, data, dataLength, 0);                // read remaining tiles
            cout << "server=> " << data << endl;
            str = string(data);
            in->takeInput(str);  
            if(in->forfeit == true)
            {
                in->challengeOpen = false;
                break;
            }            

            /*Last message received up to this point is: THE REMAINING X TILES ARE [...]*/

            recv(sock, data, dataLength, 0);
            cout << "server=> " << data << endl;
            str = string(data);
            in->takeInput(str);
            if(in->forfeit == true)
            {
                in->challengeOpen = false;
                break;
            }
            /*Last message received up to this point is: MATCH BEGINS IN 15 SECONDS*/




            /*15 seconds later......*/
                string startGame = "";
                bool beginning = true;

                cout << "entering the in->gameOpen loop" << endl;


            while(in->gameOpen)
            {
                recv(sock, data, dataLength, 0);
                cout << "server=> " << data << endl;
                str = string(data);
                in->takeInput(str);
                if(in->forfeit == true)
                {
                    in->gameOpen = false;
                    break;
                }

                if(beginning == true)
                {
                    startGame = in->gid;
                    beginning = false;   
                    cout << "startGame: " << startGame << endl; 
                }
                


                if(!in->gameOpen)
                {
                    cout << "!in->gameOpen was reached" << endl;
                    recv(sock, data, dataLength, 0);            //GAME A OVER!!!!!
                    cout << "server=> " << data << endl;
                    str = string(data);
                    cout << "entering the input parsing" << endl;
                    
                    in->takeInput(str);
                    cout << "exiting the input parsing" << endl;
                    
                    if(in->forfeit == true)
                    {
                        in->gameOpen = false;
                        break;
                    } 

                    recv(sock, data, dataLength, 0);            //GAME B OVER!!!!!
                    cout << "server=> " << data << endl;
                    str = string(data);
                    cout << "entering the input parsing" << endl;

                    in->takeInput(str);
                    cout << "exiting the input parsing" << endl;

                    if(in->forfeit == true)
                    {
                        in->gameOpen = false;
                        break;
                    }  

                    recv(sock, data, dataLength, 0);            //END OF ROUND X OF X
                    cout << "server=> " << data << endl;
                    str = string(data);
                    in->takeInput(str);
                    if(in->forfeit == true)
                    {
                        in->gameOpen = false;
                        break;
                    }

                    if(in->rid == in->rounds)
                    {
                        recv(sock, data, dataLength, 0);            //END OF CHALLENGES
                        cout << "server=> " << data << endl;
                        str = string(data);
                        in->takeInput(str);
                        if(in->forfeit == true)
                        {
                            in->gameOpen = false;
                            break;
                        }                        
                        in->gameOpen = false;
                        in->challengeOpen = false;
                    }

                    break;                                       
                }
            

                //AT THIS POINT THE AI WILL HAVE TO TAKE THE INPUT PARAMETERS AND MAKE A MOVE
                


                if(in->gid == startGame)          // our first move game
                {
                    cout << "entering the in->gid == startGame loop" << endl;
                    game1->giveCard(in->tile, in);
                    /*AI IMPLEMENTATION MAKING A MOVE*/
                    game1->giveTurn(in->coord.first, in->coord.second);

                    out->outputFunc(in->coord.second - ROWS/2, -1*(in->coord.first - COLS/2), in->orientation, in->gid, in->tile);
                    cout << "client=> " << out->outMessage << endl;
                    str = out->outMessage;
                    str.append("\n");
                    send(sock, str.c_str(), dataLength, 0);

                    recv(sock, data, dataLength, 0);
                    cout << "server=> " << data << endl;
                    str = string(data);
                    in->takeInput(str);
                    if(in->forfeit == true)
                    {
                        in->gameOpen = false;
                        break;
                    } 
                    string gameID = "GAME" + in->gid;
                    
                    if(str.find(gameID) != -1)
                    {
						cout << "waiting to receive" << endl;
                        recv(sock, data, dataLength, 0);
                        cout << "server=> " << data << endl;
                        str = string(data);
                        in->takeInput(str);
                        if(in->forfeit == true)
                        {
                            in->gameOpen = false;
                            break;
                        }                         
                        game2->giveTurn(ROWS/2 - in->coord.second , COLS/2 + in->coord.first);
                    }

                }
                else
                {
                    cout << "entering the in->gid != startGame loop" << endl;
                    game2->giveCard(in->tile, in);
                    /*AI IMPLEMENTATION MAKING A MOVE*/
                    game2->giveTurn(in->coord.first, in->coord.second);

                    out->outputFunc(in->coord.second - ROWS/2, -1*(in->coord.first - COLS/2), in->orientation, in->gid, in->tile);
                    cout << "client=> " << out->outMessage << endl;
                    str = out->outMessage;
                    str.append("\n");
                    send(sock, str.c_str(), dataLength, 0);

                    recv(sock, data, dataLength, 0);
                    cout << "server=> " << data << endl;
                    str = string(data);
                    in->takeInput(str);
                    if(in->forfeit == true)
                    {
                        in->gameOpen = false;
                        break;
                    } 

                    string gameID = "GAME" + in->gid;
                    
                    if(str.find(gameID) != -1)
                    {
                        recv(sock, data, dataLength, 0);
                        cout << "server=> " << data << endl;
                        str = string(data);
                        in->takeInput(str);
                        if(in->forfeit == true)
                        {
                            in->gameOpen = false;
                            break;
                        }                         
                        game1->giveTurn(ROWS/2 - in->coord.second , COLS/2 + in->coord.first);
                    }                                       

                }
                cout << "exiting the in->gameOpen loop" << endl;
            }


             delete game1;
             delete game2; 
             cout << "game1 and game2 are deleted" << endl;         
        

        }
    }
    return 0;
}
