"""specs_s284.py - unclaimed area 67, gap band: 0x5f4990 (range search over a list; hook 0x7003b0 at a recording stub returning 0x77)."""
from pilot import S

HOOK = 0x5f5012


def _hook_stub(e, r):
    e.calllog.append(('hook284',))
    e.ret(eax=0x77, argbytes=0)


def _case(c):
    c.emu.hook(HOOK, _hook_stub)
    c.emu.w32(0x7003b0, HOOK)
    n = c.rng.choice([0, 1, 2, 3])
    entries = []
    for _ in range(n):
        ent = c.emu.alloc(0x100, 4)
        c.emu.wbytes(ent, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
        lo = c.rng.randint(0, 12)
        hi = lo + c.rng.randint(0, 12)
        c.emu.w32(ent + 0x54, lo)
        c.emu.w32(ent + 0x58, hi)
        c.emu.w32(ent + 0x48, c.rng.randint(0, 40))
        entries.append(ent)
    for k, ent in enumerate(entries):
        c.emu.w32(ent + 0x9c, entries[k + 1] if k + 1 < len(entries) else 0)
    o = c.emu.alloc(0x200, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    c.emu.w32(o + 0x96, entries[0] if entries else 0)
    c.emu.w32(o + 0xa6, c.rng.randint(0, 25))
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x5f4990, 'FUN_5f4990 (rangeSearch4990)', 'thiscall', None, ret='eax', gen=_case, note='batch284; list range search, hook fallback')
