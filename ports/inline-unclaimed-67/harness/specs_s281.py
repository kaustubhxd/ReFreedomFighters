"""specs_s281.py - unclaimed area 67, gap band: 0x5f4ff0 (record pop; hook at 0x7003b0 is a recording stub returning 0x4321)."""
from pilot import S

HOOK = 0x5f5012


def _hook_stub(e, r):
    e.calllog.append(('hook281',))
    e.ret(eax=0x4321, argbytes=0)


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


S(0x5f4ff0, 'FUN_5f4ff0 (popRecord)', 'thiscall', None, ret='eax', gen=_case, note='batch281; pop 8-byte records; hook when empty')
