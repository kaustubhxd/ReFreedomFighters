"""specs_s210066.py - Sonnet-w3a: 0x576330. Manager slots 0x138 (returns lookup objects), 0x58, 0x4c; lookup slot 0x88 writes a tag into its stack out pointer; the two exe name strings at 0x6a6e5c / 0x6a8558 are randomised and this[0x94]+0x48 is set equal to one, the other or neither; this[0x94] sometimes null."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def _str(c):
    return bytes(c.rng.choice(b'abXY') for _ in range(c.rng.choice([0, 1, 2, 3, 5]))) + b'\0'


def g576330(c):
    clear_hooks(c)
    e = c.emu
    s1, s2 = _str(c), _str(c)
    e.wbytes(0x6a6e5c, s1); e.wbytes(0x6a8558, s2)
    tags = [_r(c) for _ in range(3)]
    holder = []
    clear94 = c.rng.random() < 0.2

    def s88(emu, k):
        emu.w32(emu.arg32(1), tags[min(k, 2)])
        if k == 2 and clear94:
            emu.w32(holder[0] + 0x94, 0)
        emu.calllog.append(('s88', k, emu.arg32(0), tags[min(k, 2)]))
    lk = obj(c, 0x40, {0x88: pystub(c, 2, ret=_r(c), this=True, stackmark=(1,), side=s88)}, nslots=0x40)
    tgt = obj(c, 0x40, {0xbc: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x60)
    mg = obj(c, 0x40, {0x138: pystub(c, 0, ret=lk, this=True), 0x58: pystub(c, 1, ret=tgt, this=True),
                       0x4c: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x60)
    so = rnd(c, 0x200)
    e.wbytes(so + 0x9b, mg.to_bytes(4, 'little'))
    e.w32(0x70039c, so)
    hook_rec(c, 0x576a30, 1, ret=_r(c), this=True)
    eb = rnd(c, 0x13400)
    r = c.rng.random()
    nm = s1 if r < 0.35 else (s2 if r < 0.7 else _str(c))
    e.wbytes(eb + 0x48, nm)
    e.wbytes(eb + 0x1040, bytes([c.rng.choice([0, 0, 1])]))
    this = rnd(c, 0x240)
    e.w32(this + 0x94, eb); holder.append(this)
    return [this]


S(0x576330, 'cache_registry_ids', 'thiscall', None, ret=None, gen=g576330, note='batch210066')
