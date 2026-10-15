"""specs_s1317.py - inventory thread batch 1317 (src/batch1317.cpp): ZItem::UpdateDeactivate.

Same list shape as UpdateActivate (begin/next/remove on the controller at +0x74). The holder (ref slot 0x58) may be
missing for an entry. Float answers come from a per-case sequence on the x87 stack; the two owners (+0x70, +0x6c) take
slot 0x40; the holder takes slot 0x210.
"""
from pilot import S
from inv_helpers import Rec, rnd, set_global

SYS = 0x70039C


def _arg(emu, k):
    return emu.r32(emu.reg('esp') + 4 + 4 * k)


def deact(c):
    r = Rec(c)
    sysobj = rnd(c, 0x2000, 4)
    set_global(c, SYS, sysobj)
    c.emu.w32(sysobj + 0x40, c.rng.randrange(0, 4000 * 1024))
    ref = rnd(c, 0x1000, 4)
    c.emu.w32(sysobj + 0x9B, ref)
    holder = rnd(c, 0x40, 4)
    c.emu.w32(holder, r.vtable({0x210: r.stub(70, 1, rand=True)}))
    holders = [holder if c.rng.random() < 0.75 else 0 for _ in range(6)]
    hs = {'i': 0}

    def h58(emu, res):
        i = hs['i']
        hs['i'] += 1
        emu.ret(eax=holders[i % len(holders)], argbytes=4)
    c.emu.w32(ref, r.vtable({0x58: h58}))

    elems = [rnd(c, 0x20, 4) for _ in range(c.rng.randrange(0, 5))]
    for e in elems:
        c.emu.w32(e, c.rng.getrandbits(32))
    state = {'i': 0}

    def begin(emu, res):
        cur = _arg(emu, 0)
        state['i'] = 0
        emu.w32(cur, 1 if elems else 0)
        emu.ret(argbytes=4)

    def nxt(emu, res):
        cur = _arg(emu, 0)
        i = state['i']
        v = elems[i] if i < len(elems) else 0
        state['i'] = i + 1
        emu.w32(cur, 1 if i + 1 < len(elems) else 0)
        emu.ret(eax=v, argbytes=4)

    dues = [c.rng.choice([-1.0, 0.0, 1.0, 3.5, 1e9, float('nan')]) for _ in range(8)]
    ds = {'i': 0}

    def due(emu, res):
        i = ds['i']
        ds['i'] += 1
        emu.ret(st0=dues[i % len(dues)], argbytes=4)

    C = rnd(c, 0x40, 4)
    c.emu.w32(C, r.vtable({0x4C: begin, 0x64: nxt, 0x44: r.stub(71, 1, rand=True), 0x9C: due}))

    o70 = rnd(c, 0x40, 4)
    c.emu.w32(o70, r.vtable({0x40: r.stub(72, 1, rand=True)}))
    o6c = rnd(c, 0x40, 4)
    c.emu.w32(o6c, r.vtable({0x40: r.stub(73, 1, rand=True)}))

    self_obj = rnd(c, 0x200, 4)
    c.emu.w32(self_obj + 0x74, C)
    c.emu.w32(self_obj + 0x70, o70)
    c.emu.w32(self_obj + 0x6C, o6c)
    return [self_obj]


S(0x471930, 'ZItem::UpdateDeactivate', 'thiscall', None, ret=None, gen=deact, note='batch1317')
