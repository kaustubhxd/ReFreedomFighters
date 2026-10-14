"""specs_s1714.py - residue 13 batch 1714: 0x5f3410. Factory function that allocates 0x1014 bytes and calls
the sound dll constructor 0x5f12d0 (thiscall, plain ret; already verified in docs/20-fresh-01.md). The new operator
0x41e290 and the constructor 0x5f12d0 are both hooked by address."""
from pilot import S
from sthelp import rnd, obj, Seq, clear_hooks, HOOKED


def _newhook(c, vals):
    """Hook the new operator to return mock pointers in sequence."""
    cnt = c.emu.alloc(4, 4)
    def h(e, r):
        i = e.r32(cnt)
        e.w32(cnt, i + 1)
        e.ret(eax=vals[i % len(vals)], argbytes=0)
    HOOKED.add(0x41e290)
    c.emu.hook(0x41e290, h)


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)

    # Allocate mock objects or return null sometimes
    p1 = obj(c, 0x1014, {}) if r.random() < 0.8 else 0
    p2 = obj(c, 0x1014, {}) if r.random() < 0.8 else 0

    # Hook the new operator to return the mock pointers
    _newhook(c, [p1, p2])

    # Hook the constructor to verify it receives the allocated pointer and returns it
    rec = c.emu.alloc(4, 4)
    def h_ctor(e, ret):
        ecx = e.reg('ecx')
        e.w32(rec, ecx)
        e.ret(eax=ecx, argbytes=0)
    HOOKED.add(0x5f12d0)
    c.emu.hook(0x5f12d0, h_ctor)

    # Factory function takes no arguments, just returns the result
    return []


S(0x5f3410, 'CreateScriptEngine', 'cdecl', None, ret='eax', gen=_gen, note='batch1714; factory allocates 0x1014 bytes and tails to sound ctor 0x5f12d0')
