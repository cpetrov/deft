# deft

A Linux LKM to add support for the 3 function buttons of Elecom DEFT trackballs.

Based on a [kernel patch](https://patchwork.kernel.org/patch/9217713/) by Yuxuan Shui.

## Requirements
Linux 4.2+
Kernel headers

## Installation

### Ubuntu

```
# add-apt-repository ppa:christian-petrov/deft
# apt-get update
# apt-get install deft-dkms
```

### Arch Linux

```
$ yaourt deft-dkms
```
... or use your favorite [AUR helper](https://wiki.archlinux.org/index.php/AUR_helpers) or [install the package manually](https://wiki.archlinux.org/index.php/Arch_User_Repository#Installing_packages).

### Manual

```
$ cd driver
$ make
# make install
```

### DKMS

```
$ cd driver
# cp -rv . /usr/src/deft-1.0.2
# dkms install deft/1.0.2
```

## Removal

### Ubuntu/Debian

```
# apt-get remove deft-dkms
```

### Arch Linux

```
# pacman -R deft-dkms
``` 

### Manual

```
# make uninstall
```

### DKMS

```
# dkms remove deft/1.0.2 --all
```
