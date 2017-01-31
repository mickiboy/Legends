# Legends

## Build instructions

### Prerequisites

- C++11 compiler
- CMake 3.1 or newer
- Qt 5.6 or newer
- Doxygen 1.8 or newer _(optional)_

#### Windows

- Set the following environment variables to their respective locations:
  - `QT_PATH_MSVC_32`
  - `QT_PATH_MSVC_64`
  - `SDL_PATH_MSVC`

### Preparing

If not already cloned:

```bash
$ git clone --recursive https://github.com/mickiboy/Legends.git
$ cd Legends
```

Otherwise (in top-level directory):

```bash
$ git submodule init
$ git submodule update
```

### Compiling

In top-level directory:

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
```
