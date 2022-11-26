```
cmake . --preset <configure-preset>
cmake --build <path>
```

If you want to see the list of available presets, you can run:
```
cmake --list-presets=all .
```

For example preset unixlike-gcc-debug:
```
cmake --preset unixlike-gcc-debug
cmake --build ./out/build/unixlike-gcc-debug/
```

Run preset tests after build. Example for unixlike-gcc-debug:
```
ctest --preset test-unixlike-gcc-debug
```
