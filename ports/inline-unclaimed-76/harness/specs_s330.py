"""specs_s330.py - gap band, batch 330: the cursor reader with unit 68 (0x60eeb0). Same fixture as batch 319 (the buffer's slot 0x2c stub)."""
from pilot import S
import importlib.util, os

_spec = importlib.util.spec_from_file_location('s319', os.path.join(os.path.dirname(__file__), 'specs_s319.py'))
_m = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(_m)

S(0x60eeb0, 'cursorRead60eeb0 (GUESS)', 'thiscall', None, ret='eax', gen=_m._make('c'), note='batch330; ret 8; slot 0x2c stubbed (unit 68)')
