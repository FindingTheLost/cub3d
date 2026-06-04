_This project has been created as part of the 42 curriculum by pde-alme && rogde-so._

---

<pre style="font-family: monospace; line-height: 1.1;"><span style="background: repeating-linear-gradient(to bottom, rgba(50, 50, 50, 0.22), rgba(50, 50, 50, 0.22) 1px,transparent 1px, transparent 3px);">
<span style=><span style="color: rgb(255, 69, 69);">                           ______________________________/\\\____________/\\\\\\\\\\___/\\\\\\\\\\\\____                                   <span>
<span style="color: rgb(255, 69, 69);">                            _____________________________\/\\\__________/\\\///////\\\_\/\\\////////\\\__                                  <span>
<span style="color: rgb(255, 69, 69);">                             _____________________________\/\\\_________\///______/\\\__\/\\\______\//\\\_                                 <span>
<span style="color: rgb(255, 69, 69);">                              _____/\\\\\\\\__/\\\____/\\\_\/\\\________________/\\\//___\/\\\_______\/\\\_                                <span>
<span style="color: rgb(255, 69, 69);">                               ___/\\\//////__\/\\\___\/\\\_\/\\\\\\\\\_________\////\\\__\/\\\_______\/\\\_                               <span>
<span style="color: rgb(255, 69, 69);">                                __/\\\_________\/\\\___\/\\\_\/\\\////\\\___________\//\\\_\/\\\_______\/\\\_                              <span>
<span style="color: rgb(255, 69, 69);">                                 _\//\\\________\/\\\___\/\\\_\/\\\__\/\\\__/\\\______/\\\__\/\\\_______/\\\__                             <span>
<span style="color: rgb(255, 69, 69));">                                  __\///\\\\\\\\_\//\\\\\\\\\__\/\\\\\\\\\__\///\\\\\\\\\/___\/\\\\\\\\\\\\/___                            <span>
<span style="color: rgb(255, 69, 69);">                                   ____\////////___\/////////___\/////////_____\/////////_____\////////////_____                           <span>
</pre>





> <span style="color: rgb(251, 175, 116); font-size: 13px;">New competition has come forth to put down legendary Dukes and to bring first-person shooters to their DOOM, taking them down one by one, like a Shadow Warrior... 30 years later. Enter, cube3D.





# <span style="background: repeating-linear-gradient(to bottom, rgba(211, 0, 0, 0.38) 1px, transparent 3px);"><span style="border:1px solid rgb(255, 69, 69); padding:2px 6px; border-radius:10px;"><span style="color: rgb(255, 69, 69);">**DESCRIPTION**</span>
<pre><span style="color: rgb(251, 175, 116);"><span style="font-size: 17px; font-weight: bold;">cub3D is an introductory project to early 1990's 3D graphics techniques - Raycasting. Its goal is to build a first-person 3D maze where a player can traverse the map with keyboard and mouse controls using a raycasted field-of-view perspective, much inspired by the game <i>Wolfenstein 3D</i>.

Raycasting (not to be confused with Raytracing) is the act of casting a ray anywhere in a 3D space to perform calculations upon or collect data regarding, but not limited to, distances, collisions, color, lighting, etc... and is one of the most important 3D graphics rendering techniques still in use.

The program is to use Raycasting to calculate the distance a player is from a wall, in a given 2D map location, and draw it according to how close or far it is to represent the player's field-of-view, giving the illusion of being inside the 3D maze. A simple ray is not enough to represent the image in three dimensions due to our real field-of-view pointing to not one, but many directions at a time, thus, multiple rays have to be casted from the player's position across all of its field-of-view.

With the help of the <i>miniLibX</i> graphics library, the program can render walls with different textures per cardinal direction with individual ceiling and floor colors and represent a first-person perspective in an enclosed user created map. It also allows navigation through the map using keyhooks in the form of keyboard inputs and mouse movement.

Drawing in a computer canvas follows the same rules as drawing in the real world, the furthest objects from the point of view are drawn first and the closest ones are drawn on top of the ones before. Knowing this, the ceiling and floor colors are drawn first, the map's walls next, and lastly, any heads-up-displays (HUDs) or player related animations are drawn last.

The project has no creative limit, although, with more additions and functionality comes more time spent developing the project. Subject mandatory and bonus sections were 100% implemented plus some little extras.</pre>





# <span style="background: repeating-linear-gradient(to bottom, rgba(211, 0, 0, 0.38) 1px, transparent 3px);"><span style="border:1px solid rgb(255, 69, 69); padding:2px 6px; border-radius:10px;"><span style="color: rgb(255, 69, 69);">**DESIGN**</span>
<pre><span style="color: rgb(251, 175, 116);"><span style="font-size: 17px; font-weight: bold;">This project's code structure, design and organization has a certain similarity to C with classes, although completely original. The project files are distributed into major groups, such as:</span>

<span style="color: rgb(255, 163, 24);"><span style="font-size: 25px; font-weight: bold;"><i>PARSING:</i></span></span> 
A valid map file is composed of specific components in any given order (cannot be set below the map content). These include:

=> The wall textures in a ".xpm" file format for each cardinal direction: <b><i>North (NO)</i></b>, <b><i>South (SO)</i></b>, <b><i>West (WE)</i></b> and <b><i>East (EA)</i></b>;
=> The colors in R/G/B format for the <b><i>Ceiling (C)</i></b> and <b><i>Floor (F)</i></b>. Each spectrum ranges from 0 to 255;
=> The map, which is composed of the following characters: <b><i>Wall (1)</i></b>, <b><i>Ground (0)</i></b>, <b><i>Empty Space ( )</i></b>, <b><i>Player (N, S, W, E)</i></b> and <b><i>Door (D)</i></b>;
=> The player character refers to the spawning location and orientation;
=> The map is only valid if all ground and player tiles are properly surrounded by walls.
<h2 id="section2">Example of a valid map:</h2><pre><span style="color: rgb(255, 241, 231);">NO assets/textures/wall/north.xpm
SO assets/textures/wall/south.xpm
WE assets/textures/wall/west.xpm
EA assets/textures/wall/east.xpm

F 0,128,255
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
100000000000000011000000D0001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111</span></pre>

<span style="color: rgb(255, 163, 24);"><span style="font-size: 25px; font-weight: bold;"><i>STRUCTS:</i></span></span> 
With growing complexity comes the need for organization based on functionality. Each struct has its own folder with its member functions and is responsible for its own construction, destruction, debugging output, error handling, and more. These structs are the following:

=> <b><i>t_cub</i></b> - holds the raw data of a valid ".cub" map file;
=> <b><i>t_game</i></b> - holds all the remaining structures together, composing the full game. It is the main structure;
=> <b><i>t_player</i></b> - holds the current position and rotation of a player;
=> <b><i>t_map</i></b> - holds the layout of the current map as well as its size; 
=> <b><i>t_image</i></b> - holds an image texture or a canvas to be drawn and their respective data;
=> <b><i>t_key</i></b> - holds boolean information of all available keyboard keys;
=> <b><i>t_mouse</i></b> - holds mouse movement axis and pointer position information;
=> <b><i>t_render</i></b> - holds all render algorithm, ray and drawing data and variables regarding the current frame to be drawn;
=> <b><i>t_anim</i></b> - holds frame, image, boolean and time data of an animation.

<span style="color: rgb(255, 163, 24);"><span style="font-size: 25px; font-weight: bold;"><i>GAME:</i></span></span> 
Takes care of initializing all of the structs and variables to be used, detecting if the game's current resolution is unsupported, if the number of rays currently set are invalid for the current resolution, as well as setting the key and mouse hooks the game will listen to when updating each frame. It controls the loop of updating the game's logic and redrawing every frame, making this the heart of the project that connects every structure together.</pre>





# <span style="background: repeating-linear-gradient(to bottom, rgba(211, 0, 0, 0.38) 1px, transparent 3px);"><span style="border:1px solid rgb(255, 69, 69); padding:2px 6px; border-radius:10px;"><span style="color: rgb(255, 69, 69);">**INSTRUCTIONS**</span>
#### <span style="color: rgb(255, 163, 24);">***CONTROLS:***</span>
<pre><span style="color: rgb(251, 175, 116);"><div style="display:grid; grid-template-columns: auto 1fr; gap: 4px 16px">
<kbd>  W</kbd> <span>Move Forward</span>
<kbd>  S</kbd> <span>Move Backwards</span>
<kbd>  A</kbd> <span>Strafe Left</span>
<kbd>  D</kbd> <span>Strafe Right</span>
<kbd>  E</kbd> <span>Equip Helmet</span>
<kbd>  M</kbd> <span>Toggle Minimap</span>
<kbd>LEFT</kbd> <span>Rotate Left</span>
<kbd>RIGHT</kbd> <span>Rotate Right</span>
<kbd>SHIFT</kbd> <span>Sprint</span>
<kbd>SPACE</kbd> <span>Open Doors</span>
<kbd>CTRL</kbd> <span>Unlock Mouse</span>
</div></pre></span>

#### <span style="color: rgb(255, 163, 24);">***COMPILATION:***</span>
<pre><span style="color: rgb(251, 175, 116);">-> Type <span style="font-size: 18px;"><b><i>make</b></i></span> in the root of the project's folder to build the <i>'cub3D'</i> executable. 
-> Type <span style="font-size: 18px;"><b><i>make clean</b></i></span> to clear the object files produced by compilation.
-> Type <span style="font-size: 18px;"><b><i>make fclean</b></i></span> to clear the object files and the executable. 
-> Type <span style="font-size: 18px;"><b><i>make re</b></i></span> to clear the object files and executable and re-compile the project.</pre></span>

#### <span style="color: rgb(255, 163, 24);">***EXECUTION:***</span>
<pre><span style="color: rgb(251, 175, 116);">To launch the executable, in a terminal of your choice type <span style="font-size: 18px; color: rgb(255, 69, 69);">./cub3D [ARG]</span> where [ARG] is the relative path of a valid ".cub" <a href="#section2">map file</a> as described above.</pre></span>

#### <span style="color: rgb(255, 163, 24);">***HELP:***</span>
<pre><span style="color: rgb(251, 175, 116);">To access the program's help/credits screen, append the -h or --help option when launching it: <span style="font-size: 18px; color: rgb(255, 69, 69);">./cub3D -h</span> or <span style="font-size: 18px; color: rgb(255, 69, 69);">./cub3D --help</span></pre></span>





# <span style="background: repeating-linear-gradient(to bottom, rgba(211, 0, 0, 0.38) 1px, transparent 3px);"><span style="border:1px solid rgb(255, 69, 69); padding:2px 6px; border-radius:10px;"><span style="color: rgb(255, 69, 69);">**RESOURCES**</span>

#### <span style="color: rgb(255, 163, 24);">***DOCUMENTS:***</span>
- [<span style="color: rgb(251, 175, 116);">Minilibx 42 Docs</span>](https://harm-smits.github.io/42docs/libs/minilibx)
- [<span style="color: rgb(251, 175, 116);">Lode's Computer Graphics Tutorial</span>](https://lodev.org/cgtutor/raycasting.html)
- [<span style="color: rgb(251, 175, 116);">DDA Algorithm Interactive Explanation</span>](https://aaaa.sh/creatures/dda-algorithm-interactive/)
- [<span style="color: rgb(251, 175, 116);">Permadi Raycasting Tutorial</span>](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
- [<span style="color: rgb(251, 175, 116);">Understanding Raycasting Step-by-Step</span>](https://andorsaga.wordpress.com/2014/01/22/understanding-raycasting-step-by-step/)

#### <span style="color: rgb(255, 163, 24);">***VIDEOS (YouTube):***</span>
- [<span style="color: rgb(251, 175, 116);">Super Fast Ray Casting in Tiled Worlds using DDA</span>](https://www.youtube.com/watch?v=NbSee-XM7WA)
- [<span style="color: rgb(251, 175, 116);">3DSage make your own Raycaster</span>](https://www.youtube.com/watch?v=gYRrGTC7GtA)
- [<span style="color: rgb(251, 175, 116);"> Ray casting fully explained. Pseudo 3D game.</span>](https://www.youtube.com/watch?v=g8p7nAbDz6Y)

#### <span style="color: rgb(255, 163, 24);">***AI:***</span>
> <span style="color: rgb(251, 175, 116);"> AI was used to learn, explain and exemplify mathematical and trigonometry concepts such as radians, cosine, sine, tangent, cotangent and arctangent, how and why these are used and what are they used for. No code was asked, copied from or generated by AI. All code was man-made by both devs with the intent of learning every topic the subject requires from start to finish.</span>