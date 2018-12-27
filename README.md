# WOLF3D
This project is part of the 42 Program.
The main goal is to learn about 2D graphics in game development.

## Usage
- `make` to create the executeable wolf3d
- `./wolf3d [mapname]` to run the program. You can find maps in the ./maps directory or create your own.
- `make clean` to clean object files
- `make fclean` to clean object files and the executable wolf3d

### Game controls
<kbd>W</kbd> or <kbd>&uparrow;</kbd> To walk forward

<kbd>S</kbd> or <kbd>&downarrow;</kbd> To walk backwards

<kbd>A</kbd> To walk left

<kbd>D</kbd> To walk right

<kbd>&leftarrow;</kbd> To rotate the camera left

<kbd>&rightarrow;</kbd> To rotate the camera right

Or use the mouse to move the camera left or right.

## How to make your own map
- A map is made up of positive integers, where every integer represents a [texture](#textures)
- If the Number is invalid it defaults to 0 (no texture).
- Each map must have **one** starting point, represented by a `X` character instead of a number.

## Textures
| Index | Name           |
|:-----:|:--------------:|
| 0     |  no texture    |
| 1     | redbrick       |
| 2     | wood           |
| 3     | greystone      |
| 4     | bluestone      |
| 5     | colorstone     |
| 6     | eagle          |
| 7     | mossy          |
| 8     | purplestone    |
| 9     | intra          |
| 10    | sky            |

[![Screen-Shot-2018-12-26-at-10-30-22-PM.png](https://i.postimg.cc/85DPjLR6/Screen-Shot-2018-12-26-at-10-30-22-PM.png)](https://postimg.cc/LqCMWY09)

### How to add new Textures
1. Add the texture to the textures directory.
2. Add the absolut path to `static char *paths[TXT_COUNT + 1]` in `ft_load_texture` located in `main.c`.
3. Make sure that the last element is `NULL` and the second last element is the skybox texture.
3. Update the Macro `TXT_COUNT` in wolf3d.h  

## Planned implementations:
- hold keys
- Minimap
- Sprinting
- Sprites
- Controler support

## Screenshots
[![Screen-Shot-2018-12-26-at-8-02-59-PM.png](https://i.postimg.cc/pLvdgXKX/Screen-Shot-2018-12-26-at-8-02-59-PM.png)](https://postimg.cc/tYry6brL)
