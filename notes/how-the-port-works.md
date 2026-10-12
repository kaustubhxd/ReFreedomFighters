# How the Freedom Fighters browser port works

## The three layers of the original game

The split is "what happens" versus "how it happens", not hero versus world.

- **Data, not code at all.** Buildings, the map, textures, models, animations and sounds are files the engine loads. Our decoders read them straight from the install, which is why levels already look right.
- **Bytecode scripts: the "what".** Mission flow and high-level decisions, for example: when the player enters this area, spawn three soldiers, play this voice line, guard these positions, attack on alarm. Enemy and civilian behaviour choices come from here. IO wrote these in their own scripting language and compiled them to small bytecode (.ppo files inside .zgf) so designers could change missions without rebuilding the engine. The bytecode has about 150 opcodes (157 entries in `script-vm/`).
- **x86 engine code: the "how".** The mechanics every character uses, enemies included: walking, pathfinding, aiming, shooting, ladders, mounted guns, molotov physics, collision, animation blending, rendering and sound. IO wrote this in C++ and compiled it to x86 machine code for speed. The PC exe has about 13,000 functions; the scripts reach into it through about 224 "native" functions (`decoders/ppo_natives.txt`), and the first level touches 75 to 94% of the engine.

## How the browser port (the browser port) is built today

- Data: decoded by our decoders (see `formats/`) and drawn with WebGL.
- Scripts: the original bytecode runs unchanged in a small JavaScript virtual machine (`script-vm/`). That's why enemies attack and the C05A super soldier appears: the original script says so.
- Engine: the natives and the mechanics behind them are hand-written in JavaScript by reading the original exe, mostly the GameCube build because it still has function names. This is where the port drifts from the original. Enemies freezing up close, ladders, weapons and mounted guns all live in this layer. When something is wrong, the script usually asked for the right thing and our hand-written "how" didn't carry it out properly.

## Ways to get the engine exact

- **Decompilation (running now).** Turn exe functions back into C++ and prove each one matches the original on 1,000 random inputs. The plan is to compile it to WebAssembly and replace the hand-written engine code. It runs at full speed but costs the most effort. None of it is used by the browser yet.
- **Emulation.** Run the original x86 machine code in a virtual machine in the browser, the same idea as the script VM but for a whole CPU. You'd get the original behaviour exactly with no engine code to write. The catches: it has to fake Windows and Direct3D 8 and turn the graphics into WebGL (what CrossOver does on the Mac), and emulated x86 runs several times slower than native, so playability is unproven.
- **Keep hand-writing (current fallback).** It's fastest to get something playable, but it drifts from the original wherever we guess.
