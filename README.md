# ArroU

## Build

### Windows (exe)

```powershell
cmake --preset windows
cmake --build --preset windows
```

Output:
- `Build/out/windows/Source/App/Windows/ArroU.exe` (generator dependent)

### WiiU (elf)

Required environment variables:
- `DEVKITPRO` (example: `D:/devkitPro`)
- `WUT_ROOT` (optional, default: `%DEVKITPRO%/wut`)

```powershell
cmake -S . -B Build/out/wiiu -G "MinGW Makefiles" -DPLATFORM=WiiU -DCMAKE_TOOLCHAIN_FILE="$PWD/ToolChain/WiiU.cmake"
cmake --build Build/out/wiiu
```

Output:
- `Build/out/wiiu/Source/App/WiiU/ArroU.elf` (generator dependent)

### Test

```powershell
cmake --preset test
cmake --build --preset test
```
