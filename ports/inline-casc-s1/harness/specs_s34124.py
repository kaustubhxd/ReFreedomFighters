"""specs_s34124.py - three items; callees are recorders (this recorded).
0x48b700: slot 0x7c low byte in half; log chain through [0x700390]; c zero in a half (slot 0x154 returns an object or null); 0x4cbe40 returns an object with slot 0x70.
0x4d86c0: slot 0xc returns null / a holder whose first dword is null / a holder with a container (slots 0x4c, 0x5c) of 0..3 items with slot 0x10.
0x4f4c20: stream helpers are recorders; 0x4e11e0 writes the mode (0, 1 or random) through its pointer argument."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g48b700(c):
    clear_hooks(c)
    r = c.rng
    pr = obj(c, 0x20, {0x2c: pystub(c, 3, pop=0)}, nslots=0x30 // 4)
    eng = obj(c, 0x20, {0x20: pystub(c, 2, ret=pr, this=True)}, nslots=0x24 // 4)
    c.emu.w32(0x700390, eng)
    bound = obj(c, 0x20, {0x70: pystub(c, 2, this=True)}, nslots=0x74 // 4)
    hook_rec(c, 0x4cbe40, 0, this=True, pop=0, ret=bound)
    found = 0 if r.random() < 0.3 else rnd(c, 0x20)
    me = obj(c, 0x30, {0x7c: pystub(c, 0, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101]), this=True),
                       0x154: pystub(c, 2, ret=found, this=True)}, nslots=0x158 // 4)
    cc = 0 if r.random() < 0.5 else rnd(c, 0x20)
    return [me, r.getrandbits(32), r.getrandbits(32), cc]


def _g4d86c0(c):
    clear_hooks(c)
    r = c.rng
    items = [obj(c, 0x20, {0x10: pystub(c, 1, this=True)}, nslots=0x14 // 4) for _ in range(r.choice([0, 1, 2, 3]))]
    cont = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, stackmark=(0,)),
                         0x5c: pystub(c, 1, this=True, stackmark=(0,), side=lambda em, k: em.w32(em.arg32(0), 1 if k + 1 < len(items) else 0),
                                      ret=lambda em, k: items[k] if k < len(items) else 0)}, nslots=0x60 // 4)
    mode = r.choice(['null', 'empty', 'full', 'full'])
    holder = rnd(c, 0x20)
    c.emu.w32(holder, 0 if mode == 'empty' else cont)
    me = obj(c, 0x30, {0xc: pystub(c, 1, ret=0 if mode == 'null' else holder, this=True)}, nslots=0x10 // 4)
    return [me, r.getrandbits(32), r.getrandbits(32)]


def _g4f4c20(c):
    clear_hooks(c)
    r = c.rng

    def wmode(em, k):
        em.w32(em.arg32(0), r.choice([0, 1, 1, 2, r.getrandbits(32)]))

    def wslot(em, k):
        em.w32(em.arg32(0), r.getrandbits(32))
    hook_rec(c, 0x4f9c90, 1, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x4e11e0, 2, this=True, ret=r.getrandbits(32), side=wmode, stackmark=(0,))
    hook_rec(c, 0x4e12e0, 2, this=True, ret=r.getrandbits(32), side=wslot, deref={0: 1})
    hook_rec(c, 0x4e1b30, 0, this=True, pop=0, ret=r.getrandbits(32))
    return [rnd(c, 0xa0), rnd(c, 0x20)]


S(0x48b700, 'GUESS create or look up an object and bind it', 'thiscall', None, ret='eax', gen=_g48b700, note='batch34124')
S(0x4d86c0, 'GUESS broadcast to a container', 'thiscall', None, ret='al', gen=_g4d86c0, note='batch34124')
S(0x4f4c20, 'GUESS read a mode word', 'thiscall', None, ret=None, gen=_g4f4c20, note='batch34124')
