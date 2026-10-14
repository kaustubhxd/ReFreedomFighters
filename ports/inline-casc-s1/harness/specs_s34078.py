"""specs_s34078.py - tail thunks that rewrite their stack argument: the tail targets are recorders (slot stubs record this and the rewritten argument).
0x4f4b60 slot 0x2ec (arg byte zero / non-zero), 0x536350 slot 0x1ec (arg zero in a third; unaligned +0x5302), 0x596d00 member +0x1d0f null in a third then hooked 0x5a5e90,
0x517510 low word of the arg equal to the word at +0x164e half the time, counter +0x1639 around zero, hooked 0x5153e0, 0x5c08d0 limit +0x54 vs signed arg, slot 0x98; 0x4e5080 table getter."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g4f4b60(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x20, {0x2ec: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x2f0 // 4)
    return [me, r.choice([0, 1, 0x100, 0x1234, r.getrandbits(32), 0xff])]


def _g536350(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x5310, {0x1ec: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x1f0 // 4)
    c.emu.wbytes(me + 0x5302, r.getrandbits(32).to_bytes(4, 'little'))
    return [me, r.choice([0, 0, 1, r.getrandbits(32), 0xffffffff])]


def _g596d00(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5a5e90, 1, ret=r.getrandbits(32), this=True)
    me = rnd(c, 0x1fc0)
    inner = 0 if r.random() < 0.33 else rnd(c, 0x20)
    c.emu.wbytes(me + 0x1d0f, inner.to_bytes(4, 'little'))
    return [me, r.getrandbits(32)]


def _g517510(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5153e0, 1, ret=r.getrandbits(32), this=True)
    me = rnd(c, 0x1660)
    w = r.getrandbits(16)
    c.emu.wbytes(me + 0x164e, w.to_bytes(2, 'little'))
    c.emu.wbytes(me + 0x1639, r.choice([0, 1, 5, 0xffffffff, 0x80000000, r.getrandbits(32)]).to_bytes(4, 'little'))
    a = w if r.random() < 0.5 else r.getrandbits(32)
    if r.random() < 0.5:
        a |= r.getrandbits(16) << 16
    return [me, a]


def _g5c08d0(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x60, {0x98: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x9c // 4)
    lim = r.choice([0, 3, 10, 0xffffffff, r.getrandbits(32)])
    c.emu.w32(me + 0x54, lim)
    a = r.choice([0, 2, 9, 10, 0xffffffff, r.getrandbits(32), lim, (lim - 1) & 0xffffffff])
    return [me, a]


def _g4e5080(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x20)
    c.emu.w32(me + 0xc, r.randrange(0, 0x38))
    a = rnd(c, 0x90)
    c.emu.w32(a + 0x80, rnd(c, 0x40))
    return [me, a]


S(0x4f4b60, 'GUESS bool arg to 0x10 or 1 then slot 0x2ec', 'thiscall', None, ret='eax', gen=_g4f4b60, note='batch34078')
S(0x536350, 'GUESS offset arg by base then slot 0x1ec', 'thiscall', None, ret='eax', gen=_g536350, note='batch34078')
S(0x596d00, 'GUESS store arg and forward to member', 'thiscall', None, ret='eax', gen=_g596d00, note='batch34078')
S(0x517510, 'GUESS decrement counter on matching id then forward', 'thiscall', None, ret='eax', gen=_g517510, note='batch34078')
S(0x5c08d0, 'GUESS bounds-checked element address then slot 0x98', 'thiscall', None, ret='eax', gen=_g5c08d0, note='batch34078')
S(0x4e5080, 'GUESS table dword getter', 'thiscall', None, ret='eax', gen=_g4e5080, note='batch34078')
