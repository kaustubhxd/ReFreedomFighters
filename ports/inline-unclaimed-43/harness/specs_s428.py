"""specs_s428.py - residue 2 row 0x4b5ca0 (thiscall, no arguments; nested vtable calls).
Get engine = [0x70039c]; obj = [engine+0x9b]; call slot 0x138 with ECX = obj (no args),
returns r1. Call slot 0x88 with ECX = r1 (thiscall, two stack args: local buffer, 0x69206c).
Get obj2 = [[0x70039c]+0x9b]. Call slot 0x58 with ECX = obj2 (thiscall, one stack arg: [ebp-4]).
Store result at [this+0x12a]."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu

SHARED = {'r1': 0, 'r2': 0, 'buf_val': 0, 'final': 0}


def _vt(c, name, slots_spec, n=0x200):
    slots = {}
    for i in range(n // 4):
        slots[4 * i] = (lambda e, rr: e.ret(eax=0, argbytes=0))
    slots.update(slots_spec)
    return c.emu.fake_vtable(name, n // 4, slots)


def _setup(c):
    pass


def _gen(c):
    r = c.rng
    SHARED['r1'] = r.getrandbits(32)
    SHARED['r2'] = r.getrandbits(32)
    SHARED['buf_val'] = r.getrandbits(32)
    SHARED['final'] = r.getrandbits(32)

    def h138(e, rr):
        e.calllog.append(('slot_138', 0x138, e.reg('ecx') & 0xffffffff, ()))
        e.ret(eax=SHARED['r1'], argbytes=0)

    def h88(e, rr):
        e.calllog.append(('slot_88', 0x88, e.reg('ecx') & 0xffffffff,
                          (e.arg32(0), e.arg32(1))))
        e.ret(eax=SHARED['r2'], argbytes=8)

    def h58(e, rr):
        e.calllog.append(('slot_58', 0x58, e.reg('ecx') & 0xffffffff, (e.arg32(0),)))
        SHARED['buf_val'] = e.arg32(0)
        e.ret(eax=SHARED['final'], argbytes=4)

    # Create the object with vtable slots
    obj = E.zero_obj(c, 0x100)
    c.emu.w32(obj, _vt(c, 'OBJ', {0x138: h138, 0x88: h88, 0x58: h58}))

    # Create the r1 result object
    r1 = E.zero_obj(c, 0x100)
    c.emu.w32(r1, _vt(c, 'R1', {0x88: h88}))
    SHARED['r1'] = r1

    # Create engine with obj at offset 0x9b
    engine = E.zero_obj(c, 0x100)
    c.emu.w32(engine + 0x9b, obj)
    E.set_global(c, 0x70039c, engine)

    # Create a "this" object for the function
    o = E.zero_obj(c, 0x2000)
    for i in range(0x2000 // 4):
        c.emu.w32(o + 4 * i, r.getrandbits(32))
    c.emu.mu.ctl_flush_tb()
    return [o, r.getrandbits(32)]


S(0x4b5ca0, 'nested vtable calls (residue 2) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='residue 2 batch 428; slots 0x138, 0x88, 0x58 mocked; result stored at offset 0x12a')
