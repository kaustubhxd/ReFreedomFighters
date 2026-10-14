"""specs_s43000.py - t4 () batch 43000: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _fbits(c, lo=-100.0, hi=100.0):
    r = c.rng
    k = r.random()
    if k < 0.08:
        v = r.choice([0.0, -0.0, float('inf'), float('-inf'), float('nan'), 1.0, 3.0])
    elif k < 0.2:
        v = r.uniform(-1e6, 1e6)
    else:
        v = c.fv(lo, hi, 0.25)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _fmod_stub(c):
    # guest x87 code for the _CIfmod import (st0 = divisor, st1 = dividend): fxch st1; fprem; fstp st1; ret
    code = bytes([0xd9, 0xc9, 0xd9, 0xf8, 0xdd, 0xd9, 0xc3])
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    c.emu.mu.ctl_flush_tb()
    c.emu.w32(0x676358, a)


def _g4e59b0(c):
    clear_hooks(c)
    _fmod_stub(c)
    r = c.rng
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', lambda e, res: e.ret(eax=_w(c))))
    me = rnd(c, 0x20)
    w = r.choice([0, 1, 2, 5, 7, 60, 360, 0x7fff, 0xffff, r.getrandbits(16), r.randrange(1, 400)])
    c.emu.wbytes(me + 8, w.to_bytes(2, 'little'))
    flag = r.choice([0, 1, 2, 0x100, 0xff, _w(c)])
    x = struct.unpack('<f', struct.pack('<I', _fbits(c, -500.0, 500.0)))[0]
    return [me, flag, F(x)]


def _g51aaf0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res: em.ret(eax=_w(c))))
    # table object read by 0x5003d0 (hooked): returns pointers into a heap block of float/flag pairs
    blk = rnd(c, 0x40)
    e.w32(blk, _fbits(c))
    e.w32(blk + 8, r.choice([0, 1, _w(c)]))
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=lambda em, k: blk + 8 * (em.arg32(0) & 1))
    s = pystub(c, 2, this=True)
    ch = obj(c, 0x40, {0x360: s})
    me = rnd(c, 0x40)
    e.w32(me + 0x18, ch)
    a = rnd(c, 0x20)
    e.w32(a + 4, rnd(c, 0x20))
    return [me, a]


def _g5f4e60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res: em.ret(eax=_w(c))))
    o2 = obj(c, 0x40, {0x2c: pystub(c, 3, this=True, pop=0)})
    e.w32(0x700390, obj(c, 0x40, {0x20: pystub(c, 2, ret=o2, this=True)}))
    me = rnd(c, 0x20)
    e.wbytes(me + 4, bytes([r.choice([2, 2, 2, 0, 1, 3, r.getrandbits(8)])]))
    e.w32(me, _fbits(c))
    p = rnd(c, 0x10)
    e.w32(p, _fbits(c))
    return [me, p]


S(0x4e59b0, 'GUESS word wrap by fmod or clamp to word', 'stdcall', None, ret='st0', gen=_g4e59b0, note='batch43000')
S(0x51aaf0, 'GUESS table float and flag to slot 0x360', 'thiscall', None, ret=None, gen=_g51aaf0, note='batch43000')
S(0x5f4e60, 'GUESS multiply float when kind 2 else log and assert', 'thiscall', None, ret=None, gen=_g5f4e60, note='batch43000')
