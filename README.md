# deft

A Linux LKM to add support for the 3 function buttons of Elecom DEFT trackballs.

Based on a [kernel patch](https://patchwork.kernel.org/patch/9217713/) by Yuxuan Shui.

## Requirements
Linux 4.2+
Kernel headers

## Installation

### Ubuntu

```sh
$ sudo add-apt-repository ppa:christian-petrov/deft
$ sudo apt-get update
$ sudo apt-get install deft-dkms
```

### Manual

```sh
$ cd driver
$ make
# make install
```

### DKMS

```sh
$ cd driver
# cp -rv . /usr/src/deft-1.0.2
# dkms install deft/1.0.2
```

## Removal

### Ubuntu/Debian

```sh
$ sudo apt-get remove deft-dkms
```

### Manual

```sh
# make uninstall
```

### DKMS

```sh
# dkms remove deft/1.0.2 --all
