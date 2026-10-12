"""specs_s280.py - unclaimed area 67, gap band: 0x5f4ec0 (counted index; hook 0x7003b0 points at a recording stub that returns 0x1234)."""
from pilot import S

HOOK = 0x5f5012


def _hook_stub(e, r):
    e.calllog.append(('hook280',))
    e.ret(eax=0x1234, argbytes=0)


def _case(c):
    c.emu.hook(HOOK, _hook_stub)
    c.emu.w32(0x7003b0, HOOK)
    tab = c.emu.alloc(0x100, 4)
    c.emu.wbytes(tab, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    o = c.emu.alloc(0x40, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    cnt = c.rng.choice([0, 1, 2, 4, 8])
    c.emu.w32(o + 8, cnt)
    c.emu.w32(o + 0, tab)
    k = c.rng.choice([0, 1, 2, 3, 5, 0xffffffff, c.rng.getrandbits(32)])   # 0xffffffff hits the esi-1 == count boundary
    c.emu.mu.ctl_flush_tb()
    return [o, k]


S(0x5f4ec0, 'FUN_5f4ec0 (indexCounted4ec0)', 'thiscall', None, ret='eax', gen=_case, note='batch280; counted index, hook fallback')
