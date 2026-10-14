"""specs_s35191.py - 0x50e920 (stdcall(a) ret 4, ret=None, nan_heap). a: 0x20 random bytes. 0x5003d0 hooked (thiscall, 1 arg, a record block per call from a rotating list; byte +4 is 0, 2 or another value, so the log + assert paths are taken; the first call's dword gives the id).
Engine table slot 0x58 (1 arg) returns an entity (null in 1/4) whose slot 0x80 (2 args) writes random floats at 0x70148c..0x701494; the globals at 0x701480..0x701494 start random. Logger at 0x700390: slot 0x20 (2 args) returns an object with slot 0x2c (3 args, ECX = the vtable, caller-popped); assert hook at 0x7003b0 recorded."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g50e920(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    for off in range(0, 0x18, 4):
        e.w32(0x701480 + off, _fb(c.fv(-10, 10)))
    blocks = []
    for _ in range(6):
        b = rnd(c, 0x10)
        e.wbytes(b + 4, bytes([r.choice([0, 2, 2, 0, 1, 0x80, r.getrandbits(8)])]))
        blocks.append(b)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: blocks[k % 6])
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 3, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))

    def s80(em, k):
        for off in (0xc, 0x10, 0x14):
            em.w32(0x701480 + off, _fb(c.fv(-10, 10)))
    ent = 0 if r.random() < 1 / 4 else obj(c, 0x20, {0x80: pystub(c, 2, this=True, side=s80)}, nslots=0x24)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=ent)}, table_size=0x60)
    return [rnd(c, 0x20)]


S(0x50e920, 'GUESS entity orientation negated into three record slots', 'stdcall', None, ret=None, gen=_g50e920, nan_heap=True, note='batch35191')
