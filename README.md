# TGB

<details>
<summary><h3 align="center">GameBoy Resources :bookmark_tabs:</h3></summary>

<details>
<summary><h3 align="center">GameBoy Specifications :desktop_computer:</h3></summary>

Specifications from [gbdev.io](https://gbdev.io/pandocs/) 

|                 | **Game Boy**                   | **Game Boy Pocket** | **Game Boy Color** | **Super Game Boy**         |
| --------------- | ------------------------------ | ------------------- | ------------------ | -------------------------- |
| CPU             | 8-bit Sharp LR35902            |                     |                    |                            |
| Clock           | 4.194304 MHz                   |                     | 8.388608 MHz       | 4.295454MHz (SGB1, NTSC)   |
| Work RAM        | 8 KB                           |                     | 32 KB              |                            |
| Video RAM       | 8 KB                           |                     | 16 KB              |                            |
| Screen Size     | LCD 4,7 x 4,3 cm               | LCD 4,8 x 4,4 cm    | TFT 4,4 x 4 cm     |                            |
| Resolution      | 160x144                        |                     |                    | 256x224 (including border) |
| Sprites         | Max 40 per screen, 10 per line |                     |                    |                            |
| Palettes        | 1x4 BG, 2x3 OBJ                |                     | 8x4 BG, 8x3 OBJ    | 1+4x3, 4x15 (border)       |
| Colors          | 4 grayshades                   |                     | 32768 colors       |                            |
| Horizontal Sync | 9.198 KHz                      |                     | 9.41986 KHz        |                            |
| Vertical Sync   | 59.73 Hz                       |                     | 61.1679 Hz         |                            |
| Sound           | 4 channels with stereo sound   |                     |                    |                            |
| Power           | DC6V 0.7W                      | DC3V 0.7W           | DC3V 0.6W          |                            |

<br/>

| **Start** | **End** | **Description**                                                                           | **Notes**                                           |
| --------- | ------- | ----------------------------------------------------------------------------------------- | --------------------------------------------------- |
| 0000      | 3FFF    | 16 KiB ROM bank 00                                                                        | From cartridge, usually a fixed bank                |
| 4000      | 7FFF    | 16 KiB ROM Bank 01~NN                                                                     | From cartridge, switchable bank via mapper (if any) |
| 8000      | 9FFF    | 8 KiB Video RAM (VRAM)                                                                    | In CGB mode, switchable bank 0/1                    |
| A000      | BFFF    | 8 KiB External RAM                                                                        | From cartridge, switchable bank if any              |
| C000      | CFFF    | 4 KiB Work RAM (WRAM)                                                                     |                                                     |
| D000      | DFFF    | 4 KiB Work RAM (WRAM)                                                                     | In CGB mode, switchable bank 1~7                    |
| E000      | FDFF    | Mirror of C000~DDFF (ECHO RAM)                                                            | Nintendo says use of this area is prohibited.       |
| FE00      | FE9F    | Sprite attribute table ([OAM](https://gbdev.io/pandocs/#vram-sprite-attribute-table-oam)) |                                                     |
| FEA0      | FEFF    | Not Usable                                                                                | Nintendo says use of this area is prohibited        |
| FF00      | FF7F    | I/O Registers                                                                             |                                                     |
| FF80      | FFFE    | High RAM (HRAM)                                                                           |                                                     |
| FFFF      | FFFF    | [Interrupts](https://gbdev.io/pandocs/#interrupts) Enable Register (IE)                   |                                                     |

<br/>

</details>

#### Links:
Most links (if not all) are from [The Emulation Development Discord Server](https://discord.gg/dkmJAes)

##### **Game Boy/Game Boy Color:**

- Pandocs: https://gbdev.io/pandocs
- The Cycle-Accurate GB Docs: https://github.com/AntonioND/giibiiadvance/blob/master/docs/TCAGBD.pdf
- Opcode table: https://izik1.github.io/gbops/table/table.html
- List of GB opcodes and their behavior: https://rednex.github.io/rgbds/gbz80.7.html
- GB instruction decoding table: https://cdn.discordapp.com/attachments/465586075830845475/742438340078469150/SM83_decoding.pdf
- Decoding GB opcodes algorithmically: https://gb-archive.github.io/salvage/decoding_gbz80_opcodes/Decoding%20Gamboy%20Z80%20Opcodes.html
- A journey into GB emulation: https://robertovaccari.com/blog/2020_09_26_gameboy
- WIP tutorial on writing a GB emulator in Rust: https://rylev.github.io/DMG-01/public/book/
- GameBoy Emulator Development Guide: https://hacktix.github.io/GBEDG
- Test ROMs:
   - Blargg's test ROMs: https://github.com/retrio/gb-test-roms
   - Mooneye-gb test ROMs: https://github.com/Gekkio/mooneye-gb/tree/mastertests
   - dmg-acid (rendering test): https://github.com/mattcurrie/dmg-acid2
   - cgb-acid (rendering test): https://github.com/mattcurrie/cgb-acid2
   - PeterLemon's GB demos: https://github.com/PeterLemon/GB
   - Test ROM execution logs: https://github.com/wheremyfoodat/Gameboy-logs
- Bootrom disassembly: https://gist.github.com/6063288
- The Ultimate Game Boy Talk: https://youtu.be/HyzD8pNlpwI
- Other valuable resources: https://github.com/avivace/awesome-gbdev
- Notes by GhostSonic on GB sound emulation: https://www.reddit.com/r/EmuDev/comments/5gkwi5/gb_apu_sound_emulation/dat3zni
- Explanation of binary-coded decimals and the DAA instruction: https://ehaskins.com/2018-01-30%20Z80%20DAA
- Guide to the half-carry flag: https://robdor.com/2016/08/10/gameboy-emulator-half-carry-flag
⠀
##### **Game Boy Advance:**

- See relevant ARM resources (the ARM7TDMI used in the GBA implements ARMv4T)
- GBATEK: https://problemkaputt.de/gbatek.htm
- no$gba (get the debug version): https://problemkaputt.de/gba.htm
- TONC (GBA tutorial and demos): https://www.coranac.com/projects/tonc
- Cycle counting on the GBA: https://mgba.io/2015/06/27/cycle-counting-prefetch
- Test ROMs:
   - Various test ROMs, including an archive of TONC binaries: [https:/github.com/shonumi/Emu-Docs/tree/master/GameBoy%20Advance/test_roms](https://github.com/shonumi/Emu-Docs/tree/master/GameBoy%20Advance/test_roms) 
   - https://github.com/destoer/armwrestler-gba-fixed
   - https://github.com/DenSinH/FuzzARM
   - https://github.com/jsmolka/gba-suite
   - https://github.com/destoer/gba_tests
   - https://github.com/PeterLemon/GBA
   - https://github.com/ladystarbreeze/gba-tests/tree/master/dma-test
   - https://github.com/mgba-emu/suite
- mGBA blog (particularly the "development" and "emulation" tags): https://mgba.io/
- Homebrew development:
   - https://rust-console.github.io/gba
   - https://patater.com/gbaguy/gbaasm.htm

</details>

### "Plan"
* [X]   ~~Committed test project.~~
* [X]   ~~Get a window on screen.~~
* [ ]   Learning how to make an emulator.
* [ ]   Start researching/gathering information on GameBoy's.
* [ ]   Working prototype.

## Current task

  * Learning how to make an emulator.
  * Researching/gathering information on GameBoy's. (Partial)

## Goal

N/A

<br/><br/><br/><br/><br/>


_**Under development by ~ [Tobsi](https://github.com/TobsiDev)**_
