"""fu_kit.py - shared spec helpers for the inline-frameupdate batches (400+).

Stand-ins are Python stubs (pe_emu stub_fn / hook) that append (name, ecx, args) to emu.calllog, which pilot.py
compares in order. Pointer args into the caller's stack frame are logged by content (or as 'stk'), because the
exe and the port lay out their frames differently. Stub return values and out-buffer contents are drawn from the
input's rng in setup, so both runs see the same values.
"""
import struct

import pe_emu
from pe_emu import F, f32

STK_LO, STK_HI = pe_emu.STACK_TOP - pe_emu.STACK_SIZE, pe_emu.STACK_TOP


def rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def vec(c, n, lo=-100.0, hi=100.0, pad=4):
    a = c.emu.alloc(4 * (n + pad), 4)
    for i in range(n + pad):
        c.emu.wf32(a + 4 * i, c.rng.uniform(lo, hi))
    return a


def fbits(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def norm(e, a, size=0):
    if isinstance(size, tuple) and size[0] == 'mask':   # only these bits are defined (e.g. a bool pushed as a dword)
        return a & size[1]
    if STK_LO <= a < STK_HI:
        return ('stk', e.rbytes(a, size).hex()) if size else ('stk',)
    return a


def _handler(name, nargs, ret, body, sizes, st0, cdecl=False, noecx=False):
    sizes = sizes or {}

    def h(e, r):
        args = [e.arg32(i) for i in range(nargs)]
        ecx = None if noecx else norm(e, e.reg('ecx'))
        e.calllog.append((name, ecx, tuple(norm(e, a, sizes.get(i, 0)) for i, a in enumerate(args))))
        if body:
            body(e, args)
        eax = ret(e, args) if callable(ret) else ret
        s = st0(e, args) if callable(st0) else st0
        e.ret(eax=eax, argbytes=0 if cdecl else 4 * nargs, st0=s)
    return h


def fn(c, name, nargs=0, ret=0, body=None, sizes=None, st0=None, cdecl=False, noecx=False):
    """A stub function address. ret: int or f(e, args). body(e, args) may write out-buffers.
    sizes: {arg index: bytes to log when the arg points into the stack}. st0: float return."""
    return c.emu.stub_fn(name, _handler(name, nargs, ret, body, sizes, st0, cdecl, noecx))


def obj(c, size, slots, name='obj', nslots=None):
    """Random-filled object whose vtable has the given slots {byte off: stub addr}; other slots stop the run."""
    o = rnd(c, size)
    n = max(nslots or 1, (max(slots) // 4 + 1) if slots else 1)
    vt = c.emu.alloc(4 * n, 4)
    for i in range(n):
        t = slots.get(4 * i)
        if t is None:
            t = c.emu._new_stub('%s slot +0x%x' % (name, 4 * i), None)
        c.emu.w32(vt + 4 * i, t)
    c.emu.w32(o, vt)
    return o


_HOOKED = set()


def hooks(c, table):
    """Replace exe functions for this input: {addr: (name, nstackargs, ret, body)}. Earlier hooks are removed."""
    e = c.emu
    for a in list(_HOOKED):
        e.unhook(a)
    _HOOKED.clear()
    for addr, t in (table or {}).items():
        name, nargs = t[0], t[1]
        ret = t[2] if len(t) > 2 else 0
        body = t[3] if len(t) > 3 else None
        sizes = t[4] if len(t) > 4 else None
        opts = t[5] if len(t) > 5 else {}
        e.hook(addr, _handler(name, nargs, ret, body, sizes, None, **opts))
        _HOOKED.add(addr)


def bool8(c, p=0.5):
    """A random dword whose low byte is zero with probability p (callers test only al)."""
    r = c.rng
    return (r.getrandbits(24) << 8) if r.random() < p else (r.getrandbits(32) | 1)


def setbyte(c, a, p_zero=0.5):
    c.emu.w8(a, 0 if c.rng.random() < p_zero else c.rng.randint(1, 255))


def wfloats(e, a, vals):
    for i, v in enumerate(vals):
        e.wf32(a + 4 * i, v)


def sysobj(c, slots=None, size=0x1ab0, prof=True):
    """The engine object at [0x70039c]. With prof, the profiler flags +0x9c3/+0x9c7 are random (0 in 25%) and slots
    0x1c8/0x178/0x17c are stubs, so the profiler begin/end functions (batch 48) run as exe code."""
    r = c.rng
    sl = dict(slots or {})
    if prof:
        stamp = (r.getrandbits(32), r.getrandbits(32))
        sl.setdefault(0x1c8, fn(c, 'sys.stamp', 2, ret=stamp[0], body=lambda e, a, s=stamp: e.mu.reg_write(
            pe_emu.REGS['edx'], s[1])))
        sl.setdefault(0x178, fn(c, 'sys.profBegin', 3))
        sl.setdefault(0x17c, fn(c, 'sys.profEnd', 3))
    o = obj(c, size, sl, 'sys', nslots=0x200 // 4 + 0x40)
    if prof:
        for off in (0x9c3, 0x9c7):
            x = r.random()
            c.emu.wf32(o + off, 0.0 if x < 0.25 else r.uniform(-1.0, 1.0))
    c.emu.w32(0x70039c, o)
    return o


def install_pow(emu):
    """_libm_sse2_pow_precise (xmm0, xmm1 -> xmm0) with Python's pow; the same stub serves the exe and the port."""
    import math
    import struct as _s
    R = pe_emu.REGS
    from unicorn.x86_const import UC_X86_REG_XMM1

    def h(e, r):
        x = _s.unpack('<d', _s.pack('<Q', e.mu.reg_read(R['xmm0']) & (2 ** 64 - 1)))[0]
        y = _s.unpack('<d', _s.pack('<Q', e.mu.reg_read(UC_X86_REG_XMM1) & (2 ** 64 - 1)))[0]
        try:
            z = math.pow(x, y)
        except (ValueError, OverflowError):
            z = float('nan') if x < 0 else float('inf')
        e.mu.reg_write(R['xmm0'], _s.unpack('<Q', _s.pack('<d', z))[0])
        e.ret()
    emu.stub_import('_libm_sse2_pow_precise', h)


FMOD_CODE = bytes([0xd9, 0xc9,              # fxch          (ST0 = x, ST1 = y)
                   0xd9, 0xf8,              # L: fprem
                   0xdf, 0xe0,              # fnstsw ax
                   0x9e,                    # sahf
                   0x7a, 0xf9,              # jp L          (C2 set: reduction incomplete)
                   0xdd, 0xd9,              # fstp st(1)
                   0xc3])                   # ret


def install_cifmod(c):
    """_CIfmod (x87: x pushed first, then y; returns fmod(x, y) in ST0) as x87 code using fprem, which is exact like
    the CRT's fmod. The import slot 0x676358 is pointed at it for this input (the image is restored on reset)."""
    a = c.emu.alloc(len(FMOD_CODE) + 16, 16)
    c.emu.wbytes(a, FMOD_CODE)
    c.emu.w32(0x676358, a)
    return a
