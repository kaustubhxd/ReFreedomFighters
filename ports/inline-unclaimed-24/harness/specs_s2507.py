"""specs_s2507.py - decomp area 24, batch 2507.
0x633d35 (GUESS CRT start-up check): cdecl(a), returns bool in AL. a == 0 sets byte 0x7254b0. 0x634b1b hooked (cdecl, no arg).
0x549de0 hooked (cdecl, no arg; the original is `mov al,1; ret`, the hook returns 0 or 1 per call so all branches run)."""
from pilot import S
from recruits_util import clear_hooks, hook_rec


def _gen(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634b1b, 0)
    seq = [r.choice([0, 1, 1]) for _ in range(4)]
    hook_rec(c, 0x549de0, 0, ret=lambda emu, n: seq[n % 4])
    c.emu.wbytes(0x7254b0, bytes([r.choice([0, 0, 7])]))
    return [r.choice([0, 0, 1, r.getrandbits(32)])]


S(0x633d35, 'GUESS CRT start-up check', 'cdecl', None, ret='al', gen=_gen, note='batch2507')
