"""specs_s34008.py - cascade escalation batch 34008: 0x45d5b0 (slot 0x48) and 0x4d49b0 (embedded subobject at +0x10db, unaligned vtable
pointer, slot 4). Slots are recorder stubs (ECX and 2 stack args recorded)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g45d5b0(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x40, {0x48: pystub(c, 2, ret=r.getrandbits(32), this=True)})
    return [me, r.getrandbits(32), r.getrandbits(32)]


def _g4d49b0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x1200)
    vt = c.emu.alloc(0x20, 4)
    c.emu.wbytes(vt, bytes(r.getrandbits(8) for _ in range(0x20)))
    c.emu.w32(vt + 4, pystub(c, 2, ret=r.getrandbits(32), this=True))
    c.emu.wbytes(me + 0x10db, vt.to_bytes(4, 'little'))
    return [me, r.getrandbits(32), r.getrandbits(32)]


S(0x45d5b0, 'GUESS vtable tail thunk slot 0x48', 'thiscall', None, ret='eax', gen=_g45d5b0, note='batch34008')
S(0x4d49b0, 'GUESS subobject +0x10db slot 4 forward', 'thiscall', None, ret='eax', gen=_g4d49b0, note='batch34008')
