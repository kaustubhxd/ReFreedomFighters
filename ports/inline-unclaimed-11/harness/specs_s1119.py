"""specs_s1119.py - unclaimed-11 batch 20 (gap band): 0x5bf7f0, thiscall, one word argument (ret 8, second argument ignored).
GUESS on the name. The word argument is compared with four words in the object: +0x55 (increment dword +0x59), +0x57
(decrement dword +0x59 when > 0), +0x66 (increment dword +0x6a), +0x68 (decrement dword +0x6a when > 0). Always returns 0.
The word argument equals one of the four in about 80% of cases; the counters are random signed dwords."""
from pilot import S


def _gen(c):
    o = c.emu.alloc(0x100, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    words = [c.rng.getrandbits(16) for _ in range(4)]
    for off, w in zip((0x55, 0x57, 0x66, 0x68), words):
        c.emu.w16(o + off, w)
    for off in (0x59, 0x6a):
        c.emu.w32(o + off, c.rng.randint(-3, 3) & 0xffffffff)
    arg = c.rng.choice(words) if c.rng.random() < 0.8 else c.rng.getrandbits(16)
    return [o, arg, c.rng.getrandbits(32)]


S(0x5bf7f0, 'GUESS (no name) word counters thiscall ret 8', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-11 batch 20 (gap band)')
