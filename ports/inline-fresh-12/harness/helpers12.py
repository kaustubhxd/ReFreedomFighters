"""helpers12.py - shared spec helpers for inline-fresh-12 (random objects, logging hooks by address)."""
from engine_stubs import zero_obj, logged_obj, set_global


def rand_obj(c, n):
    a = c.emu.alloc(n, 16)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def hk(addr, name, nargs, retfn=None):
    """thiscall/stdcall hook: logs (ecx, stack args), pops nargs words, returns retfn(em) or a fixed marker."""
    def h(em, r):
        args = tuple(em.arg32(k) for k in range(nargs))
        em.calllog.append((name, 0, em.reg('ecx'), args))
        em.ret(eax=retfn(em) if retfn else 0x1234abcd ^ addr, argbytes=4 * nargs)
    return h


def hk_cdecl(addr, name, nargs, retfn=None):
    """cdecl hook: logs the stack args, pops nothing."""
    def h(em, r):
        em.calllog.append((name, 0, 0, tuple(em.arg32(k) for k in range(nargs))))
        em.ret(eax=retfn(em) if retfn else 0x5eed0000 ^ addr, argbytes=0)
    return h


def done(c, args):
    c.emu.mu.ctl_flush_tb()
    return args


def rand_fast(c, n):
    """Random block from the case rng in one call (for large objects)."""
    a = c.emu.alloc(n, 16)
    c.emu.wbytes(a, c.rng.randbytes(n))
    return a


def com_obj(c, name, nslots, impl=None, argwords=None, callee_pops=True, size=0x40):
    """Object whose vtable slots are called with `this` on the stack (COM stdcall, or cdecl with callee_pops=False).
    Logs (slot, stack args) only: ECX holds the vtable pointer there, which the port need not reproduce."""
    impl = impl or {}
    argwords = argwords or {}
    slots = {}
    for i in range(nslots):
        off = 4 * i

        def h(e, r, off=off):
            n = argwords.get(off, 0)
            args = tuple(e.arg32(k) for k in range(n))
            e.calllog.append((name, off, 0, args))
            f = impl.get(off)
            eax = f(e, args) if f else 0
            e.ret(eax=eax, argbytes=4 * n if callee_pops else 0)
        slots[off] = h
    o = zero_obj(c, size)
    c.emu.w32(o, c.emu.fake_vtable(name, nslots, slots))
    return o


def fail_stub(c, val=0x0fa11ed0):
    """Failure handler at 0x7003b0 (cdecl, no args): logged, returns val."""
    def h(em, r):
        em.calllog.append(('fail', 0, 0, ()))
        em.ret(eax=val, argbytes=0)
    c.emu.w32(0x7003b0, c.emu.stub_fn('fail', h))
