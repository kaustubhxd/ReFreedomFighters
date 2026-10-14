"""specs_s38024.py - cascade s8 batch 38024: 0x4991c0. Writer object with a custom slot 0x10 (logs ptr, length and the first bytes written: this is where the index form of the table is seen),
slots 0x8 / 0x28 recorded; owner (this+8) with slots 0x1c (iterator) / 0x20 (block) and fields +0xc/+0x10/+0x14, the entry count +0x10 (-1..5); iterator with slot 0x14 and the cursor
slots 0x4c / 0x5c (cursor dword non-zero for the first 0..4 reads). Table at this+0xc: null, base + 0x70*k, or random pointers; base = [[this+0x14]+4]. Signed division by 0x70 included."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g4991c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    block = rnd(c, 0x8000)

    def w10(em, res_):
        p, n = em.arg32(0), em.arg32(1)
        data = em.rbytes(p, min(n, 0x20)) if (p < 0x40000000 or p >= 0x70000000) or True else b''
        em.calllog.append(('put', em.reg('ecx'), p if 0x20000000 <= p < 0x40000000 else 0, n, data))
        em.ret(eax=0, argbytes=8)
    writer = obj(c, 0x40, {8: pystub(c, 1, this=True), 0x10: e.stub_fn('put', w10), 0x28: pystub(c, 1, this=True)})
    n = r.choice([-1, 0, 1, 2, 3, 5])
    nm = max(n, 0)
    ncur = r.randrange(0, 5)
    it = obj(c, 0x40, {0x14: pystub(c, 0, this=True, ret=lambda em, k: r.getrandbits(32)),
                       0x4c: pystub(c, 1, this=True, stackmark=(0,)),
                       0x5c: pystub(c, 1, this=True, stackmark=(0,), ret=lambda em, k: r.getrandbits(32),
                                    side=lambda em, k: em.w32(em.arg32(0), 1 if k < ncur else 0))})
    own = obj(c, 0x40, {0x1c: pystub(c, 0, this=True, ret=it), 0x20: pystub(c, 0, this=True, ret=block)})
    e.w32(own + 0x10, n & 0xffffffff)
    for off in (0xc, 0x14):
        e.w32(own + off, r.getrandbits(32))
    base = r.getrandbits(32)
    holder = rnd(c, 0x20)
    e.w32(holder + 4, base)
    tab = e.alloc(4 * (nm + 4), 4)
    ent = []
    for _ in range(nm + 1):
        k = r.random()
        if k < 0.25:
            ent.append(0)
        elif k < 0.8:
            ent.append((base + 0x70 * r.randrange(0, 40)) & 0xffffffff)
        else:
            ent.append(r.getrandbits(32))
    e.wbytes(tab, struct.pack('<%dI' % len(ent), *ent) + bytes(12))
    me = rnd(c, 0x40)
    e.w32(me + 8, own)
    e.w32(me + 0xc, tab)
    e.w32(me + 0x14, holder)
    return [me, writer]


S(0x4991c0, 'GUESS write object table to stream', 'thiscall', None, ret=None, gen=_g4991c0, note='batch38024')
