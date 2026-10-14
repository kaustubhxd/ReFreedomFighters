"""specs_s38013.py - cascade s8 batch 38013: 0x5c3560. Table object (engine +0x9b): slot 0x58 maps a small id to a fixed object (or 0), slot 0x114 returns a random id.
The list at this+0x48 has a vtable with slot 0x4c (begin) and slot 0x5c (next: returns the k-th item id and sets the cursor dword to 1 while k < n). Item objects have
recording slots 0x1e0 (flag test: low byte random), 0x214, 0x218, 0xbc, 0x20 (returns a helper), 0x128, and a payload pointer at +8; 0x43ec00 hooked. The counter
(+0x112 byte start / word limit) is small so both the step and the wrap run; the unaligned engine field +0x1a9f is zero about half of the time."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g5c3560(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def rb(em, k):
        return r.choice([0, 1, 0x100, 0x101, r.getrandbits(32)])
    helper = rnd(c, 0x20)
    ids = r.sample(range(1, 40), 8)
    objs = {}
    for i in ids:
        if r.random() < 0.15:
            continue
        o = obj(c, 0x60, {0x1e0: pystub(c, 1, this=True, ret=rb), 0x214: pystub(c, 0, this=True), 0x218: pystub(c, 0, this=True),
                          0xbc: pystub(c, 1, this=True), 0x20: pystub(c, 0, this=True, ret=helper),
                          0x128: pystub(c, 3, this=True)})
        e.w32(o + 8, rnd(c, 0x40))
        objs[i] = o

    def s58(em, res_):
        a = em.arg32(0)
        em.calllog.append(('s58', em.reg('ecx'), a))
        em.ret(eax=objs.get(a, 0), argbytes=4)
    so = sysobj(c, {}, table_slots={0x58: e.stub_fn('s58', s58),
                                    0x114: pystub(c, 4, this=True, ret=lambda em, k: r.getrandbits(32))})
    e.wbytes(so + 0x1a9f, struct.pack('<I', 0 if r.random() < 0.4 else r.getrandbits(32) | 1))
    n = r.choice([0, 1, 2, 3, 4, 5])
    seq = [r.choice(ids + [99]) for _ in range(8)]

    def nxt(em, k):
        em.w32(em.arg32(0), 1 if k < n else 0)
        return seq[k % 8]
    vt = e.alloc(0x80, 4)
    e.w32(vt + 0x4c, pystub(c, 1, this=True, stackmark=(0,)))
    e.w32(vt + 0x5c, pystub(c, 1, this=True, stackmark=(0,), ret=lambda em, k: seq[k % 8], side=lambda em, k: em.w32(em.arg32(0), 1 if k < n else 0)))
    me = rnd(c, 0x200)
    e.w32(me + 0x48, vt)
    xid = r.choice(ids + [98])
    e.wbytes(me + 0x10a, struct.pack('<I', xid))
    e.wbytes(me + 0x10e, struct.pack('<I', r.choice([0, r.getrandbits(32)])))
    e.wbytes(me + 0x112, struct.pack('<H', r.randrange(0, 5)))
    hook_rec(c, 0x43ec00, 6, this=True, pop=0x18)
    return [me, r.choice([0, 1, 1, 2, 0x101]), r.choice([0, 1, 1, 0x100, 0x101])]


S(0x5c3560, 'GUESS apply state change to list items', 'thiscall', None, ret=None, gen=_g5c3560, note='batch38013')
