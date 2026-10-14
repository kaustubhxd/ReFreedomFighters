"""specs_s38047.py - cascade s8 batch 38047. Octree-like state: this[0x5a] = records (12 bytes, +6 u16 count of bit levels, +0xa u16 base id) indexed by the id word, this[0x2a] u16 stride, this[0x72] bit data
(random dwords, large enough), this[0x48] = level count 0..4. X: first callback object (null 25%, vtable slot 0 logs (this, id, lo, hi contents) and returns AL true / false), second callback object (null 20%, slot
0 logs its args with the contents of the bit word and the lo / hi boxes and returns a small count), stop flag byte +0x10 (set 15%). The callbacks are custom stubs (the boxes live on the stack)."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks


def _g52d580(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    nrec = 3
    recs = e.alloc(12 * nrec + 8, 4)
    levels = r.randrange(0, 5)
    for i in range(nrec):
        e.wbytes(recs + 12 * i, r.randbytes(12))
        e.wbytes(recs + 12 * i + 6, struct.pack('<H', r.choice([0, 1, 3])))
        e.wbytes(recs + 12 * i + 0xa, struct.pack('<H', r.randrange(0, 0x1000)))
    stride = r.randrange(1, 4)
    data = e.alloc(0x2000, 4)
    e.wbytes(data, r.randbytes(0x2000))
    me = rnd(c, 0x100)
    e.w32(me + 0x5a, recs)
    e.wbytes(me + 0x2a, struct.pack('<H', stride))
    e.w32(me + 0x72, data)
    e.w32(me + 0x48, levels)
    pa = r.choice([0.3, 0.7, 1.0])

    def cb1(em, res_):
        lo, hi = em.arg32(2), em.arg32(3)
        em.calllog.append(('cb1', em.reg('ecx'), em.arg32(0), em.arg32(1), em.rbytes(lo, 12), em.rbytes(hi, 12)))
        em.ret(eax=(r.getrandbits(24) << 8) | (1 if r.random() < pa else 0), argbytes=16)

    def cb2(em, res_):
        bits, lo, hi = em.arg32(1), em.arg32(3), em.arg32(4)
        em.calllog.append(('cb2', em.reg('ecx'), em.arg32(0), em.r32(bits), em.arg32(2), em.rbytes(lo, 12), em.rbytes(hi, 12), em.arg32(5), em.arg32(6)))
        em.ret(eax=r.choice([0, 1, 2, 5]), argbytes=28)
    c1 = obj(c, 0x20, {0: e.stub_fn('cb1', cb1)}) if r.random() > 0.25 else 0
    c2 = obj(c, 0x20, {0: e.stub_fn('cb2', cb2)}) if r.random() > 0.2 else 0
    x = rnd(c, 0x20)
    e.w32(x, c1)
    e.w32(x + 0xc, c2)
    e.wbytes(x + 0x10, bytes([1 if r.random() < 0.15 else 0]))
    idp = e.alloc(4, 4)
    e.wbytes(idp, struct.pack('<H', r.randrange(0, nrec)))
    return [me, x, idp, r.randrange(1, 9), r.randrange(-100, 100), r.randrange(-100, 100), r.randrange(-100, 100), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x52d580, 'GUESS visit 8x8 cells with callbacks', 'thiscall', None, ret='eax', gen=_g52d580, note='batch38047')
