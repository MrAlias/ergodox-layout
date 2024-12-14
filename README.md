# MrAlias Ergodox Layout

## Layout

### Base Layer

[Open on keyboard-layout-editor.com](https://www.keyboard-layout-editor.com/#/gists/a582a0c7562feb6d4b5038a9dcafc170)

![Base Layer](./images/base-layer.png)

## Building

Install dependencies.

```bash
$ sudo pacman -S qmk
```

Setup QMK.

```bash
$ git clone git@github.com:MrAlias/qmk_firmware.git
$ cd qmk_firmware
$ git remote add upstream git@github.com:qmk/qmk_firmware.git

# Add udev rules.
$ sudo cp util/udev/50-qmk.rules /etc/udev/rules.d/

# Run QMK setup.
$ qmk setup
```

Add keymap and buil.

```bash
$ git clone git@github.com:MrAlias/ergodox-layout.git keyboards/hotdox/keymaps/MrAlias
$ make keyboard=hotdox keymap=MrAlias
```
