"""specs_s273x.py - cross-check of batch 273 (0x4ce550) against area 66's shared list stub (harness/iter66.py).
Same address as specs_s273.py; this one builds the object with make_list() instead of the local protocol stub."""
import os
import sys
sys.path.insert(0, os.path.join(os.environ.get('FF_RE_ROOT', '/Users/kaustubh/freedom-fighters-re'), 'decomp-pilot', 'inline-unclaimed-66', 'harness'))
from pilot import S  # noqa: E402
from iter66 import make_list  # noqa: E402


def _list_walk(c):
    elems = [c.emu.alloc(0x20, 4) for _ in range(c.rng.randrange(0, 6))]
    obj = make_list(c, elems)
    n = c.rng.randrange(0, 5) if c.rng.random() < 0.8 else c.rng.getrandbits(32)
    return [obj, n]


S(0x4ce550, 'walk via iter66 (cross-check)', 'thiscall', None, ret='eax', gen=_list_walk,
  note='batch273 cross-check; area 66 iter stub; ret 4')
