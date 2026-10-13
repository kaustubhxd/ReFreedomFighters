"""specs_s426.py - residue 2 row 0x43b9a0 (thiscall, one stack argument msg, ret 4; config reader error report). The logger at
global 0x700390 has a logging vtable whose slot 0x20 takes (file, line) with ret 8 and returns a stream object; the stream's
slot 0x2c is cdecl (argbytes 0) and logs its five stack arguments (stream, fmt, file, line, msg). 0x61bbd0 is hooked by address
(GUESS: thiscall, no arguments, returns the line number drawn in gen)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu

SHARED = {'line': 0, 'p': 0}


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _vt(c, name, slots_spec, n=0x40):
    slots = {}
    for i in range(n // 4):
        slots[4 * i] = (lambda e, rr: e.ret(eax=0, argbytes=0))
    slots.update(slots_spec)
    return c.emu.fake_vtable(name, n // 4, slots)


def _setup(c):
    def h61bb(em, rr):
        em.calllog.append(('line61bbd0', 0, em.reg('ecx') & 0xffffffff, ()))
        em.ret(eax=SHARED['line'], argbytes=0)
    c.emu.hook(0x61bbd0, h61bb)


def _gen(c):
    r = c.rng
    SHARED['line'] = r.getrandbits(32)

    def h2c(e, rr):
        e.calllog.append(('LOG2C', 0x2c, 0, tuple(_nostack(e.arg32(k)) for k in range(5))))
        e.ret(eax=0, argbytes=0)
    stream = E.zero_obj(c, 0x20)
    c.emu.w32(stream, _vt(c, 'STREAM', {0x2c: h2c}))

    def h20(e, rr):
        e.calllog.append(('LOG20', 0x20, e.reg('ecx') & 0xffffffff, (e.arg32(0), e.arg32(1))))
        e.ret(eax=stream, argbytes=8)
    logger = E.zero_obj(c, 0x20)
    c.emu.w32(logger, _vt(c, 'LOGGER', {0x20: h20}))
    E.set_global(c, 0x700390, logger)
    o = E.zero_obj(c, 0x200)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x200)))
    c.emu.mu.ctl_flush_tb()
    return [o, r.getrandbits(32)]


S(0x43b9a0, 'config reader error report (residue 2) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='residue 2 batch 426; 0x61bbd0 hooked (GUESS); logger and stream vtables mocked')
