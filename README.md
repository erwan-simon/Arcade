# Arcade
C++ launcher with 2 games and 2 graphical librairies

## Requirements

 - [Make](https://www.gnu.org/software/make/)
 - [G++](https://gcc.gnu.org/)
 - [ncurses](https://www.gnu.org/software/ncurses/)
 - [SFML](https://www.sfml-dev.org/)

## Compilation

Navigate to the root of the repository from your Terminal and run `make` to build the `arcade` executable file.

## Execute

- Execute with NCurses

```
./arcade ./lib/lib_arcade_ncurses.so
```

- Execute with SFML

```
./arcade ./lib/lib_arcade_sfml.so
```

## User manual

The program is made for QWERTY keyboards. Therefore, when we advocate the use of the 4 key, for instance, the AZERTY users should press MAJ key to do so.

The user can switch graphical library or game whenever it is desired (even when the game is launched).

- `2` to use NCurse librairy
- `3` to use SFML librairy
- `4` to select snake game
- `5` to select pacman game
- `8` to launch the game
- `Escape` to quit

### In Game

The arrow keys are used to move the character.

## Authors

* **Erwan Simon** ([GitHub](https://github.com/erwan-simon) / [LinkedIn](https://www.linkedin.com/in/erwan-simon/))
* **Antoine Roche** ([GitHub](https://github.com/Antoine-Roche))
* **Selim Rinaz** ([GitHub](https://github.com/rinaz-a))
