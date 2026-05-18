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

# <span style="background: repeating-linear-gradient(to bottom, rgba(0, 16, 165, 0.22), rgba(0, 186, 211, 0.38) 1px,transparent 1px, transparent 3px);"><span style="border:1px solid rgb(0, 172, 120); padding:2px 6px; border-radius:10px;"><span style="color: rgb(0, 172, 120);">**DESCRIPTION**</span>
<pre><span style="color: rgb(0, 185, 218);"><span style="font-size: 17px; font-weight: bold;">The goal of this project is to introduce students to the challenges of the early days of computing, where visual interfaces were still a thing from the future and not as thought-out or refined as today. Thus, the only and best way to interact with a computer was by running a piece of software where a user could interact with the computer by typing it <i>commands</i>. This software is called a <i>Shell</i> - it's a command-line that surrounds the operating system's <i>kernel</i>, allowing the user to communicate with it and be given access to hardware resources to perform multiple tasks and programs.
Minishell is based off some of <i>Bash</i>'s functionality and behaviour by <i>heart</i>.

A <i>Shell</i>, and consequently <i>Minishell</i>, can be defined by two major sectors:</span>

<span style="font-size: 17px; font-weight: bold;"><i>-> INTERPRETER:</i></span> (by pde-alme) Also known as a <i>parser</i>, takes the user inputted prompt from the command-line and performs a plethora of tasks from <i>syntax-checking</i>, <i>heredoc-reading</i>, <i>symbol-interpretation</i> and splits it into tokens to build a structure that the <i>execution</i> sector will then read from.

<span style="font-size: 17px; font-weight: bold;"><i>-> EXECUTION:</i></span> (by rogde-so) Takes the built structure from the <i>interpreter</i> and, depending on what the user has specified, will perform various tasks such as <i>redirecting file descriptors</i>, <i>pipe results of programs into others</i>, <i>create child processes to divide the various tasks</i>, <i>execute regular and built-in binaries</i>, <i>read and perform actions with the Shell's environment variables</i>, <i>create/remove/edit/manipulate files</i>, etc... and all of this within the Shell's own environment. As soon as the <i>execution</i> is finished, it returns to the <i>interpreter</i> unless terminated.

<span style="font-size: 17px; font-weight: bold;"><i>MINISHELL</span></i> handles almost every command, multiple redirections <i>(<, >, <<, >>)</i>, multiple pipes, environment variables <i>('$?' included)</i>, some signals <i>(Ctrl-C, Ctrl-D and Ctrl-\)</i> and some shell built-in binaries <i>('echo' with option '-n', 'cd', 'pwd', 'export', 'unset', 'env', 'exit')</i>. It is far from a feature-rich and battle-tested <i>Shell</i> like <i>Bash</i>, <i>Bourne Shell (sh)</i> or even <i>Z Shell (zsh)</i> but the principle is still there.
</span></pre>

---

# <span style="background: repeating-linear-gradient(to bottom, rgba(0, 16, 165, 0.22), rgba(0, 186, 211, 0.47) 1px,transparent 1px, transparent 3px);"><span style="border:1px solid rgb(0, 172, 120); padding:2px 6px; border-radius:10px;"><span style="color: rgb(0, 172, 120);">**INSTRUCTIONS**</span>
#### <span style="color: rgb(0, 121, 85);">**COMPILATION:**</span>
<pre><span style="color: rgb(0, 185, 218);">-> Type <span style="font-size: 18px;"><b><i>make</b></i></span> in the root of the project's folder to build the <i>'minishell'</i> executable. 
-> Type <span style="font-size: 18px;"><b><i>make clean</b></i></span> to clear the object files produced by compilation.
-> Type <span style="font-size: 18px;"><b><i>make fclean</b></i></span> to clear the object files and the executable. 
-> Type <span style="font-size: 18px;"><b><i>make re</b></i></span> to clear the object files and executable and re-compile the project.</pre></span>
#### <span style="color: rgb(0, 121, 85);">**EXECUTION:**</span>
<pre><span style="color: rgb(0, 185, 218);">To launch the executable, type <span style="font-size: 18px; color: rgb(0, 172, 120);">./minishell</span> in your terminal of choice.</pre></span>
#### <span style="color: rgb(0, 121, 85);">**DEBUG OPTIONS:**</span>
<pre><span style="color: rgb(0, 185, 218);">To access <span style="font-size: 18px;"><b><i>minishell</b></i></span> debugging options, simply export the variable 'MINISHELL_DEBUG' with the following values:
-> <span style="font-size: 18px;"><b><i>0</b></i></span> - Minishell will operate with its default behaviour (same as not declaring 'MINISHELL_DEBUG').
-> <span style="font-size: 18px;"><b><i>1</b></i></span> - Minishell will enter its pipeline structure debugging-mode.
-> <span style="font-size: 18px;"><b><i>2</b></i></span> - Minishell will enter its parser memory debugging-mode (to debug memmory in the interpreter).
-> <span style="font-size: 18px;"><b><i>3</b></i></span> - Minishell will enter both its pipeline structure and parser memory debugging-modes at once.

Due to the soft-locking nature of modes <span style="font-size: 18px;"><b><i>2</b></i></span> and <span style="font-size: 18px;"><b><i>3</b></i></span>, as soon as the user types a command after setting into one of these modes, <span style="font-size: 18px;"><b><i>minishell</b></i></span> will reset the 'MINISHELL_DEBUG' environment variable back to <span style="font-size: 18px;"><b><i>0</b></i></span>.
</pre></span>

---

# <span style="background: repeating-linear-gradient(to bottom, rgba(0, 16, 165, 0.22), rgba(0, 186, 211, 0.47) 1px,transparent 1px, transparent 3px);"><span style="border:1px solid rgb(0, 172, 120); padding:2px 6px; border-radius:10px;"><span style="color: rgb(0, 172, 120);">**RESOURCES**</span>

#### <span style="color: rgb(0, 121, 85);">**DOCUMENTS:**</span>
- [<span style="color: rgb(0, 185, 218);">Linux Manual</span>](https://man7.org/linux/man-pages/man1/man.1.html)
- [<span style="color: rgb(0, 185, 218);">Minishell Allowed Functions</span>](https://42-cursus.gitbook.io/guide/3-rank-03/minishell/functions)
#### <span style="color: rgb(0, 121, 85);">**TUTORIALS:**</span>
- [<span style="color: rgb(0, 185, 218);">Oceano's Mini-minishell</span>](https://www.youtube.com/watch?v=yTR00r8vBH8&t=1205s)
- [<span style="color: rgb(0, 185, 218);">CodeVault Useful Playlist</span>](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)
- [<span style="color: rgb(0, 185, 218);">What is Bash by Fireship</span>](https://www.youtube.com/watch?v=I4EWvMFj37g)
#### <span style="color: rgb(0, 121, 85);">**AI:**</span>
- [<span style="color: rgb(0, 185, 218);">Cs50 Duck</span>](https://cs50.ai/)
> <span style="color: rgb(0, 185, 218);">AI was only used to understand how some of the allowed functions worked due to lack of clear and concise documentation and to understand how some of <i>Bash</i>'s behaviour works behind the curtains.</span>

# cub3d
Repository for 42's cub3d by pde-alme and rogde-so.

Macro ZERO_DELTA needs fine tuning (only if nothing is being rendered).
Diagonals have no pythagoras theorem applied, therefore will move faster.
