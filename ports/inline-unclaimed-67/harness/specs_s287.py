"""specs_s287.py - unclaimed area 67, gap band: 0x5f5020 (float record pop, st0 result). Hook 0x7003b0 is a recording stub that
returns st0 = 1.5 (the empty path tail-jumps to it; null would trap in the original)."""
from pilot import S

HOOK = 0x5f5012


def _hook_stub(e, r):
    e.calllog.append(('hook287',))
    e.ret(st0=1.5, argbytes=0)


def _case(c):
    c.emu.hook(HOOK, _hook_stub)
    c.emu.w32(0x7003b0, HOOK)
    recs = c.emu.alloc(0x80, 4)
    c.emu.wbytes(recs, bytes(c.rng.getrandbits(8) for _ in range(0x80)))
    o = c.emu.alloc(0x40, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    c.emu.w32(o + 0, recs)
    c.emu.w32(o + 8, c.rng.choice([0, 1, 2, 5, 8]))
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x5f5020, 'FUN_5f5020 (popFloat5020)', 'thiscall', None, ret='st0', gen=_case, note='batch287; pop float record; hook when empty')
