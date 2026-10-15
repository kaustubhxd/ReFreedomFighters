"""h18.py - stub helpers for the fresh-18 specs (Python handlers; every call is logged in emu.calllog, so the
order, this/ecx, edx and every stack argument are compared between the exe and the port).

L(c, name, nargs, ret=0, regs=('ecx',), wr=None): a stub address. ret: int, list (next value per call) or
  fn(e, ecx, edx, args) -> int. wr: fn(e, ecx, edx, args) run before returning (to write through out pointers).
  Pops 4*nargs bytes (stdcall/thiscall/fastcall stack words). Use pops= to override (cdecl: pops=0).
obj(c, slots, size=0x100, vt_slots=None): random-bytes object, vtable with slots {off: stub}; other slots unstubbed.
hk(c, addr, name, nargs, ...): replace exe function addr with the same logging behaviour (persistent hook)."""
import struct


def _mk(c, name, nargs, ret=0, regs=('ecx',), wr=None, pops=None):
    st = {'i': 0}
    pops = 4 * nargs if pops is None else pops

    def h(e, r):
        args = tuple(e.arg32(k) for k in range(nargs))
        rv = tuple(e.reg(x) for x in regs)
        e.calllog.append((name, rv, args))
        if wr:
            wr(e, rv, args)
        if callable(ret):
            v = ret(e, rv, args)
        elif isinstance(ret, (list, tuple)):
            v = ret[min(st['i'], len(ret) - 1)]
        else:
            v = ret
        st['i'] += 1
        e.ret(eax=v, argbytes=pops)
    return h


def L(c, name, nargs, ret=0, regs=('ecx',), wr=None, pops=None):
    return c.emu.stub_fn(name, _mk(c, name, nargs, ret, regs, wr, pops))


def hk(c, addr, name, nargs, ret=0, regs=('ecx',), wr=None, pops=None):
    c.emu.hook(addr, _mk(c, name, nargs, ret, regs, wr, pops))


def obj(c, slots, size=0x100, nslots=None):
    o = c.emu.alloc(size, 4)
    c.emu.wbytes(o, c.rng.randbytes(size))
    n = nslots or (max(list(slots) + [0]) // 4 + 1)
    vt = c.emu.fake_vtable('obj', n, slots)
    c.emu.w32(o, vt)
    return o


def rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, c.rng.randbytes(n))
    return a


def setg(c, addr, v):
    c.emu.w32(addr, v)


def engine(c, off, o):
    """[0x70039c] = a block whose dword at +off is o (other bytes random)."""
    blk = rnd(c, off + 0x40)
    c.emu.w32(blk + off, o)
    c.emu.w32(0x70039c, blk)
    return blk
