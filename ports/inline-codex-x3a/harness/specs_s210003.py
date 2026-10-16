"""specs_s210003.py - Sonnet-w3a: engine-table slot calls, ctor-style init, flag getters; callees hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _edx(emu, k): emu.calllog.append(('edx', emu.reg('edx')))


def g5d8420(c):
    clear_hooks(c)
    eng = obj(c, 0x200, {0x1cc: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x80)
    c.emu.w32(0x70039c, eng)
    hook_rec(c, 0x5d7b10, 0, ret=_r(c))
    return []


def g475aa0(c):
    clear_hooks(c)
    o = rnd(c, 0x400)
    vt = c.emu.r32(obj(c, 0x40, {0xc: pystub(c, 1, ret=_r(c), this=True)}, nslots=8))
    c.emu.wbytes(o + 0x2e7, vt.to_bytes(4, 'little'))
    return [o]


def g493110(c):
    clear_hooks(c)
    o = rnd(c, 0xc10)
    if c.rng.random() < 0.5: c.emu.wbytes(o + 0xbc2, b'\x00')
    c.emu.w32(o + 8, 0 if c.rng.random() < 0.3 else rnd(c, 0x40))
    hook_rec(c, 0x498700, 0, ret=_r(c), this=True, side=_edx)
    return [o, _r(c)]


def g4d5510(c):
    clear_hooks(c)
    return [rnd(c, 0x40)]


def g463300(c):
    clear_hooks(c)
    a = rnd(c, 0x80)
    this = rnd(c, 0x40); c.emu.w32(this + 8, a)
    q = obj(c, 0x40, {0xb4: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x40)
    o = rnd(c, 0x40); c.emu.w32(o + 0x18, q)
    eng = rnd(c, 0x1b00); c.emu.wbytes(eng + 0x1aa3, o.to_bytes(4, 'little'))
    c.emu.w32(0x70039c, eng)
    return [this]


def g49df00(c):
    clear_hooks(c)
    o = rnd(c, 0x40)
    if c.rng.random() < 0.4: c.emu.w32(o + 4, 0)
    hook_rec(c, 0x634273, 2, ret=_r(c), pop=0)
    return [o]


def g56dda0(c):
    clear_hooks(c)
    c.emu.w32(0x7003b8, rnd(c, 0x40))
    hook_rec(c, 0x562260, 0, ret=_r(c), this=True)
    hook_rec(c, 0x589c20, 1, ret=0 if c.rng.random() < 0.35 else rnd(c, 0x40), this=True)
    hook_rec(c, 0x59a570, 0, ret=_r(c), this=True)
    return [rnd(c, 0x40)]


def g57e210(c):
    clear_hooks(c)
    o = rnd(c, 0x340)
    if c.rng.random() < 0.5: c.emu.w32(o + 0x33c, 0)
    hook_rec(c, 0x562d90, 1, ret=_r(c), this=True)
    return [o, _r(c)]


def g4e1600(c):
    clear_hooks(c)
    o = rnd(c, 0x20)
    if c.rng.random() < 0.3: c.emu.w32(o + 4, 0)
    b = rnd(c, 4)
    if c.rng.random() < 0.3: c.emu.wbytes(b, b'\xff')
    c.emu.w32(o + 8, b)
    return [o]


S(0x5d8420, 'engine_slot_1cc_then_5d7b10', 'cdecl', None, ret='eax', gen=g5d8420, note='batch210003')
S(0x475aa0, 'vslot_c_of_embedded_obj_2e7', 'thiscall', None, ret='eax', gen=g475aa0, note='batch210003')
S(0x493110, 'once_flag_then_498700', 'fastcall', None, ret=None, gen=g493110, note='batch210003')
S(0x4d5510, 'init_fields_return_this', 'thiscall', None, ret='eax', gen=g4d5510, note='batch210003')
S(0x463300, 'engine_obj_slot_b4', 'thiscall', None, ret='eax', gen=g463300, note='batch210003')
S(0x49df00, 'set_vt_free_member', 'thiscall', None, ret='eax', gen=g49df00, note='batch210003')
S(0x56dda0, 'chain_562260_589c20_59a570', 'thiscall', None, ret='eax', gen=g56dda0, note='batch210003')
S(0x57e210, 'false_if_33c_else_562d90', 'thiscall', None, ret='al', gen=g57e210, note='batch210003')
S(0x4e1600, 'byte_flag_mask_3f', 'thiscall', None, ret='al', gen=g4e1600, note='batch210003')
