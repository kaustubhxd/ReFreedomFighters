"""specs_s423.py - residue 2 row 0x4964e0 (thiscall, one stack argument v, ret 4; returns the hash). No exe callees: the hash object
P (at this+8) has a logging vtable whose slot 4 returns a random dword h; the logger object at global 0x70038c has a logging vtable
whose slot 0x2c takes three arguments. The table at this+0xc is a 4 KB zeroed block and the mask at P+0x10 is 0..0x3ff, so the
store stays inside it."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu

SHARED = {'h': 0}


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _vt(c, name, slots_spec, n=0x40):
    slots = {}
    for i in range(n // 4):
        slots[4 * i] = (lambda e, rr: e.ret(eax=0, argbytes=0))
    slots.update(slots_spec)
    return c.emu.fake_vtable(name, n // 4, slots)


def _setup(c):
    pass


def _gen(c):
    r = c.rng
    SHARED['h'] = r.getrandbits(32)

    def h4(e, rr):
        e.calllog.append(('HASH4', 4, e.reg('ecx') & 0xffffffff, ()))
        e.ret(eax=SHARED['h'], argbytes=0)
    P = E.zero_obj(c, 0x40)
    c.emu.w32(P, _vt(c, 'HASHP', {4: h4}))
    c.emu.w32(P + 0x10, r.randint(0, 0x3ff))

    def h2c(e, rr):
        e.calllog.append(('LOG2C', 0x2c, e.reg('ecx') & 0xffffffff, tuple(e.arg32(k) for k in range(3))))
        e.ret(eax=0, argbytes=12)
    logger = E.zero_obj(c, 0x40)
    c.emu.w32(logger, _vt(c, 'LOGGER', {0x2c: h2c}))
    E.set_global(c, 0x70038c, logger if r.random() < 0.8 else 0)
    tab = E.zero_obj(c, 0x1000)
    o = E.zero_obj(c, 0x20)
    c.emu.w32(o + 0x8, P)
    c.emu.w32(o + 0xc, tab)
    c.emu.mu.ctl_flush_tb()
    return [o, r.getrandbits(32)]


S(0x4964e0, 'hash insert into table with logger (residue 2) thiscall', 'thiscall', None, ret='eax', gen=_gen, setup=_setup,
  note='residue 2 batch 423; no exe callees; vtables mocked')
