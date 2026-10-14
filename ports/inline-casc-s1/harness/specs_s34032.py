"""specs_s34032.py - cascade tier E, batch 34032.
0x5c92a0: engine table slots 0x58 and 0x114 are recorders returning objects / words; s slot 0x2f4 returns y; hooked 0x5c9330; [this+0x44] slot 0x288 and y slot 0x128 are recorders.
0x5d4a70: hooked 0x4e5e60 returns five random dwords (recording the stream); engine table slot 0x58 returns random values.
0x638cf0: this slot 0x38 returns a surface object (pitch 0..16 at +4, pixel buffer at +0x10); x, y, w, h small, h sometimes zero or negative, w sometimes zero or negative; dst is a random buffer
and the stride (bytes) is random; every dst byte is compared."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g5c92a0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5c9330, 1, this=True)
    y = obj(c, 0x20, {0x128: pystub(c, 1, this=True)}, nslots=0x140 // 4)
    s = obj(c, 0x20, {0x2f4: pystub(c, 0, ret=y, this=True)}, nslots=0x300 // 4)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=s, this=True), 0x114: pystub(c, 6, ret=lambda em, k: r.getrandbits(32), this=True)}, table_size=0x120)
    p = obj(c, 0x20, {0x288: pystub(c, 3, this=True)}, nslots=0x290 // 4)
    me = rnd(c, 0x90)
    c.emu.w32(me + 0x44, p)
    return [me]


def _g5d4a70(c):
    clear_hooks(c)
    r = c.rng
    vals = [r.getrandbits(32) for _ in range(5)]
    hook_rec(c, 0x4e5e60, 0, ret=lambda em, k: vals[min(k, 4)], this=True, pop=0)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=lambda em, k: r.getrandbits(32), this=True)})
    return [rnd(c, 0x80), rnd(c, 0x20)]


def _g638cf0(c):
    clear_hooks(c)
    r = c.rng
    pitch = r.randint(0, 16)
    surf = rnd(c, 0x20)
    c.emu.w32(surf + 4, pitch)
    c.emu.w32(surf + 0x10, rnd(c, 0x4000))
    me = obj(c, 0x40, {0x38: pystub(c, 1, ret=surf, this=True)}, nslots=0x40 // 4)
    h = r.choice([0, 1, 3, 6, -1, r.randint(1, 6)]) & 0xffffffff
    w = r.choice([0, 1, 4, 8, -2, r.randint(1, 8)]) & 0xffffffff
    stride = r.choice([0, 4, 16, 32, 64, r.randint(0, 64)])
    return [me, rnd(c, 0x600), r.randint(0, 8), r.randint(0, 8), w, h, stride, r.getrandbits(32)]


S(0x5c92a0, 'GUESS re-resolve target and notify', 'thiscall', None, ret=None, gen=_g5c92a0, note='batch34032')
S(0x5d4a70, 'GUESS read five fields from a stream', 'thiscall', None, ret=None, gen=_g5d4a70, note='batch34032')
S(0x638cf0, 'GUESS copy rectangle of dwords out of a surface', 'thiscall', None, ret=None, gen=_g638cf0, note='batch34032')
