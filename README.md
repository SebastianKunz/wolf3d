# WOLF3D
This project is part of the 42 Program. 

## Usage
- `make` to create the executeable wolf3d
- `./wolf3d [mapname]` to run the program. You can find maps in the ./maps directory or create your own.
- `make clean` to clean object files
- `make fclean` to clean object files and the executable wolf3d

## How to make your own map
A map is made up of positive integers, where every integer represents a texture (###Textures).
If the Number is invalid it defaults to 0 (no texture).
Each map must have **one** starting point, represented by a `X` character instead of a number.

## Textures
0 - no texture.
1 - redbrick
2 - wood
3 - greystone
4 - bluestone
5 - colorstone
6 - eagle
7 - mossy
8 - purplestone
9 - intra (my intra picture, please don't ask)
10 - hitler on wood
11 - sky

### How to add new Textures
1. Add the texture to the textures directory.
2. Add the absolut path to `static char *paths[TXT_COUNT + 1]` in `ft_load_texture` located in `main.c`.
3. Make sure that the last element is `NULL` and the second last element is the skybox texture.
3. Update the Macro TXT_COUNT in wolf3d.h  

## Planned implementations:
- hold keys
- Minimap
- Sprinting
- Sprites

## Screenshots
[![Screen-Shot-2018-12-26-at-8-02-59-PM.png](https://i.postimg.cc/pLvdgXKX/Screen-Shot-2018-12-26-at-8-02-59-PM.png)](https://postimg.cc/tYry6brL)
