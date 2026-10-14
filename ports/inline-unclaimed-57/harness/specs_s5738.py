"""specs_s5738.py - unclaimed-57, band batch 38: 0x5de230 (stdcall, two args, returns 0) and 0x5d83e0 (thiscall, no args). Hooks, logged:
0x5de090 (stdcall, one argument, pops 4) and 0x5d8470 (thiscall, no args). Stub: the sub-object at this+0x44 has slot +0x114 (one argument).
The word at global 0x7143a0 equals the first argument's low word in half the cases (the other half differs); the engine tick at +0x40 and this+0xb3 are chosen so both
outcomes of the signed compare occur."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hooks(c):
    def log_a(em, r):
        em.calllog.append(('5de090', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def log_b(em, r):
        em.calllog.append(('5d8470', 0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)
    c.emu.hook(0x5de090, log_a)
    c.emu.hook(0x5d8470, log_b)


def _gate(c):
    _hooks(c)
    w = c.rng.getrandbits(16)
    g = w if c.rng.random() < 0.5 else (w ^ 1)
    c.emu.wbytes(0x7143a0, bytes([g & 0xff, (g >> 8) & 0xff]))
    return [w | (c.rng.getrandbits(16) << 16), c.rng.getrandbits(32)]


def _cond(c):
    _hooks(c)
    vt = c.emu.logging_vtable('band5d83e0_sub', 280, argwords={0x114: 1})
    sub = _rnd(c, 0x40)
    c.emu.w32(sub, vt)
    eng = _rnd(c, 0x200)
    c.emu.w32(0x70039c, eng)
    obj = _rnd(c, 0x200)
    c.emu.wbytes(obj + 0xbb, bytes([c.rng.choice([0, 0, 1])]))
    tick = c.rng.getrandbits(32)
    c.emu.w32(eng + 0x40, tick)
    c.emu.w32(obj + 0xb3, tick if c.rng.random() < 0.3 else c.rng.getrandbits(32))
    c.emu.w32(obj + 0xbc, 0 if c.rng.random() < 0.6 else 1)
    c.emu.w32(obj + 0x44, sub)
    return [obj]


S(0x5de230, 'unnamed_5de230 (GUESS) stdcall', 'stdcall', None, ret='eax', gen=_gate,
  note='unclaimed-57 band batch 38; calls 0x5de090 with a2 when w matches the word at 0x7143a0 (hooked, logged)')
S(0x5d83e0, 'unnamed_5d83e0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_cond,
  note='unclaimed-57 band batch 38; calls 0x5d8470 (hooked, logged) and sub slot +0x114 (stubbed)')
