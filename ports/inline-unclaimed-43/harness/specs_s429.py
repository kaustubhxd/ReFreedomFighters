"""specs_s429.py - residue 2 row 0x608da0 (thiscall, no arguments; conditional vtable calls).
If byte [0x724b34] != 0, return early. Otherwise: get obj = [this+0x1377];
call slot 0x80 with (address [this+0x1416], obj); call slot 0x84 with
(address [this+0x141a], [this+0x1377]); call slot 0x140 of [this] with ECX = this,
no stack args. Store 0 at [0x724844]; store 1 at [this+0x1e]; return."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu

SHARED = {}


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

    # Early exit case: set the flag to 0 (no early return)
    c.emu.wbytes(0x724b34, bytes([0]))

    def h80(e, rr):
        e.calllog.append(('slot_80', 0x80, e.reg('ecx') & 0xffffffff,
                          (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=8)

    def h84(e, rr):
        e.calllog.append(('slot_84', 0x84, e.reg('ecx') & 0xffffffff,
                          (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=8)

    def h140(e, rr):
        e.calllog.append(('slot_140', 0x140, e.reg('ecx') & 0xffffffff, ()))
        e.ret(eax=0, argbytes=0)

    # Create the object with vtable
    obj = E.zero_obj(c, 0x2000)
    c.emu.w32(obj, _vt(c, 'OBJ', {0x80: h80, 0x84: h84, 0x140: h140}))

    # Create a "this" object with the obj at offset 0x1377
    this_obj = E.zero_obj(c, 0x2000)
    c.emu.w32(this_obj, _vt(c, 'THIS', {0x140: h140}))
    c.emu.w32(this_obj + 0x1377, obj)

    # Initialize globals
    c.emu.wbytes(0x724844, bytes(4))  # Will be zeroed by the function

    o = E.zero_obj(c, 0x2000)
    for i in range(0x2000 // 4):
        c.emu.w32(o + 4 * i, r.getrandbits(32))
    c.emu.mu.ctl_flush_tb()
    return [this_obj, r.getrandbits(32)]


S(0x608da0, 'conditional vtable calls (residue 2) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='residue 2 batch 429; slots 0x80, 0x84, 0x140 mocked; global flag 0x724b34 always 0 (no early exit)')
