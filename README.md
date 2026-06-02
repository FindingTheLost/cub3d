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

--- 

> <span style="color: rgb(251, 175, 116); font-size: 13px;">New competition has come forth to put down legendary Dukes and to bring first-person shooters to their DOOM, taking them down one by one, like a Shadow Warrior... 30 years later. Enter, cube3D.

---

# <span style="background: repeating-linear-gradient(to bottom, rgba(211, 0, 0, 0.38) 1px, transparent 3px);"><span style="border:1px solid rgb(255, 69, 69); padding:2px 6px; border-radius:10px;"><span style="color: rgb(255, 69, 69);">**DESCRIPTION**</span>
<pre><span style="color: rgb(251, 175, 116);"><span style="font-size: 17px; font-weight: bold;">cub3D is a project inspired by <i>Wolfenstein 3D</i>, regarded as the first true First Person Shooter. The goal is to develop a 3D graphical representation of a first-person perspective, learning and implementing math concepts such as radians, basic trigonometry and raycasting.

Using the <i>miniLibX</i> graphics library, the program renders walls with different textures per cardinal direction, floor and ceiling colors, and navigation through the space/map using the keyhooks of the aformentioned library in the form of keyboard inputs and mouse movement.

Trying to keep a C with classes style of code and organization, the project files are distributed into major groups, these are:</span>

<span style="color: rgb(255, 163, 24);"><span style="font-size: 25px; font-weight: bold;"><i>-> PARSING:</i></span></span> 
A valid map file is composed of specific components in a specific order. These are the wall textures in a .xpm format for each cardinal direction: <i>NO -> North | SO -> South | WE -> West | EA -> East</i>. Then the colors in R/G/B format for the Ceiling (C) and Floor (F). After these components comes the map, which is composed of the following characters: <i>1 -> Walls | 0 -> Empty Space | N/S/W/E -> Player | D -> Doors</i>. The player is spawned in the map in the orientation specified by the choosen character. The map is only valid if all the empty spaces (0) are inside or surrounded by walls (1).
<h2 id="section2">A valid map would look like this:</h2><pre><span style="color: rgb(255, 241, 231);">NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

1111111
1000N01
1111111</span></pre>

<span style="color: rgb(255, 163, 24);"><span style="font-size: 25px; font-weight: bold;"><i>-> STRUCTS:</i></span></span> 
With growing complexity comes the need for organization based on functionality. Each struct has it's own folder and is responsible for it's own construction, destruction, debugging output and error handling. The structs are:

=> <b><i>t_cub</i></b>, responsible for extracting and allocating all the map file components, these being the .xpm files for the cardinal textures, the colors for the ceiling and the floor and the map itself, also counting its width and height for future use.

=> <b><i>t_game</i></b>, responsible for most the gaming logic: 
<sup>-> The initialization of the mlx pointer and window pointer.
-> The inputed key action, calculating players rotation and movement speed, wall collisions, as well as toggling the minimap on and off. 
-> The mouse movement execution as well as locking it in the center of the screen.
-> The drawing function as well as drawing the floor, ceiling and the minimap, including the player icon navigating through it.
-> The initialization of the given texture paths into images to then be drawn with dda checks.

=> <b><i>t_image</i></b>, responsible for allocating all the images to be drawn on screen through minilibx.

=> <b><i>t_map</i></b>, responsible for saving the map copy to be used in-game, along with its heigth and width. 

=> <b><i>t_key</i></b>, responsible for saving all the keys in the form of integers used as booleans, this way key press holds can be read seemlessly. 

=> <b><i>t_mouse</i></b> responsible for saving the x and y variable positions of the mouse.

=> <b><i>t_render</i></b> responsible for rendering the 3D world with DDA algorithm.

=> <b><i>t_anim</i></b> responsible for initiating and replaying the helmet equip animation.

<span style="color: rgb(255, 163, 24);"><span style="font-size: 25px; font-weight: bold;"><i>-> GAME:</i></span></span> 
Takes care of initializing all the structs and variables to be used, as well as the keyhooks for the mlx_loop to detect, calling the appropriate hooked function for if ESC or the windows [x] was pressed, checks which key was pressed or released and updating the boolean value accordingly. It then maintains the loop of updating the game and redrawing every frame, making this the heart of the project.</pre>

---
# <span style="background: repeating-linear-gradient(to bottom, rgba(211, 0, 0, 0.38) 1px, transparent 3px);"><span style="border:1px solid rgb(255, 69, 69); padding:2px 6px; border-radius:10px;"><span style="color: rgb(255, 69, 69);">**INSTRUCTIONS**</span>
#### <span style="color: rgb(255, 163, 24);">**CONTROLS:**</span>
<pre><span style="color: rgb(251, 175, 116);"><div style="display:grid; grid-template-columns: auto 1fr; gap: 4px 16px">
<kbd>W Key</kbd> <span>Move Forward</span>
<kbd>S Key</kbd> <span>Move Backwards</span>
<kbd>A Key</kbd> <span>Strafe Left</span>
<kbd>D Key</kbd> <span>Strafe Right</span>
<kbd>E Key</kbd> <span>Equip Helmet</span>
<kbd>M Key</kbd> <span>Toggle Minimap</span>
<kbd>Left</kbd> <span>Rotate Left</span>
<kbd>Right</kbd> <span>Rotate Right</span>
<kbd>Shift</kbd> <span>Sprint</span>
<kbd>SPACE</kbd> <span>Open Doors</span>
<kbd>CTRL</kbd> <span>Unlock Mouse</span>
</div></pre></span>

#### <span style="color: rgb(255, 163, 24);">**COMPILATION:**</span>
<pre><span style="color: rgb(251, 175, 116);">-> Type <span style="font-size: 18px;"><b><i>make</b></i></span> in the root of the project's folder to build the <i>'cub3D'</i> executable. 
-> Type <span style="font-size: 18px;"><b><i>make clean</b></i></span> to clear the object files produced by compilation.
-> Type <span style="font-size: 18px;"><b><i>make fclean</b></i></span> to clear the object files and the executable. 
-> Type <span style="font-size: 18px;"><b><i>make re</b></i></span> to clear the object files and executable and re-compile the project.</pre></span>

#### <span style="color: rgb(255, 163, 24);">**EXECUTION:**</span>
<pre><span style="color: rgb(251, 175, 116);">To launch the executable, in a terminal of your choice type <span style="font-size: 18px; color: rgb(255, 69, 69);">./cub3D [ARG]</span> where [ARG] is the relative path for a valid <a href="#section2">map file</a> as described above.</pre></span>
#### <span style="color: rgb(255, 163, 24);">**DEBUG OPTIONS:**</span>
<pre><span style="color: rgb(251, 175, 116);">De bug is da beetle
</pre></span>

---

# <span style="background: repeating-linear-gradient(to bottom, rgba(211, 0, 0, 0.38) 1px, transparent 3px);"><span style="border:1px solid rgb(255, 69, 69); padding:2px 6px; border-radius:10px;"><span style="color: rgb(255, 69, 69);">**RESOURCES**</span>

#### <span style="color: rgb(255, 163, 24);">**DOCUMENTS:**</span>
- [<span style="color: rgb(251, 175, 116);">Minilibx 42 Docs</span>](https://harm-smits.github.io/42docs/libs/minilibx)
- [<span style="color: rgb(251, 175, 116);">Lode's Computer Graphics Tutorial</span>](https://lodev.org/cgtutor/raycasting.html)
- [<span style="color: rgb(251, 175, 116);">DDA Algorithm explained interactively</span>](https://aaaa.sh/creatures/dda-algorithm-interactive/)

#### <span style="color: rgb(255, 163, 24);">**VIDEOS:**</span>
- [<span style="color: rgb(251, 175, 116);">Super Fast Ray Casting in Tiled Worlds using DDA</span>](https://www.youtube.com/watch?v=NbSee-XM7WA)
- [<span style="color: rgb(251, 175, 116);">3DSage make your own Raycaster</span>](https://www.youtube.com/watch?v=gYRrGTC7GtA)

#### <span style="color: rgb(255, 163, 24);">**AI:**</span>
> <span style="color: rgb(251, 175, 116);"> AI was used to clarify raycasting math concepts such as radians and DDA algorithm in a interactive way. All code was man-made with fleshy, bony fingers and cold keyboards</span>

# cub3d
Repository for 42's cub3d by pde-alme and rogde-so.

Macro ZERO_DELTA needs fine tuning (only if nothing is being rendered).
Diagonals have no pythagoras theorem applied, therefore will move faster.
