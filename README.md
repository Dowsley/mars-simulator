# What is this?
To be honest, I don't know. I suppose I could make it similar to No Man's Sky idea, but 2D and pixel-like.

# Engine
Place the engine source code (regardless of platform) inside `src/engine/graphics` at root level.

https://github.com/MumflrFumperdink/olcPGEMac

# Design Pattern highly inspired in:
https://github.com/munificent/hauberk

# Broad inspiration
- https://github.com/CleverRaven/Cataclysm-DDA
- https://codereview.stackexchange.com/questions/254731/dwarf-fortress-clone-c
- https://github.com/th3v0ice/Dwarf_Fortress_Clone
- https://github.com/h4ctar/yadf
- https://github.com/Trevoke/dwarlixir
- https://docs.unity3d.com/Packages/com.unity.entities@0.51/manual/index.html

# Scientific data
- https://www.mars.asu.edu/data/
- http://www.mars.asu.edu/data/mola_color/
- https://en.wikipedia.org/wiki/Martian_soil
- https://en.wikipedia.org/wiki/Space_suit#Requirements

# Dwarf fortress inspiration
- https://dwarffortresswiki.org/index.php/DF2014:Raw_file
- https://dwarffortresswiki.org/index.php/DF2014:Modding
- https://dwarffortresswiki.org/index.php/DF2014:Token
- https://dwarffortresswiki.org/index.php/DF2014:Tile
- https://dwarffortresswiki.org/index.php/DF2014:Inorganic_material_definition_token#SOIL
# Progress
- [X] Tile system
- [X] ASCII Sprite Tile Representations with colors
- [X] Tile Color variance for same context
- [X] Tile Sprite variance for same context
- [X] Third dimension
- [X] Rethink the current framework into separate systems
- [X] Tile primary & secondary color
- [X] Entities
  - [X] Organic and inorganic tiles
  - [X] Trees
  - [X] Creatures
  - [ ] Small plants
- [ ] Organize metadata system, it is COMPLETELY fucked up. Gladly not used, *yet*.
- [ ] Player
- [ ] Separate OLC pixel game engine classes from mine (vi2d and Pixel)
- [ ] Color schemes (DF)
- [ ] Tile sprite & color variance by context
  - [ ] Slopes
  - [ ] Multi-level view
- [ ] Procedurally generate materials and creatures
- [ ] Procedurally generate planets and its geology
- [ ] Environment dynamics (weather, etc)
- [ ] Space travel & spaceship

# Idea Dump
### Tile Size: two meters long, two meters wide, and three meters high