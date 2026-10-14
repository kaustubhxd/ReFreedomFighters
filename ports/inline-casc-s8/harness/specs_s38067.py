"""specs_s38067.py - cascade s8 batch 38067: 0x61f0d0. cdecl(a, b) void. a = 0xb0 random block with: five (array, count, free-struct) groups at (0,4,0x10) (0x70,0x74,0x80) (0x14,0x18,0x24) (0x28,0x2c,0x38) (0x3c,0x40,0x4c),
arrays of 0..4 entries (some null), entries of the a[0x14] array are small blocks with a flag at +0x10 and a value at +0x14; two singly linked chains at a[0x50] / a[0x54] (0..3 nodes, next at +0), their free struct a[0x64];
buffers a[0xa4] / a[0x90] (maybe null); b+0x14 = free function. All free functions are logging stubs (each logs the group name and the pointer)."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks


def _g61f0d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def fr(name):
        def h(em, res_):
            em.calllog.append((name, em.arg32(0)))
            em.ret(eax=r.getrandbits(32))
        return e.stub_fn(name, h)

    def fs(name):
        s = e.alloc(0x20, 4)
        e.wbytes(s, r.randbytes(0x20))
        e.w32(s + 8, fr(name))
        return s
    a = e.alloc(0xb0, 4)
    e.wbytes(a, r.randbytes(0xb0))
    for k, (arr, cnt, f) in enumerate(((0, 4, 0x10), (0x70, 0x74, 0x80), (0x14, 0x18, 0x24), (0x28, 0x2c, 0x38), (0x3c, 0x40, 0x4c))):
        n = r.choice([0, 1, 2, 3, 4])
        ar = e.alloc(4 * 5, 4)
        ents = []
        for i in range(5):
            if r.random() < 0.25:
                ents.append(0)
            elif arr == 0x14:
                blk = e.alloc(0x20, 4)
                e.wbytes(blk, r.randbytes(0x20))
                if r.random() < 0.4:
                    e.w32(blk + 0x10, 0)
                ents.append(blk)
            else:
                ents.append(r.getrandbits(32) | 1)
        e.wbytes(ar, struct.pack('<5I', *ents))
        e.w32(a + arr, ar if r.random() < 0.9 else 0) if n and False else e.w32(a + arr, ar if (n or r.random() < 0.7) else 0)
        e.w32(a + cnt, n)
        e.w32(a + f, fs('g%d' % k))
    chainfs = fs('chain')
    e.w32(a + 0x64, chainfs)
    for head in (0x50, 0x54):
        nxt = 0
        for i in range(r.choice([0, 1, 2, 3])):
            nd = e.alloc(0x10, 4)
            e.wbytes(nd, r.randbytes(0x10))
            e.w32(nd, nxt)
            nxt = nd
        e.w32(a + head, nxt)
    for off in (0xa4, 0x90):
        e.w32(a + off, r.choice([0, r.getrandbits(32) | 1]))
    b = e.alloc(0x20, 4)
    e.wbytes(b, r.randbytes(0x20))
    e.w32(b + 0x14, fr('bfree'))
    return [a, b]


S(0x61f0d0, 'GUESS free owned arrays and chains', 'cdecl', None, ret=None, gen=_g61f0d0, note='batch38067')
