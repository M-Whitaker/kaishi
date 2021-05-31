# Kaishi Engine

## Linux Build

### Dependencies
- Cmake >= 3.10
```bash
wget https://github.com/Kitware/CMake/releases/download/v3.20.0/cmake-3.20.0-linux-x86_64.tar.gz
tar -xvf cmake-3.20.0-linux-x86_64.tar.gz
cd cmake-3.20.0-linux-x86_64.tar.gz
cp -r bin/* /usr/bin
cp -r share/* /usr/share
```
- X11
```bash
$ apt install xorg-dev libglu1-mesa-dev
```

### Compile
```bash
$ mkdir build
$ make build
```

## macOS Build

### Dependencies
- Cmake >= 3.10
```bash
$ brew install cmake
```
### Compile
```bash
$ python3 vender/patches/addVendorPatches.py
$ make build
```
## Windows Build
```commandline

```
