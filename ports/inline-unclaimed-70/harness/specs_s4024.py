"""specs_s4024.py - area 70 batch 4024: 0x4cecd0 and 0x5fa050 (GUESS names). The logger global 0x700390 is a fake whose slot
0x20 (thiscall, two args) returns a fake stream S; S's slot 0x2c is a cdecl recorder (its three arguments are constants, logged).
0x7003b0 is set to a recording cdecl stub. Slot 0x40 on the this object returns a per-case flag."""
import struct
from pilot import S, F


def _stub_addr(c, addr, name, handler):
    e = c.emu
    stub = e.stub_fn(name, handler)
    e.mu.mem_write(addr, b'\xe9' + struct.pack('<i', stub - (addr + 5)))   # jmp stub
    e._image_dirty = True
    e.mu.ctl_flush_tb()


def _logger(c, tag):
    e = c.emu
    stream_vt = e.fake_vtable('stream_' + tag, 0x10, {0x2c: lambda em, rr: _rec(em, tag)})
    stream = e.alloc(0x40, 4)
    e.w32(stream, stream_vt)

    def slot20(em, rr):
        em.calllog.append(('20', em.arg32(0), em.arg32(1)))
        em.ret(eax=stream, argbytes=8)

    lvt = e.fake_vtable('logger_' + tag, 0x10, {0x20: slot20})
    logger = e.alloc(0x40, 4)
    e.w32(logger, lvt)
    e.w32(0x700390, logger)
    return stream


def _rec(em, tag):
    em.calllog.append(('2c', tag, em.arg32(0), em.arg32(1), em.arg32(2)))
    em.ret(argbytes=0)          # cdecl: the caller cleans up


def _hook(c):
    e = c.emu

    def hook(em, rr):
        em.calllog.append(('hook',))
        em.ret(argbytes=0)

    h = e.stub_fn('hook_7003b0', hook)
    e.w32(0x7003b0, h)


def _cecd0(c):
    e, r = c.emu, c.rng
    flag_ret = (r.getrandbits(32) & ~0xff) if r.random() < 0.5 else (r.getrandbits(32) | 1)   # al zero half the time: the log branch runs
    _logger(c, 'a')
    vt = e.fake_vtable('this_4cecd0', 0x11, {0x40: lambda em, rr: em.ret(eax=flag_ret, argbytes=4)})
    self_ = e.alloc(0x40, 4)
    e.w32(self_, vt)
    return [self_, r.getrandbits(32)]


def _fa050(c):
    _logger(c, 'b')
    _hook(c)
    return [0]


S(0x4cecd0, 'log the flag through the stream when slot 0x40 returns zero (name GUESS)', 'thiscall', None, ret=None,
  gen=_cecd0, note='batch4024')
S(0x5fa050, 'log two fixed tags, then call the hook at 0x7003b0 (name GUESS)', 'thiscall', None, ret='eax', gen=_fa050,
  note='batch4024')
