"""specs_s1316.py - inventory thread batch 1316 (src/batch1316.cpp): ZItem::UpdateActivate.

The activation list (slot 0x4c begin, 0x64 next, 0x44 remove) gives 0-4 entries; the controller's slot 0x9c returns a
float on the x87 stack (per call from a sequence); the event manager (0x70038c) slot 0xcc returns a record whose +0x44
is read; the holder (ref slot 0x58) takes slot 0x2e8. The clock is sys+0x40.
"""
from pilot import S
from inv_helpers import Rec, rnd, set_global

SYS = 0x70039C
MGR = 0x70038C


def _arg(emu, k):
    return emu.r32(emu.reg('esp') + 4 + 4 * k)


def update(c):
    r = Rec(c)
    sysobj = rnd(c, 0x2000, 4)
    set_global(c, SYS, sysobj)
    c.emu.w32(sysobj + 0x40, c.rng.randrange(0, 4000 * 1024))
    ref = rnd(c, 0x1000, 4)
    c.emu.w32(sysobj + 0x9B, ref)
    holder = rnd(c, 0x40, 4)
    c.emu.w32(holder, r.vtable({0x2E8: r.stub(60, 2, rand=True)}))
    c.emu.w32(ref, r.vtable({0x58: r.stub(61, 1, rets=[holder if c.rng.random() < 0.8 else 0])}))

    rec = rnd(c, 0x40, 4)
    c.emu.w32(rec + 0x44, c.rng.getrandbits(32))
    mgr = G_obj = rnd(c, 0x40, 4)
    c.emu.w32(mgr, r.vtable({0xCC: r.stub(62, 1, rets=[rec])}))
    set_global(c, MGR, mgr)

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

    L = rnd(c, 0x40, 4)
    c.emu.w32(L, r.vtable({0x4C: begin, 0x64: nxt, 0x44: r.stub(63, 1, rand=True)}))

    dues = [c.rng.choice([-1.0, 0.0, 1.0, 3.5, 1e9, float('nan')]) for _ in elems]
    dues_state = {'i': 0}

    def due(emu, res):
        i = dues_state['i']
        dues_state['i'] += 1
        v = dues[i] if i < len(dues) else 0.0
        emu.ret(st0=v, argbytes=4)

    C = rnd(c, 0x40, 4)
    c.emu.w32(C, r.vtable({0x9C: due}))

    self_obj = rnd(c, 0x200, 4)
    c.emu.w32(self_obj + 0x60, c.rng.getrandbits(32))
    c.emu.w32(self_obj + 0x78, L)
    c.emu.w32(self_obj + 0x74, C)
    return [self_obj]


S(0x471860, 'ZItem::UpdateActivate', 'thiscall', None, ret=None, gen=update, note='batch1316')
