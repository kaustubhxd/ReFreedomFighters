"""specs_s2725.py - unclaimed-27 batch 25 (gap band): FUN_5979c0 (GUESS, thiscall, returns eax). Stubs and hooks, NOT verified:
the engine object (the global 0x70039c's +0x9b) has a vtable whose slot +0x58 (one argument, ret 4) records its argument and
returns a random value from a small set; 0x59ffc0 is hooked and returns a value from {3, 5, random} per call (records its this).
The count at +0x1fae is 0..6 (signed; negative gives zero iterations)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f5c0(c):
    rec = c.emu.alloc(0x80, 4)   # +0 slot 0x58 calls, +4 0x59ffc0 calls, +8.. the recorded arguments (up to 16)
    vals = [c.rng.choice([3, 5, 5, c.rng.getrandbits(32)]) for _ in range(16)]

    def h58(e, r, rec=rec):
        e.w32(rec, (e.r32(rec) + 1) & 0xffffffff)
        i = e.r32(rec) - 1
        if i < 16:
            e.w32(rec + 8 + 4 * i, e.arg32(0))
        e.ret(eax=vals[i % 16], argbytes=4)

    def hffc(e, r, rec=rec):
        e.w32(rec + 4, (e.r32(rec + 4) + 1) & 0xffffffff)
        e.ret(eax=vals[(e.r32(rec + 4) - 1) % 16], argbytes=0)

    g9vt = c.emu.alloc(0x200, 4)
    c.emu.w32(g9vt + 0x58, c.emu.stub_fn('FUN_5979c0 slot 0x58', h58))
    eng = _rnd(c, 0x800)
    c.emu.w32(eng, g9vt)
    g = _rnd(c, 0x800)
    c.emu.w32(g + 0x9b, eng)
    c.emu.w32(0x70039c, g)
    c.emu.hook(0x59ffc0, hffc)
    o = _rnd(c, 0x2000)
    n = c.rng.choice([0, 1, 2, 3, 4, 6, -1])
    c.emu.w32(o + 0x1fae, n & 0xffffffff)
    for i in range(16):
        c.emu.w32(o + 0x1dae + 4 * i, c.rng.getrandbits(32))
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x5979c0, 'FUN_5979c0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_f5c0,
  note='gap band batch 25; engine slot +0x58 and 0x59ffc0 are stubs/hooks')
