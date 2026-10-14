"""specs_s34152.py - tier H with exe helpers. 0x423f90: the real 0x633910 float-to-int helper runs; Sleep (KERNEL32 import) stubbed (logs the int, stdcall(4)). 0x4df9d0: same helper. 0x4dfda0: CRT sqrt import stubbed by the harness; x87 result. 0x52b330: logger printer + assert hook. 0x5efcc0 / 0x4b89d0: engine int at [0x70039c]+0x40 around the float-derived thresholds, hooked callees. 0x535940: real log10 via the harness stub. 0x46abb0: child object slots."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec
from pe_emu import DEFAULT_EXE
import pefile

_pe = pefile.PE(DEFAULT_EXE)
_img = _pe.OPTIONAL_HEADER.ImageBase


def _const(addr):
    return struct.unpack('<f', _pe.get_data(addr - _img, 4))[0]


def _fbits(r, center=None, wide=False):
    k = r.random()
    if k < 0.15:
        v = r.choice(EDGE_F)
    elif k < 0.2:
        return r.getrandbits(32)
    elif center is not None and k < 0.5:
        v = center + r.choice([0.0, 1e-6, -1e-6, 0.01, -0.01, 1.0, -1.0, 100.0, -100.0])
    elif wide and k < 0.65:
        v = r.choice([1, -1]) * r.uniform(1e8, 4e9)
    else:
        v = r.uniform(-1000, 1000)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _stub_except1(c):
    r = c.rng

    def ex(em, res_):
        em.calllog.append(('_except1', em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3), em.arg32(4), em.arg32(5), em.arg32(6)))
        em.ret(eax=0, argbytes=0, st0=float(r.choice([0.0, 1.0, -2.5])))
    c.emu.stub_import('_except1', ex)


def _g423f90(c):
    clear_hooks(c)
    r = c.rng

    def sleep(em, res_):
        em.calllog.append(('Sleep', em.arg32(0)))
        em.ret(eax=r.getrandbits(32), argbytes=4)
    c.emu.stub_import('Sleep', sleep)
    _stub_except1(c)
    return [_fbits(r, wide=True)]


def _g4df9d0(c):
    clear_hooks(c)
    r = c.rng
    _stub_except1(c)
    return [_fbits(r, -_const(0x67a6ac), wide=True)]


def _g4dfda0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x10)
    c.emu.w32(me, _fbits(r))
    c.emu.w32(me + 4, _fbits(r))
    return [me]


def _g52b330(c):
    clear_hooks(c)
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))
    pr = obj(c, 0x20, {0x2c: pystub(c, 2, pop=0)}, nslots=0x30 // 4)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=pr, this=True)}, nslots=0x24 // 4)
    c.emu.w32(0x700390, lg)
    return [r.getrandbits(32), r.getrandbits(32)]


def _eng(c, n):
    so = rnd(c, 0x50)
    c.emu.w32(so + 0x40, n & 0xffffffff)
    c.emu.w32(0x70039c, so)


def _g5efcc0(c):
    clear_hooks(c)
    r = c.rng
    k = _const(0x678620)
    hook_rec(c, 0x5ef240, 0, this=True, pop=0, ret=r.getrandbits(32))
    n = r.choice([0, 7, -7, 100, r.randrange(-3000, 3000)])
    _eng(c, n)
    me = rnd(c, 0xb0)
    c.emu.wbytes(me + 0xa0, bytes([0 if r.random() < 0.25 else r.choice([1, 2])]))
    for off in (0x9c, 0x98):
        if r.random() < 0.6 and k:
            v = (n + r.choice([-2, -1, 0, 0, 1, 2, 0.5, -0.5])) / k
            bits = struct.unpack('<I', struct.pack('<f', v))[0]
        else:
            bits = _fbits(r)
        c.emu.w32(me + off, bits)
    return [me]


def _g4b89d0(c):
    clear_hooks(c)
    r = c.rng
    k = _const(0x678620)
    hook_rec(c, 0x4b8ab0, 1, this=True, ret=r.getrandbits(32))
    n = r.choice([0, 7, -7, 100, r.randrange(-3000, 3000)])
    _eng(c, n)
    me = obj(c, 0x60, {0x68: pystub(c, 2, this=True, ret=r.getrandbits(32))}, nslots=0x6c // 4)
    if r.random() < 0.6 and k:
        tot = (n + r.choice([-2, -1, 0, 0, 1, 2, 0.5, -0.5])) / k
        a = r.uniform(-50, 50)
        fa = struct.unpack('<I', struct.pack('<f', a))[0]
        fb = struct.unpack('<I', struct.pack('<f', tot - a))[0]
    else:
        fa, fb = _fbits(r), _fbits(r)
    c.emu.w32(me + 0x50, fa)
    c.emu.w32(me + 0x54, fb)
    return [me]


def _g535940(c):
    clear_hooks(c)
    r = c.rng
    k = r.random()
    if k < 0.1:
        b = r.choice([0, 0x80000000])
    elif k < 0.2:
        b = struct.unpack('<I', struct.pack('<f', _const(0x67cd40) * r.choice([1.0, 10.0, 0.1, 100.0])))[0]
    else:
        b = _fbits(r)
    return [b]


def _g46abb0(c):
    clear_hooks(c)
    r = c.rng
    ch = obj(c, 0x20, {0x98: pystub(c, 3, this=True, ret=r.getrandbits(32))}, nslots=0x9c // 4)
    me = obj(c, 0x80, {0x110: pystub(c, 2, this=True)}, nslots=0x114 // 4)
    c.emu.w32(me + 0x74, ch)
    return [me, r.getrandbits(32), _fbits(r)]


S(0x423f90, 'GUESS Sleep of a float', 'stdcall', None, ret='eax', gen=_g423f90, note='batch34152')
S(0x4df9d0, 'GUESS float plus constant to int', 'stdcall', None, ret='eax', gen=_g4df9d0, note='batch34152')
S(0x4dfda0, 'GUESS vector length', 'thiscall', None, ret='st0', gen=_g4dfda0, note='batch34152')
S(0x52b330, 'GUESS error stub returning zero', 'stdcall', None, ret='st0', gen=_g52b330, note='batch34152')
S(0x5efcc0, 'GUESS conditional tail call', 'thiscall', None, ret=None, gen=_g5efcc0, note='batch34152')
S(0x4b89d0, 'GUESS time check and reset', 'thiscall', None, ret=None, gen=_g4b89d0, note='batch34152')
S(0x535940, 'GUESS log10 scale', 'stdcall', None, ret='eax', gen=_g535940, note='batch34152')
S(0x46abb0, 'GUESS forward through child', 'thiscall', None, ret='eax', gen=_g46abb0, note='batch34152')
