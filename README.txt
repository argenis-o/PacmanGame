REFERENCES TO IMAGES AND SOUNDS:
 
 Special Thanks to Hermin Nicole Vargas Marquéz for the awesome Menu image made for us (Instagram: ji_hikari) -> PacManMenu.png

    DarthVader.png: -> https://www.pinterest.com/pin/235172411769819475/?autologin=true
    deadbody_amongus.png -> https://i.redd.it/pwdgucy89en51.png
    VictoryScreen.png -> https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.inverse.com%2Fgaming%2Famong-us-crewmate-tips-how-to-complete-tasks-unmask-imposters&psig=AOvVaw3nYw5DvBc3q-SiYZKr2sli&ust=1604799803428000&source=images&cd=vfe&ved=0CAIQjRxqFwoTCIi4y6un7-wCFQAAAAAdAAAAABAD
    YouDied.jpg -> https://www.google.com/imgres?imgurl=https%3A%2F%2Fi.kym-cdn.com%2Fentries%2Ficons%2Foriginal%2F000%2F029%2F198%2FDark_Souls_You_Died_Screen_-_Completely_Black_Screen_0-2_screenshot.png&imgrefurl=https%3A%2F%2Fknowyourmeme.com%2Fmemes%2Fyou-died&tbnid=8KDUO7MXjacbKM&vet=12ahUKEwiz_afSp-_sAhUSbTABHeNZBUwQMygAegUIARCmAQ..i&docid=pt-PwsneAmzjrM&w=1920&h=1080&q=dark%20souls%20you%20died%20png&ved=2ahUKEwiz_afSp-_sAhUSbTABHeNZBUwQMygAegUIARCmAQ

    PacMan Sound Effects: 
        https://www.youtube.com/watch?v=SPjEhbRFTUk
        https://www.classicgaming.cc/classics/pac-man/sounds
        https://downloads.khinsider.com/game-soundtracks/album/pac-man-game-sound-effects
        VictorySound.mp3 -> https://www.youtube.com/watch?v=96YhBRqW6T4
    
    Darth Vader Sound Effects:
        ImperialMarch.mp3 -> https://www.youtube.com/watch?v=-bzWSJG93P8
        DarthVaderJoins -> https://www.youtube.com/watch?v=-bzWSJG93P8
        DarthVaderVoiceLine.mp3 -> https://www.youtube.com/watch?v=onhFH7jpq2c
        DarthVaderVoiceLine.mp3 -> https://www.youtube.com/watch?v=zHryvLi6u84



BUGS,FEATURES AND WHATS NEXT:

    Bug #1
    
    There is a bug that crashes the game, however this bug happens very randomly and it is very specific. By trial and error we
    managed to discover that the crash occurs when PacMan eats two Ghosts at the same time after they have been eating a first time,
    this means that after PacMan EATS the ghosts for the first time and the spawn, this crash can occur. However, we also discovered
    random instances, but very limited ones, where the game crashed when two entities collided at the same time. The bug occurs on  
    EntityMananger on the tick function, the program tries to delete the position that equals the size of the vector, for exmaple if
    the vector has a size of 49, the program tries to delete the 49 item, crashing it. We were notified by some TAs that it was an error
    that came with the source code, it was not directly our fault.

    Bug #2

    The music when Darth Vader Spawns does not stop until the program is closed again and it will play everytime after 3 minutes
    When the map changes, only the ImperialMarch sound effect plays on. There are sounds for the Victory and GameOver
    States. To listen to them you have to pay attention, in the case of the GameOverState you can just press 'n' to take
    out all lifes and trigger the GameOverState. For the Victory Screen, you have to finish the game. I recommend setting
    PacMan's speed to 4 to finish the game faster if you dont mind for the sound to be glitched when he eats dots.

    Bug #3

    We had a problem with GitHub in the sense that in a Push some binary, compiled and JSON files were pushed to the repository,
    if any problems are given when compiling please just do a make clean and compile again and then it should work perfectly.
    If not please contact us by email: sebastian.estrada@upr.edu and argenis.olivo@upr.edu

    WHATS NEXT:

        * the feature of making the Ghosts spawn as the same color that they died 
        * the feature of making PacMan not to enter the SpawnGate 
        * Make the Blue and white animations better
        * Make an animation for PacMan when he dies 
        * Make the Attacks for the Boss to work 
        * Make the Ghosts Movements smarter
        * Make Multiplayer (Miss PacMan)
        * Add more PowerUps, maps and Bosses
        * Fix the Sound abd Crash BUGS
        * Simplify and clean code 

    ADDED FEATURES:

        * Added a new map when PacMan eats all the dots of the first map
        * Added a Victory Game State
        * Added Darth Vader as the intention of a Boss, but right now it is just a cool easter egg
        * Added lots of Sound Effects 
        * Added the option to Spawn a fruit with the 'c' key, for now it does not  have a sound or gives points
        * Added a custom image for the intro

        Note: To change Maps, please finish the game.