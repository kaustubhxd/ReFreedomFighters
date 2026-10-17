"""specs_s984.py - area 56 band, claim A50 (0x537fd0): a list walk with two virtual calls per node; void.

this is a 0x5400-byte object of random bytes. Its list lives at this+0x10a7: 1 to 3 nodes, each (value, next) with the index
(1 to 3, never zero) and the last next = 0x80000000. The global at 0x70039c points to a fake object whose +0x9b dword points to a
second fake object. Its vtable slot 0x58 (thiscall, one argument) is a GUESS recording stub that returns either zero (about half the
cases) or the address of a result object (a fake object whose vtable slot 0x128 is a GUESS recording stub, thiscall, three
arguments). The word at +0x50a7 and arg2 are random. ret=None (void)."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng

    def h128(e2, r):
        e2.calllog.append(('V128', e2.reg('ecx'), e2.arg32(0), e2.arg32(1), e2.arg32(2)))
        e2.ret(argbytes=12)

    vt_r = e.fake_vtable('vt537fd0r', 0x200, {0x128: h128})
    robj = e.alloc(0x40, 4)
    e.wbytes(robj, bytes(rng.getrandbits(8) for _ in range(0x40)))
    e.w32(robj, vt_r)
    rv58 = 0 if rng.random() < 0.5 else robj

    def h58(e2, r):
        e2.calllog.append(('V58', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(eax=rv58, argbytes=4)

    vt_obj = e.fake_vtable('vt537fd0obj', 0x200, {0x58: h58})
    obj = e.alloc(0x100, 4)
    e.wbytes(obj, bytes(rng.getrandbits(8) for _ in range(0x100)))
    e.w32(obj, vt_obj)
    g = e.alloc(0x100, 4)
    e.wbytes(g, bytes(rng.getrandbits(8) for _ in range(0x100)))
    e.w32(g + 0x9b, obj)
    e.w32(0x70039c, g)
    this = e.alloc(0x5400, 4)
    e.wbytes(this, bytes(rng.getrandbits(8) for _ in range(0x5400)))
    e.w32(this + 0x50a7, rng.getrandbits(16))
    nodes = rng.randint(1, 3)
    idxs = rng.sample([1, 2, 3], nodes)
    for k, idx in enumerate(idxs):
        base = this + 0x10a7 + idx * 8
        e.w32(base, rng.getrandbits(32))
        e.w32(base + 4, idxs[k + 1] if k + 1 < nodes else 0x80000000)
    return [this, idxs[0], rng.getrandbits(32)]


S(0x537fd0, 'unnamed 0x537fd0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-56 A50; vt slots 0x58/0x128 are GUESS recording stubs; global 0x70039c fake object')
