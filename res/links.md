Configure SFML
https://www.sfml-dev.org/tutorials/2.5/start-vc.php

1. Header files include location: C/C++ > General
2. Library files lib location: Linker > General
3. Following in Linker input:
sfml-graphics-d.lib
sfml-window-d.lib
sfml-system-d.lib
sfml-audio-d.lib
sfml-network-d.lib
4. Add required debug DLLs in same directory as exe.
5. Run in Debug mode.