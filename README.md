# DS Learn

This repo is a playground area for me to be able to learn the basics of nintendo DS development.

## Setting up a development environment
1. Download and install [devkitPro](https://devkitpro.org), [installer link](https://github.com/devkitPro/installer/releases/latest)
    - Only the NDS development kit is required
    - I installed to `C:/nds/devkitPro`
2. Modify your system environment variables, the paths will be wrong if you're using a windows machine
    - Update `/opt/` in the paths for DEVKITPRO, DEVKITARM, & DEVKITPPC to your installation path
    - For me I updated DEVKITPRO to `/c/nds/devkitPro`
3. Get an emulator like [DeSmuME](http://desmume.org) or [No$GBA](https://www.nogba.com)
    - the less time you can spend copying onto a flash cart the better
4. Set yourself up with a decent IDE, I chose [VSCode](https://code.visualstudio.com)
    - Useful VSCode plugins
      - C/C++
      - C++ Intellisense

## Building the project
1. Open `MSYS2`, this was installed as part of devkitPro
    - I chose to add this as an option to [Windows Terminal](https://www.msys2.org/docs/terminals)
2. Navigate to your repository
    - Run the command `cd /c/nds/repo/dsLearn`
3. Run the `make` command

## Useful material
- [NDS Homebrew Development](https://github.com/jdriselvato/NDS-Development)
- [VSCode Template](https://github.com/cuibonobo/nds_vscode_template)
- [libnds Documentation](https://libnds.devkitpro.org/index.html)
- [OSDL - A guide to homebrew development for the Nintendo DS](http://osdl.sourceforge.net/main/documentation/misc/nintendo-DS/homebrew-guide/HomebrewForDS.html)
- [DMA - Backgrounds](http://cpp4ds.blogspot.com)
- [VRAM Banks Selector](https://mtheall.com/banks.html#)
- [VRAM BG Allocation Conflict Viewer](https://mtheall.com/vram.html#)
- [dsgmLib - DS Game Maker](https://github.com/CTurt/dsgmLib) 
    - _The first person I found to have implemented NiFi, by changing packet headers in promiscuous mode, no clue if it works yet_
- [NES DS](https://github.com/RocketRobz/NesDS)
    - _Includes NiFi support_ [Related](https://gbatemp.net/threads/anybody-got-nifi-to-work-in-nesds.317583)
- [CQuake](https://gbatemp.net/threads/cquake-nifi-ds-2-ds-local-multiplayer.350334)
    - _Includes NiFi support_

## Other peoples games to learn from
- [Space Impakto DS](http://rel.phatcode.net/index.php?action=contents&item=Space-Impakto-DS)
- [Bubble Fight EX DS](http://rel.phatcode.net/index.php?action=contents&item=Bubble_Fight_EX_DS)
- [SpelunkyDS](https://github.com/dbeef/spelunky-ds)
- [CalculaThreeDS](https://github.com/LiquidFenrir/CalculaThreeDS)
- [CellsDS](https://github.com/clone45/cellsds)
- [DSChess](http://www.vonloesch.de/dschess.html)

