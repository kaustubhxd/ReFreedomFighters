"""specs_s279.py - unclaimed area 67, gap band: 0x5f4a80 (table lookup; the global hook at 0x7003b0 points at a recording stub)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


HOOK = 0x5f5012   # a plain ret in the exe; hooked by address with a recording stub


def _hook_stub(e, r):
    e.calllog.append(('hook279',))
    e.ret(argbytes=0)


def _case(c):
    c.emu.hook(HOOK, _hook_stub)
    c.emu.w32(0x7003b0, HOOK)   # with the hook null the original falls into int3 (an assert trap), so set it
    tab = _rnd(c, 0x40)
    count = c.rng.choice([0, 1, 4, 8, 0x10])
    o = _rnd(c, 0x200)
    c.emu.w32(o + 0x104, count)
    c.emu.w32(o + 0x108, tab)
    w = c.rng.choice([0, 1, 3, 7, 8, 0x10, 0xffff, 0x10000, c.rng.getrandbits(32)])
    c.emu.mu.ctl_flush_tb()
    return [o, w]


S(0x5f4a80, 'FUN_5f4a80 (indexTable4a80)', 'thiscall', None, ret='eax', gen=_case, note='batch279; table lookup, hook 0x7003b0 null')
