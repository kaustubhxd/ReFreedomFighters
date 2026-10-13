"""anim_common.py - helpers shared by the animation-layer thread's specs (decomp-pilot/inline-anim)."""
import struct
from pilot import F

HOOKED = set()


GLOBALS = (0x700390, 0x70039c, 0x7003b0, 0x676358)   # globals the specs write with host writes


def only_hooks(c, hooks):
    """Install exactly these exe-function hooks {addr: handler(emu, result)} for this case (both runs).
    Also puts back the exe's own values of the globals that specs set (host writes do not mark the image dirty, so
    pilot.py's image reset does not undo them)."""
    e = c.emu
    for g in GLOBALS:
        off = g - e.base
        e.mu.mem_write(g, bytes(e.image[off:off + 4]))
    for a in list(HOOKED):
        if a not in hooks:
            e.unhook(a)
            HOOKED.discard(a)
    for a, h in hooks.items():
        e.hook(a, h)
        HOOKED.add(a)


def logged_fn(name, nargs, ret=0, st0=None):
    """Hook handler for a __thiscall/__stdcall exe function with nargs stack words: logs (name, ecx, args)."""
    def h(e, r):
        args = tuple(e.arg32(k) for k in range(nargs))
        e.calllog.append((name, e.reg('ecx'), args))
        e.ret(eax=ret(e, args) if callable(ret) else ret, argbytes=4 * nargs, st0=st0)
    return h


def rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def install_logger(c, nargs=3):
    """Engine logger at [0x700390]: slot +0x20 (thiscall file, line) returns a sink; sink slot +0x2c is a cdecl
    printf(sink, fmt, ...). Both calls are logged (the printf with its first 3 words)."""
    e = c.emu

    def p(e, r):
        e.calllog.append(("log.printf",) + tuple(e.arg32(k) for k in range(nargs)))
        e.ret(eax=0, argbytes=0)
    sink = e.fake_object('sink', 0x10, nslots=12, slots={0x2c: p})

    def g(e, r):
        e.calllog.append(('log.where', e.reg('ecx'), e.arg32(0), e.arg32(1)))
        e.ret(eax=sink, argbytes=8)
    lg = e.fake_object('logger', 0x10, nslots=9, slots={0x20: g})
    e.w32(0x700390, lg)
    return lg


def vt_object(c, size, slots, nslots=None, name='obj'):
    """Random-filled object of `size` bytes whose vtable (at +0) has handler slots {byte_off: handler}."""
    e = c.emu
    o = rnd(c, size)
    n = nslots or (max(slots) // 4 + 1 if slots else 1)
    vt = e.fake_vtable(name, n, slots)
    e.w32(o, vt)
    return o


def vslot(name, nargs, ret=0, st0=None):
    """Logged vtable-slot handler (thiscall, callee pops nargs words)."""
    def h(e, r):
        args = tuple(e.arg32(k) for k in range(nargs))
        e.calllog.append((name, e.reg('ecx'), args))
        e.ret(eax=ret(e, args) if callable(ret) else ret, argbytes=4 * nargs, st0=st0)
    return h


FMOD = b'\xd9\xc9\xd9\xf8\xdf\xe0\x9e\x7a\xf9\xdd\xd9\xc3'   # fxch; fprem loop; fstp st1; ret (as specs_s58)


def install_fmod(c):
    """Point the _CIfmod import slot (0x676358) at an fprem loop (fmod is exact, so this equals the CRT)."""
    fm = c.emu.alloc(32, 16)
    c.emu.wbytes(fm, FMOD)
    c.emu.w32(0x676358, fm)
    c.emu.mu.ctl_flush_tb()


def install_memset(c):
    """VCRUNTIME140!memset import (cdecl): does the fill and logs (dst, value, n)."""
    def h(e, r):
        d, v, n = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('memset', d, v & 0xff, n))
        if n:
            e.wbytes(d, bytes([v & 0xff]) * n)
        e.ret(eax=d, argbytes=0)
    c.emu.stub_import('memset', h)


def _cstr(e, p, n=256):
    return e.rbytes(p, n).split(b'\0')[0]


def install_crt_str(c, log_stricmp=True):
    """CRT string imports used by striwcmp / GetAnim: strchr, _memicmp, _stricmp (ASCII case folding, as the
    "C" locale). _stricmp calls are logged by content (one side may be a stack buffer)."""
    e = c.emu

    def strchr(e, r):
        p, ch = e.arg32(0), e.arg32(1) & 0xff
        s = _cstr(e, p) + b'\0'
        i = s.find(bytes([ch]))
        e.ret(eax=p + i if i >= 0 else 0, argbytes=0)

    def fold(b):
        return bytes(x + 32 if 65 <= x <= 90 else x for x in b)

    def cmp(a, b):
        a, b = fold(a), fold(b)
        return 0 if a == b else (0xffffffff if a < b else 1)

    def memicmp(e, r):
        a, b, n = e.arg32(0), e.arg32(1), e.arg32(2)
        e.ret(eax=cmp(e.rbytes(a, n), e.rbytes(b, n)) if n else 0, argbytes=0)

    def stricmp(e, r):
        a, b = _cstr(e, e.arg32(0)), _cstr(e, e.arg32(1))
        if log_stricmp:
            e.calllog.append(('_stricmp', a, b))
        e.ret(eax=cmp(a, b), argbytes=0)
    e.stub_import('strchr', strchr)
    e.stub_import('_memicmp', memicmp)
    e.stub_import('_stricmp', stricmp)
