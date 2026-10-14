"""specs_s38037.py - cascade s8 batch 38037. Batch object (+0xc count, +4 -> record chain, current record +0xc with field +8 non-null 90%), item object (+0x14 owner with +8 / +0xc / +0x20 / byte +5, +0x28,
+0xc, byte +5 with bit 4 set in either 30% of the time), target object (slots 0x29c, 0x28c: 3 args with the matrix bytes recorded, flag byte +0x115f, unaligned pointers at +0x13fa / +0x140a to objects with slot 8
and the +0x30 / +0x2c / +0x18 / +0x14 fields). Device (0x724a00, stdcall slots 0xc8 / 0x130 / 0x14c / 0x154 logged in order) and the cached state globals match or differ at random. The matrix helpers fill their
stack outputs with random bytes (recorded through the 0x28c deref), the timer helpers 0x441730 / 0x440530 and 0x610070 / 0x6107e0 / 0x61a6b0 are hooked."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g619c20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def slot(name, n):
        def h(em, res_):
            em.calllog.append((name,) + tuple(em.arg32(i) for i in range(n)))
            em.ret(eax=0, argbytes=4 * n)
        return e.stub_fn(name, h)
    dev = obj(c, 0x200, {0xc8: slot('c8', 3), 0x130: slot('130', 2), 0x14c: slot('14c', 4), 0x154: slot('154', 3)})
    e.w32(0x724a00, dev)
    match = r.random() < 0.5
    cur = lambda v, alt: v if match else alt
    e.w32(0x724948, r.choice([0, 1, 5]))
    e.w32(0x7249f8, 0x152 if r.random() < 0.5 else r.getrandbits(32))
    esi = obj(c, 0x60, {8: pystub(c, 0, this=True)})
    e.w32(esi + 0x30, r.choice([0, 1, 7]))
    e.w32(esi + 0x2c, r.getrandbits(32))
    edi = obj(c, 0x60, {8: pystub(c, 0, this=True)})
    e.w32(edi + 0x18, r.choice([0, 1, 7]))
    e.w32(edi + 0x14, r.getrandbits(32))
    cnt = r.choice([0, 1, 2, 5]) if r.random() < 0.1 else r.choice([1, 2, 5])
    if r.random() < 0.5:
        e.w32(0x724970, e.r32(esi + 0x2c))
        e.w32(0x7249b0, 0x24)
    else:
        e.w32(0x724970, r.getrandbits(32))
        e.w32(0x7249b0, r.choice([0x24, 0x25]))
    if r.random() < 0.5:
        e.w32(0x7249f0, e.r32(edi + 0x14))
        e.w32(0x7249f4, r.choice([cnt, cnt, cnt + 1]))
    else:
        e.w32(0x7249f0, r.getrandbits(32))
        e.w32(0x7249f4, r.choice([cnt, cnt + 1]))

    def dump(em, res_):
        em.calllog.append(('28c', em.reg('ecx'), em.rbytes(em.arg32(0), 0x24), em.rbytes(em.arg32(1), 0xc), em.arg32(2)))
        em.ret(eax=0, argbytes=12)

    def s29c(em, res_):
        em.calllog.append(('29c', em.reg('ecx'), em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=12)
    y = obj(c, 0x1500, {0x29c: e.stub_fn('29c', s29c), 0x28c: e.stub_fn('28c', dump)})
    e.wbytes(y + 0x115f, bytes([r.choice([0, 2, 3, 0xff])]))
    e.wbytes(y + 0x13fa, struct.pack('<I', esi))
    e.wbytes(y + 0x140a, struct.pack('<I', edi))
    rec_obj = rnd(c, 0x60)
    q4 = rnd(c, 0x20)
    e.w32(q4 + 8, rec_obj)
    q = rnd(c, 0x40)
    e.w32(q + 4, q4)
    e.w32(q + 0xc + 8, 0 if r.random() < 0.1 else r.getrandbits(32) | 1)
    me = rnd(c, 0x40)
    e.w32(me + 4, q)
    e.w32(me + 0xc, cnt)
    e.w32(me + 8, rnd(c, 0x20))
    d = rnd(c, 0x40)
    e.w32(d + 8, rnd(c, 0x60))
    e.w32(d + 0xc, rnd(c, 0x60) if r.random() < 0.5 else 0)
    e.wbytes(d + 5, bytes([r.choice([0, 4, 1, 5])]))
    e.w32(d + 0x20, r.getrandbits(32))
    item = rnd(c, 0x40)
    e.w32(item + 0x14, d)
    e.w32(item + 0x28, r.getrandbits(32))
    e.w32(item + 0xc, rnd(c, 0x60) if r.random() < 0.4 else 0)
    e.wbytes(item + 5, bytes([r.choice([0, 4, 1, 5])]))

    def fill(n):
        def side(em, k):
            em.wbytes(em.reg('ecx'), bytes(r.getrandbits(8) for _ in range(n)))
            em.calllog.append(('edx', em.reg('edx')))
        return side
    hook_rec(c, 0x441730, 0, this=True)
    hook_rec(c, 0x440530, 0, this=True)
    hook_rec(c, 0x4de440, 1, this='mark', pop=4, side=fill(0x24))
    hook_rec(c, 0x441970, 1, this='mark', pop=4, side=fill(0xc))
    hook_rec(c, 0x441940, 0, this='mark', side=fill(0xc))
    hook_rec(c, 0x610070, 1, this=True, pop=4)
    hook_rec(c, 0x6107e0, 1, this=True, pop=4)
    hook_rec(c, 0x61a6b0, 0, this=True, side=lambda em, k: em.calllog.append(('edx', em.reg('edx'))))
    return [me, item, y]


S(0x619c20, 'GUESS draw one batch entry', 'thiscall', None, ret=None, gen=_g619c20, note='batch38037')
