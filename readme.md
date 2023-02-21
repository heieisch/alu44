# alu44

A split keyboard with 3x6 vertically staggered keys and 4 thumb keys.

* Keyboard Maintainer: [heieisch](https://github.com/heieisch)
* Hardware Supported: alu44 PCB, EliteC

Make example for this keyboard (after setting up your build environment):

    qmk compile -kb alu44/rev1 -km default

Flashing example for this keyboard:

    qmk flash -kb alu44/rev1 -km default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

* **Physical reset button**: Briefly press the button on the PCB of the EliteC or short RST to VCC
