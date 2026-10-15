"""specs_c123.py - climb thread batch 123: MYSTR dtor, CHostInterface::alloc wrapper, unnamed wrapper at 0x54f870."""
import struct
from pilot import S
from ckit import rnd


def _delete(e, r):
    e.calllog.append(('delete', e.arg32(0), e.arg32(1)))
    e.ret(argbytes=0)


def _alloc(e, r):
    n = e.arg32(0)
    e.calllog.append(('alloc', n))
    e.ret(eax=e.alloc(max(1, n & 0xff), 16) if True else 0, argbytes=0)


def _alloc2(e, r):
    n = e.arg32(0)
    e.calllog.append(('alloc2', n))
    e.ret(eax=0x30000000 | (n & 0xffff), argbytes=0)


def _hooks(e):
    e.hook(0x634273, _delete)
    e.hook(0x41e290, _alloc)
    e.hook(0x41e2c0, _alloc2)


def _mystr(c):
    r = c.rng
    e = c.emu
    _hooks(e)
    self_ = rnd(c, 0x20)
    inline = (self_ + 4)
    if r.random() < 0.5:
        e.w32(self_, inline)
    else:
        e.w32(self_, rnd(c, 0x40))
    return [self_]


S(0x4cbec0, 'MYSTR::~MYSTR', 'thiscall', None, ret=None, gen=_mystr, note='c123; delete is a logging hook')


def _ha(c):
    _hooks(c.emu)
    return [c.rng.getrandbits(16)]


S(0x6014a0, 'CHostInterface::alloc', 'stdcall', None, ret='eax', gen=_ha, note='c123; allocator is a hook')


def _un(c):
    _hooks(c.emu)
    return [c.rng.getrandbits(16), c.rng.getrandbits(32)]


S(0x54f870, 'unnamed wrapper (no GC match)', 'stdcall', None, ret='eax', gen=_un, note='c123; allocator is a hook')
