"""specs_f1008.py - fresh-10 batch 8: list cleanup, wildcard compare, sound scene pop, DBREAD copy, min/max (slice 10)."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
from h10 import L, obj, rbuf, patch, iat, log_obj


def R(c): return c.rng.getrandbits(32)


def g_49a3e0(c):   # GUESS: free every block of the list (+8) then the list and +4
    patch(c, 0x4ce1c0, L('f4ce1c0', 2)); patch(c, 0x634273, L('delete', 2, pop=0, ecx=False))
    n = c.rng.randint(0, 5); els = []
    for i in range(n):
        e = rbuf(c, 0x20); r = c.rng.random()
        if r < 0.2: c.emu.w32(e + 4, 0)
        else:
            d = rbuf(c, 0x10) + 4; c.emu.w32(e + 4, d); x = rbuf(c, 0x10); c.emu.w32(e + 0x10, x)
            c.emu.w32(x + 4, 0 if r < 0.6 else rbuf(c, 0x10))
        els.append(e)
    st = {'k': 0}
    def h4c(e, r):
        p = e.arg32(0); e.calllog.append(('lst4c', e.reg('ecx'), (p,))); e.wbytes(p, b'\x22' * 12); st['k'] = 0; e.ret(eax=0, argbytes=4)
    def h64(e, r):
        p = e.arg32(0); k = st['k']; st['k'] += 1; e.calllog.append(('lst64', e.reg('ecx'), (p,)))
        e.ret(eax=els[k] if k < n else 0, argbytes=4)
    o = rbuf(c, 0x20)
    c.emu.w32(o + 8, 0 if c.rng.random() < 0.2 else obj(c, 'lst', {0x4c: h4c, 0x64: h64, 0: L('lstdtor', 1)}, size=0x10))
    c.emu.w32(o + 4, 0 if c.rng.random() < 0.3 else obj(c, 'o4', {0: L('o4dtor', 1)}, size=0x10))
    return [o]
S(0x49a3e0, 'GUESS free list blocks', 'thiscall', None, ret=None, gen=g_49a3e0, stack_arg_bytes=12)


def g_602160(c):   # CHostInterface::stricmpwild(const char*, const char*)
    def sncpy(e, _):
        d, s, n = e.arg32(0), e.arg32(1), e.arg32(2)
        b = e.rbytes(s, n + 1); b = b[:b.index(0)] if 0 in b else b
        e.calllog.append(('strncpy', 0, (n,)))
        e.wbytes(d, (b + b'\0' * n)[:n]); e.ret(eax=d, argbytes=0)
    c.emu.w32(0x67642c, c.emu.stub_fn('strncpy', sncpy))
    def wcmp(e, _):
        a, b = e.reg('ecx'), e.reg('edx')
        bb = e.rbytes(b, 0x408); bb = bb[:bb.index(0) + 1]
        e.calllog.append(('striwcmp', a, (len(bb), bytes(bb[:24]).hex())))
        e.ret(eax=len(bb) * 7 + 1, argbytes=0)
    patch(c, 0x4cc850, wcmp)
    n = c.rng.choice([0, 1, 5, 999, 1000, 1001, 1100, c.rng.randint(0, 40)])
    s = c.emu.alloc(n + 8, 4); c.emu.wbytes(s, bytes(c.rng.randint(1, 255) for _ in range(n)) + b'\0')
    return [rbuf(c, 0x10), rbuf(c, 0x10), s]
S(0x602160, 'CHostInterface::stricmpwild', 'thiscall', None, ret='eax', gen=g_602160)


def g_538220(c):   # ZDllSound::PopScene()
    patch(c, 0x634273, L('delete', 2, pop=0, ecx=False)); patch(c, 0x53a8f0, L('~CEVENTCONTROLLER', 0)); patch(c, 0x534510, L('ObjPopScene', 0))
    k = c.rng.randint(0, 3); st = {'n': 0}
    def h19c(e, r):
        st['n'] += 1; e.calllog.append(('snd19c', e.reg('ecx'), ())); e.ret(eax=0x100 if st['n'] <= k else 0x101, argbytes=0)
    o = obj(c, 'snd', {0x208: L('snd208', 0), 0x160: L('snd160', 1), 0x19c: h19c}, size=0x5310)
    c.emu.w32(o + 0x52fe, 0 if c.rng.random() < 0.3 else obj(c, 'a', {0: L('adtor', 1)}, size=0x10))
    for off in (0x5302, 0x52fa):
        if c.rng.random() < 0.3: c.emu.w32(o + off, 0)
    c.emu.w8(o + 0x50ba, c.rng.choice([0, 1]))
    return [o]
S(0x538220, 'ZDllSound::PopScene', 'thiscall', None, ret=None, gen=g_538220)


def g_56f220(c):   # CNewMenu::CopyEventDataBlock(DBREAD&)
    seq = [R(c) for _ in range(11)]; st = {'k': 0}
    def u32op(e, r):
        k = st['k']; st['k'] += 1; e.calllog.append(('DBREAD u32', e.reg('ecx'), ())); e.ret(eax=seq[k % 11], argbytes=0)
    patch(c, 0x4e5e60, u32op); patch(c, 0x610100, L('CopyData', 1))
    return [rbuf(c, 0x1d0), rbuf(c, 0x10)]
S(0x56f220, 'CNewMenu::CopyEventDataBlock', 'thiscall', None, ret=None, gen=g_56f220)


def g_63a2e0(c):   # GUESS fastcall(n, rows): per-column signed min (start 0xff) and max (start 0) of n 4-int rows
    n = c.rng.choice([0, 1, 2, c.rng.randint(0, 12), 0xffffffff])
    rows = c.emu.alloc(16 * 13, 4)
    for i in range(52): c.emu.w32(rows + 4 * i, c.rng.choice([c.rng.randint(-300, 600), R(c)]))
    return [n, rows, rbuf(c, 0x10), rbuf(c, 0x10)]
S(0x63a2e0, 'GUESS column min/max', 'fastcall', None, ret=None, gen=g_63a2e0)


def g_45ace0(c):   # GUESS fastcall(cls, parent; name, geom): new ZSTDOBJ-derived object (vtable 0x683e50)
    o = rbuf(c, 0x30); c.emu.w32(o + 8, rbuf(c, 0x10))
    patch(c, 0x45c4f0, L('alloc2', 2, pop=0, ecx=False, ret=c.rng.choice([0, o])))
    patch(c, 0x43de40, L('ZSTDOBJ', 3, ret=R(c))); patch(c, 0x4dcdf0, L('SetPrim', 1))
    return [R(c), R(c), R(c), R(c)]
S(0x45ace0, 'GUESS fastcall new ZSTDOBJ 0x683e50', 'fastcall', None, ret='eax', gen=g_45ace0)
