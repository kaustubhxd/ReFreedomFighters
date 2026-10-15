"""h10.py - stub helpers for the fresh-11 specs.
L(name, nargs): a Python stub handler that logs (name, ecx, args) into the call log, pops nargs*4 (or pop) and
returns ret (or retf(e, args)). Every call is logged in order, so argument and order mistakes both show.
obj(c, name, slots, size): random bytes object whose vtable holds the handlers (other slots stop the run)."""
import struct


def L(name, nargs, ret=0, pop=None, retf=None, ecx=True):
    def h(e, r):
        args = tuple(e.arg32(k) for k in range(nargs))
        e.calllog.append((name, e.reg('ecx') if ecx else 0, args))
        e.ret(eax=ret if retf is None else retf(e, args), argbytes=4 * nargs if pop is None else pop)
    return h


def obj(c, name, slots, size=0x200, nslots=None):
    o = c.emu.alloc(size, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(size)))
    n = nslots or (max(slots) // 4 + 1 if slots else 1)
    c.emu.w32(o, c.emu.fake_vtable(name, n, slots))
    return o


def rbuf(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def patch(c, addr, handler, name='patched'):
    """Exe function at addr jumps to a Python stub."""
    s = c.emu.stub_fn(name, handler)
    c.emu.wbytes(addr, b'\xb8' + struct.pack('<I', s) + b'\xff\xe0')
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)




def iat(c, slot, name, nargs, ret=0, pop=None):
    s = c.emu.stub_fn(name, L(name, nargs, ret=ret, pop=pop, ecx=False))
    c.emu.w32(slot, s)


def log_obj(c, nfmt):
    """[0x700390] = object; slot 0x20(file, line) (thiscall, pops 8) returns obj2; obj2 slot 0x2c cdecl(obj2, ...)."""
    o2 = obj(c, 'log2', {0x2c: L('log2c', 1 + nfmt, pop=0, ecx=False)}, size=0x10)
    o1 = obj(c, 'log', {0x20: L('log20', 2, ret=o2)}, size=0x10)
    c.emu.w32(0x700390, o1)


def fbuf(c, n):
    """Like rbuf, but fills with randbytes (fast; for large buffers). Different stream from rbuf."""
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, c.rng.randbytes(n))
    return a
