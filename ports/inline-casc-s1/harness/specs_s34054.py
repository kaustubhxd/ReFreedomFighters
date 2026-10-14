"""specs_s34054.py - cascade tier E, batch 34054.
0x5d5c20: this slot 0x80 writes random dwords into A (9) and B (3) through its stack pointers; b slot 0x94 and this slot 0xdc log the pointed-to dwords; the /GS check is a zero-argument recorder.
0x5e0250: owner [this+8] slots 0x504 (returns o, 0 in a fifth), 0x228 (five stack args) and the byte at +0x94e; o slots 0x1e0 (0/1), 0x350 (returns an object whose slot 0x330 returns 0..9); [this+0xc] / [this+0x10]
random; byte +0x14 random.
0x62d990 (cdecl): code 0xf, 0x11, 0x12, 0x1c or another value; [a+0xc] zero in half the cases; c has a function pointer at +0x1c (a cdecl recorder with four stack args returning 0 or non-zero)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g5d5c20(c):
    clear_hooks(c)
    r = c.rng

    def wAB(em, k):
        for i in range(9):
            em.w32(em.arg32(0) + 4 * i, r.getrandbits(32))
        for i in range(3):
            em.w32(em.arg32(1) + 4 * i, r.getrandbits(32))
    hook_rec(c, 0x633654, 0, pop=0)
    b = obj(c, 0x20, {0x94: pystub(c, 2, this=True, deref={0: 9, 1: 3})}, nslots=0x98 // 4)
    me = obj(c, 0x20, {0x80: pystub(c, 2, this=True, side=wAB, stackmark=(0, 1)),
                       0xdc: pystub(c, 4, this=True, deref={2: 9, 3: 3})}, nslots=0xe0 // 4)
    return [me, r.getrandbits(32), b]


def _g5e0250(c):
    clear_hooks(c)
    r = c.rng
    pobj = obj(c, 0x20, {0x330: pystub(c, 0, ret=r.randint(0, 9), this=True)}, nslots=0x334 // 4)
    o = 0 if r.random() < 0.2 else obj(c, 0x20, {0x1e0: pystub(c, 1, ret=r.choice([0, 1]) | (r.getrandbits(24) << 8), this=True),
                                                  0x350: pystub(c, 0, ret=pobj, this=True)}, nslots=0x354 // 4)
    owner = obj(c, 0x960, {0x504: pystub(c, 0, ret=o, this=True), 0x228: pystub(c, 5, this=True)}, nslots=0x508 // 4)
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, owner)
    return [me]


def _g62d990(c):
    clear_hooks(c)
    r = c.rng
    fp = pystub(c, 4, ret=r.choice([0, 1, r.getrandbits(32) | 1]), pop=0)
    cobj = rnd(c, 0x40)
    c.emu.w32(cobj + 0x1c, fp)
    a = rnd(c, 0x20)
    if r.random() < 0.5:
        c.emu.w32(a + 0xc, 0)
    code = r.choice([0xf, 0x11, 0x12, 0x1c, 0x12, 0x11, r.getrandbits(32), 0, 1])
    return [a, code, r.getrandbits(32), r.getrandbits(32), cobj]


S(0x5d5c20, 'GUESS fetch two blocks through slots', 'thiscall', None, ret='al', gen=_g5d5c20, note='batch34054')
S(0x5e0250, 'GUESS select mode value and send command with a vector', 'thiscall', None, ret='al', gen=_g5e0250, note='batch34054')
S(0x62d990, 'GUESS callback picking a handler by message code', 'cdecl', None, ret='eax', gen=_g62d990, note='batch34054')
