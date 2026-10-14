"""specs_s38061.py - cascade s8 batch 38061. A node with an optional child (this[0x9c], depth up to 2, the child has its own tables), two tables at this[0x84] / this[0x80] (+ this[0x98]) of 0..3 entries
(6-byte stride: dword index at +4, word id at +8; ids drawn inside the local range, below it (child / assert path) and beyond it (error path)), the local id table (this[0xa0] base, [0xa8] count, [0xac]
dword table, [0xb0] addend) and A (unaligned dword at +0x9e -> region of object pointers indexed by the entries). B: sink object (slot 0 recorded with the value); the objects have slot 0x3c; 0x5ffb00 and 0x5f9db0
are hooked; the logger stream and the assert hook are always set. The recursion goes through the node itself in both the original and the port."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g5fe610(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    st = obj(c, 0x20, {0x2c: pystub(c, 3, pop=0)})

    def lg(em, res_):
        em.calllog.append(('logger', em.reg('ecx') != 0, em.arg32(0), em.arg32(1)))
        em.ret(eax=st, argbytes=8)
    e.w32(0x700390, obj(c, 0x40, {0x20: e.stub_fn('logger', lg)}))
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    nobj = 6
    objs = [obj(c, 0x20, {0x3c: pystub(c, 1, this=True)}) for _ in range(nobj)]
    region = e.alloc(4 * nobj + 8, 4)
    e.wbytes(region, struct.pack('<%dI' % nobj, *objs) + bytes(8))
    A = e.alloc(0xb0, 4)
    e.wbytes(A, r.randbytes(0xb0))
    e.wbytes(A + 0x9e, struct.pack('<I', region))
    B = obj(c, 0x20, {0: pystub(c, 1, this=True)})
    pretab = e.alloc(64, 4)
    e.wbytes(pretab, r.randbytes(64))

    def mknode(depth):
        n = e.alloc(0xc0, 4)
        e.wbytes(n, r.randbytes(0xc0))
        child = mknode(depth - 1) if depth > 0 and r.random() < 0.6 else 0
        e.w32(n + 0x9c, child)
        add = r.choice([0, 0x20])
        e.w32(n + 0x98, add)
        base0 = r.choice([0x10, 0x30])
        cnt = r.choice([0, 1, 2, 3])
        lo = r.randrange(0, 0x40)
        local = r.choice([0, 4, 6]) if r.random() < 0.8 else 0
        e.w32(n + 0xa0, lo)
        e.w32(n + 0xa8, local)
        tab = e.alloc(4 * max(local, 1) + 8, 4)
        e.wbytes(tab, r.randbytes(4 * max(local, 1) + 8))
        e.w32(n + 0xac, tab)
        e.w32(n + 0xb0, r.getrandbits(32))
        for off in (0x84, 0x80):
            cnt = r.choice([0, 1, 2, 3])
            blk = e.alloc(0x70, 4)
            e.wbytes(blk, bytes(0x70))
            e.w32(blk + add, cnt)
            for i in range(cnt):
                k = r.random()
                if k < 0.5 and local:
                    wid = lo + r.randrange(local)
                elif k < 0.75:
                    wid = r.randrange(0, lo) if lo else 0
                else:
                    wid = lo + local + r.randrange(0, 5)
                e.wbytes(blk + add + 4 + 6 * i, struct.pack('<IH', 4 * r.randrange(nobj), wid & 0xffff))
            e.w32(n + off, blk)
        return n
    top = mknode(2)
    hook_rec(c, 0x5ffb00, 1, this=True, pop=4, ret=lambda em, k: r.getrandbits(32))
    hook_rec(c, 0x5f9db0, 1, this=True, pop=4)
    return [top, A, B]


S(0x5fe610, 'GUESS replay node tables into sink', 'thiscall', None, ret=None, gen=_g5fe610, note='batch38061')
