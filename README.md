# Aether X6100 Control

A project to make an interface library between the radio's STM32 base controller
and user-space applications.

Now part of the [Aether-Radio project](https://github.com/AetherRadio).

## How to build with CMake Presets

`git clone` both this project and Ather-Radio's X6100Buildroot project into
parallel directories, something like:

```txt
└── AetherRadio
    ├── X6100Buildroot
    └── X6100Control
```

First, make sure you build the buildroot project once.
Then, you can invoke CMake with the provided `./build_buildroot.sh` script on
this project's root, that will build this project and install it into the
buildroot project.

Then you can run `./br_make.sh` on the buildroot project, which will rebuild the
`sd_card.img` file.

## Credits

The original project belongs to [Oleg Belousov](https://github.com/strijar).

Most of the information present reverse was obtained from reverse-engineering
the Xiegu X6100's front end app, called `x6100_ui_v100`. Credits go to Jet Yee,
the original software developer, and the only software developer at Xiegu from
what we know.

## Licensing

The code is licensed under the `SPDX-License-Identifier: LGPL-2.1-or-later`,
unless explicitly stated otherwise.
Files not supporting comments, and therefore not supporting license headers, are
licensed under the same license, unless explicitly stated on accompanying
information.
