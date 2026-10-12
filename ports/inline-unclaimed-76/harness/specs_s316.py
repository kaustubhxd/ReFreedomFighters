"""specs_s316.py - gap band, batch 316: 0x602ff0 (thiscall, ret 4). SEH frame and stack cookie not reproduced (see the source).
The header object at this+1 holds a tree root at +1; nodes carry left/right at +5/+9 and string range at +0xd/+0x11. The IAT _strnicmp
(0x676408) is a stub. The ctor 0x42b390 and the tree search 0x5fb980 and the free 0x54f870 run as exe code; the CRT free is a stub."""
import struct
from pilot import S


def _strnicmp(em, r):
    # cdecl import 0x676408 (_strnicmp): case-insensitive compare of at most n bytes; the caller pops the arguments
    a, b, n = em.arg32(0), em.arg32(1), em.arg32(2)
    res = 0
    for i in range(n):
        x = em.mu.mem_read(a + i, 1)[0]
        y = em.mu.mem_read(b + i, 1)[0]
        x = x + 32 if 65 <= x <= 90 else x
        y = y + 32 if 65 <= y <= 90 else y
        if x != y or x == 0:
            res = x - y
            break
    em.ret(eax=res & 0xffffffff, argbytes=0)


def _memmove(em, r):
    # cdecl import VCRUNTIME140.memmove(dst, src, n): overlap-safe copy; the caller pops the arguments
    dst, src, n = em.arg32(0), em.arg32(1), em.arg32(2)
    data = bytes(em.mu.mem_read(src, n)) if n else b''
    if n:
        em.mu.mem_write(dst, data)
    em.ret(eax=dst, argbytes=0)


def _gen(c):
    e = c.emu
    rng = c.rng
    e.stub_import('_strnicmp', _strnicmp)
    e.stub_import('memmove', _memmove)
    # the exe allocator 0x41e290 / free 0x41e2c0 go through the global 0x70038c (an object; the image value is not one): a fake
    # object whose slot 8 allocates (thiscall, one argument) and whose slot 0x10 frees (thiscall, one argument)
    alloc_obj = e.alloc(0x10, 4)
    e.w32(alloc_obj, e.fake_vtable('allocator', 0x20, {
        0x8: lambda em, r: em.ret(eax=em.alloc(max(em.arg32(0), 4), 16), argbytes=4),
        0x10: lambda em, r: (em.calllog.append(('free316', 0x10, em.reg('ecx'), (em.arg32(0),))), em.ret(eax=0, argbytes=4))[1]}))
    e.w32(0x70038c, alloc_obj)

    def cstr_block(s, extra=0x40):
        blk = e.alloc(len(s) + 1 + extra, 4)
        e.wbytes(blk, s.encode() + b'\0' + bytes(rng.getrandbits(8) for _ in range(extra)))
        return blk

    # the tree: nodes with random lowercase strings, random children among later nodes (no cycles)
    n = rng.randrange(0, 5)
    nodes = []
    strs = []
    for _ in range(n):
        s = ''.join(rng.choice('abcde') for _ in range(rng.randrange(0, 4)))
        strs.append(s)
        nb = e.alloc(0x40, 4)
        e.wbytes(nb, bytes(rng.getrandbits(8) for _ in range(0x40)))   # random payload: [node+0x19] is the returned value
        sb = cstr_block(s, 4) if s else e.alloc(8, 4)
        e.w32(nb + 0xd, sb)
        e.w32(nb + 0x11, sb + len(s))
        nodes.append(nb)
    for i, nb in enumerate(nodes):
        later = nodes[i + 1:]
        e.w32(nb + 5, rng.choice(later) if later and rng.random() < 0.6 else 0)
        e.w32(nb + 9, rng.choice(later) if later and rng.random() < 0.6 else 0)
    head = e.alloc(0x40, 4)
    e.w32(head + 1, nodes[0] if nodes and rng.random() < 0.8 else 0)
    hobj = e.alloc(0x20, 4)                 # this: the head pointer lives at this+1
    e.w32(hobj + 1, head)
    # the argument: a 0x40-byte block whose bytes end in a NUL before 0x18 (the ctor reads a C string); [a+0x19] is readable
    a = e.alloc(0x40, 4)
    if strs and rng.random() < 0.5:          # half the time the key is one of the node strings: the search can find it
        body = rng.choice(strs).encode()
    else:
        body = bytes(rng.choice(b'abcde') for _ in range(rng.randrange(0, 0x18)))
    e.wbytes(a, body + b'\0' + bytes(rng.getrandbits(8) for _ in range(0x40 - len(body) - 1)))
    e.w32(a + 0x19, rng.getrandbits(32))
    return [hobj, a]


S(0x602ff0, 'lookup602ff0 (GUESS)', 'thiscall', None, ret='eax', gen=_gen, note='batch316; ret 4; SEH frame not reproduced')
