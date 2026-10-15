"""specs_f1015.py - fresh-10 batch 15 (slice 10)."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
from h10 import L, obj, rbuf, patch, iat, log_obj


def R(c): return c.rng.getrandbits(32)


def g_6316e0(c):   # zlib adler32
    n = c.rng.choice([0, 1, 15, 16, 17, 100, 5552, 5553, 11104, 12000, c.rng.randint(0, 20000)])
    b = c.emu.alloc(n + 16, 4)
    fill = c.rng.choice(['rand', 'ff'])
    c.emu.wbytes(b, (b'\xff' * n) if fill == 'ff' else bytes(c.rng.getrandbits(8) for _ in range(n)))
    return [c.rng.choice([1, R(c), 0xfff0fff0, 0xffffffff]), c.rng.choice([b, b, b, 0]), n]
S(0x6316e0, 'zlib adler32', 'stdcall', None, ret='eax', gen=g_6316e0)


def col(c):
    a = c.emu.alloc(16, 4)
    for k in range(3): c.emu.w32(a + 4 * k, c.rng.choice([c.rng.randint(0, 255), c.rng.randint(-300, 300), R(c)]))
    return a
def g_6383a0(c):   # GUESS DXT1 palette
    return [c.rng.choice([0, 1, R(c)]), rbuf(c, 0x40), col(c), col(c)]
S(0x6383a0, 'GUESS DXT1 palette', 'fastcall', None, ret=None, gen=g_6383a0)


def g_63a1a0(c):   # GUESS DXT1 block indices
    px = c.emu.alloc(0x100, 4)
    for i in range(64):
        c.emu.w32(px + 4 * i, c.rng.choice([c.rng.randint(0, 255), 0, R(c)]) if i % 4 == 3 else c.rng.choice([c.rng.randint(0, 255), R(c)]))
    return [c.rng.choice([0, 1]), c.rng.randint(0, 3), col(c), col(c), px, rbuf(c, 0x40)]
S(0x63a1a0, 'GUESS DXT1 block indices', 'fastcall', None, ret=None, gen=g_63a1a0)


def g_50b860(c):   # ZScriptItemInterface_t::AttachItem
    def a3d0(e, r):
        e.calllog.append(('arg', e.reg('ecx'), (e.arg32(0),))); e.ret(eax=e.reg('ecx') + 0x10 + 4 * e.arg32(0), argbytes=4)
    patch(c, 0x5003d0, a3d0); patch(c, 0x5002f0, L('setres', 1))
    patch(c, 0x441730, L('lock', 0)); patch(c, 0x440530, L('unlock', 0))
    def p2c(e, r):
        f = e.arg32(1); a = (e.arg32(0), f) + ((e.arg32(2),) if f == 0x69d5fc else ())
        e.calllog.append(('log2c', 0, a)); e.ret(eax=0, argbytes=0)
    o2 = obj(c, 'log2', {0x2c: p2c}, size=0x10); c.emu.w32(0x700390, obj(c, 'log', {0x20: L('log20', 2, ret=o2)}, size=0x10))
    item = rbuf(c, 0x20); c.emu.w32(item, c.emu.fake_vtable('item', 0x79, {0x1e0: L('item1e0', 1, ret=c.rng.choice([0, 1, 0x100, 0xffff0001]))}))
    tgt = rbuf(c, 0x20); c.emu.w32(tgt, c.emu.fake_vtable('tgt', 0x4d, {0x130: L('SendCommand', 3)}))
    rets = {}
    a4 = rbuf(c, 0x20); a8 = rbuf(c, 0x20)
    v0, v1 = c.emu.r32(a4 + 0x10), c.emu.r32(a4 + 0x14)
    rets[v1] = c.rng.choice([0, item, item, item]); rets.setdefault(v0, c.rng.choice([0, tgt, tgt]))
    def s58(e, r):
        k = e.arg32(0); e.calllog.append(('scene58', e.reg('ecx'), (k,))); e.ret(eax=rets.get(k, 0), argbytes=4)
    s = obj(c, 'scene', {0x58: s58, 0x114: L('RegisterZMsg', 4, ret=R(c))}, size=0x200)
    rm = rbuf(c, 0x100); c.emu.w32(rm + 0x9b, s); c.emu.w32(0x70039c, rm)
    p = rbuf(c, 0x10); c.emu.w32(p + 4, a4); c.emu.w32(p + 8, a8)
    return [rbuf(c, 0x10), p]
S(0x50b860, 'ZScriptItemInterface_t::AttachItem', 'thiscall', None, ret=None, gen=g_50b860)
