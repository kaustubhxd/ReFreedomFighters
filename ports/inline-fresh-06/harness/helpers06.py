"""helpers06.py - spec helpers for fresh slice 06 (docs/20-fresh-06.md).

hk(): replaces an exe callee by address with a Python stub (pe_emu hook). The stub logs its name, ECX/EDX when asked,
and its stack words, returns a fixed EAX (or a value from a function), and pops the bytes the real callee pops (read
from the callee's `ret N`). The port reaches the same address through ext_<hex>, so both sides hit the same stub."""
import struct
import pe_emu


def rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def zero(c, n, align=4):
    return c.emu.alloc(n, align)


def hk(c, addr, nargs, ret=0, pop=None, ecx=False, edx=False, fn=None, st0=None, name=None):
    """fn(emu, args) runs before returning (it may write memory) and may return the EAX value."""
    pop = 4 * nargs if pop is None else pop
    nm = name or '%x' % addr

    def h(e, r):
        args = tuple(e.arg32(k) for k in range(nargs))
        regs = ()
        if ecx:
            regs += (e.reg('ecx'),)
        if edx:
            regs += (e.reg('edx'),)
        e.calllog.append((nm, regs, args))
        v = fn(e, args) if fn else None
        e.ret(eax=ret if v is None else v, argbytes=pop, st0=st0)
    c.emu.hook(addr, h)


def vt(c, name, slots):
    """A fake vtable: slots = {byte_off: (nargs, fn_or_const)}; fn(emu, args) -> eax. Logs (name, off, ecx, args)."""
    impl, aw = {}, {}
    for off, (n, f) in slots.items():
        aw[off] = n
        impl[off] = (lambda e, a, f=f: (f(e, a) if callable(f) else f, None))
    top = max(slots) // 4 + 1
    return c.emu.logging_vtable(name, top, impl=impl, argwords=aw)


def obj(c, size, vtab=None, rand=True):
    o = rnd(c, size) if rand else zero(c, size)
    if vtab is not None:
        c.emu.w32(o, vtab)
    return o


def seq(vals):
    """A hook fn that returns vals[0], vals[1], ... (wraps)."""
    st = [0]

    def f(e, a):
        v = vals[st[0] % len(vals)]
        st[0] += 1
        return v
    return f


def rv(c, n=8):
    return [c.rng.getrandbits(32) for _ in range(n)]


def eng(c, fields):
    """Engine object at 0x70039c (random bytes) with {offset: value} fields."""
    e = rnd(c, 0x2000)
    for off, v in fields.items():
        c.emu.w32(e + off, v)
    c.emu.w32(0x70039c, e)
    return e


def cvt(c, name, slots, pops=None):
    """A fake vtable for slots called WITHOUT a meaningful ECX (cdecl/stdcall COM style): ECX is not logged.
    slots = {byte_off: (nargs, fn_or_const)}; pops = {byte_off: bytes popped} (default 0 = cdecl)."""
    pops = pops or {}
    hs = {}
    for off, (n, f) in slots.items():
        def h(e, r, off=off, n=n, f=f):
            args = tuple(e.arg32(k) for k in range(n))
            e.calllog.append((name, off, args))
            v = f(e, args) if callable(f) else f
            e.ret(eax=v, argbytes=pops.get(off, 0))
        hs[off] = h
    return c.emu.fake_vtable(name, max(slots) // 4 + 1, hs)


def logger(c, nargs=1):
    """Error logger at 0x700390: slot 0x20(line, file) returns a sink; sink slot 0x2c is cdecl (sink, nargs words)."""
    sink = obj(c, 0x10, cvt(c, 'sink', {0x2c: (1 + nargs, 0)}))
    lg = obj(c, 0x10, vt(c, 'log', {0x20: (2, sink)}))
    c.emu.w32(0x700390, lg)


def handler(c, ret=None):
    """Error handler pointer at 0x7003b0: a logged stub returning a random EAX."""
    v = c.rng.getrandbits(32) if ret is None else ret

    def f(e, r):
        e.calllog.append(('handler',))
        e.ret(eax=v)
    c.emu.w32(0x7003b0, c.emu.stub_fn('handler', f))
