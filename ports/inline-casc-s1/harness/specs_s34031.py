"""specs_s34031.py - cascade tier E, batch 34031.
0x5175a0: hooked 0x515630; the engine object at +0x1a9f is null in a third of the cases (else slot 0x60 returns a value); this slot 0x80 and engine table slots 0x138 / 0x58 are recorders;
the settings object's slot 0x88 writes a random id through its (stack) pointer argument; unaligned fields +0x12f / +0x161d / +0x164a.
0x52b0c0: [this+0x44] is null in a seventh; byte +0x10 zero in a fifth; engine slot 0x1c8 returns the 'now' value; [p] = now - delta with the threshold [p+4] below, at or above the delta; counter
[p+0xc] below, at or above the limit [p+8].
0x5b3ba0: hooked 0x5b58a0 (thiscall, four stack args) records ECX and the arguments; the engine block is random so +0x40 differs per case."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g5175a0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x515630, 0, this=True, pop=0)

    def wid(em, k):
        em.w32(em.arg32(1), r.getrandbits(32))
    t = obj(c, 0x20, {0x88: pystub(c, 2, this=True, side=wid, stackmark=(1,))}, nslots=0x90 // 4)
    so = sysobj(c, table_slots={0x138: pystub(c, 0, ret=t, this=True), 0x58: pystub(c, 1, ret=lambda em, k: r.getrandbits(32), this=True)})
    w = 0 if r.random() < 0.33 else obj(c, 0x20, {0x60: pystub(c, 2, ret=r.getrandbits(32), this=True)}, nslots=0x70 // 4)
    c.emu.wbytes(so + 0x1a9f, w.to_bytes(4, 'little'))
    me = obj(c, 0x1700, {0x80: pystub(c, 2, this=True)}, nslots=0x90 // 4)
    return [me]


def _g52b0c0(c):
    clear_hooks(c)
    r = c.rng
    now = r.getrandbits(32)
    delta = r.choice([0, 1, 5, 100, r.getrandbits(32)])
    sysobj(c, slots={0x1c8: pystub(c, 2, ret=now, this=True)})
    p = rnd(c, 0x20)
    c.emu.w32(p, (now - delta) & 0xffffffff)
    c.emu.w32(p + 4, (delta + r.choice([-1, 0, 1, 5])) & 0xffffffff if r.random() < 0.7 else r.getrandbits(32))
    lim = r.choice([0, 1, 5, 100, r.getrandbits(32)])
    c.emu.w32(p + 8, lim)
    c.emu.w32(p + 0xc, (lim + r.choice([-1, 0, 1, -5])) & 0xffffffff if r.random() < 0.7 else r.getrandbits(32))
    if r.random() < 0.2:
        c.emu.wbytes(p + 0x10, b'\0')
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x44, 0 if r.random() < 1 / 7 else p)
    return [me]


def _g5b3ba0(c):
    clear_hooks(c)
    hook_rec(c, 0x5b58a0, 4, this=True)
    sysobj(c)
    return [rnd(c, 0x200)]


S(0x5175a0, 'GUESS initialise widget from engine services', 'thiscall', None, ret=None, gen=_g5175a0, note='batch34031')
S(0x52b0c0, 'GUESS rate-limit counter', 'thiscall', None, ret='al', gen=_g52b0c0, note='batch34031')
S(0x5b3ba0, 'GUESS run helper for three channels with engine time', 'thiscall', None, ret=None, gen=_g5b3ba0, note='batch34031')
