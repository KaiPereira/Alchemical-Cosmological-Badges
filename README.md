# Alchemical-Cosmological Badges

These are alchemical-cosmological PCB hackathon badges I designed in a day for the Fallout hackathon in Shenzhen, China. It's 3 PCB's stacked on-top of each other using testpoints and it's powered by the 10 cent, CH32V003 MCU, with WS2812B neopixels.

<img width="1148" height="1000" alt="IMG_2615 1" src="https://github.com/user-attachments/assets/6faa6783-c593-44d4-8d61-3aee0b9c9191" />
<img width="1148" height="1000" alt="IMG_2618 1" src="https://github.com/user-attachments/assets/148a21dc-8aed-410e-a3df-1eabf4387e3f" />

## PCB Design

There's 2 different PCB's; the outer ring and the inner sun. The 2 outer rings are soldered onto the testpoints with the second one rotated 180 degree's to look more 3D.

The rings have exposed soldermask so that the neopixels can shine through, and you actually only need to solder neopixels onto one ring to get the effect.

There's also a battery connector on the top-left corner to attach a small battery with a voltage between 2.7V - 5V, and I'd just suggest a small LiPo.

<img width="2560" height="1404" alt="image" src="https://github.com/user-attachments/assets/910b8b80-0d3c-4180-aaf2-cf9fd625cc9d" />
<img width="2560" height="1405" alt="image" src="https://github.com/user-attachments/assets/5fd57a58-db8a-4559-83e1-74d17e690e6d" />
<img width="2560" height="1404" alt="image" src="https://github.com/user-attachments/assets/c8b2e5b3-a68b-479d-85fd-0ee0cac41bb5" />
<img width="2560" height="1401" alt="image" src="https://github.com/user-attachments/assets/d978e7b3-f050-4422-b3b0-3189b60cdac4" />

## Manufacturing

Each full badge costs about $10 at MOQ, but I'm sure you could get that down to under $4 if you create quite a few at once.

If you want to manufacture the boards, all of their production and development files are in their relative folder. I'd suggest getting the boards from JLCPCB with ENIG and a stencil, and then buying the components from LCSC and hand soldering. 

All the design files are also open-source if you want to make modifications so that they're unique to you, so just go crazy!!

## Firmware

These boards use the CH32V003 and program over SWIO using the header pins in the middle of the board. You'll want to program the boards using either a WCH-LinkE or PicoRVD which is what I used and what you'll find in the firmware folder.
